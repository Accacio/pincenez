#include "math/vec2.hpp"

Vec2::Vec2(float x, float y){
    _x=x; _y=y;

}
Vec2::Vec2(float xy){
    _x=xy; _y=xy;
}

Vec2::~Vec2(){
}

Vec2 Vec2::Zero(){
    return Vec2(0.0f,0.0f);
}
Vec2 Vec2::Unit(){
    return Vec2(1.0f,1.0f);
}
Vec2 Vec2::UnitX(){
    return Vec2(1.0f,0.0f);
}
Vec2 Vec2::UnitY(){
    return Vec2(0.0f,1.0f);
}


bool Vec2::operator==(Vec2 vec){

    return _x==vec._x && _y==vec._y;
};
bool Vec2::operator!=(Vec2 vec){
    return !(_x==vec._x && _y==vec._y);
};

std::ostream& operator<<(std::ostream& os, const Vec2& vec){
    os << "(" << vec._x << ',' << vec._y <<")" ;
    return os;
}
