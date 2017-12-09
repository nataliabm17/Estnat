#include "farach.h"

//funcion para cambiar el string a un vector de ints
vector<int> C_Farach::numericAlphabet(string s, int size){
	vector<int>	numeric(size,0);				//vector para guardar el string transformado a int
	vector<char> a(s.begin(),s.end());		//vector donde se guardan los caracteres del string
	if(!isdigit(a[0])){			//en el caso de que los caracteres no sean numeros
		vector<char> list;		//vector donde se guardan los numeros ya utilizados
		int c = 1;						//contador para ir cambiando los numeros conforme se cambie de letra
		bool found = false;		//bandera que indica si ya a esa letra se le habia asignado un numero

		for(int i=0;i<size;i++){			//se recorre todo el vector
			for(int j=0;j<list.size();j++){
				if(list[j]==a[i]){	//se compara para verificar si ya esa letra se habia utilizado
					numeric[i]=j+1;		//se le asigna un numero a la letra
					found=true;
				}
			}
			if(found==false){
				list.push_back(a[i]);		//se agraga la letra a la lista para saber que ya se le asigno un numero
				numeric[i]=c;				//se le asigna un numero a la letra
				c++;
			}
			found = false;
		}
	}
	else{		//en el caso de tratarse de un string con numeros
		for(int i=0;i<a.size();i++){
			numeric[i]=(int)a[i]-48;		//se pasan los caracteres a ints
		}
	}
	numeric.push_back(10);	//se agrega un 10 al final del array representando el simbolo $ que indica el final del string
	return numeric;
}


//funcion encargada de generar el odd tree
void C_Farach::createOddTree(string s){
	vector<int> numeric=numericAlphabet(s,s.length());	//vector en el que se guarda el devuelto por el metodo numericAlphabet
	vector< pair<int,int> > pairs;		//vector con los pairs del string

	for(int i=0;i<numeric.size();i=i+2){		//se divide el vector numerico en pares
		pair<int,int> pair;
		if(numeric[i+1]){	//en el caso de tener cantidad de numeros par
			pair = make_pair(numeric[i],numeric[i+1]);
		}
		else{		//en el caso de tener una cantidad impar de numeros
			pair = make_pair(numeric[i],-2);		//se agrega un -2 para representar el espacio vacio
		}
		pairs.push_back(pair);
	}
	int c = 1;	//contador utilizado para recorrer los vectores
	pairSort(pairs);	//se llama a la funcion para ordenar el vector de tuplas
	for(int i=0;i<pairs.size();i++){		//se recorre el vector de tuplas para verificar que no hayan dos iguales
		for(int j=c;j<pairs.size();j++){
			if((pairs[i].first==pairs[j].first)&&(pairs[i].second==pairs[j].second)){	//en el caso de ser iguales
				pairs.erase (pairs.begin()+j);		//se borra una de las tuplas
			}
		}
		c++;
	}
	for(int i=0;i<pairs.size();i++){
		std::cout << "pairs finales "<< pairs[i].first<<"  "<<pairs[i].second << '\n';
	}
	for(int i=0;i<pairs.size();i++){			//se guardan en el vector s los numeros que quedaron en las tuplas
		s.push_back(pairs[i].first);
		s.push_back(pairs[i].second);
	}
}

//funcion para ordenas un vector de tuplas
vector< pair<int,int> > C_Farach::pairSort(vector<	pair<int,int> > vect){

	sort(vect.begin(), vect.end());	//se ordenan las tuplas
	for(int i=0;i<vect.size();i++){
		std::cout << "pairs "<< vect[i].first<<"  "<<vect[i].second << '\n';
	}
	return vect;
}

void C_Farach::createTree(vector<int> s){

}

int main(void){
	string s = ("818189");
	C_Farach f;
	f.createOddTree(s);
}
