#ifndef __POINT_H_
#define __POINT_H_

#include <iostream>
#include <cmath>

#include "vector2.hpp"

class Point {
    public:
        Point(int x, int y);
        virtual ~Point();

        static Point Zero();

        Point operator-(){return Point(-_x,-_y);};
        Point operator-(Point poin){return Point(_x-poin._x,_y-poin._y);};
        Point operator+(Point poin){return Point(_x+poin._x,_y+poin._y);};
        Point operator*(float f){return Point(f*_x,f*_y);};
        Point operator/(float f){return Point(_x/f,_y/f);};
        bool operator==(Point poin);
        bool operator!=(Point poin);
        float length(){return std::sqrt(_x*_x+_y*_y);};
        Point normalize(){return *this/length();};

        int _x;
        int _y;
        friend std::ostream& operator<<(std::ostream& os, const Point& poin);
    private:
};


#endif // __POINT_H_
