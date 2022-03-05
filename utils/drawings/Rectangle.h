#ifndef UTILS_DRAWINGS_RECTANGLE_H_
#define UTILS_DRAWINGS_RECTANGLE_H_

//C system includes

//C++ system includes
#include<cstdint>

//3rd-party includes

//Own includes

//Forward Declaration


struct Rectangle {
	Rectangle() = default;
	Rectangle(int32_t inputX, int32_t inputY,
				int32_t inputHeight, int32_t inputWidth);

	int32_t x = 0;
	int32_t y = 0;
	int32_t w = 0;
	int32_t h = 0;

};


extern const Rectangle ZERO;
extern const Rectangle UNDEFINED;


#endif /* UTILS_DRAWINGS_RECTANGLE_H_ */
