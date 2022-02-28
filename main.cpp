#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <string>
//3rd-party includes

#include <SDL.h>
//#include <SDL2/SDL.h>

#include "sdl_utils/SDLLoader.h"

static void draw(SDL_Window* window, SDL_Surface* screenSurface,
		SDL_Surface* image)
{
	SDL_BlitSurface(image, nullptr, screenSurface, nullptr);
	if(EXIT_SUCCESS != SDL_UpdateWindowSurface(window)){
		std::cerr << "SDL_UpdateWindowSurface failed. Reason: " << SDL_GetError() << std::endl;
	}

	SDL_Delay(5000);
}



static int32_t loadResources(SDL_Surface*& outImage){
	const std::string filePath = "../resources/hello.bmp";	//get the path to the file we need

	outImage = SDL_LoadBMP(filePath.c_str()); //load the file with the path

	if(outImage == nullptr){	//check if loading the file went well
		std::cerr << "SDL_LoadBMP failed. Reason: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}



static int32_t init(SDL_Window*& outWindow, SDL_Surface*& outScreenSurface,
		SDL_Surface*& outImage ){

	if(EXIT_SUCCESS != SDL_Init(SDL_INIT_VIDEO)){
		std::cerr << "SDL_Init failed. Reason: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	//using SDL_WINDOW_SHOWN as flag
	const std::string windowName = "Hello, World!";
	const int32_t windowX = SDL_WINDOWPOS_UNDEFINED;
	const int32_t windowY = SDL_WINDOWPOS_UNDEFINED;
	const int32_t windowWidth = 640;
	const int32_t windowHeight = 480;
	outWindow = SDL_CreateWindow(windowName.c_str(), windowX,
					windowY, windowWidth, windowHeight, SDL_WINDOW_SHOWN);

	if(nullptr==outWindow){	//check if gWindow was correctly instanced
		std::cerr << "SDL_Init failed. Reason: " << SDL_GetError() << std::endl;
	}

	outScreenSurface = SDL_GetWindowSurface(outWindow);	//make the window
	if(nullptr == outScreenSurface){		//check if the window was correctly instanced
		std::cerr << "SDL_GetWindowSurface() failed. Reason: " << SDL_GetError() << std::endl;
	}

	if (EXIT_SUCCESS != loadResources(outImage)){	//load the resources in the window
			std::cerr << "loadResources() failed. Reason: " << SDL_GetError() << std::endl;
			return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}


static void deinit(SDL_Window*& outWindow, SDL_Surface*& outImage){	//deinit
	SDL_FreeSurface(outImage);
	outImage = nullptr;

	if(outWindow != nullptr){	//shouldn't destroy a nullpointer
		SDL_DestroyWindow(outWindow);
		outWindow = nullptr;
	}


}



static int32_t runAplication(){
	SDL_Window* window = nullptr;
	SDL_Surface* screenSurface = nullptr;
	SDL_Surface* image = nullptr;

	if(EXIT_SUCCESS != init(window, screenSurface, image)){
			std::cerr << "init() failed" << std::endl;
			return EXIT_FAILURE;
		}

		draw(window, screenSurface, image);

		deinit(window, image);

		return EXIT_SUCCESS;

}



int32_t main ([[maybe_unused]]int32_t argc, [[maybe_unused]]char* argv[])
{

	if(EXIT_SUCCESS != SDLLoader::init())
	{
		std::cerr << "init() failed. " << std::endl;
		return EXIT_FAILURE;
	}

	if(EXIT_SUCCESS != runAplication())
	{
		std::cerr << "runAplication failed. " << std::endl;
		return EXIT_FAILURE;
	}


	SDL_Quit();

	return EXIT_SUCCESS;
}
