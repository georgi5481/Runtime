//Corresponding header
#include "SDLLoader.h"

//C system includes

//C++ system includes
#include<cstdint>
#include<iostream>

//3rd-party includes
#include<SDL.h>
#include<SDL_ttf.h>
#include<SDL_image.h>

//Own includes
#include "sdl_utils/SDLLoader.h"

int32_t SDLLoader::init(){
	if(EXIT_SUCCESS != TTF_Init())
	{
		std::cerr << "SDL_Init failed. Reason:" << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	if(EXIT_SUCCESS != SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO))
	{
		std::cerr << "SDL_Init failed. Reason:" << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	constexpr int32_t imgFlags = IMG_INIT_PNG;
	if(! (IMG_Init(imgFlags) & imgFlags)){
		std::cerr << "SDL image coul not be initialised! SDL_miage Error:" <<
				IMG_GetError() << std::endl;
		return EXIT_FAILURE;
	}


	return EXIT_SUCCESS;
}
void SDLLoader::deinit(){

	TTF_Quit;
	SDL_Quit();

}
