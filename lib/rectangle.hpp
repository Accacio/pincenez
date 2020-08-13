#ifndef __RECTANGLE_H_
#define __RECTANGLE_H_

#include <iostream>
#include <cmath>

#include "math/vec2.hpp"
#include "math/point.hpp"

class Rectangle {
    public:
        Rectangle(Point loc, Point size);
        Rectangle(int x,int y, int w, int h);
        virtual ~Rectangle();

        static Rectangle Empty(){
            return Rectangle(0,0,0,0);
        }

        bool contains(Rectangle rec);
        bool contains(Vec2 vec);
        bool contains(Point poin);
        bool contains(int x, int y);
        bool contains(float x, float y);
        bool intersects(Rectangle rec);
        bool isEmpty(){return _x==0 && _y==0 && _width==0 && _height==0;};

        static Rectangle intersect(Rectangle rec1,Rectangle rec2);
        static Rectangle unite(Rectangle rec1,Rectangle rec2);

        Point center(){return Point((_x+_width)/2,(_y+_width)/2);}
        Point location(){return Point(_x,_y);}
        Point size(){return Point(_width,_width);}

        int top(){return _y;}
        int bottom(){return _y+_height;}
        int left(){return _x;}
        int right(){return _x+_width;}

        bool operator==(Rectangle rec);
        bool operator!=(Rectangle rec);


        int _x, _y;
        int _width, _height;
    private:
};

#endif // __RECTANGLE_H_
