
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
#include "geometry/matrix2.hpp"
#include "geometry/point3.hpp"

namespace tool::geo {

template<typename acc>
struct Mat3;

using Mat3f = Mat3<float>;
using Mat3d = Mat3<double>;


// functions
template <typename acc>
constexpr acc trace(const Mat3<acc> &m) noexcept;
template <typename acc>
Mat3<acc> minor(const Mat3<acc> &m);

// operators
template <typename acc>
Vec3<acc> operator*(const Mat3<acc> &l, const Vec3<acc> &r);
template <typename acc>
Vec3<acc> operator*(const Vec3<acc> &l, const Mat3<acc> &r);


template<typename acc>
struct Mat3 : public Matrix<acc,3,3>{

    using Matrix<acc,3,3>::array;
    using Matrix<acc,3,3>::at;

    Mat3() = default;
    Mat3(const Mat3& other) = default;
    Mat3& operator=(const Mat3& other) = default;
    Mat3(Mat3&& other) = default;
    Mat3& operator=(Mat3&& other) = default;

    explicit inline Mat3(bool identity)         noexcept : Matrix<acc,3,3>(identity){}
    explicit inline Mat3(acc *values)           noexcept : Matrix<acc,3,3>(values){}
    inline Mat3(std::initializer_list<acc> l)   noexcept : Matrix<acc,3,3>(l){}

    constexpr Mat3(Matrix<acc,3,3> mat) noexcept{
        array = std::move(mat.array);
    }

    constexpr Mat3(vecN<acc, 9> array) noexcept{
        array = std::move(array);
    }

    /**
     * @param pitch: angle in degrees
     */
    static constexpr Mat3<acc> x_rotation_matrix(acc pitch) noexcept{
        pitch = deg_2_rad<acc>(pitch);
        const acc cosA = cos(pitch);
        const acc sinA = sin(pitch);
        return {
            1,  0,      0,
            0,  cosA,   sinA,
            0,  -sinA,  cosA
        };
    }

    /**
     * @param head: angle in degrees
     */
    static constexpr Mat3<acc> y_rotation_matrix(acc head) noexcept{
        head = deg_2_rad<acc>(head);
        const acc cosA = cos(head);
        const acc sinA = sin(head);
        return {
            cosA,   0,  -sinA,
            0,      1,  0,
            sinA,   0,  cosA
        };
    }

    /**
     * @param roll: angle in degrees
     */
    static constexpr Mat3<acc> z_rotation_matrix(acc roll) noexcept{
        roll = deg_2_rad<acc>(roll);
        const acc cosA = cos(roll);
        const acc sinA = sin(roll);
        return {
            cosA,   sinA,   0,
            -sinA,  cosA,   0,
            0,      0,      1
        };
    }


    template <typename acc2>
    constexpr Mat3<acc2> conv() const noexcept{
        Mat3<acc2> mc;
        for(size_t ii = 0; ii < 9; ++ii){
            mc.array[ii] = static_cast<acc2>(array[ii]);
        }
        return mc;
    }



    Mat3<acc> cofactor2() const{
        return cofactor(minor(*this));
    }


    acc determinant() const{
        // sarrus (only for m3x3)
        //        return
        //            at(0)*at(2)*at(8) +
        //            at(3)*at(7)*at(2) +
        //            at(1)*at(5)*at(6) -
        //            at(6)*at(2)*at(2) -
        //            at(3)*at(1)*at(8) -
        //            at(0)*at(7)*at(5);

        acc result{0};
        const Mat3<acc> cof = cofactor2();
        for(size_t ii = 0; ii < 3; ++ii){
            result += array[ii] * cof.at(0,ii);
        }

        return result;
    }

    inline Mat3<acc> adjugate()const {
        return cofactor2().transpose();
    }

    Mat3<acc> inverse() const{

        const acc det = determinant();
        if(almost_equal<acc>(det, acc{0})){
            return Mat3<acc>{};
        }
        // #######################################
        // return cofactor().transpose()*(acc{1}/det);
        // #######################################
        const auto &a = array;
        const acc invDet = acc{1}/det;
        Mat3<acc> r;
        r.at(0) = (a[4]*a[8]-a[5]*a[7])*invDet;
        r.at(3) = (a[5]*a[6]-a[3]*a[8])*invDet;
        r.at(6) = (a[3]*a[7]-a[4]*a[6])*invDet;
        r.at(1) = (a[2]*a[7]-a[1]*a[8])*invDet;
        r.at(4) = (a[0]*a[8]-a[2]*a[6])*invDet;
        r.at(7) = (a[1]*a[6]-a[0]*a[7])*invDet;
        r.at(2) = (a[1]*a[5]-a[2]*a[4])*invDet;
        r.at(5) = (a[2]*a[3]-a[0]*a[5])*invDet;
        r.at(8) = (a[0]*a[4]-a[1]*a[3])*invDet;
        return r;
    }



    /**
     * @return head/pitch/roll angles in degrees
     */
    constexpr Vec3<acc> to_hpr_angles() const{ // head/pitch/roll

        const auto p = std::asin(at(1,2));
        if(almost_equal<acc>(std::abs(p), PI_2<acc>)){ // grimbal lock
            return{
                0,
                d180_PI<acc>*p,
                d180_PI<acc>*(std::atan2(at(0,1),at(0,0)))
            };
        }

        return{
            d180_PI<acc>*std::atan2(-at(0,2),at(2,2)),
            d180_PI<acc>*p,
            d180_PI<acc>*std::atan2(-at(1,0),at(1,1))
        };
    }



    /**
     * equivalent to: //  return y_rotation_matrix(angles.y())*x_rotation_matrix(angles.x())*z_rotation_matrix(angles.z());
     */
    static constexpr Mat3<acc> rotation_matrix(const Pt3<acc> &angles) noexcept{

        const auto cosH = std::cos(angles.y());
        const auto cosP = std::cos(angles.x());
        const auto cosR = std::cos(angles.z());
        const auto sinH = std::sin(angles.y());
        const auto sinP = std::sin(angles.x());
        const auto sinR = std::sin(angles.z());

        return{
            cosR*cosH-sinR*sinP*sinH,   sinR*cosH+cosR*sinP*sinH,   -cosP*sinH,
            -sinR*cosP,                 cosR*cosP,                  sinP,
            cosR*sinH+sinR*sinP*cosH,   sinR*sinH-cosR*sinP*cosH,   cosP*cosH
        };
    }


    static Mat3<acc> axis_angle(const Vec3<acc> &axis, acc angle){

        angle = deg_2_rad<acc>(angle);
        auto u = normalize(axis);
        const auto cA = cos(angle);
        const auto sA = sin(angle);
        const auto ux = u.x();
        const auto uy = u.y();
        const auto uz = u.z();
        const auto ux2 = ux*ux;
        const auto uy2 = uy*uy;
        const auto uz2 = uz*uz;

        return {
            cA + ux2*(1-cA), ux*uy*(1-cA) - uz*sA, ux*uz*(1-cA) + uy*sA,
            uy*ux*(1-cA) + uz*sA,   cA+uy2*(1-cA), uy*uz*(1-cA)-ux*sA,
            uz*ux*(1-cA)-uy*sA, uz*uy*(1-cA) +ux*sA,    cA +uz2*(1-cA)
        };
    }

    Pt3<acc> multiply_point(const Pt3<acc> &pt) const{
        return Pt3<acc>{pt.x()*at(0,0) + pt.y() * at(1,0) + pt.z() * at(2,0) + at(3,0),
                        pt.x()*at(0,1) + pt.y() * at(1,1) + pt.z() * at(2,1) + at(3,1),
                        pt.x()*at(0,2) + pt.y() * at(1,2) + pt.z() * at(2,2) + at(3,2)};
    }

    Vec3<acc> multiply_vector(const Vec3<acc>& vec) const {
        return Vec3<acc>{
            dot(vec, Vec3<acc>{ at(0,0), at(1,0), at(2,0)}),
            dot(vec, Vec3<acc>{ at(0,1), at(1,1), at(2,1)}),
            dot(vec, Vec3<acc>{ at(0,2), at(1,2), at(2,2)})
        };
    }


};

template <typename acc>
constexpr acc trace(const Mat3<acc> &m) noexcept{
    return m(0) + m(4) + m(8);
}

template <typename acc>
Mat3<acc> minor(const Mat3<acc> &m) {
    Mat3<acc> res = {};
    for(int ii = 0; ii < 3; ++ii){
        for(int jj = 0; jj < 3; ++jj){
            res.at(ii,jj) =  determinant(Mat2<acc>{cut(m,ii,jj)});
        }
    }
    return res;
}

template <typename acc>
Vec3<acc> operator*(const Mat3<acc> &l, const Vec3<acc> &r){
    return Vec3<acc>{multiply(l,r)};
}

template <typename acc>
Vec3<acc> operator*(const Vec3<acc> &l, const Mat3<acc> &r){
    return Vec3<acc>{multiply(l,r)};
}


}
