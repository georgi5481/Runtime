#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <string>
//0rd-party includes

#include <SDL.h>
//#include <SDL2/SDL.h>

SDL_Window* gWindow = nullptr;
SDL_Surface* globalScreenSurface = nullptr;
SDL_Surface* globalImage = nullptr;


static int32_t init(){
	if(EXIT_SUCCESS != SDL_Init(SDL_INIT_VIDEO)){
		std::cerr << "SDL_Init failed. Reason: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;


//SDL_WINDOW_SHOWN
const std::string windowName = "Hello, World!";
const int32_t windowX = 0;
const int32_t windowY = 0;
const int32_t windowWidth = 640;
const int32_t windowHeight = 480;

gWindow = SDL_CreateWindow(windowName.c_str(), windowX,
		windowY, windowWidth, windowHeight,SDL_WINDOW_SHOWN);
//title, x, y, width, height, flag

}

int32_t main ([[maybe_unused]]int32_t argc, [[maybe_unused]]char* argv[])
{
	if(EXIT_SUCCESS != init()){
		std::cerr << "init() failed " << std::endl;
		return EXIT_SUCCESS;
	}



	return EXIT_SUCCESS;
}
