
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
#include "geometry/matrix.hpp"

namespace tool::geo {

template<typename acc>
struct Mat2 : public Matrix<acc,2,2>{

    using Matrix<acc,2,2>::array;

    Mat2() = default;
    Mat2(const Mat2& other) = default;
    Mat2& operator=(const Mat2& other) = default;
    Mat2(Mat2&& other) = default;
    Mat2& operator=(Mat2&& other) = default;

    explicit inline Mat2(bool identity)         noexcept : Matrix<acc,2,2>(identity){}
    explicit inline Mat2(acc *values)           noexcept : Matrix<acc,2,2>(values){}
    inline Mat2(std::initializer_list<acc> l)   noexcept : Matrix<acc,2,2>(l){}

    constexpr Mat2(Matrix<acc,2,2> mat) noexcept{
        array = std::move(mat.array);
    }

    constexpr Mat2(vecN<acc, 4> array) noexcept{
        array = std::move(array);
    }

    template <typename acc2>
    constexpr Mat2<acc2> conv() const noexcept{
        Mat2<acc2> mc;
        for(size_t ii = 0; ii < 4; ++ii){
            mc.array[ii] = static_cast<acc2>(array[ii]);
        }
        return mc;
    }

//    // any
    inline Mat2<acc> cofactor(const Mat2<acc> &minor) const{return cofactor(minor);}
};

// functions
template <typename acc>
constexpr Mat2<acc> minor(const Mat2<acc> &m) noexcept{
    return Mat2<acc>{m.at(1,1), m.at(1,0), m.at(0,1), m.at(0,0)};
}

template <typename acc>
constexpr acc determinant(const Mat2<acc> &m) noexcept{
    return m.at(0,0)*m.at(1,1)-m.at(0,1)*m.at(1,0);
}

template <typename acc>
Mat2<acc> inverse(const Mat2<acc> &m) noexcept{

    const acc det = determinant(m);
    if(almost_equal<acc>(det, acc{0})){
        return Mat2<acc>{};
    }

    // return adjugate()*(acc{1}/det);
    const acc invDet = acc{1}/ det;
    Mat2<acc> result{};
    const auto &a = m.array;
    result[0] =  a[3] * invDet;
    result[1] = -a[1] * invDet;
    result[2] = -a[2] * invDet;
    result[3] =  a[0] * invDet;
    return result;
}

}
