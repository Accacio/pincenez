#include "color.hpp"

Color::Color(int r, int b, int g, int a){
    _r=r;
    _b=b;
    _g=g;
    _a=a;
}
Color Color::White(){
    return Color(0xFF,0xFF,0xFF);
}
