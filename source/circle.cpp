#include "circle.hpp"
#include "vec2.hpp"
#include "color.hpp"
#include <cmath>

#include <iostream>

Circle::Circle(){
    center = Vec2(0.0f, 0.0f);
    radius = 0.0f;
}
float Circle::getRadius() const{
    return radius;
}

void Circle::debug(){
    std::cout<< "Center: " << center.x << " " << center.y << "\n";
    std::cout<< "Radius: " << radius << "\n";
}

bool Circle::operator<(const Circle& crc) const 
{
   return radius < crc.radius;
}

bool Circle::operator>(const Circle& crc) const 
{
   return radius > crc.radius;
}

bool Circle::operator==(const Circle& crc) const 
{
   return radius == crc.radius;
}