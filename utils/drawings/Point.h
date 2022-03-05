#ifndef UTILS_DRAWINGS_POINT_H_
#define UTILS_DRAWINGS_POINT_H_

//C system includes

//C++ system includes
#include<cstdint>

//3rd-party includes

//Own includes

//Forward Declaration

struct Point {
	Point() = default;
	Point(int32_t inputX, int32_t inputY);

	int32_t x = 0;
	int32_t y = 0;


};


extern const Point ZERO;
extern const Point UNDEFINED;

#endif /* UTILS_DRAWINGS_POINT_H_ */
