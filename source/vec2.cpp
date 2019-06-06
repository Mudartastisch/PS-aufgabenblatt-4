#include <iostream>
#include "vec2.hpp"

Vec2 operator+(Vec2 const& u, Vec2 const& v)
{
    Vec2 temp{u.x + v.x, u.y + v.y};
    return temp;
};

Vec2 operator-(Vec2 const &u, Vec2 const &v)
{
    Vec2 temp{u.x - v.x, u.y - v.y};
    return temp;
};

Vec2 operator*(Vec2 const &v, float s)
{
    Vec2 temp{v.x * s, v.y * s};
    return temp;
};

Vec2 operator*(float s, Vec2 const &v)
{
    Vec2 temp{v.x * s, v.y * s};
    return temp;
};

Vec2 operator/(Vec2 const &v, float s)
{
    if (s == 0)
    {
        std::cerr << "You can't devide by ZERO!";
        Vec2 err_vec{0.0, 0.0};
        return err_vec;
    };
    Vec2 temp{v.x / s, v.y / s};
    return temp;
};