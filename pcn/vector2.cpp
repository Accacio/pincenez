#include "vector2.hpp"

Vector2::Vector2(float x, float y){
    _x=x; _y=y;

}
Vector2::Vector2(float xy){
    _x=xy; _y=xy;
}

Vector2::~Vector2(){
}

Vector2 Vector2::Zero(){
    return Vector2(0.0f,0.0f);
}
Vector2 Vector2::Unit(){
    return Vector2(1.0f,1.0f);
}
Vector2 Vector2::UnitX(){
    return Vector2(1.0f,0.0f);
}
Vector2 Vector2::UnitY(){
    return Vector2(0.0f,1.0f);
}


bool Vector2::operator==(Vector2 vec){

    return _x==vec._x && _y==vec._y;
};
bool Vector2::operator!=(Vector2 vec){
    return !(_x==vec._x && _y==vec._y);
};

std::ostream& operator<<(std::ostream& os, const Vector2& vec){
    os << "(" << vec._x << ',' << vec._y <<")" ;
    return os;
}
