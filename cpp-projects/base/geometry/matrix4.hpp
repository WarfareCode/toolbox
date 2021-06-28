
/*******************************************************************************
** Toolbox-base                                                               **
** MIT License                                                                **
** Copyright (c) [2018] [Florian Lance]                                       **
**                                                                            **
** Permission is hereby granted, free of charge, to any person obtaining a    **
** copy of this software and associated documentation files (the "Software"), **
** to deal in the Software without restriction, including without limitation  **
** the rights to use, copy, modify, merge, publish, distribute, sublicense,   **
** and/or sell copies of the Software, and to permit persons to whom the      **
** Software is furnished to do so, subject to the following conditions:       **
**                                                                            **
** The above copyright notice and this permission notice shall be included in **
** all copies or substantial portions of the Software.                        **
**                                                                            **
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR **
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,   **
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL    **
** THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER **
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING    **
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER        **
** DEALINGS IN THE SOFTWARE.                                                  **
**                                                                            **
********************************************************************************/

#pragma once

// local
#include "geometry/matrix3.hpp"
#include "point4.hpp"


namespace tool::geo {

// #######################################

//{ x.x x.y x.z 0
//  y.x y.y y.z 0
//  z.x z.y z.z 0
//  p.x p.y p.z 1 }

//   r  r  r
// r 00 01 02 | 03
// r 10 11 12 | 13
// r 20 21 22 | 23
// -----------------
// t 30 31 32 | 33
// #######################################

template<typename acc>
struct Mat4;

using Mat4f = Mat4<float>;
using Mat4d = Mat4<double>;

template<typename acc>
struct Mat4 : public Matrix<acc,4,4>{

    using Matrix<acc,4,4>::array;
    using Matrix<acc,4,4>::at;

    Mat4() = default;
    explicit inline Mat4(bool identity)         noexcept : Matrix<acc,4,4>(identity){}
    explicit inline Mat4(acc *values)           noexcept : Matrix<acc,4,4>(values){}
    inline Mat4(std::initializer_list<acc> l)   noexcept : Matrix<acc,4,4>(l){}

    inline Mat4(Matrix<acc,4,4> mat){
        array = std::move(mat.array);
    }

    static auto constexpr identity() noexcept{
        return Mat4<acc>(true);
    }

    inline bool is_identity() const noexcept{
        for(int ii = 0; ii < 4; ++ii){
            for(int jj = 0; jj < 4; ++jj){
                if(ii == jj){
                    if(!almost_equal(at(ii,jj), acc{1})){
                        return false;
                    }
                }else{
                    if(!almost_equal(at(ii,jj), acc{0})){
                        return false;
                    }
                }
            }
        }
        return true;
    }

    inline Mat4(vecN<acc, 16> array) noexcept{
        array = std::move(array);
    }

    inline Mat4(Mat3<acc> rotation){
        for(int  ii = 0; ii < 9; ++ii){
            r(ii) = rotation(ii);
        }
        array[15] = 1;
    }

    inline Mat4(Mat3<acc> rotation, Pt3<acc> translation){
        *this = transform({1,1,1},rotation, translation);
    }

    inline Mat4(Pt3<acc> scale, Mat3<acc> rotation, Pt3<acc> translation){
        *this = transform(scale,rotation, translation);
    }

    template <typename acc2>
    Mat4<acc2> conv() const{
        Mat4<acc2> mc;
        for(size_t ii = 0; ii < 16; ++ii){
            mc.array[ii] = static_cast<acc2>(array[ii]);
        }
        return mc;
    }


    Mat4<acc> minor() const{

        Mat4<acc> res = {};
        for(int ii = 0; ii < 4; ++ii){
            for(int jj = 0; jj < 4; ++jj){                
                res.at(ii,jj) = static_cast<Mat3<acc>>(cut(this, ii,jj)).determinant();
            }
        }
        return res;
    }

//    inline Mat4<acc> cofactor() const{
//        return Matrix<acc,4,4>::cofactor(minor());
//    }

    constexpr acc trace() const{
        return array[0] + array[5] + array[10] + array[15];
    }

    acc determinant() const{
        // #######################################
        // acc result{0};
        // Mat4<acc> cof = cofactor();
        // for(int ii = 0; ii < 4; ++ii){
        //     result += array[ii] * cof.at(0,ii);
        // }
        // return result;
        // #######################################
        return
              at(0) * at(5) * at(10) * at(15) + at(0) * at(6) * at(11) * at(13) + at(0) * at(7) * at(9)  * at(14)
            + at(1) * at(4) * at(11) * at(14) + at(1) * at(6) * at(8)  * at(15) + at(1) * at(7) * at(10) * at(12)
            + at(2) * at(4) * at(9)  * at(15) + at(2) * at(5) * at(11) * at(12) + at(2) * at(7) * at(8)  * at(13)
            + at(3) * at(4) * at(10) * at(13) + at(3) * at(5) * at(8)  * at(14) + at(3) * at(6) * at(9)  * at(12)
            - at(0) * at(5) * at(11) * at(14) - at(0) * at(6) * at(9)  * at(15) - at(0) * at(7) * at(10) * at(13)
            - at(1) * at(4) * at(10) * at(15) - at(1) * at(6) * at(11) * at(12) - at(1) * at(7) * at(8)  * at(14)
            - at(2) * at(4) * at(11) * at(13) - at(2) * at(5) * at(8)  * at(15) - at(2) * at(7) * at(9)  * at(12)
            - at(3) * at(4) * at(9)  * at(14) - at(3) * at(5) * at(10) * at(12) - at(3) * at(6) * at(8)  * at(13);
    }

    inline Mat4<acc> adjugate()const {
        return cofactor(this).transpose();
    }

    Mat4<acc> inverse () const{

        const acc det  = determinant();
        if(almost_equal<acc>(det, acc{0})){
            return Mat4<acc>{};
        }
        // #######################################
        // return adjugate()*(acc{1}/det);
        // #######################################
        const acc invDet = acc{1}/ det;

        Mat4<acc> result{};
        result(0)  = (at(5) * at(10) * at(15) + at(6) * at(11) * at(13) + at(7) * at(9) * at(14) - at(5) * at(11) * at(14) - at(6) * at(9) * at(15) - at(7) * at(10) * at(13)) * invDet;
        result(1)  = (at(1) * at(11) * at(14) + at(2) * at(9) * at(15) + at(3) * at(10) * at(13) - at(1) * at(10) * at(15) - at(2) * at(11) * at(13) - at(3) * at(9) * at(14)) * invDet;
        result(2)  = (at(1) * at(6) * at(15) + at(2) * at(7) * at(13) + at(3) * at(5) * at(14) - at(1) * at(7) * at(14) - at(2) * at(5) * at(15) - at(3) * at(6) * at(13)) * invDet;
        result(3)  = (at(1) * at(7) * at(10) + at(2) * at(5) * at(11) + at(3) * at(6) * at(9) - at(1) * at(6) * at(11) - at(2) * at(7) * at(9) - at(3) * at(5) * at(10)) * invDet;
        result(4)  = (at(4) * at(11) * at(14) + at(6) * at(8) * at(15) + at(7) * at(10) * at(12) - at(4) * at(10) * at(15) - at(6) * at(11) * at(12) - at(7) * at(8) * at(14)) * invDet;
        result(5)  = (at(0) * at(10) * at(15) + at(2) * at(11) * at(12) + at(3) * at(8) * at(14) - at(0) * at(11) * at(14) - at(2) * at(8) * at(15) - at(3) * at(10) * at(12)) * invDet;
        result(6)  = (at(0) * at(7) * at(14) + at(2) * at(4) * at(15) + at(3) * at(6) * at(12) - at(0) * at(6) * at(15) - at(2) * at(7) * at(12) - at(3) * at(4) * at(14)) * invDet;
        result(7)  = (at(0) * at(6) * at(11) + at(2) * at(7) * at(8) + at(3) * at(4) * at(10) - at(0) * at(7) * at(10) - at(2) * at(4) * at(11) - at(3) * at(6) * at(8)) * invDet;
        result(8)  = (at(4) * at(9) * at(15) + at(5) * at(11) * at(12) + at(7) * at(8) * at(13) - at(4) * at(11) * at(13) - at(5) * at(8) * at(15) - at(7) * at(9) * at(12)) * invDet;
        result(9)  = (at(0) * at(11) * at(13) + at(1) * at(8) * at(15) + at(3) * at(9) * at(12) - at(0) * at(9) * at(15) - at(1) * at(11) * at(12) - at(3) * at(8) * at(13)) * invDet;
        result(10) = (at(0) * at(5) * at(15) + at(1) * at(7) * at(12) + at(3) * at(4) * at(13) - at(0) * at(7) * at(13) - at(1) * at(4) * at(15) - at(3) * at(5) * at(12)) * invDet;
        result(11) = (at(0) * at(7) * at(9) + at(1) * at(4) * at(11) + at(3) * at(5) * at(8) - at(0) * at(5) * at(11) - at(1) * at(7) * at(8) - at(3) * at(4) * at(9)) * invDet;
        result(12) = (at(4) * at(10) * at(13) + at(5) * at(8) * at(14) + at(6) * at(9) * at(12) - at(4) * at(9) * at(14) - at(5) * at(10) * at(12) - at(6) * at(8) * at(13)) * invDet;
        result(13) = (at(0) * at(9) * at(14) + at(1) * at(10) * at(12) + at(2) * at(8) * at(13) - at(0) * at(10) * at(13) - at(1) * at(8) * at(14) - at(2) * at(9) * at(12)) * invDet;
        result(14) = (at(0) * at(6) * at(13) + at(1) * at(4) * at(14) + at(2) * at(5) * at(12) - at(0) * at(5) * at(14) - at(1) * at(6) * at(12) - at(2) * at(4) * at(13)) * invDet;
        result(15) = (at(0) * at(5) * at(10) + at(1) * at(6) * at(8) + at(2) * at(4) * at(9) - at(0) * at(6) * at(9) - at(1) * at(4) * at(10) - at(2) * at(5) * at(8)) * invDet;
        return result;
    }

    Pt3<acc> multiply_point(const Pt3<acc> &pt) const{
        return Pt3<acc>{pt.x()*at(0,0) + pt.y() * at(1,0) + pt.z() * at(2,0) + at(3,0),
                        pt.x()*at(0,1) + pt.y() * at(1,1) + pt.z() * at(2,1) + at(3,1),
                        pt.x()*at(0,2) + pt.y() * at(1,2) + pt.z() * at(2,2) + at(3,2)};
    }

    Pt4<acc> multiply_point(const Pt4<acc> &pt) const{
        return Pt4<acc>{
            pt.x()*at(0,0) + pt.y() * at(1,0) + pt.z() * at(2,0) + pt.w() * at(3,0),
            pt.x()*at(0,1) + pt.y() * at(1,1) + pt.z() * at(2,1) + pt.w() * at(3,1),
            pt.x()*at(0,2) + pt.y() * at(1,2) + pt.z() * at(2,2) + pt.w() * at(3,2),
            pt.x()*at(0,3) + pt.y() * at(1,3) + pt.z() * at(2,3) + pt.w() * at(3,3)
        };
    }

    Vec3<acc> multiply_vector(const Vec3<acc>& vec) const {
        return Vec3<acc>{
            dot(vec, Vec3<acc>{ at(0,0), at(1,0), at(2,0)}),
            dot(vec, Vec3<acc>{ at(0,1), at(1,1), at(2,1)}),
            dot(vec, Vec3<acc>{ at(0,2), at(1,2), at(2,2)})
        };
    }

    Vec4<acc> multiply_vector(const Vec4<acc>& vec) const {
        return Vec4<acc>{
            dot(vec, Vec4<acc>{ at(0,0), at(1,0), at(2,0), at(3,0)}),
            dot(vec, Vec4<acc>{ at(0,1), at(1,1), at(2,1), at(3,1)}),
            dot(vec, Vec4<acc>{ at(0,2), at(1,2), at(2,2), at(3,2)}),
            dot(vec, Vec4<acc>{ at(0,3), at(1,3), at(2,3), at(3,3)})
        };
    }

    inline Vec3<acc> translation() const noexcept{
        return {t(0), t(1), t(2)};
    }

//    inline Mat3<acc> rotation() const noexcept{
//        return Mat3<acc>{
//            at(0,0),at(0,1),at(0,2),
//            at(1,0),at(1,1),at(1,2),
//            at(2,0),at(2,1),at(2,2)
//        };
//    }

    constexpr  acc t(int id) const {return at(3,id);}
    constexpr acc& t(int id) {return at(3,id);}

    constexpr  acc s(int id) const {return at(id,id);}
    constexpr acc& s(int id) {return at(id,id);}

    constexpr  acc r(int id) const {
        switch (id) {
        case 0: return array[0];
        case 1: return array[1];
        case 2: return array[2];
        case 3: return array[4];
        case 4: return array[5];
        case 5: return array[6];
        case 6: return array[8];
        case 7: return array[9];
        case 8: return array[10];
        default: return array[0];
        }
    }

    constexpr acc& r(int id) {
        switch (id) {
        case 0: return array[0];
        case 1: return array[1];
        case 2: return array[2];
        case 3: return array[4];
        case 4: return array[5];
        case 5: return array[6];
        case 6: return array[8];
        case 7: return array[9];
        case 8: return array[10];
        default: return array[0];
        }
    }

    // static
    static constexpr Mat4<acc> scale(const Mat4<acc> &m, const Vec3<acc> &s){

        const auto row0 = m.row(0) * s.x();
        const auto row1 = m.row(1) * s.y();
        const auto row2 = m.row(2) * s.z();
        const auto row3 = m.row(3);

        return Mat4<acc>{
            row0[0], row0[1], row0[2], row0[3],
            row1[0], row1[1], row1[2], row1[3],
            row2[0], row2[1], row2[2], row2[3],
            row3[0], row3[1], row3[2], row3[3],
        };
    }

    static constexpr Mat4<acc> translate(const Mat4<acc> &m, const Vec3<acc> &t){

        const auto r = m.row(0)*t.x() + m.row(1) * t.y() + m.row(2) * t.z() + m.row(3);
        return Mat4<acc>{
            m.array[0], m.array[1], m.array[2], m.array[3],
            m.array[4], m.array[5], m.array[6], m.array[7],
            m.array[8], m.array[9], m.array[10],m.array[11],
            r[0], r[1], r[2], r[3]
        };
    }


    static Mat4<acc> LookAt(const Pt3<acc> &eye, const Pt3<acc> &at, const Vec3<acc> &up){

        Vec3<acc> zaxis = normalize(at - eye);
        Vec3<acc> xaxis = normalize(cross(zaxis, up));
        Vec3<acc> yaxis = cross(xaxis, zaxis);
        zaxis = -zaxis;

        return {
            xaxis.x(), yaxis.x(), zaxis.x(), 0,
            xaxis.y(), yaxis.y(), zaxis.y(), 0,
            xaxis.z(), yaxis.z(), zaxis.z(), 0,
            -dot(xaxis, eye), -dot(yaxis, eye), -dot(zaxis, eye), 1

        };
    }

    static constexpr Mat4<acc> Perspective(acc fovY, acc aspectRatio, acc zNear, acc zFar){

        // fovy = 2 atan(w/(2d))
        // w: width of the object perpendicular to the line of sight
        // d: distance of the object
        const auto c = acc{1}/std::tan(fovY/2);
        const auto diffZ = zFar-zNear;
        return {
            c/aspectRatio, 0,    0,                     0,
            0,             c,    0,                     0,
            0,             0,    -(zFar+zNear)/diffZ,   -1,
            0,             0,    -(2*zFar*zNear)/diffZ, 0
        };
    }

    static constexpr Mat4<acc> Ortho(acc left, acc right, acc bottom, acc top, acc zNear, acc zFar){
//        return Mat4<acc>{
//            acc{2}/(right-left),0,0,0,
//            0,acc{2}/(top-bottom),0,0,
//            0,0,acc{-2}/(zFar-zNear),0,
//            -((right+left)/(right-left)), -((top+bottom)/(top-bottom)), -((zFar+zNear)/(zFar-zNear)), 1
//        };
        return Mat4<acc>{
            acc{2}/(right-left),0,0,-((right+left)/(right-left)),
            0,acc{2}/(top-bottom),0,-((top+bottom)/(top-bottom)),
            0,0,acc{-2}/(zFar-zNear),-((zFar+zNear)/(zFar-zNear)),
            0, 0, 0, 1
        };
    }

    static constexpr Mat4<acc> translation_matrix(const Vec3<acc> &t) noexcept{
        return {
            1,      0,      0,      0,
            0,      1,      0,      0,
            0,      0,      1,      0,
            t.x(),  t.y(),  t.z(),  1
        };
    }

    static constexpr Mat4<acc> scale_matrix(const Vec3<acc> &s) noexcept{
        return {
            s.x(),  0,      0,      0,
            0,      s.y(),  0,      0,
            0,      0,      s.z(),  0,
            0,      0,      0,      1
        };
    }


    static Mat4<acc> rotation_matrix(const Pt3<acc> &angles){
        return Mat4<acc>{Mat3<acc>::rotation_matrix(angles)};
    }

    static Mat4<acc> rotate(const Mat4<acc> &m, const Vec3<acc> &angles){
        // equivalent to:
        // return m * Mat4<acc>(
        //     Mat3<acc>::y_rotation_matrix(angles.y())*
        //     Mat3<acc>::x_rotation_matrix(angles.x())*
        //     Mat3<acc>::z_rotation_matrix(angles.z())
        // );
        return m*rotation_matrix(angles*PI_180<acc>);
    }

    static Mat4<acc> transform(const Vec3<acc> &scale, const Vec3<acc> &rotation, const Vec3<acc> &translate){
        return translation_matrix(translate)*rotation_matrix(rotation*PI_180<acc>)*scale_matrix(scale);
    }

    static Mat4<acc> transform2(const Vec3<acc> &scale, const Vec3<acc> &rotation, const Vec3<acc> &translate){
        Mat4<acc> tr = rotation_matrix(rotation*PI_180<acc>)*scale_matrix(scale);
        tr.t(0) = translate.x();
        tr.t(1) = translate.y();
        tr.t(2) = translate.z();
        return tr;
    }

    static Mat4<acc> rotate(const Mat4<acc> &m, const Vec3<acc> &v, acc angle){

        angle = deg_2_rad(angle);

        // glm
        const acc a = angle;
        const acc c = cos(a);
        const acc s = sin(a);

        Vec3<acc> axis(normalize(v));
        Vec3<acc> temp((acc{1} - c) * axis);

        Mat4<acc> Rotate;
        Rotate.at(0,0) = c + temp[0] * axis[0];
        Rotate.at(0,1) = temp[0] * axis[1] + s * axis[2];
        Rotate.at(0,2) = temp[0] * axis[2] - s * axis[1];

        Rotate.at(1,0) = temp[1] * axis[0] - s * axis[2];
        Rotate.at(1,1) = c + temp[1] * axis[1];
        Rotate.at(1,2) = temp[1] * axis[2] + s * axis[0];

        Rotate.at(2,0) = temp[2] * axis[0] + s * axis[1];
        Rotate.at(2,1) = temp[2] * axis[1] - s * axis[0];
        Rotate.at(2,2) = c + temp[2] * axis[2];

        const auto row0{m.row(0)};
        const auto row1{m.row(1)};
        const auto row2{m.row(2)};
        const auto row3{m.row(3)};
        const auto r0 = row0 * Rotate.at(0,0) + row1 * Rotate.at(0,1) + row2 * Rotate.at(0,2);
        const auto r1 = row0 * Rotate.at(1,0) + row1 * Rotate.at(1,1) + row2 * Rotate.at(1,2);
        const auto r2 = row0 * Rotate.at(2,0) + row1 * Rotate.at(2,1) + row2 * Rotate.at(2,2);

        return Mat4<acc>{
            r0[0], r0[1], r0[2], r0[3],
            r1[0], r1[1], r1[2], r1[3],
            r2[0], r2[1], r2[2], r2[3],
            row3[0], row3[1], row3[2], row3[3],
        };
    }


    static Mat4<acc> axis_angle(const Vec3<acc> &axis, acc angle){
        return {Mat3<acc>::axis_angle(axis,angle)};
    }


};
}




//Mat4d Mat4d::operator*(const Mat4d& mat) const
//{
//    return Mat4d(
//        values[0] * mat.values[0] + values[4] * mat.values[1] + values[8] * mat.values[2] + values[12] * mat.values[3],
//        values[1] * mat.values[0] + values[5] * mat.values[1] + values[9] * mat.values[2] + values[13] * mat.values[3],
//        values[2] * mat.values[0] + values[6] * mat.values[1] + values[10] * mat.values[2] + values[14] * mat.values[3],
//        values[3] * mat.values[0] + values[7] * mat.values[1] + values[11] * mat.values[2] + values[15] * mat.values[3],
//        values[0] * mat.values[4] + values[4] * mat.values[5] + values[8] * mat.values[6] + values[12] * mat.values[7],
//        values[1] * mat.values[4] + values[5] * mat.values[5] + values[9] * mat.values[6] + values[13] * mat.values[7],
//        values[2] * mat.values[4] + values[6] * mat.values[5] + values[10] * mat.values[6] + values[14] * mat.values[7],
//        values[3] * mat.values[4] + values[7] * mat.values[5] + values[11] * mat.values[6] + values[15] * mat.values[7],
//        values[0] * mat.values[8] + values[4] * mat.values[9] + values[8] * mat.values[10] + values[12] * mat.values[11],
//        values[1] * mat.values[8] + values[5] * mat.values[9] + values[9] * mat.values[10] + values[13] * mat.values[11],
//        values[2] * mat.values[8] + values[6] * mat.values[9] + values[10] * mat.values[10] + values[14] * mat.values[11],
//        values[3] * mat.values[8] + values[7] * mat.values[9] + values[11] * mat.values[10] + values[15] * mat.values[11],
//        values[0] * mat.values[12] + values[4] * mat.values[13] + values[8] * mat.values[14] + values[12] * mat.values[15],
//        values[1] * mat.values[12] + values[5] * mat.values[13] + values[9] * mat.values[14] + values[13] * mat.values[15],
//        values[2] * mat.values[12] + values[6] * mat.values[13] + values[10] * mat.values[14] + values[14] * mat.values[15],
//        values[3] * mat.values[12] + values[7] * mat.values[13] + values[11] * mat.values[14] + values[15] * mat.values[15]
//        );
//}
