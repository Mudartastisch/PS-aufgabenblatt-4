#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"
#include "color.hpp"
#include <string>

using namespace std; 


class Circle
{
private:
    Vec2 center;
    float radius;
    Color color;
    string name;
public:
    Circle(Vec2 const& c, float i, Color const& cl, string n):center(c), radius(i), color(cl), name(n) {}
    Circle();
    
    float getRadius() const;
    string getName() const;
    void setColor(Color const & c);
    bool operator<(const Circle& crc) const;
    bool operator>(const Circle& crc) const;
    bool operator==(const Circle& crc) const;

    void debug();

    bool is_inside(Vec2 const& test);
};

#endif //CIRCLE_HPP