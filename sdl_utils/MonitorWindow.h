//C system includes

//C++ system includes
#include<cstdint>
#include<string>
//3rd-party includes

//Own includes
#include "utils/drawings/Rectangle.h"
#include "utils/drawings/Point.h"

//Forward Declaration

#ifndef SDL_UTILS_MONITORWINDOW_H_
#define SDL_UTILS_MONITORWINDOW_H_

struct SDL_Window;
struct SDL_Surface;	//declaring these just so we can create void pointers to a struct/class

enum WindowFlags{
	WINDOW_SHOWN = 4
};

struct MonitorWindowCfg{
	 std::string windowName;
	 Point windowPosition = Point::UNDEFINED;
	 int32_t windowWidth = 0;
	 int32_t windowHeight = 0;
	 WindowFlags windowFlags = WINDOW_SHOWN;
};

class MonitorWindow {
public:
	MonitorWindow() = default;
	 ~MonitorWindow();

	MonitorWindow(const MonitorWindow& other) = delete;
	//deleting the copy constructor cuz we cant have 2 monitor-screens of our application

	MonitorWindow(MonitorWindow&& other) = delete;
	//deleting the move constructor

	MonitorWindow& operator=(const MonitorWindow& other) = delete; //delete copy/assignment constructor
	MonitorWindow& operator=(MonitorWindow&& other) = delete;	//delete the move constructor

	int32_t init(const MonitorWindowCfg& cfg);
	void deinit();

	SDL_Surface* getWindowSurface();//remove this later on
	void updateWindowSurface();


private:
	SDL_Window* _window = nullptr;
	Rectangle _windowRect = Rectangle::UNDEFINED;
};

#endif /* SDL_UTILS_MONITORWINDOW_H_ */
