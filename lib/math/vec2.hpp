#ifndef __VECTOR2_H_
#define __VECTOR2_H_

#include <iostream>
#include <cmath>

class Vec2 {
    public:
        Vec2(float x, float y);
        Vec2(float xy);
        virtual ~Vec2();

        static Vec2 Unit();
        static Vec2 UnitX();
        static Vec2 UnitY();
        static Vec2 Zero();

        static float distance(Vec2 vec1,Vec2 vec2){return std::sqrt((vec1._x-vec2._x)*(vec1._x-vec2._x) +(vec1._y-vec2._y)*(vec1._y-vec2._y));};
        // operators
        Vec2 operator-(){return Vec2(-_x,-_y);};
        Vec2 operator-(Vec2 vec){return Vec2(_x-vec._x,_y-vec._y);};
        Vec2 operator+(Vec2 vec){return Vec2(_x+vec._x,_y+vec._y);};
        Vec2 operator*(float f){return Vec2(f*_x,f*_y);};
        Vec2 operator/(float f){return Vec2(_x/f,_y/f);};
        bool operator==(Vec2 vec);
        bool operator!=(Vec2 vec);
        float dot(Vec2 vec){return _x*vec._x+_y*vec._y;};
        float cross(Vec2 vec){return _x*vec._y-_y*vec._x;};
        float length(){return std::sqrt(_x*_x+_y*_y);};
        Vec2 normalize(){return *this/length();};

        float _x;
        float _y;
        friend std::ostream& operator<<(std::ostream& os, const Vec2& vec);
    private:
};

#endif // __VECTOR2_H_
