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

static void draw()
{
	SDL_BlitSurface(globalImage, nullptr, globalScreenSurface, nullptr);
}

static int32_t loadResources(){
	const std::string filePath = "./resources/hello.bmp";	//get the path to the file we need

	globalImage = SDL_LoadBMP(filePath.c_str()); //load the file with the path

	if(globalImage == nullptr){	//check if loading the file went well
		std::cerr << "SDL_LoadBMP failed. Reason: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

static int32_t init(){
	if(EXIT_SUCCESS != SDL_Init(SDL_INIT_VIDEO)){
		std::cerr << "SDL_Init failed. Reason: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	//using SDL_WINDOW_SHOWN as flag
	const std::string windowName = "Hello, World!";
	const int32_t windowX = 0;
	const int32_t windowY = 0;
	const int32_t windowWidth = 640;
	const int32_t windowHeight = 480;
	gWindow = SDL_CreateWindow(windowName.c_str(), windowX,
					windowY, windowWidth, windowHeight,SDL_WINDOW_SHOWN);

	if(nullptr==gWindow){	//check if gWindow was correctly instanced
		std::cerr << "SDL_Init failed. Reason: " << SDL_GetError() << std::endl;
	}

	globalScreenSurface = SDL_GetWindowSurface(gWindow);	//make the window
	if(nullptr == globalScreenSurface){		//check if the window was correctly instanced
		std::cerr << "SDL_GetWindowSurface() failed. Reason: " << SDL_GetError() << std::endl;
	}

	if (EXIT_SUCCESS != loadResources()){	//load the resources in the window
			std::cerr << "loadResources() failed. Reason: " << SDL_GetError() << std::endl;
			return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}


static void deinit(){	//deinit
	//SDL_FreeSurface()
	if(gWindow != nullptr){	//shouldn't destroy a nullpointer
		SDL_DestroyWindow(gWindow);
		gWindow = nullptr;
	}

	SDL_Quit();
}

int32_t main ([[maybe_unused]]int32_t argc, [[maybe_unused]]char* argv[])
{
	if(EXIT_SUCCESS != init()){
		std::cerr << "init() failed" << std::endl;
		return EXIT_FAILURE;
	}


	deinit();

	return EXIT_SUCCESS;
}
