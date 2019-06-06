#include "circle.hpp"
#include "vec2.hpp"
#include "color.hpp"
#include <cmath>

#include <iostream>

Circle::Circle(){
    center = Vec2(0.0f, 0.0f);
    radius = 0.0f;
    color = Color();
    name = "default";
}
float Circle::getRadius() const{
    return radius;
}

string Circle::getName() const{
    return name;
}

void Circle::setColor(Color const& c){
    this->color = c;
}

void Circle::debug(){
    std::cout<< "Name: " << name << "\n"; 
    std::cout<< "Center: " << center.x << " " << center.y << "\n";
    std::cout<< "Radius: " << radius << "\n";
    std::cout<< "Color: " << color.r << " " << color.g << " " << color.b << "\n";    
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