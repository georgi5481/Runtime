//C system includes

//C++ system includes
#include<cstdint>
#include<string>
//3rd-party includes

//Own includes
#include "utils/drawings/Rectangle.h"

//Forward Declaration

#ifndef SDL_UTILS_MONITORWINDOW_H_
#define SDL_UTILS_MONITORWINDOW_H_

struct SDL_Window;

struct MonitorWindowCfg{
	 std::string windowName;
	 int32_t windowX;
	 int32_t windowY;
	 int32_t windowWidth;
	 int32_t windowHeight;
	 uint32_t windowFlags;
};

class MonitorWindow {
public:
	MonitorWindow();
	virtual ~MonitorWindow();

	MonitorWindow(const MonitorWindow& other) = delete;
	//deleting the copy constructor cuz we cant have 2 monitor-screens of our application

	MonitorWindow(MonitorWindow&& other) = delete;
	//deleting the move constructor

	MonitorWindow& operator=(const MonitorWindow& other) = delete; //delete copy/assignment constructor
	MonitorWindow& operator=(MonitorWindow&& other) = delete;	//delete the move constructor

	int32_t init(const MonitorWindowCfg& cfg);
	void deinit();

private:
	SDL_Window* _window = nullptr;
	Rectangle _windowRect;
};

#endif /* SDL_UTILS_MONITORWINDOW_H_ */
