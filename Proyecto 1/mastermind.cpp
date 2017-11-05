#include<string>
#include<iostream>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <stdio.h>
#include<SDL/SDL.h>
using namespace std;

int main(int argc, char* argv[]) {

	const int height = 700;
	const int width = 700;

	SDL_Window *window = NULL;                    // Declare a pointer
  SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2
	SDL_Renderer* renderer;

	if(SDL_Init(SDL_INIT_VIDEO)<0){
		std::cout << "Error de inicializacion de video :(" << SDL_GetError<<'\n';
	}
	else{
		window = SDL_CreateWindow(
	      "Master Mind",                  // window title
	      SDL_WINDOWPOS_UNDEFINED,           // initial x position
	      SDL_WINDOWPOS_UNDEFINED,           // initial y position
	      width,                               // width, in pixels
	      height,                               // height, in pixels
	      SDL_WINDOW_OPENGL                  // flags - see below
	  );
		if(window == NULL){
	      // In the case that the window could not be made...
	      cout << "No se pudo crear la ventana" << SDL_GetError();
	  }
		else{
			renderer = SDL_CreateRenderer(window, -1, 0);

      // Select the color for drawing. It is set to red here.
      SDL_SetRenderDrawColor(renderer, 100, 30, 200, 0);
      // Clear the entire screen to our selected color.
      SDL_RenderClear(renderer);
      // Up until now everything was drawn behind the scenes.
      // This will show the new, red contents of the window.
      SDL_RenderPresent(renderer);
			SDL_UpdateWindowSurface(window);
			SDL_Delay(3000);
		}
	}
  // Close and destroy the window
  SDL_DestroyWindow(window);

  // Clean up
  SDL_Quit();
  return 0;
}
