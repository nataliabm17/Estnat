
#include<Magick++.h>
#include"matriz.h"
#include"vector"
#include <iostream>

using namespace Magick;


C_matriz iluminancia(string direccion){
		Image imagen(direccion);

		int a = (int)imagen.rows();
		int b =(int)imagen.columns();
		C_matriz matriz(a,b);
		ColorRGB pixelrgb;

		for(int i=1;i<a;i++){
			for(int j=1;j<b;j++){
				pixelrgb = imagen.pixelColor(j,i);
				float n = pixelrgb.red()*0.299 + pixelrgb.green()*0.587 +pixelrgb.blue()*0.114;
				matriz.set(i,j,n);
			}
		}
		return matriz;
	}

void revisar(int i, int j,int a, C_matriz* m, int* c, int ultimo, int si, int sj);
void revisar2(int i, int j,int a, C_matriz* m, int* c, int ultimo, int si, int sj,int mayor);

//funcion que se encarga de agrupar los pixeles negros
int revisarNegro(int i, int j, int a, C_matriz* m, int* c, int ultimo){
	//se verifica que no sean piexeles blancos
	if(m->get(i,j)!=0){
		//se revisan los pixeles ubicados alrededor en la matriz
		//a funciona como contador que indica que posicion se va a revisar
		if(a==0){
			//si el pixel es negro, se le asigna el valor que tiene el contador c
			//se le asigna a ultimo, el numero asignado al pixel
			if(m->get(i,j)==1){
				m->set(i,j,*c);
				ultimo=*c;
				*c=*c+1;

				//se llama al mismo metodo, variando el contador a para revisar otra posicion
				revisarNegro(i,j,1,m,c,ultimo);
			}

			else{
				//se le asigna a ultimo el valor encontrado en la posicion revisada
				ultimo=m->get(i,j);
				//se llama al mismo metodo, variando el contador a para revisar otra posicion
				revisarNegro(i,j,1,m,c,ultimo);
			}
		}

		//Se revisan todas las posiciones alrededor del pixel, llamando a la fucion revisar
		//Se varian los ultimos dos parametros para cambiar la posicion
		else if(a==1){
			revisar(i,j,a,m,c,ultimo,1,0);
		}
		else if(a==2){
			revisar(i,j,a,m,c,ultimo,1,1);
		}
		else if(a==3){
			revisar(i,j,a,m,c,ultimo,0,1);
		}

		else if(a==4){
			revisar(i,j,a,m,c,ultimo,-1,1);
		}

		else if(a==5){
			revisar(i,j,a,m,c,ultimo,-1,0);
		}

		else if(a==6){
			revisar(i,j,a,m,c,ultimo,-1,-1);
		}

		else if(a==7){
			revisar(i,j,a,m,c,ultimo,0,-1);
		}
		else if(a==8){
			revisar(i,j,a,m,c,ultimo,1,-1);
		}
		else{
		}

	}
	else{

	}
	return *c;
}


//metodo para agrupar los pixeles blancos
	int revisarBlanco(int i, int j, int a, C_matriz* m, int* c, int ultimo,int mayor){
		//se verfica que sean pixeles blancos o que sean mayores al ultimo numero asignado a un grupo de pixeles negros

		if(m->get(i,j)>mayor||(m->get(i,j)==0)){
			//se revisa posicion por posicion
			if(a==0){
				if(m->get(i,j)==0){
					m->set(i,j,*c);
					ultimo=*c;
					*c=*c+1;

					revisarBlanco(i,j,1,m,c,ultimo,mayor);
				}
				else{
					ultimo=m->get(i,j);
					revisarBlanco(i,j,1,m,c,ultimo,mayor);
					}
				}
			//se revisan las distintas posiciones alredeos del pixel
			//se cambian los ultimos dos parametros al llamar al metodo revisar2
			else if(a==1){
				revisar2(i,j,a,m,c,ultimo,1,0,mayor);
			}
			else if(a==2){
				revisar2(i,j,a,m,c,ultimo,1,1,mayor);
			}
			else if(a==3){
				revisar2(i,j,a,m,c,ultimo,0,1,mayor);
			}
			else if(a==4){
				revisar2(i,j,a,m,c,ultimo,-1,1,mayor);
			}
			else if(a==5){
				revisar2(i,j,a,m,c,ultimo,-1,0,mayor);
			}
			else if(a==6){
				revisar2(i,j,a,m,c,ultimo,-1,-1,mayor);
			}
			else if(a==7){
				revisar2(i,j,a,m,c,ultimo,0,-1,mayor);
			}
			else if(a==8){
				revisar2(i,j,a,m,c,ultimo,1,-1,mayor);
			}
			else{
			}
		}
		else{
		}
		return *c;
	}

//metodo para revisar los pixeles negros para asignarles un valor
//se cambia de posicion dependiendo de los parametros sj y si
void revisar(int i, int j,int a, C_matriz* m, int* c, int ultimo, int si, int sj){
	//se verifica que el pixel sea negro y que ultimo sea distinto de 0


	if(m->get(i+si,j+sj)==1&&ultimo!=0){

		//se le asigna el valor de ultimo a la posicion revisada
		m->set(i+si,j+sj,ultimo);
		//se llama al metodo revisarNegro, cambiando el parametro a para revisar la siguiente posicion
		revisarNegro(i,j,a+1,m,c,ultimo);
	}


	//se verifica que el pixel sea negro y que ultimo es igual a 0, indicando que es el primer elemento del grupo
	else if(m->get(i+si,j+sj)==1&&ultimo==0){

		//se asigna el valor del contador en la posicion revisada y se aumenta en 1 el contador
		m->set(i+si,j+sj,*c);
		ultimo=*c;
		*c=*c+1;
		//se llama a la funcion revisarNegro cambiando los parametros para revisar otra posicion
		revisarNegro(i,j,a+1,m,c,ultimo);
	}

	//si dos numeros que estan a la par son iguales, ninguno se cambia
	else if(m->get(i+si,j+sj)==m->get(i,j)){
		revisarNegro(i,j,a+1,m,c,ultimo);
	}

	//si se encuentra un pixel blanco, no se hace nada y pasa a la siguiente posicion
	else if(m->get(i+si,j+sj)==0){
		revisarNegro(i,j,a+1,m,c,ultimo);
	}

	else{
	//si un numero encontrado es menor, el de la posicion central secambia por este
		if(m->get(i+si,j+sj)<m->get(i,j)){
			m->set(i,j,m->get(i+si,j+sj));
			ultimo = m->get(i+si,j+sj);
			revisarNegro(i,j,0,m,c,ultimo);

		}
	//si el numero encontrado es mayor, este se cambia por el de la posicion central
		else if(m->get(i+si,j+sj)>m->get(i,j)){
			m->set(i+si,j+sj,m->get(i,j));
			ultimo = m->get(i,j);

			revisarNegro(i,j,a+1,m,c,ultimo);

		}
		else{
		}
	}

}

//metodo para revisar los pixeles blancos para asignarles un valor
//se cambia de posicion dependiendo de los parametros sj y si
void revisar2(int i, int j,int a, C_matriz* m, int* c, int ultimo, int si, int sj,int mayor){
	//se verifica que el pixel sea blanco y que ultimo sea distinto de 0
	if(m->get(i+si,j+sj)==0&&ultimo!=0){
		//se le asigna el valor de ultimo a la posicion revisada
		m->set(i+si,j+sj,ultimo);
		//se llama al metodo revisarNegro, cambiando el parametro a para revisar la siguiente posicion
		revisarBlanco(i,j,a+1,m,c,ultimo,mayor);
	}
	//se verifica que el pixel sea blanco y que ultimo es igual a 0, indicando que es el primer elemento del grupo
	else if(m->get(i+si,j+sj)==0&&ultimo==0){
		//se asigna el valor del contador en la posicion revisada y se aumenta en 1 el contador
		m->set(i+si,j+sj,*c);
		ultimo = *c;
		//se llama a la funcion revisarBlanco cambiando los parametros para revisar otra posicion
		revisarBlanco(i,j,a+1,m,c,ultimo,mayor);
	}
	//si dos numeros que estan a la par son iguales, ninguno se cambia
	else if(m->get(i+si,j+sj)==m->get(i,j)){
		revisarBlanco(i,j,a+1,m,c,ultimo,mayor);
	}
	//si un numero encontrado es menor, el de la posicion central se cambia por este
	else{
		if(m->get(i+si,j+sj)<m->get(i,j)){
			m->set(i,j,m->get(i+si,j+sj));
			ultimo = m->get(i+si,j+sj);
			revisarBlanco(i,j,0,m,c,ultimo,mayor);

		}
		//si el numero encontrado es mayor, este se cambia pot el de la posicion central
		else if(m->get(i+si,j+sj)>m->get(i,j)){
			m->set(i+si,j+sj,m->get(i,j));
			ultimo = m->get(i,j);
			revisarBlanco(i,j,a+1,m,c,ultimo,mayor);

		}
	}
}

int main(int argc,char **argv){
	InitializeMagick(NULL);

	C_matriz mimagen = iluminancia("imagen.jpg");
	Image imagen2("imagen.jpg");
	ColorRGB color;
	int a = (int)imagen2.rows();
	int b =(int)imagen2.columns();
	//se recorre la matriz guardando cada valor en los pixeles de imagen2
	for(int i=1;i<=a;i++){
		for(int j=1;j<=b;j++){
			float n = mimagen.get(i,j);
				color.red(n);
				color.green(n);
				color.blue(n);
				imagen2.pixelColor(j-1,i-1,color);
			}
		}
		//Se crea la imagen con los valores de los pixeles cambiados
		imagen2.write("prueba.jpg");

		//Se recorre la matriz cambiando a blanco todos los valores menores a 0.4 y a negro los mayores
		for(int i=1;i<=a;i++){
			for(int j=1;j<=b;j++){
				if(mimagen.get(i,j)>0.4){
					color.red(1);
					color.green(1);
					color.blue(1);
					mimagen.set(i,j,1);

				}
				else{
					color.red(0);
					color.green(0);
					color.blue(0);
					mimagen.set(i,j,0);
				}
				imagen2.pixelColor(j-1,i-1,color);
			}
		}

		imagen2.write("prueba2.jpg");

		//contador para el numero del grupo
		int c = 2;
		//contador para las posiciones
		int a2 = 0;
		//numero mayor asignado a un grupo de pixeles negros
		int mayor;
		int mayor2 = 0;
		//se recorre la matriz revisadndo los pixeles negros
		for(int i=2;i<=mimagen.filas-1;i++){
			for(int j=2;j<=mimagen.columnas-1;j++){
				mayor = revisarNegro(i,j,a2,&mimagen,&c,0);
				}
			}

		//se recorre la matriz revisando los pixeles blancos
		for(int i=2;i<=mimagen.filas-1;i++){
			for(int j=2;j<=mimagen.columnas-1;j++){
				mayor2 = revisarBlanco(i,j,a2,&mimagen,&mayor,0, mayor);
			}
		}
		//vector para guaradar la cantidad de pixeles que hay en cada grupo
		std::vector<int> array1(mayor2-2);
		int n = 0;
		//se asigna el valor de 0 a todas las posiciones
		while(n<mayor2-2){
			array1[n]=0;
			n++;
		}
		//se recorre la matriz guardando en array1 la cantidad de pixeles por grupo
			for(int i=1;i<=mimagen.filas;i++){
			for(int j=1;j<=mimagen.columnas;j++){
				int c = 0;
				while(c<=mayor2){
					if(array1[mimagen.get(i,j)]!=0){
						array1[mimagen.get(i,j)]+=1;
						c=c+1;
					}
					else{
						array1[mimagen.get(i,j)]=1;
						c++;
					}
				}
			}
		}
		//se recorre la matriz, cambiando los grupos pequenos por blancos
		for(int c=0;c<=mayor2;c++){
			if(array1[c]<20){
				for(int i=1;i<=a;i++){
					for(int j=1;j<=b;j++){
						if(mimagen.get(i,j)==array1[c]){
							mimagen.set(i,j,0);
						}
						else{}
					}
				}
			}
		}
		//se guardan los valores de la matriz en los pixeles de la imagen
		for(int i=1;i<=a;i++){
			for(int j=1;j<=b;j++){
				color.red(mimagen.get(i,j));
				color.green(mimagen.get(i,j));
				color.blue(mimagen.get(i,j));
				imagen2.pixelColor(j-1,i-1,color);
			}
		}
		imagen2.write("prueba3.jpg");
}
