
// g++ -o main farach.cpp -g -std=c++11 -std=gnu++11


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
	numeric.push_back(10);	//se agrega un 50 al final del array representando el simbolo $ que indica el final del string
	return numeric;
}


//funcion encargada de generar el odd tree
vector<int> C_Farach::createOddTree(string s){
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
	vector<int> sf;
	for(int i=0;i<pairs.size();i++){			//se guardan en el vector s los numeros que quedaron en las tuplas
		sf.push_back(pairs[i].first);
		sf.push_back(pairs[i].second);
	}
	createTree(sf);		//se llama a la funcion createTree() para hacer el arbol con el vector s
	return sf;
}

//funcion para ordenas un vector de tuplas
vector< pair<int,int> > C_Farach::pairSort(vector<	pair<int,int> > vect){
	sort(vect.begin(), vect.end());	//se ordenan las tuplas
	for(int i=0;i<vect.size();i++){
		std::cout << "pairs "<< vect[i].first<<"  "<<vect[i].second << '\n';
	}
	return vect;
}


//funcion para encontrar donde se debe insertar un nodo en el arbol, recibe un vector de int con el alfabeto numerico del string
pair<S_node*,pair<int,int> > C_Farach::placeInTree(vector<int> s, S_node* node, int pos){
	bool found = false;			//bandera que indica si ya se encontro la posicion
	pair<int,int> pair2;		//tupla para guardar las posiciones en donde se divide el vector s y el suffix del nodo donde se va a introducir el nuevo
	pair<S_node*,pair<int,int> > pair;		//tupla para guardar el puntero al nodo donde se va a agregar el nuevo
	S_node* aux=NULL;						//nodo auxiliar para guardar el puntero de la posicion donde se va ainsertar el nuevo nodo
	for(int i=0;i<s.size();i++){									//se recorre el vector s
		for(int j=0;j<node->childrenCount;j++){			//se recorren todos los hijos del nodo a revisar
			if(node->children[j]->suffix[0]==s[i]){		//si el primer numero del sufijo de uno de los hijos coincide con el primero del vector s
				aux = node->children[j];								//se guarda en aux el nodo donde el numero coincide
			}
		}

		if(aux){				//si se encontro un numero en la primera posicion que coinciera con el primero del vector s
			for(int i=0;i<aux->suffix.size();i++){				//se recorren todos los numeros del sufijo de el nodo auxiliar
				if(aux->suffix[i]!=s[pos+i]){								//si los numeros en el nodo dejan de coincidir con el del vector s
					found=true;					//la bandera se cambia para indicar que ya se encontro la posicion
					pair2.second=i;			//se guarda la posicion en donde se debe dividir el sufijo del nodo
					pair2.first=pos+i;		//se guarda la posicion donde se debe dividir el vector s
					pair.second=pair2;		//se guarda en otra tupla, la tupla anterior y el puntero al nodo con la posicion donde se debe agregar el nuevo
				}
			}
			pos=pos+aux->suffix.size();			//se cambia el valos de la posicion donde se empieza a compara el vector s con los sufijos del arbol
			if(!found){											//en el caso de no haber encontrado la posicion
				placeInTree(s,aux,pos);				//se llama recursivamente la funcion
			}
		}
		pair.first=aux;			//se asigna al primer lugar de la tupla el puntero de la posicion donde se debe agregar el nuevo
		return pair;				//se retorna la tupla con los datos
	}
}


//funcion para crear el arbol de sufijos
void C_Farach::createTree(vector<int> s){

	this->root->parent=NULL;
	root->childrenCount=0;				//se inicializa el contador de los hijos del root en 0
	vector<int> vect;							//vector para guardar los sufijos a insertar en el arbol
	int c = 1;										//contador para leer los sufijos del vector s
	for(int i=0;i<s.size();i++){			//se realiza el proceso de anadir sufijos al arbol una cantidad de veces igual a la cantidad de numeros del vector s
		vect.clear();								//se vacia el vector cada vez
		for(int j=0;j<c;j++){				//se llena el vector con el sufijo a insertar
			vect.push_back(s[s.size()-1-i+j]);
		}
		pair<S_node*,pair<int,int> > pos = placeInTree(vect,root,0);		//se guarda la posicion en donde se debe insertar el nodo

		S_node* posn = pos.first;		//posicion del nodo
		int posl1 = pos.second.second;		//posicion de l numero en el vector s donde se debe dividir el sufijo
		int posl = pos.second.first;			//posicion del numero en el sufijo del arbol donde se debe dividir
		S_node* newNode = new S_node;			//se crea el nuevo nodo
		newNode->index=c;									//se asigna el valor del index al nuevo nodo
		if(pos.first==NULL){							//en el caso de que no coincida el primer numero del vector con el de algun nodo
			root->children[root->childrenCount]=newNode;			//se guarda el nuevo en la lista de hijos del root
			root->childrenCount=root->childrenCount+1;				//se suma 1 al contador de hijos del root
			newNode->suffix=vect;							//se asiga el sufijo al nodo
			newNode->parent=root;							//se asigna como padre el root

			cout << "se agrega nodo con:" << '\n';
			for(int i=0;i<newNode->suffix.size();i++){
				cout << newNode->suffix[i] << '\n';
			}
			cout << "con index: "<<newNode->index << '\n';
		}

		else{							//en el caso de coincidir el primer numero con el de algun nodo, se deben agregar dos nodos nuevos
			vector<int> v;						//vector para el sufijo de uno de los nodos nuevos
			S_node* newNode2 = new S_node;			//se crea el otro nodo
			for(int x=posl;x<posn->suffix.size();x++){				//se copia en v la parte del sufijo sobrante del nodo viejo del arbol
				v.push_back(posn->suffix[x]);
			}
			for(int x=posn->suffix.size()-1;x>posl;x--){			//se borran del nodo viejo los numeros sobrantes del sufijo
				posn->suffix.erase(posn->suffix.begin()+x);
			}
			newNode2->suffix=v;															//se asigna el sufijo al nodo nuevo
			newNode2->parent=posn;													//se adigna el nodo viejo como padre
			newNode2->index=posn->index;										//se asigna el index del nodo viejo
			newNode2->childrenCount=0;											//se inicializa el contador de hijos en 0
			newNode->childrenCount=0;												//se inicializa el contador de hijos en 0
			posn->children[posn->childrenCount]=newNode;		//se agrega el nuevo nodo a la lista de hijos del nodo viejo
			posn->children[posn->childrenCount]=newNode2;		//se agrega el nuevo nodo a la lista de hijos del nodo viejo
			posn->index=0;																	//se cambia el index del nodo viejo a 0
			posn->childrenCount=posn->childrenCount+2;			//se suma 2 al contador de hijos del nodo viejo
			newNode->parent=posn;														//se asigna el nodo viejo como padre

			vector<int> v2;																	//se crea el vector para el segundo sufijo
			for(int x=posl1;x<s.size();x++){								//se llema el vector con el sufijo nuevo del vector s
				v2.push_back(s[x]);
			}
			newNode->suffix=v2;															//se asigna el sufijo al nodo nuevo
			cout << "se agrega nodo con:" << '\n';
			for(int i=0;i<newNode->suffix.size();i++){
				cout << newNode->suffix[i] << '\n';
			}
			cout << "con index: "<<newNode->index << '\n';
			cout << ".........." << '\n';
			cout << "se agrega nodo con:" << '\n';
			for(int i=0;i<newNode2->suffix.size();i++){
				cout << newNode2->suffix[i] << '\n';
			}
			cout << "con index: "<<newNode2->index << '\n';

		}
		c++;		//se aumenta el contador para agregar un numero mas al sufijo
		cout << ".........." << '\n';
	}
}

//funcion para crear el even tree, recibe como parametro en vector de int utilizado para hacer el odd tree
void C_Farach::createEvenTree(vector<int> s){
	vector<	pair<int,int>	> pairs;					//vector para guardar tuplas con los valores de suffix y index del arbol
	for(int i=1;2*i<s.size();i++){					//se recorre el vector s para copiar los numeros en las tuplas
		pair<int,int> pair;
		pair.first=s[2*i];										//valor de suffix
		pair.second=2*i;											//valor de index
		pairs.push_back(pair);
	}
	pairs=pairSort(pairs);
//	vector<int> sf;
	root2->childrenCount=0;
	int lcp;
	for(int i=0;i<pairs.size();i++){									//se recorre el vector de tuplas insertar los nodos en el arbol
		S_node* newNode = new S_node;										//se crea un nuevo nodo
		newNode->index=pairs[0].second;									//se le asigna el index respectivo
		newNode->suffix.push_back(pairs[0].first);			//se adigna el suffix respectivo
		newNode->parent=root2;													//se le asigna como padre el root
		newNode->height=1;															//su altura es 1 por ser el primer nodo
		root2->children[root2->childrenCount]=newNode;	//se asigna como hijo del root
		root2->childrenCount++;
		S_node* last = newNode;
		S_node* aux = newNode;
		S_node* new2 = new S_node;
		if(i>pairs.size()){															//es caso de que no sea el primer nodo a insertar
			lcp=LCP(s,pairs[i].first,pairs[i+1].first);		//se calcula el lcp entre el ultimo nodo insertado y el nuevo a insertar
			int dif = last->height-lcp;										//diferencia entre el nodo y donde debe estar el lcp
			for(int i=0;i<=dif;i++){
				aux=aux->parent;
			}
			new2->parent=aux;															//se asigna como padre del nuevo nodo
			aux->children[aux->childrenCount]=new2;
			aux->childrenCount=aux->childrenCount+1;			//se anade 1 al contador de hijos del padre del nuevo nodo
			new2->index=pairs[i].second;									//se asigna el index respectivo
			new2->suffix.push_back(pairs[i].first);				//se asigna el suffix respectivo
		}
	}
}



int C_Farach::LCP(vector<int> s,int i, int j){
	int lcp;
	if(s[2*i]==s[2*j]){
		lcp = LCP(s,i+1,j+1)+1;
	}
	else{
		lcp = 0;
	}
	return lcp;
}

int main(void){
	string s = ("81818");
	C_Farach f;
	cout << "Se crea el Odd Tree" << '\n';
	vector<int> fs =f.createOddTree(s);
	cout << "*****************************************" << '\n';
	cout << "Se crea el Even Tree" << '\n';
	f.createEvenTree(fs);
}
