#include "point.hpp"

Point::Point(int x, int y){
    _x=x;
    _y=y;
}
Point::~Point(){}


Point Point::Zero(){
    return Point(0.0f,0.0f);
}

std::ostream& operator<<(std::ostream& os, const Point& poin){
    os << "(" << poin._x << ',' << poin._y <<")" ;
    return os;
}
