#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <string>
//3rd-party includes

#include <SDL.h>
#include "sdl_utils/MonitorWindow.h"
#include "sdl_utils/SDLLoader.h"

static void draw(MonitorWindow& window,	SDL_Surface* image)
{
	SDL_Surface* screenSurface = window.getWindowSurface();
	SDL_BlitSurface(image, nullptr, screenSurface, nullptr);
	window.updateWindowSurface();

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



static int32_t init(MonitorWindow& window,	SDL_Surface*& outImage ){

	MonitorWindowCfg cfg;

	//using SDL_WINDOW_SHOWN as flag
	cfg.windowName = "SDL_Runtime";
	cfg.windowWidth = 640;
	cfg.windowHeight = 480;
	cfg.windowFlags = WINDOW_FULLSCREEN;


	if (EXIT_SUCCESS != window.init(cfg)){	//load the resources in the window
			std::cerr << "loadResources() failed. Reason: " << SDL_GetError() << std::endl;
			return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != loadResources(outImage)){	//load the resources in the window
			std::cerr << "loadResources() failed. Reason: " << SDL_GetError() << std::endl;
			return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}


static void deinit(MonitorWindow& window, SDL_Surface*& outImage){	//deinit
	SDL_FreeSurface(outImage);
	outImage = nullptr;

	window.deinit();
}



static int32_t runAplication(){
	MonitorWindow window;
	SDL_Surface* image = nullptr;

	if(EXIT_SUCCESS != init(window, image)){
			std::cerr << "init() failed" << std::endl;
			return EXIT_FAILURE;
		}

		draw(window, image);

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
