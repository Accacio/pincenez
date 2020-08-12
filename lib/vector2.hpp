#ifndef __VECTOR2_H_
#define __VECTOR2_H_

#include <iostream>
#include <cmath>

class Vector2 {
    public:
        Vector2(float x, float y);
        Vector2(float xy);
        virtual ~Vector2();

        static Vector2 Unit();
        static Vector2 UnitX();
        static Vector2 UnitY();
        static Vector2 Zero();

        static float distance(Vector2 vec1,Vector2 vec2){return std::sqrt((vec1._x-vec2._x)*(vec1._x-vec2._x) +(vec1._y-vec2._y)*(vec1._y-vec2._y));};
        // operators
        Vector2 operator-(){return Vector2(-_x,-_y);};
        Vector2 operator-(Vector2 vec){return Vector2(_x-vec._x,_y-vec._y);};
        Vector2 operator+(Vector2 vec){return Vector2(_x+vec._x,_y+vec._y);};
        Vector2 operator*(float f){return Vector2(f*_x,f*_y);};
        Vector2 operator/(float f){return Vector2(_x/f,_y/f);};
        bool operator==(Vector2 vec);
        bool operator!=(Vector2 vec);
        float dot(Vector2 vec){return _x*vec._x+_y*vec._y;};
        float cross(Vector2 vec){return _x*vec._y-_y*vec._x;};
        float length(){return std::sqrt(_x*_x+_y*_y);};
        Vector2 normalize(){return *this/length();};

        float _x;
        float _y;
        friend std::ostream& operator<<(std::ostream& os, const Vector2& vec);
    private:
};

#endif // __VECTOR2_H_
