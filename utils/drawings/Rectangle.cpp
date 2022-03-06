//Corresponding header
#include "Rectangle.h"

//C system includes

//C++ system includes
#include<cstdint>

//3rd-party includes

//Own includes

//Forward Declaration

Rectangle::Rectangle(int32_t inputX, int32_t inputY, int32_t inputHeight, int32_t inputWidth)
										: x(inputX), y(inputY), h(inputHeight), w(inputWidth){
}

const Rectangle ZERO(0,0,0,0);
const Rectangle UNDEFINED(10000,10000,10000,10000);
