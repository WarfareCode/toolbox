
// catch
#include "catch.hpp"

// glm
// #include "glm/mat4x4.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/quaternion.hpp>

// base
#include "geometry/transform.hpp"
#include "geometry/point2.hpp"

using namespace tool;

geo::Vec2f from_glm(const glm::vec2 &v){
    return geo::Vec2f{v.x, v.y};
}

geo::Vec3f from_glm(const glm::vec3 &v){
    return {v.x, v.y, v.z};
}

geo::Vec4f from_glm(const glm::vec4 &v){
    return {v.x, v.y, v.z, v.w};
}

geo::Quatf from_glm(const glm::quat &q){
    return {q.x, q.y, q.z, q.w};
}

geo::Mat3f from_glm(const glm::mat3 &m){
    return transpose(geo::Mat3f{
        m[0][0], m[1][0], m[2][0],
        m[0][1], m[1][1], m[2][1],
        m[0][2], m[1][2], m[2][2],
    });
}

geo::Mat3f clean(geo::Mat3f m){
    for(int ii = 0; ii < 9; ++ii){
        if(m.at(ii) < 0.0000001f){
            m.at(ii) = 0.f;
        }
    }
    return m;
}

geo::Mat4f from_glm(const glm::mat4 &m){
    return transpose(geo::Mat4f{
        m[0][0], m[1][0], m[2][0], m[3][0],
        m[0][1], m[1][1], m[2][1], m[3][1],
        m[0][2], m[1][2], m[2][2], m[3][2],
        m[0][3], m[1][3], m[2][3], m[3][3],
    });
}

geo::Mat4f clean(geo::Mat4f m){
    for(int ii = 0; ii < 16; ++ii){
        if(m.at(ii) < 0.0000001f){
            m.at(ii) = 0.f;
        }
    }
    return m;
}

geo::Quatf clean(geo::Quatf q){
    if(q.x < 0.0000001f){
        q.x = 0.f;
    }
    if(q.y < 0.0000001f){
        q.y = 0.f;
    }
    if(q.z < 0.0000001f){
        q.z = 0.f;
    }
    if(q.w < 0.0000001f){
        q.w = 0.f;
    }
    return q;
}

glm::mat4 glm_x_rotation(float value){
    return glm::rotate(glm::mat4(1.0f), glm::radians(value), glm::vec3(1.0, 0.0, 0.0));
}
glm::mat4 glm_y_rotation(float value){
    return glm::rotate(glm::mat4(1.0f), glm::radians(value), glm::vec3(0.0, 1.0, 0.0));
}
glm::mat4 glm_z_rotation(float value){
    return glm::rotate(glm::mat4(1.0f), glm::radians(value), glm::vec3(0.0, 0.0, 1.0));
}

glm::mat4 glm_rotate(const glm::vec3 &rotation){
    return glm_z_rotation(rotation.z)*glm_x_rotation(rotation.x)*glm_y_rotation(rotation.y);
}

geo::Mat4f transform1(const geo::Vec3f &scale, const geo::Vec3f &rotation, const geo::Vec3f &translate){
    return geo::Mat4f::scale_matrix(scale)*geo::Mat4f::rotation_matrix(rotation*PI_180<float>)*geo::Mat4f::translation_matrix(translate);
}
geo::Mat4f transform2(const geo::Vec3f &scale, const geo::Vec3f &rotation, const geo::Vec3f &translate){
    return geo::Mat4f::translation_matrix(translate)*geo::Mat4f::rotation_matrix(rotation*PI_180<float>)*geo::Mat4f::scale_matrix(scale);
}
geo::Mat4f transform3(const geo::Vec3f &scale, const geo::Vec3f &rotation, const geo::Vec3f &translate){
    auto tr = geo::Mat4f::scale_matrix(scale);
    tr      = tr * geo::Mat4f::rotation_matrix(rotation*PI_180<float>);
    tr      = tr * geo::Mat4f::translation_matrix(translate);
    return tr;
}
geo::Mat4f transform4(const geo::Vec3f &scale, const geo::Vec3f &rotation, const geo::Vec3f &translate){
    auto tr = geo::Mat4f::scale_matrix(scale);
    tr *= geo::Mat4f::rotation_matrix(rotation*PI_180<float>);
    tr *= geo::Mat4f::translation_matrix(translate);
    return tr;
}
geo::Mat4f transform5(const geo::Vec3f &scale, const geo::Vec3f &rotation, const geo::Vec3f &translate){
    return geo::Mat4f::scale_matrix(scale)*(geo::Mat4f::rotation_matrix(rotation*PI_180<float>)*geo::Mat4f::translation_matrix(translate));
}

geo::Mat4f transform6(const geo::Vec3f &scale, const geo::Vec3f &rotation, const geo::Vec3f &translate){
    auto tr = geo::Mat4f::scale_matrix(scale);
    tr      = geo::Mat4f::rotation_matrix(rotation*PI_180<float>)*tr;
    tr      = geo::Mat4f::translation_matrix(translate)*tr;
    return tr;
}

template <typename acc, int _rowsL, int _colsL, int _rowsR, int _colsR>
geo::Matrix<acc,_rowsL, _colsR> multiply2(const geo::Matrix<acc,_rowsL,_colsL> &l, const geo::Matrix<acc,_rowsR,_colsR> &r){
    geo::Matrix<acc,_rowsL, _colsR> res;
    for(int ii = 0; ii < l.rows(); ++ii){
        for(int jj = 0; jj < r.cols(); ++jj){
            for(int kk = 0; kk < r.rows(); ++kk){
                res(r.cols() * ii +jj) += l(l.cols() * ii + kk) * r(r.cols() * kk + jj);
            }
        }
    }
    return res;
}
template <typename acc, int _rowsL, int _colsL, int _rowsR, int _colsR>
geo::Matrix<acc,_rowsL, _colsR> multiply3(const geo::Matrix<acc,_rowsL,_colsL> &r, const geo::Matrix<acc,_rowsR,_colsR> &l){
    geo::Matrix<acc,_rowsL, _colsR> res;
    for(int ii = 0; ii < l.rows(); ++ii){
        for(int jj = 0; jj < r.cols(); ++jj){
            for(int kk = 0; kk < r.rows(); ++kk){
                res(r.cols() * ii +jj) += l(l.cols() * ii + kk) * r(r.cols() * kk + jj);
            }
        }
    }
    return res;
}

TEST_CASE("glm mat4x4 comparison with geometry::Mat4"){

    auto dm1 = geo::Mat3f{
        7.f,2,1,
        0,3,-1,
        -3,4,-2
    };
    auto glmdm1 = glm::mat3(
        glm::vec3(7,2,1),
        glm::vec3(0,3,-1),
        glm::vec3(-3,4,-2)
    );
    SECTION("Matrix 3x3"){


        REQUIRE(geo::equals(dm1,from_glm(glmdm1)));
        REQUIRE(dm1.determinant() == glm::determinant(glmdm1));
    }
    return;

    SECTION("Look at"){
        auto lightView1 = from_glm(glm::lookAt(
            glm::vec3(-2.0f, 4.0f, -1.0f),
            glm::vec3( 0.0f, 0.0f,  0.0f),
            glm::vec3( 0.0f, 1.0f,  0.0f)
        ));

        auto lightView2 = geo::Mat4f::LookAt(
            geo::Pt3f{-2.0f, 4.0f, -1.0f},
            geo::Vec3f{0.0f, 0.0f,  0.0f},
            geo::Vec3f{0.0f, 1.0f,  0.0f}
        );

        REQUIRE(geo::equals(clean(lightView1),clean(lightView2)));
    }


    glm::mat4 trans1 = glm::mat4(1.0f);
    auto trans2 = geo::Mat4f::identity();
    auto trans3 = geo::Mat4f::identity();
    auto trans4 = geo::Mat4f::identity();


    geo::Mat4f r1,r2;

    SECTION("Transform combination 1"){
        trans1 = glm::scale(glm::mat4(1.0f), glm::vec3(0.5, 0.5, 0.5));
        trans2 = geo::Mat4f::scale(geo::Mat4f::identity(), {0.5f, 0.5f, 0.5f});
        REQUIRE(clean(from_glm(trans1)) == clean(trans2));

        // rotation 1
        trans1 = glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0, 0.0, 0.0));
        trans2 = geo::Mat4f::rotate(geo::Mat4f::identity(), {1.f,0.f,0.f}, 90.f);
        REQUIRE(clean(from_glm(trans1)) == clean(trans2));

        trans1 = glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(0.0, 1.0, 0.0));
        trans2 = geo::Mat4f::rotate(geo::Mat4f::identity(), {0.f,1.f,0.f}, 90.f);
        REQUIRE(clean(from_glm(trans1)) == clean(trans2));

        trans1 = glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(0.0, 0.0, 1.0));
        trans2 = geo::Mat4f::rotate(geo::Mat4f::identity(), {0.f,0.f,1.f}, 90.f);
        REQUIRE(clean(from_glm(trans1)) == clean(trans2));

        // rotation 2
        trans1 = glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0, 0.0, 0.0));
        trans2 = geo::Mat4f::rotate(geo::Mat4f::identity(), {90.f,0.f,0.f});
        REQUIRE(clean(from_glm(trans1)) == clean(trans2));

        trans1 = glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(0.0, 1.0, 0.0));
        trans2 = geo::Mat4f::rotate(geo::Mat4f::identity(), {0.f,90.f,0.f});
        REQUIRE(clean(from_glm(trans1)) == clean(trans2));

        trans1 = glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(0.0, 0.0, 1.0));
        trans2 = geo::Mat4f::rotate(geo::Mat4f::identity(), {0.f,0.f,90.f});
        REQUIRE(clean(from_glm(trans1)) == clean(trans2));

        // rotation 3
        trans1 = glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0, 0.0, 0.0));
        trans2 = geo::Mat4f::identity()*geo::Mat4f::rotation_matrix({90.f*tool::PI_180<float>,0.f,0.f});
        REQUIRE(clean(from_glm(trans1)) == clean(trans2));

        trans1 = glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(0.0, 1.0, 0.0));
        trans2 = geo::Mat4f::identity()*geo::Mat4f::rotation_matrix({0.f,90.f*tool::PI_180<float>,0.f});
        REQUIRE(clean(from_glm(trans1)) == clean(trans2));

        trans1 = glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(0.0, 0.0, 1.0));
        trans2 = geo::Mat4f::identity()*geo::Mat4f::rotation_matrix({0.f,0.f,90.f*tool::PI_180<float>});
        REQUIRE(clean(from_glm(trans1)) == clean(trans2));

        // combination 1
        trans1 = glm::scale(glm::mat4(1.0f), glm::vec3(0.5, 0.5, 0.5));
        trans1 = glm::rotate(trans1, glm::radians(90.0f), glm::vec3(1.0, 0.0, 0.0));
        trans2 = geo::Mat4f::scale(geo::Mat4f::identity(), {0.5f, 0.5f, 0.5f});
        trans2 = geo::Mat4f::rotate(trans2, {1.f,0.f,0.f}, 90.f);
        REQUIRE(clean(from_glm(trans1)) == clean(trans2));
    }

    SECTION("Transformation comparison"){

        // rotation matrices
        trans1 = glm_x_rotation(87.f);
        trans2 = geo::Mat3f::x_rotation_matrix(87.f);
        REQUIRE(clean(from_glm(trans1)) == clean(trans2));

        trans1 = glm_y_rotation(87.f);
        trans2 = geo::Mat3f::y_rotation_matrix(87.f);
        REQUIRE(clean(from_glm(trans1)) == clean(trans2));

        trans1 = glm_z_rotation(87.f);
        trans2 = geo::Mat3f::z_rotation_matrix(87.f);
        REQUIRE(clean(from_glm(trans1)) == clean(trans2));

        trans1 = glm_rotate(glm::vec3(10.0, 20., -30.));
        trans2 = geo::Mat4f::rotate(geo::Mat4f::identity(), {10.0, 20., -30.});
        REQUIRE(clean(from_glm(trans1)) == clean(trans2));

        // scale matrix
        trans1 = glm::scale(glm::mat4(1.0f), glm::vec3(0.5, 0.5, 0.5));
        trans2 = geo::Mat4f::scale(geo::Mat4f::identity(), {0.5f, 0.5f, 0.5f});
        trans3 = geo::Mat4f::scale_matrix({0.5f, 0.5f, 0.5f});

        REQUIRE(clean(from_glm(trans1)) == clean(trans2));
        REQUIRE(clean(trans2) == clean(trans3));

        // translate matrix
        trans1 = glm::translate(glm::mat4(1.0f), glm::vec3(-1.0, 17.0, 56.0));
        trans2 = geo::Mat4f::translate(geo::Mat4f::identity(), {-1.f, 17.f, 56.f});
        trans3 = geo::Mat4f::translation_matrix({-1.f, 17.f, 56.f});

        REQUIRE(clean(from_glm(trans1)) == clean(trans2));
        REQUIRE(clean(trans2) == clean(trans3));


        trans1 = glm::scale(glm::mat4(1.0f), glm::vec3(0.5, 0.5, 0.5));
        trans1 = glm::rotate(trans1, glm::radians(-47.0f), glm::vec3(1.0, 0.0, 0.0));
        trans1 = glm::translate(trans1, glm::vec3(-1.0, 17.0, 56.0));

        trans2 = geo::Mat4f::scale(geo::Mat4f::identity(), {0.5f, 0.5f, 0.5f});
        trans2 = geo::Mat4f::rotate(trans2, {-47.f,0.f,0.f});
        trans2 = geo::Mat4f::translate(trans2, {-1.0, 17.0, 56.0});

        trans3 = geo::Mat4f::scale_matrix({0.5f, 0.5f, 0.5f});
        trans3 = geo::Mat4f::rotation_matrix(geo::Vec3f{-47.f,0.f,0.f}*tool::PI_180<float>)*trans3;
        trans3 = geo::Mat4f::translation_matrix({-1.0, 17.0, 56.0})* trans3;

        REQUIRE(clean(from_glm(trans1)) == clean(trans2));
        REQUIRE(clean(trans2) == clean(trans3));

        trans4 = geo::Mat4f::transform({0.5f, 0.5f, 0.5f}, {-47.f,0.f,0.f}, {-1.0, 17.0, 56.0});
        CHECK(clean(trans3) == clean(trans4));
    }

    glm::mat4 mul1 = glm::mat4(
        glm::vec4(5,7,9,10),
        glm::vec4(2,3,3,8),
        glm::vec4(8,10,2,3),
        glm::vec4(3,3,4,8)
    );
    glm::mat4 mul2 = glm::mat4(
        glm::vec4(3,10,12,18),
        glm::vec4(12,1,4,9),
        glm::vec4(9,10,12,2),
        glm::vec4(3,12,4,10)
    );
    auto mul3 = geo::Mat4f{
        5.f,7,9,10,2,3,3,8,8,10,2,3,3,3,4,8
    };
    auto mul4 = geo::Mat4f{
        3.f,10,12,18,12,1,4,9,9,10,12,2,3,12,4,10
    };
    auto res = geo::Mat4f{
        210,267,236,271,
        93,149,104,149,
        171,146,172,268,
        105,169,128,169
    };

    SECTION("Matrices multiplication"){
        REQUIRE(clean(from_glm(mul1)) == clean(mul3));
        REQUIRE(clean(from_glm(mul2)) == clean(mul4));

        auto r11 = mul1 * mul2;
        auto r12 = mul2 * mul1;

        auto r21 = mul3 * mul4;
        auto r22 = mul4 * mul3;

        REQUIRE(clean(from_glm(r11)) == clean(r22));
        REQUIRE(clean(from_glm(r12)) == clean(r21));
        REQUIRE(clean(res) == clean(r21));
    }



    SECTION("Point2"){
        constexpr glm::vec2 pt1(1,2);
        constexpr glm::vec2 pt2(4,5);
        constexpr geo::Pt2f pt3{1,2};
        constexpr geo::Pt2f pt4{4,5};
        constexpr auto dotR = geo::dot(pt3,pt4);
        constexpr auto inv  = invert(pt3);
        constexpr auto sqn  = geo::square_norm(pt3);

        const glm::vec2 v(0);
        auto v2 = glm::normalize(v);
        // getters
        REQUIRE(pt2.x == pt4.x());
        REQUIRE(pt2.y == pt4.y());
        // operators
        REQUIRE(from_glm(pt1) == pt3);
        REQUIRE(from_glm(pt2) == pt4);
        REQUIRE(from_glm(-pt2) == -pt4);
        REQUIRE(from_glm(pt1+pt2) == (pt3+pt4));
        REQUIRE(from_glm(pt1-pt2) == (pt3-pt4));
        REQUIRE(from_glm(pt1*pt2) == (pt3*pt4));
        REQUIRE(from_glm(pt1/pt2) == (pt3/pt4));
        REQUIRE(from_glm(pt1+pt2) == (add(pt3,pt4)));
        REQUIRE(from_glm(pt1-pt2) == (substract(pt3,pt4)));
        REQUIRE(from_glm(pt1*pt2) == (multiply(pt3,pt4)));
        REQUIRE(from_glm(pt1/pt2) == (divide(pt3,pt4)));
        // functions
        REQUIRE(glm::dot(pt1,pt2) == geo::dot(pt3,pt4));
        REQUIRE(from_glm(-pt1) == invert(pt3));
        REQUIRE(tool::almost_equal(glm::length(pt1)*glm::length(pt1),sqn));
        REQUIRE(from_glm(glm::normalize(pt1)) == geo::normalize(pt3));
        REQUIRE(from_glm(glm::normalize(glm::vec2(4,5))) == normalize(geo::Pt2f{4,5}));
    }

    SECTION("Point3"){        
        constexpr glm::vec3 pt1(1,2,3);
        constexpr glm::vec3 pt2(4,5,6);
        constexpr geo::Pt3f pt3{1,2,3};
        constexpr geo::Pt3f pt4{4,5,6};
        constexpr auto dotR = geo::dot(pt3,pt4);
        constexpr auto inv  = invert(pt3);
        constexpr auto sqn  = geo::square_norm(pt3);

        const glm::vec3 v(0);
        auto v2 = glm::normalize(v);
        // getters
        REQUIRE(pt2.x == pt4.x());
        REQUIRE(pt2.y == pt4.y());
        REQUIRE(pt2.z == pt4.z());
        // operators
        REQUIRE(from_glm(pt1) == pt3);
        REQUIRE(from_glm(pt2) == pt4);
        REQUIRE(from_glm(-pt2) == -pt4);
        REQUIRE(from_glm(pt1+pt2) == (pt3+pt4));
        REQUIRE(from_glm(pt1-pt2) == (pt3-pt4));
        REQUIRE(from_glm(pt1*pt2) == (pt3*pt4));
        REQUIRE(from_glm(pt1/pt2) == (pt3/pt4));
        REQUIRE(from_glm(pt1+pt2) == (add(pt3,pt4)));
        REQUIRE(from_glm(pt1-pt2) == (substract(pt3,pt4)));
        REQUIRE(from_glm(pt1*pt2) == (multiply(pt3,pt4)));
        REQUIRE(from_glm(pt1/pt2) == (divide(pt3,pt4)));
        // functions
        REQUIRE(glm::dot(pt1,pt2) == geo::dot(pt3,pt4));
        REQUIRE(from_glm(glm::cross(pt1,pt2)) == geo::cross(pt3,pt4));
        REQUIRE(from_glm(-pt1) == invert(pt3));
        REQUIRE(tool::almost_equal(glm::length(pt1)*glm::length(pt1),sqn));
        REQUIRE(from_glm(glm::normalize(pt1)) == geo::normalize(pt3));
        REQUIRE(from_glm(glm::normalize(glm::vec3(4,5,6))) == normalize(geo::Pt3f{4,5,6}));
    }

    SECTION("Point4"){
        constexpr glm::vec4 pt1(1,2,3,4);
        constexpr glm::vec4 pt2(5,6,7,8);
        constexpr geo::Pt4f pt3{1,2,3,4};
        constexpr geo::Pt4f pt4{5,6,7,8};
        constexpr auto dotR = geo::dot(pt3,pt4);
        constexpr auto inv  = invert(pt3);
        constexpr auto sqn  = geo::square_norm(pt3);

        const glm::vec3 v(0);
        auto v2 = glm::normalize(v);
        // getters
        REQUIRE(pt2.x == pt4.x());
        REQUIRE(pt2.y == pt4.y());
        REQUIRE(pt2.z == pt4.z());
        REQUIRE(pt2.w == pt4.w());
        // operators
        REQUIRE(from_glm(pt1) == pt3);
        REQUIRE(from_glm(pt2) == pt4);
        REQUIRE(from_glm(-pt2) == -pt4);
        REQUIRE(from_glm(pt1+pt2) == (pt3+pt4));
        REQUIRE(from_glm(pt1-pt2) == (pt3-pt4));
        REQUIRE(from_glm(pt1*pt2) == (pt3*pt4));
        REQUIRE(from_glm(pt1/pt2) == (pt3/pt4));
        REQUIRE(from_glm(pt1+pt2) == (add(pt3,pt4)));
        REQUIRE(from_glm(pt1-pt2) == (substract(pt3,pt4)));
        REQUIRE(from_glm(pt1*pt2) == (multiply(pt3,pt4)));
        REQUIRE(from_glm(pt1/pt2) == (divide(pt3,pt4)));
        // functions
        REQUIRE(glm::dot(pt1,pt2) == geo::dot(pt3,pt4));
        REQUIRE(from_glm(-pt1) == invert(pt3));
        REQUIRE(tool::almost_equal(glm::length(pt1)*glm::length(pt1),sqn));
        REQUIRE(from_glm(glm::normalize(pt1)) == geo::normalize(pt3));
        REQUIRE(from_glm(glm::normalize(glm::vec4(5,6,7,8))) == normalize(geo::Pt4f{5,6,7,8}));
    }


    auto gq1 = glm::angleAxis(glm::radians(67.f),  glm::vec3(1.f, 0.f, 0.f));
    auto gq2 = glm::angleAxis(glm::radians(135.f), glm::vec3(0.f, 1.f, 0.f));
    auto gq3 = glm::angleAxis(glm::radians(-54.f), glm::vec3(0.f, 0.f, 1.f));
    auto gq4 = glm::angleAxis(glm::radians(58.f),  glm::normalize(glm::vec3(1.f,0.6f,-0.5f)));

    auto q1 = geo::Quatf::from_axis({1.f,0,0}, 67.f);
    auto q2 = geo::Quatf::from_axis({0.f,1,0}, 135.f);
    auto q3 = geo::Quatf::from_axis({0.f,0,1}, -54.f);
    auto q4 = geo::Quatf::from_axis(normalize(geo::Vec3f{1.f,0.6f,-0.5f}), 58.f);

    auto e1 = euler_angles(q1);
    auto e2 = euler_angles(q2);
    auto e3 = euler_angles(q3);
    auto e4 = euler_angles(q4);

    SECTION("Quaternion"){

        REQUIRE(from_glm(gq1) == q1);
        REQUIRE(from_glm(gq2) == q2);
        REQUIRE(from_glm(gq3) == q3);

        REQUIRE(angle(q1) == glm::angle(gq1));
        REQUIRE(angle(q2) == glm::angle(gq2));
        REQUIRE(angle(q3) == glm::angle(gq3));

        REQUIRE(axis(q1) == from_glm(glm::axis(gq1)));
        REQUIRE(axis(q2) == from_glm(glm::axis(gq2)));
        REQUIRE(axis(q3) == from_glm(glm::axis(gq3)));

        REQUIRE(norm(q1) == glm::length(gq1));
        REQUIRE(norm(q2) == glm::length(gq2));
        REQUIRE(norm(q3) == glm::length(gq3));

        REQUIRE((q1 + q2) == from_glm(gq1 + gq2));
        REQUIRE((q1 - q2) == from_glm(gq1 - gq2));
        REQUIRE((q1 * q2) == from_glm(gq1 * gq2));
        REQUIRE((q1 * 5.f) == from_glm(gq1 * 5.f));
        REQUIRE((q1 / 5.f) == from_glm(gq1 / 5.f));

        REQUIRE(normalize(q1) == from_glm(glm::normalize(gq1)));
        REQUIRE(normalize(q2) == from_glm(glm::normalize(gq2)));
        REQUIRE(normalize(q3) == from_glm(glm::normalize(gq3)));

        REQUIRE(inverse(q1) == from_glm(glm::inverse(gq1)));
        REQUIRE(inverse(q2) == from_glm(glm::inverse(gq2)));
        REQUIRE(inverse(q3) == from_glm(glm::inverse(gq3)));

        REQUIRE(dot(q1,q2) == glm::dot(gq1, gq2));
        REQUIRE(dot(q2,q1) == glm::dot(gq2, gq1));
        REQUIRE(dot(q3,q2) == glm::dot(gq3, gq2));

        REQUIRE(conjugate(q1) == from_glm(glm::conjugate(gq1)));
        REQUIRE(conjugate(q2) == from_glm(glm::conjugate(gq2)));
        REQUIRE(conjugate(q3) == from_glm(glm::conjugate(gq3)));

        REQUIRE(slerp(q1,q2, 0.4f) == from_glm(glm::slerp(gq1, gq2, 0.4f)));
        REQUIRE(slerp(q1,q3, 0.19f) == from_glm(glm::slerp(gq1, gq3, 0.19f)));
        REQUIRE(slerp(q2,q3, 0.89f) == from_glm(glm::slerp(gq2, gq3, 0.89f)));

        REQUIRE(pitch(q1) == (glm::pitch(gq1)));
        REQUIRE(pitch(q2) == (glm::pitch(gq2)));
        REQUIRE(pitch(q3) == (glm::pitch(gq3)));
        REQUIRE(pitch(q4) == (glm::pitch(gq4)));

        REQUIRE(yaw(q1) == (glm::yaw(gq1)));
        REQUIRE(yaw(q2) == (glm::yaw(gq2)));
        REQUIRE(yaw(q3) == (glm::yaw(gq3)));
        REQUIRE(yaw(q4) == (glm::yaw(gq4)));

        REQUIRE(roll(q1) == (glm::roll(gq1)));
        REQUIRE(roll(q2) == (glm::roll(gq2)));
        REQUIRE(roll(q3) == (glm::roll(gq3)));
        REQUIRE(roll(q4) == (glm::roll(gq4)));

        REQUIRE(euler_angles(q1) == from_glm(glm::eulerAngles(gq1)));
        REQUIRE(euler_angles(q2) == from_glm(glm::eulerAngles(gq2)));
        REQUIRE(euler_angles(q3) == from_glm(glm::eulerAngles(gq3)));
        REQUIRE(euler_angles(q4) == from_glm(glm::eulerAngles(gq4)));

//        CHECK(clean(geo::Quatf::from_euler({rad_2_deg(e1.x()),rad_2_deg(e1.y()),rad_2_deg(e1.z())})) == q1);
//        CHECK(clean(geo::Quatf::from_euler({rad_2_deg(e2.x()),rad_2_deg(e2.y()),rad_2_deg(e2.z())})) == q2);
//        CHECK(clean(geo::Quatf::from_euler({rad_2_deg(e3.x()),rad_2_deg(e3.y()),rad_2_deg(e3.z())})) == q3);
//        CHECK(clean(geo::Quatf::from_euler({rad_2_deg(e4.x()),rad_2_deg(e4.y()),rad_2_deg(e4.z())})) == q4);

        REQUIRE(to_mat4(q1) == from_glm(glm::toMat4(gq1)));
        REQUIRE(to_mat4(q2) == from_glm(glm::toMat4(gq2)));
        REQUIRE(to_mat4(q3) == from_glm(glm::toMat4(gq3)));
        REQUIRE(to_mat4(q4) == from_glm(glm::toMat4(gq4)));

        REQUIRE(to_quaternion(to_mat4(q1)) == from_glm(gq1));
        REQUIRE(to_quaternion(to_mat4(q2)) == from_glm(gq2));
        REQUIRE(to_quaternion(to_mat4(q3)) == from_glm(gq3));
        REQUIRE(to_quaternion(to_mat4(q4)) == from_glm(gq4));
    }
}




//int main(int argc, char *argv[]){

//    auto rot = tool::geo::Mat3f::rotation_matrix({
//        tool::deg_2_rad(50.f),
//        tool::deg_2_rad(89.f),
//        tool::deg_2_rad(-30.f)
//    });
//    auto invRot = rot.inverse();

//    auto rot2 = tool::geo::Mat4f::rotation_matrix({
//        tool::deg_2_rad(50.f),
//        tool::deg_2_rad(89.f),
//        tool::deg_2_rad(-30.f)
//    });
//    auto invRot2 = rot2.inverse();


//    std::cout << rot2 << "\n";
//    std::cout << invRot2 << "\n";
//    std::cout << rot2*invRot2 << "\n";
//    std::cout << invRot2*rot2 << "\n";
//    std::cout << tool::geo::Mat3f::y_rotation_matrix(50.f)*
//                     tool::geo::Mat3f::x_rotation_matrix(89.f)*
//                     tool::geo::Mat3f::z_rotation_matrix(-30.f) << "\n";

//    std::cout << "rot " << (rot.to_hpr_angles().x()) << "\n";
//    std::cout << "rot " << (rot.to_hpr_angles().y()) << "\n";
//    std::cout << "rot " << (rot.to_hpr_angles().z()) << "\n";




//    std::cout << "scale:\n" << tool::geo::Mat4<float>::scale(tool::geo::Mat4<float>::identity(), {2.f,2.f,2.f}) << "\n";
//    std::cout << "scale:\n" << tool::geo::Mat4<float>::scale_matrix({2.f,2.f,2.f}) << "\n";

//    static_cast<void>(argc);
//    static_cast<void>(argv);

//    BaseSfmlGlWindow scene("Render", 1600,1200);
//    scene.init();
//    scene.start();

//    return 0;
//}







//std_v1<Test> tests;
//for(int ii = 0; ii < 10; ++ii){
//    tests.emplace_back(Test{ii});
//}


//int *f = &tests[0].a;
//for(int ii = 0; ii < 10; ++ii){
//    std::cout << f[ii] << "\n";
//}

//return 0;


//for(const auto & v : tool::graphics::textureTypes){
//    std::cout << std::get<1>(v) << '\n';
//}

////    constexpr TupleMap2<3, int, float, double> m ={
////        {1, 0, 5},
////        {2, 0, 0},
////    };

//std::cout << "ok\n";

//return 0;
//io::AiLoader::load_model("E:/DATA/Meshes/crysis-nano-suit-2/scene.fbx");
//std::cout << "nok\n";

//return 0;



//auto m3x = Mat3d::x_rotation_matrix(90.);
//auto m3y = Mat3d::y_rotation_matrix(90.);
//auto m3z = Mat3d::z_rotation_matrix(90.);

//auto m4x = Mat4d::x_rotation_matrix(90.);
//auto m4y = Mat4d::y_rotation_matrix(90.);
//auto m4z = Mat4d::z_rotation_matrix(90.);

//auto m4xb = Mat4d{m3x};
//auto m4yb = Mat4d{m3y};
//auto m4zb = Mat4d{m3z};

////    std::cout << m4x << m4y << m4z << "\n";
////    std::cout << m4xb << m4yb << m4zb << "\n";

//auto m3 = Mat3d::rotation_matrix({10.,20.,30.});
//auto m4 = Mat4d::rotation_matrix({10.,20.,30.});
////    std::cout << m3 << "\n";
////    std::cout << m4 << "\n";
//auto m3A1 = Mat3d::axis_angle({1.,0.,0.}, 20.);
//auto m3A2 = Mat3d::axis_angle({0.,1.,0.}, 30.);
//auto m3A3 = Mat3d::axis_angle({0.,0.,1.}, 40.);
//auto m3A4 = Mat3d::axis_angle({1.,0.,1.}, 50.);

//std::cout << "m3A1 euler: " << m3A1.to_euler() << "\n";
//std::cout << "m3A2 euler: " << m3A2.to_euler() << "\n";
//std::cout << "m3A3 euler: " << m3A3.to_euler() << "\n";
//std::cout << "m3A4 euler: " << m3A4.to_euler() << "\n";

//std::cout << "m3x euler: " << m3x.to_euler() << "\n";
//std::cout << "m3y euler: " << m3y.to_euler() << "\n";
//std::cout << "m3z euler: " << m3z.to_euler() << "\n";

////    std::cout << "m4x euler: " << m4x.to_euler() << "\n";
////    std::cout << "m4y euler: " << m4y.to_euler() << "\n";
////    std::cout << "m4z euler: " << m4z.to_euler() << "\n";

////    std::cout << "m4xb euler: " << m4xb.to_euler() << "\n";
////    std::cout << "m4yb euler: " << m4yb.to_euler() << "\n";
////    std::cout << "m4zb euler: " << m4zb.to_euler() << "\n";

////    std::cout << "m3 euler: " << m3.to_euler() << "\n";
////    std::cout << "m4 euler: " << m4.to_euler() << "\n";

//return 0;

//Quaternion<double> q0;
//Quaternion<double> q1{0,0,0,1};
//Quaternion<double> q2{{1,0,0},50};
//Quaternion<double> q3{{0,1,0},90};

//std::cout << Mat3d::z_rotation_matrix(90.) << "\n";
//std::cout << Mat4d::z_rotation_matrix(90.) << "\n";


//auto rx = Mat4d::x_rotation_matrix(90.);
//auto ry = Mat4d::y_rotation_matrix(90.);
//auto rz = Mat4d::z_rotation_matrix(90.);
//std::cout << "to euler: \n";
////    std::cout << (rx.to_euler()) << "\n";
////    std::cout << (ry.to_euler()) << "\n";
////    std::cout << (rz.to_euler()) << "\n";

////    rx = Mat4d::axis_angle({1,0,0}, 90.);
////    ry = Mat4d::axis_angle({0,1,0}, 90.);
////    rz = Mat4d::axis_angle({0,0,1}, 90.);
//std::cout << "to euler: \n";
////    std::cout << (rx.to_euler()) << "\n";
////    std::cout << (ry.to_euler()) << "\n";
////    std::cout << (rz.to_euler()) << "\n";

//std::cout << "Check rotation: " << Vec3d{170,-45,37} << "\n";
//auto rM = Mat4d::rotation_matrix({170,-45,37});
////    std::cout << rM << rM.rotation() << rM.to_euler()<< "\n";
//std::cout << rM.r(0) << " " << rM.r(1) << " " << rM.r(2) << " " << rM.r(3) << " " << rM.r(4) << " "
//          << rM.r(5) << " " << rM.r(6) << " " << rM.r(7) << " " << rM.r(8) << "\n\n";
//std::cout << "Check scaling: " << Vec3d{2,3,4} << "\n";
//auto sM = Mat4d::scale_matrix({2,3,4});
//std::cout << sM << sM.s(0) << " " << sM.s(1) << " " << sM.s(2) << "\n\n";

//std::cout << "Check translation: " << Vec3d{10,20,30} << "\n";
//auto tM = Mat4d::translation_matrix({10,20,30});
//std::cout << tM;
//std::cout << tM.translation() << "\n";
//std::cout << tM.t(0) << " " << tM.t(1) << " " << tM.t(2) << "\n\n";

//return 0;
////    std::cout << math::rad_2_deg(r1.to_euler().x()) << "\n";
////    std::cout << math::rad_2_deg(r1.to_euler().y()) << "\n";
////    std::cout << math::rad_2_deg(r1.to_euler().z()) << "\n\n";

//{
//    auto [axis, angle] = q2.to_angle_and_axis();
//    std::cout << "-> " << axis << " " << rad_2_deg(angle) << "\n";
//}
//{
//    auto [axis, angle] = q3.to_angle_and_axis();
//    std::cout << "-> " << axis << " " << rad_2_deg(angle) << "\n";
//}

//auto proj = Mat4d::projection(60.,1.,0.5,1000.);
//auto q4 = to_quaternion(proj);

//const auto m1 = to_matrix(q2);
//std::cout << m1 << "\n";
//auto q5 = to_quaternion(m1);
//std::cout << to_matrix(q5) << "\n";

//std::cout << q5 << "\n";
//std::cout << Quatd::inverse(q5) << "\n";
//std::cout << Quatd::inverse(Quatd::inverse(q5)) << "\n";

//Vec3<float> rUp        = {0.,1.,0.};
//Vec3<float> rDirection = {1.,0.,0.};
//auto right = geo::normalized(geo::cross(rUp, rDirection));
//std::cout << "R: " << right << "\n";

//Vec3d eulerA{90.,15,47};
//std::cout << eulerA << "\n";
//Quatd q6(eulerA);
//std::cout << q6 << "\n";
////    std::cout << "-> " << to_matrix(q6).to_euler() << "\n";
//std::cout << rad_2_deg(q6.to_euler_angles().x()) << "\n";
//std::cout << rad_2_deg(q6.to_euler_angles().y()) << "\n";
//std::cout << rad_2_deg(q6.to_euler_angles().z()) << "\n";

////    std::cout << (q2*q3).convert_to_matrix() << "\n";


//graphics::Screen screen;
//graphics::Camera camera(&screen);

//Pt3<size_t> a;
//Pt3<size_t> b;

//a += b;
//a += 5;


//graphics::Material mat;



////    read_ply_file("G:/DEV/Clouds/grass_house_01.ply", true);
////    do_tests();

//return 0;
