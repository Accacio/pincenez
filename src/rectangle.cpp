#include "rectangle.hpp"

Rectangle::Rectangle(Point loc, Point size){
    _x = loc._x;
    _y = loc._y;
    _width = size._x;
    _height = size._y;
}
Rectangle::Rectangle(int x,int y,int w,int h){
    _x = x;
    _y = y;
    _width = w;
    _height = h;
}
Rectangle::~Rectangle(){

}

// TODO verificar
bool Rectangle::contains(Rectangle rec){
  return rec.left()>=left() && rec.right()<right() && rec.top() >= top() && rec.bottom()<=bottom();
};

// TODO verificar
bool Rectangle::contains(Vec2 vec){
  return vec._x>=left() && vec._x<right() && vec._y >= top() && vec._y<=bottom();
};

// TODO verificar
bool Rectangle::contains(Point poin){
  return poin._x>=left() && poin._x<right() && poin._y >= top() && poin._y<=bottom();
};

bool Rectangle::contains(int x, int y){
  return x>=left() && x<right() && y >= top() && y<=bottom();
};

bool Rectangle::contains(float x, float y){
  return x>=left() && x<right() && y >= top() && y<=bottom();
};

// AABB
bool Rectangle::intersects(Rectangle rec){
    return left() < rec.right() && right() > rec.left() && bottom() > rec.top() && top() < rec.bottom();
};

// TODO verificar
Rectangle Rectangle::intersect(Rectangle rec1,Rectangle rec2){
    if(rec1.intersects(rec2)){
        int x = std::max(rec1.left(),rec2.left());
        int y = std::max(rec1.top(),rec2.top());
        int width = std::min(rec1.right(),rec2.right())-x;
        int height = std::min(rec1.bottom(),rec2.bottom())-y;
        return Rectangle(x,y,width,height);
    } else {
        return Rectangle::Empty();
    }
};

// TODO verificar
Rectangle Rectangle::unite(Rectangle rec1,Rectangle rec2){
    int x = std::min(rec1.left(),rec2.left());
    int y = std::min(rec1.top(),rec2.top());
    int width = std::max(rec1.right(),rec2.right())-x;
    int height = std::max(rec1.bottom(),rec2.bottom())-y;
    return Rectangle(x,y,width,height);
};


bool Rectangle::operator==(Rectangle rec){
    return this->_x==rec._x && this->_y==rec._y && this->_width == rec._width && this->_height == rec._height;
}

bool Rectangle::operator!=(Rectangle rec){
    return !(this->_x==rec._x && this->_y==rec._y && this->_width == rec._width && this->_height == rec._height);
}
