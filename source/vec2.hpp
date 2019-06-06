#ifndef VEC2_HPP
#define VEC2_HPP

// Vec2 data type definition

struct Vec2
{
    float x;
    float y;
    Vec2(float i = 0, float j = 0):x(i), y(j) {}
};

    Vec2 operator+( Vec2 const& u , Vec2 const& v );
    Vec2 operator-( Vec2 const& u , Vec2 const& v );
    Vec2 operator*( Vec2 const& v , float s );
    Vec2 operator*( float s , Vec2 const& v );
    Vec2 operator/( Vec2 const& v , float s );   

# endif // VEC2_HPP