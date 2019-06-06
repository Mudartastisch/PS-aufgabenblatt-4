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
public:
    Circle(Vec2 const& c, float i):center(c), radius(i){}
    Circle();
    
    float getRadius() const;
    string getName() const;
    bool operator<(const Circle& crc) const;
    bool operator>(const Circle& crc) const;
    bool operator==(const Circle& crc) const;

    void debug();
};

#endif //CIRCLE_HPP