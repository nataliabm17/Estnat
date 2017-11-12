#include<string>
#include<iostream>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<vector>
#include <ctime>
using namespace std;


int main(int argc, char* argv[]) {
	const int height = 700;
	const int width = 700;
	int w = 0;
	int h = 0;
	SDL_Window *window = NULL;
 // SDL_Init(SDL_INIT_VIDEO);
	SDL_Renderer* renderer = NULL;
	SDL_Texture *rosado = NULL;
	SDL_Texture *morado = NULL;
	SDL_Texture *celeste = NULL;
	SDL_Texture *verde = NULL;
	SDL_Texture *rosado2 = NULL;
	SDL_Texture *morado2 = NULL;
	SDL_Texture *celeste2 = NULL;
	SDL_Texture *verde2 = NULL;

	if(SDL_Init(SDL_INIT_VIDEO)<0){
		std::cout << "Error de inicializacion de video :(" << SDL_GetError<<'\n';
		return 1;
	}
	else{
		window = SDL_CreateWindow(
	      "Master Mind",             	     // window title
	      100,      									     // initial x position
	      100,     									 	    // initial y position
	      width,             	           // width, in pixels
	      height,           	           // height, in pixels
	      0                						  // flags - see below
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

			verde = IMG_LoadTexture(renderer,"verde.png");
			SDL_QueryTexture(verde, NULL, NULL, &w, &h);
			SDL_Rect rectVerde; rectVerde.x=width/1.8; rectVerde.y=height/1.3; rectVerde.w=w/4; rectVerde.h=h/4;

			rosado = IMG_LoadTexture(renderer,"rosado.png");
			SDL_QueryTexture(rosado, NULL, NULL, &w, &h);
			SDL_Rect rectRosado; rectRosado.x=width/9; rectRosado.y=height/1.3; rectRosado.w=rectVerde.w; rectRosado.h=rectVerde.h;

			morado = IMG_LoadTexture(renderer,"morado.png");
			SDL_QueryTexture(morado, NULL, NULL, &w, &h);
			SDL_Rect rectMorado; rectMorado.x=width/3; rectMorado.y=height/1.3; rectMorado.w=rectVerde.w; rectMorado.h=rectVerde.h;

			celeste = IMG_LoadTexture(renderer,"celeste.png");
			SDL_QueryTexture(celeste, NULL, NULL, &w, &h);
			SDL_Rect rectCeleste; rectCeleste.x=width/1.28; rectCeleste.y=height/1.3; rectCeleste.w=rectVerde.w; rectCeleste.h=rectVerde.h;

			SDL_RenderClear(renderer);
			SDL_RenderCopy(renderer,rosado, NULL, &rectRosado);
			SDL_RenderCopy(renderer,verde, NULL, &rectVerde);
			SDL_RenderCopy(renderer,celeste, NULL, &rectCeleste);
			SDL_RenderCopy(renderer,morado, NULL, &rectMorado);
			SDL_RenderPresent(renderer);

			int contador = 1;
			int contador2 = 1;
			vector<int> code(4);
			vector<int> secretCode(4);
			bool flag=true;
			srand(time(NULL));
			for(int i=0;i<4;i++){
				secretCode[i]=rand()% 4 + 1;
				std::cout << "secretCode i "<<secretCode[i] << '\n';
			}

			while(1){
					SDL_Event e;
					 if( SDL_PollEvent(&e) ){
						if (e.type == SDL_QUIT){
							break;
						}
						else if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_ESCAPE){
							break;
						}
						else if(e.type==SDL_MOUSEBUTTONDOWN){
							if(e.button.button==SDL_BUTTON_LEFT){
								if(e.button.x<2*(width/9)&&e.button.x>(width/9)){
									if((height/1.3)<e.button.y&&e.button.y<(height/1.3+rectVerde.h)){
										SDL_Texture *rosado2 = NULL;
										rosado2 = IMG_LoadTexture(renderer,"rosado.png");
										SDL_QueryTexture(rosado2, NULL, NULL, &w, &h);
										SDL_Rect rectRosado2;
										rectRosado2.x=((contador2*rectVerde.h+(contador2-1)*rectVerde.h));
										rectRosado2.y=(contador-1)/4*70+30;
										rectRosado2.w=rectVerde.w;
										rectRosado2.h=rectVerde.h;
										SDL_RenderCopy(renderer,rosado2, NULL, &rectRosado2);
										SDL_RenderPresent(renderer);
										code[contador2-1]=1;
										contador++;
										contador2++;
										if(contador2==5){
											contador2=1;
										}
									}
							}

							if(e.button.x<4*(width/9)&&e.button.x>3*(width/9)){
								if((height/1.3)<e.button.y&&e.button.y<(height/1.3+rectVerde.h)){
									SDL_Texture *morado2 = NULL;
									morado2 = IMG_LoadTexture(renderer,"morado.png");
									SDL_QueryTexture(morado2, NULL, NULL, &w, &h);
									SDL_Rect rectMorado2;
									rectMorado2.x=((contador2*rectVerde.h+(contador2-1)*rectVerde.h));
									rectMorado2.y=(contador-1)/4*70+30;
									rectMorado2.w=rectVerde.w;
									rectMorado2.h=rectVerde.h;
									SDL_RenderCopy(renderer,morado2, NULL, &rectMorado2);
									SDL_RenderPresent(renderer);
									code[contador2-1]=2;
									contador++;
									contador2++;
									if(contador2==5){
										contador2=1;
									}
								}
							}
							if(e.button.x<6*(width/9)&&e.button.x>5*(width/9)){
								if((height/1.3)<e.button.y&&e.button.y<(height/1.3+rectVerde.h)){
									SDL_Texture *verde2 = NULL;
									verde2 = IMG_LoadTexture(renderer,"verde.png");
									SDL_QueryTexture(verde2, NULL, NULL, &w, &h);
									SDL_Rect rectVerde2;
									rectVerde2.x=((contador2*rectVerde.h+(contador2-1)*rectVerde.h));
									rectVerde2.y=(contador-1)/4*70+30;
									rectVerde2.w=rectVerde.w;
									rectVerde2.h=rectVerde.h;
									SDL_RenderCopy(renderer,verde2, NULL, &rectVerde2);
									SDL_RenderPresent(renderer);
									code[contador2-1]=3;
									contador++;
									contador2++;
									if(contador2==5){
										contador2=1;
									}
								}
						}

						if(e.button.x<8*(width/9)&&e.button.x>7*(width/9)){
							if((height/1.3)<e.button.y&&e.button.y<(height/1.3+rectVerde.h)){
								SDL_Texture *celeste2 = NULL;
								celeste2 = IMG_LoadTexture(renderer,"celeste.png");
								SDL_QueryTexture(celeste2, NULL, NULL, &w, &h);
								SDL_Rect rectCeleste2;
								rectCeleste2.x=((contador2*rectVerde.h+(contador2-1)*rectVerde.h));
								rectCeleste2.y=(contador-1)/4*70+30;
								rectCeleste2.w=rectVerde.w;
								rectCeleste2.h=rectVerde.h;
								SDL_RenderCopy(renderer,celeste2, NULL, &rectCeleste2);
								SDL_RenderPresent(renderer);
								code[contador2-1]=4;
								contador++;
								contador2++;
								if(contador2==5){
									contador2=1;
								}
							}
						}
						if(contador==5||contador==9||contador==13||contador==17||contador==21){
							for(int i=0;i<4;i++){
								std::cout << "code"<<code[i] << '\n';
								if(code[i]!=secretCode[i]){
									flag=false;
								}
							}
							if(flag==true){

								SDL_RenderClear(renderer);
								SDL_Texture *winner = NULL;
								winner = IMG_LoadTexture(renderer,"winner.jpg");
								SDL_QueryTexture(winner, NULL, NULL, &w, &h);
								SDL_Rect rectWinner;
								rectWinner.x=0;
								rectWinner.y=0;
								rectWinner.w=700;
								rectWinner.h=700;
								SDL_RenderCopy(renderer,winner, NULL, &rectWinner);
								SDL_RenderPresent(renderer);
							}
							else{
								int negros=0;
								int blancos=0;
								int c=1;
								vector<int> correctos;
								for(int i=0;i<4;i++){
									if(code[i]==secretCode[i]){
										negros++;
										correctos.push_back(i);
									}
								}
								for(int i=0;i<4;i++){
									for(int j=0;j<4;j++){
										if(code[i]==secretCode[j]){
											blancos++;
											for(int a=0;a<correctos.size();a++){
												if(correctos[a]==j||correctos[a]==i){
													blancos--;
												}
											}
										}
									}
								}
								std::cout << "b "<<blancos << '\n';
								std::cout << "n "<<negros << '\n';
								for(int i=0;i<blancos;i++){
									SDL_Texture *blanco = NULL;
									blanco = IMG_LoadTexture(renderer,"blanco.png");
									SDL_QueryTexture(blanco, NULL, NULL, &w, &h);
									SDL_Rect rectBlanco;
									rectBlanco.x=((500+(c-1)*30));
									rectBlanco.y=((contador-1)/4)*(rectVerde.w+10);
									rectBlanco.w=20;
									rectBlanco.h=20;
									SDL_RenderCopy(renderer,blanco, NULL, &rectBlanco);
									SDL_RenderPresent(renderer);
									c++;
								}
								for(int i=0;i<negros;i++){
									SDL_Texture *negro = NULL;
									negro = IMG_LoadTexture(renderer,"negro.png");
									SDL_QueryTexture(negro, NULL, NULL, &w, &h);
									SDL_Rect rectNegro;
									rectNegro.x=((500+(c-1)*30));
									rectNegro.y=((contador-1)/4)*(rectVerde.w+10);
									rectNegro.w=20;
									rectNegro.h=20;
									SDL_RenderCopy(renderer,negro, NULL, &rectNegro);
									SDL_RenderPresent(renderer);
									c++;
								}
							}
						}
						flag=true;
						if(contador==25){
							for(int i=0;i<4;i++){
								std::cout << "code"<<code[i] << '\n';
								if(code[i]!=secretCode[i]){
									flag=false;
								}
							}
							if(flag==true){
								SDL_RenderClear(renderer);
								SDL_Texture *winner = NULL;
								winner = IMG_LoadTexture(renderer,"winner.jpg");
								SDL_QueryTexture(winner, NULL, NULL, &w, &h);
								SDL_Rect rectWinner;
								rectWinner.x=0;
								rectWinner.y=0;
								rectWinner.w=700;
								rectWinner.h=700;
								SDL_RenderCopy(renderer,winner, NULL, &rectWinner);
								SDL_RenderPresent(renderer);
							}
							else{
								SDL_RenderClear(renderer);
								SDL_Texture *over = NULL;
								over = IMG_LoadTexture(renderer,"gameover2.png");
								SDL_QueryTexture(over, NULL, NULL, &w, &h);
								SDL_Rect rectOver;
								rectOver.x=0;
								rectOver.y=0;
								rectOver.w=700;
								rectOver.h=700;
								SDL_RenderCopy(renderer,over, NULL, &rectOver);
								SDL_RenderPresent(renderer);

								for(int c=0;c<4;c++){
									if(secretCode[c]==1){
										SDL_Texture *rosado = NULL;
										rosado = IMG_LoadTexture(renderer,"rosado.png");
										SDL_QueryTexture(over, NULL, NULL, &w, &h);
										SDL_Rect rectRosado;
										rectRosado.x=350+c*70;
										rectRosado.y=630;
										rectRosado.w=50;
										rectRosado.h=50;
										SDL_RenderCopy(renderer,over, NULL, &rectRosado);
										SDL_RenderPresent(renderer);
									}
									if(secretCode[c]==2){
										SDL_Texture *morado2 = NULL;
										morado2 = IMG_LoadTexture(renderer,"morado.png");
										SDL_QueryTexture(morado2, NULL, NULL, &w, &h);
										SDL_Rect rectMorado2;
										rectMorado2.x=350+c*70;
										rectMorado2.y=630;
										rectMorado2.w=50;
										rectMorado2.h=50;
										SDL_RenderCopy(renderer,morado2, NULL, &rectMorado2);
										SDL_RenderPresent(renderer);
									}
									if(secretCode[c]==3){
										SDL_Texture *rosado = NULL;
										verde2 = IMG_LoadTexture(renderer,"verde.png");
										SDL_QueryTexture(verde2, NULL, NULL, &w, &h);
										SDL_Rect rectVerde2;
										rectVerde2.x=350+c*70;
										rectVerde2.y=630;
										rectVerde2.w=50;
										rectVerde2.h=50;
										SDL_RenderCopy(renderer,verde2, NULL, &rectVerde2);
										SDL_RenderPresent(renderer);
									}
									if(secretCode[c]==4){
										SDL_Texture *rosado = NULL;
										celeste2 = IMG_LoadTexture(renderer,"celeste.png");
										SDL_QueryTexture(celeste2, NULL, NULL, &w, &h);
										SDL_Rect rectCeleste2;
										rectCeleste2.x=350+c*70;
										rectCeleste2.y=630;
										rectCeleste2.w=50;
										rectCeleste2.h=50;
										SDL_RenderCopy(renderer,celeste2, NULL, &rectCeleste2);
										SDL_RenderPresent(renderer);
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
	SDL_DestroyTexture(rosado);
	SDL_DestroyTexture(morado);
	SDL_DestroyTexture(celeste);
	SDL_DestroyTexture(verde);
	SDL_DestroyTexture(rosado2);
	SDL_DestroyTexture(morado2);
	SDL_DestroyTexture(celeste2);
	SDL_DestroyTexture(verde2);
	SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  // Clean up
  //SDL_Quit();
  return 0;
}
