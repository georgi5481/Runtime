//Corresponding header
#include "Point.h"

//C system includes

//C++ system includes
#include<cstdint>

//3rd-party includes

//Own includes

//Forward Declaration

const Point ZERO(0,0);
const Point UNDEFINED(10000,10000);

Point::Point(int32_t inputX, int32_t inputY) : x(inputX), y(inputY){
}