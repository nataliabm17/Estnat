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
	SDL_Renderer *renderer = NULL;
	SDL_Texture *rosado = NULL;
	SDL_Texture *morado = NULL;
	SDL_Texture *celeste = NULL;
	SDL_Texture *verde = NULL;
	SDL_Texture *rosado2 = NULL;
	SDL_Texture *morado2 = NULL;
	SDL_Texture *celeste2 = NULL;
	SDL_Texture *verde2 = NULL;
	SDL_Texture *menu = NULL;
	SDL_Texture *fondo = NULL;

	if(SDL_Init(SDL_INIT_VIDEO)<0){
		cout << "Error de inicializacion de video :(" << SDL_GetError<<'\n';
		return 1;
	}
	else{
		//se crea la ventana
		window = SDL_CreateWindow(
	      "Master Mind",             	     // titulo de la ventana
	      100,      									     // posicion inicial x
	      100,     									 	    // posicion inicial y
	      width,             	           // ancho
	      height,           	           // largo
	      0
	  );
		if(window == NULL){
	      //En caso de que no se pueda crear la ventana
	      cout << "No se pudo crear la ventana" << SDL_GetError();
	  }
		else{
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

      //Color de la ventana
      SDL_SetRenderDrawColor(renderer, 100, 30, 200, 0);

			//se crean los rect para los botones
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

			menu = IMG_LoadTexture(renderer,"final2.png");
			SDL_QueryTexture(menu, NULL, NULL, &w, &h);
			SDL_Rect rectMenu; rectMenu.x=0; rectMenu.y=0; rectMenu.w=width; rectMenu.h=height;

			fondo = IMG_LoadTexture(renderer,"fondo.png");
			SDL_QueryTexture(fondo, NULL, NULL, &w, &h);
			SDL_Rect rectFondo; rectFondo.x=0; rectFondo.y=0; rectFondo.w=width; rectFondo.h=height;



			SDL_RenderClear(renderer);
			SDL_RenderCopy(renderer,menu, NULL, &rectMenu);
			//Se renderiza la nueva imagen
			SDL_RenderPresent(renderer);




			//variables necesarias para ordenar las fichas de los intentos de jugador
			int contador = 1;
			int contador2 = 1;

			//vector para guardar el codigo insertado por el jugador
			vector<int> code(4);
			// vector para guardar el codigo secreto creado por la computadora
			vector<int> secretCode(4);
			bool flag=true;
			//se crea el codigo secreto
			srand(time(NULL));
			for(int i=0;i<4;i++){
				secretCode[i]=rand()% 4 + 1;
				std::cout << "sc "<<secretCode[i] << '\n';
			}


			while(1){
				//se colocan en la ventana
					SDL_Event e;
					 if( SDL_PollEvent(&e) ){
						if (e.type == SDL_QUIT){
							break;
						}
						else if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_ESCAPE){
							break;
						}
						//menu
						else if(e.type==SDL_MOUSEBUTTONDOWN){
								if(e.button.button==SDL_BUTTON_LEFT){
									//boton jugar
									if(e.button.x<600&e.button.x>500){
										if(630<e.button.y&&e.button.y<670){
											SDL_RenderCopy(renderer,fondo, NULL, &rectFondo);
											SDL_RenderCopy(renderer,rosado, NULL, &rectRosado);
											SDL_RenderCopy(renderer,verde, NULL, &rectVerde);
											SDL_RenderCopy(renderer,celeste, NULL, &rectCeleste);
											SDL_RenderCopy(renderer,morado, NULL, &rectMorado);
											SDL_RenderPresent(renderer);
										}
									}

									if(e.type==SDL_MOUSEBUTTONDOWN){
											if(e.button.button==SDL_BUTTON_LEFT){

												//se crean los botones para seleccionar el color deseado de la ficha
												if(e.button.x<2*(width/9)&&e.button.x>(width/9)){
													if((height/1.3)<e.button.y&&e.button.y<(height/1.3+rectVerde.h)){
														//se inicializa el rect con la imagen del color
														SDL_Texture *rosado2 = NULL;
														rosado2 = IMG_LoadTexture(renderer,"rosado.png");
														SDL_QueryTexture(rosado2, NULL, NULL, &w, &h);
														SDL_Rect rectRosado2;
														rectRosado2.x=((contador2*rectVerde.h+(contador2-1)*rectVerde.h));
														rectRosado2.y=(contador-1)/4*70+30;
														rectRosado2.w=rectVerde.w;
														rectRosado2.h=rectVerde.h;
														SDL_RenderCopy(renderer,rosado2, NULL, &rectRosado2);
														//se renderiza en la ventana
														SDL_RenderPresent(renderer);
														code[contador2-1]=1;
														contador++;
														contador2++;
														//se reinicia el contador2 a 1 para llevar dividir las fichas de cada intento
														if(contador2==5){
															contador2=1;
														}
													}
											}

											if(e.button.x<4*(width/9)&&e.button.x>3*(width/9)){
												if((height/1.3)<e.button.y&&e.button.y<(height/1.3+rectVerde.h)){
													//se inicializa el rect con la imagen del color
													SDL_Texture *morado2 = NULL;
													morado2 = IMG_LoadTexture(renderer,"morado.png");
													SDL_QueryTexture(morado2, NULL, NULL, &w, &h);
													SDL_Rect rectMorado2;
													rectMorado2.x=((contador2*rectVerde.h+(contador2-1)*rectVerde.h));
													rectMorado2.y=(contador-1)/4*70+30;
													rectMorado2.w=rectVerde.w;
													rectMorado2.h=rectVerde.h;
													SDL_RenderCopy(renderer,morado2, NULL, &rectMorado2);
													//se renderiza en la ventana
													SDL_RenderPresent(renderer);
													code[contador2-1]=2;
													contador++;
													contador2++;
													//se reinicia el contador2 a  para llevar dividir las fichas de cada intento
													if(contador2==5){
														contador2=1;
													}
												}
											}
											if(e.button.x<6*(width/9)&&e.button.x>5*(width/9)){
												if((height/1.3)<e.button.y&&e.button.y<(height/1.3+rectVerde.h)){
													//se inicializa el rect con la imagen del color
													SDL_Texture *verde2 = NULL;
													verde2 = IMG_LoadTexture(renderer,"verde.png");
													SDL_QueryTexture(verde2, NULL, NULL, &w, &h);
													SDL_Rect rectVerde2;
													rectVerde2.x=((contador2*rectVerde.h+(contador2-1)*rectVerde.h));
													rectVerde2.y=(contador-1)/4*70+30;
													rectVerde2.w=rectVerde.w;
													rectVerde2.h=rectVerde.h;
													SDL_RenderCopy(renderer,verde2, NULL, &rectVerde2);
													//se renderiza en la ventana
													SDL_RenderPresent(renderer);
													code[contador2-1]=3;
													contador++;
													contador2++;
													//se reinicia el contador2 a  para llevar dividir las fichas de cada intento
													if(contador2==5){
														contador2=1;
													}
												}
										}

										if(e.button.x<8*(width/9)&&e.button.x>7*(width/9)){
											if((height/1.3)<e.button.y&&e.button.y<(height/1.3+rectVerde.h)){
												//se inicializa el rect con la imagen del color
												SDL_Texture *celeste2 = NULL;
												celeste2 = IMG_LoadTexture(renderer,"celeste.png");
												SDL_QueryTexture(celeste2, NULL, NULL, &w, &h);
												SDL_Rect rectCeleste2;
												rectCeleste2.x=((contador2*rectVerde.h+(contador2-1)*rectVerde.h));
												rectCeleste2.y=(contador-1)/4*70+30;
												rectCeleste2.w=rectVerde.w;
												rectCeleste2.h=rectVerde.h;
												SDL_RenderCopy(renderer,celeste2, NULL, &rectCeleste2);
												//se renderiza en la ventana
												SDL_RenderPresent(renderer);
												code[contador2-1]=4;
												contador++;
												contador2++;
												//se reinicia el contador2 a  para llevar dividir las fichas de cada intento
												if(contador2==5){
													contador2=1;
												}
											}
										}

										//cada vez que se termina un intento se revisa el codigo insertado
										if(contador==5||contador==9||contador==13||contador==17||contador==21){
											for(int i=0;i<4;i++){
												//se revisa si coinciden los colores
												if(code[i]!=secretCode[i]){
													flag=false;
												}
											}
											//si todos coinciden se finaliza el juego
											if(flag==true){
												//se limpia la pantalla
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
												//Se renderiza la nueva imagen
												SDL_RenderPresent(renderer);
											}
											//si no todas coinciden se presentan en la pantalla fichas blancas o negras
											else{
												//contadores
												int negros=0;
												int blancos=0;
												int c=1;
												//vector con las posiciones en las que se encuentran las fichas que se acertaron
												vector<int> correctos;

												//se revisan los codigos para calcular la cantidad de fichas negras que se deben devolver
												for(int i=0;i<4;i++){
													if(code[i]==secretCode[i]){
														negros++;
														//se agrega a correctos el numero de posicion de la ficha acertada
														correctos.push_back(i);
													}
												}
												//se recorre para calcular la cantidad de fichas del color correcto pero en la posicion incorrecta
												for(int i=0;i<4;i++){
													for(int j=0;j<4;j++){
														if(code[i]==secretCode[j]){
															blancos++;
															//se descartan las posiciones en las cuales ya hay una ficha acertada
															for(int a=0;a<correctos.size();a++){
																if(correctos[a]==j||correctos[a]==i){
																	blancos--;
																}
															}
														}
													}
												}
												//se presentan en la ventana las fichas blancas correspondientes al ultimo intento
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
												//se presentan en la ventana las fichas negras correspondientes al ultimo intento
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

										//se revisa el codigo insertado para el ultimo intento
										if(contador==25){
											for(int i=0;i<4;i++){
												if(code[i]!=secretCode[i]){
													flag=false;
												}
											}
											//si el codigo insertado es correcto
											if(flag==true){
												//se presenta en la pantalla una imagen indicando la victoria
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
											//en el caso de ser incorrecto, se indica que se ha perdido
											else{
												//se presenta imagen indicando la perdida
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

												//se presenta en la pantalla el codigo secreto
												for(int c=0;c<4;c++){
													//se incluyen las fichas rosadas
													if(secretCode[c]==1){
														SDL_Texture *rosado = NULL;
														rosado = IMG_LoadTexture(renderer,"rosado.png");
														SDL_QueryTexture(rosado, NULL, NULL, &w, &h);
														SDL_Rect rectRosado;
														rectRosado.x=350+c*70;
														rectRosado.y=630;
														rectRosado.w=50;
														rectRosado.h=50;
														SDL_RenderCopy(renderer,rosado, NULL, &rectRosado);
														SDL_RenderPresent(renderer);
													}
													if(secretCode[c]==2){
														//se incluyen las fichas moradas
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
														//se incluyen las fichas verdes
														SDL_Texture *verde2 = NULL;
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
														//se incluyen las fichas celeste
														SDL_Texture *celeste2 = NULL;
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
  return 0;
}
