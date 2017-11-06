#include<string>
#include<iostream>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
using namespace std;

int main(int argc, char* argv[]) {

	const int height = 700;
	const int width = 700;
	int w = 0;
	int h = 0;
	SDL_Window *window = NULL;
  SDL_Init(SDL_INIT_VIDEO);
	SDL_Renderer* renderer = NULL;
	SDL_Texture *button = NULL;
	//SDL_Surface *surface = IMG_Load("test.png");



	if(SDL_Init(SDL_INIT_VIDEO)<0){
		std::cout << "Error de inicializacion de video :(" << SDL_GetError<<'\n';
		return 1;
	}
	else{
		window = SDL_CreateWindow(
	      "Master Mind",                  // window title
	      100,           // initial x position
	      100,           // initial y position
	      width,                               // width, in pixels
	      height,                               // height, in pixels
	      0                  // flags - see below
	  );
		if(window == NULL){
	      // In the case that the window could not be made...
	      cout << "No se pudo crear la ventana" << SDL_GetError();
	  }
		else{
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

      // Select the color for drawing. It is set to red here.
      SDL_SetRenderDrawColor(renderer, 100, 30, 200, 0);
      // Clear the entire screen to our selected color.
			button = IMG_LoadTexture(renderer,"button.png");
			SDL_QueryTexture(button, NULL, NULL, &w, &h);
			SDL_Rect rectButton; rectButton.x=width/2; rectButton.y=height/2; rectButton.w=w/2; rectButton.h=h/2;

	//		SDL_Point center;
	//		center.x=0;center.y=0;


				while(1){
					SDL_Event e;
					if ( SDL_PollEvent(&e) ) {
						if (e.type == SDL_QUIT)
							break;
						else if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_ESCAPE)
							break;
					}

					SDL_RenderClear(renderer);
					SDL_RenderCopy(renderer,button, NULL, &rectButton);
					// Up until now everything was drawn behind the scenes.
					// This will show the new, red contents of the window.
					SDL_RenderPresent(renderer);
					//SDL_UpdateWindowSurface(window);
				//	SDL_Delay(3000);
				}
		}
	}

  // Close and destroy the window
	SDL_DestroyTexture(button);
	SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);

  // Clean up
  //SDL_Quit();
  return 0;
}
