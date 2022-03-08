#ifndef SDL_UTILS_TEXTURE_H_
#define SDL_UTILS_TEXTURE_H_

//C system includes

//C++ system includes
#include<cstdint>
#include<string>

//3rd-party includes

//Own includes

//Forward Declaration
struct SDL_Surface;


class Texture {
public:
	Texture() = delete;
	 ~Texture();

	 static int32_t createSurfaceFromFile(const std::string& filePath,
			 	 	 	 	 	 	 	 SDL_Surface*& outSurface);	//returning int32_t as an error message.
	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	//Otherwise it would return SLD_Surface*
	 static void freeSurface(SDL_Surface*& outSurface);
};

#endif /* SDL_UTILS_TEXTURE_H_ */
