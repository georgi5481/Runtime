#include "MonitorWindow.h"

//Corresponding header
#include "MonitorWindow.h"

//C system includes

//C++ system includes
#include<cstdint>
#include<iostream>

//3rd-party includes
#include<SDL_video.h>

//Own includes

//Forward Declaration

int32_t MonitorWindow::init(const MonitorWindowCfg& cfg){

	_window = SDL_CreateWindow(cfg.windowName.c_str(), cfg.windowPosition.x,
					cfg.windowPosition.y , cfg.windowWidth , cfg.windowHeight , cfg.windowFlags);

	if(nullptr==_window){	//check if gWindow was correctly instanced
		std::cerr << "SDL_Init failed. Reason: " << SDL_GetError() << std::endl;
	}



	return EXIT_SUCCESS;
}


MonitorWindow::~MonitorWindow(){
	deinit();
}

void MonitorWindow::deinit(){
	if(_window != nullptr){	//shouldn't destroy a nullpointer
			SDL_DestroyWindow(_window);
			_window = nullptr;
		}
}

void MonitorWindow::updateWindowSurface(){
	if(EXIT_SUCCESS != SDL_UpdateWindowSurface(_window)){
		std::cerr << "SDL_UpdateWindowSurface failed. Reason: " << SDL_GetError() << std::endl;
	}

}

SDL_Surface* MonitorWindow::getWindowSurface(){
	SDL_Surface* screenSurface = SDL_GetWindowSurface(_window);	//make the window
		if(nullptr == screenSurface){		//check if the window was correctly instanced
			std::cerr << "SDL_GetWindowSurface() failed. Reason: " << SDL_GetError() << std::endl;
			return nullptr;
		}
		return screenSurface;
}
