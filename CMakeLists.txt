cmake_minimum_required(VERSION 3.5.1)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake_helpers/helpers.cmake)

set(CMAKE_MODULE_PATH 
	${CMAKE_MODULE_PATH} ${CMAKE_MODULE_PATH}/cmake_helpers/find_modules)

project(hello_world LANGUAGES CXX)	#first instance the project and the language

find_package(SDL2 REQUIRED)	#then find the packeges
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)


set(_BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(${PROJECT_NAME} ${_BASE_DIR}/main.cpp)

set_target_cpp_standard( ${PROJECT_NAME} 17)
enable_target_warnings(${PROJECT_NAME})

target_include_directories(
${PROJECT_NAME} 
	PRIVATE 
		${_BASE_DIR}
		${SDL2_INCLUDE_DIR}
		${SDL2_IMAGE_INCLUDE_DIR}
		${SDL2_TTF_INCLUDE_DIR}
		${SDL2_MIXER_INCLUDE_DIR}
)
target_link_libraries(
${PROJECT_NAME} 
	PRIVATE 
		${SDL2_LIBRARY}
		${SDL2_IMAGE_LIBRARY}
		${SDL2_TTF_LIBRARY}
		${SDL2_MIXER_LIBRARY}
)
