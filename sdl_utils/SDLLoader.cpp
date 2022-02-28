//Corresponding header
#include "SDLLoader.h"

//C system includes

//C++ system includes
#include<cstdint>
#include<iostream>

//3rd-party includes
#include<SDL.h>

//Own includes
#include "sdl_utils/SDLLoader.h"

int32_t SDLLoader::init(){
	if(EXIT_SUCCESS != SDL_Init(SDL_INIT_VIDEO))
	{
		std::cerr << "SDL_Init failed. Reason:" << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
void SDLLoader::deinit(){
	SDL_Quit();

}
