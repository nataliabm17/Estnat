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
	vector<int> sf;
	for(int i=0;i<pairs.size();i++){			//se guardan en el vector s los numeros que quedaron en las tuplas
		sf.push_back(pairs[i].first);
		sf.push_back(pairs[i].second);
	}
	createTree(sf);		//se llama a la funcion createTree() para hacer el arbol con el vector s
}

//funcion para ordenas un vector de tuplas
vector< pair<int,int> > C_Farach::pairSort(vector<	pair<int,int> > vect){
	sort(vect.begin(), vect.end());	//se ordenan las tuplas
	for(int i=0;i<vect.size();i++){
		std::cout << "pairs "<< vect[i].first<<"  "<<vect[i].second << '\n';
	}
	return vect;
}

pair<S_node*,pair<int,int> > C_Farach::placeInTree(vector<int> s, S_node* node, int pos){
	bool found = false;
	pair<int,int> pair2;
	pair<S_node*,pair<int,int> > pair;
	S_node* aux=NULL;
	for(int i=0;i<s.size();i++){
		for(int j=0;j<node->childrenCount;j++){
			if(node->children[j]->suffix[0]==s[i]){
				aux = node->children[j];
			}
		}

		if(aux){
			for(int i=0;i<aux->suffix.size();i++){

				if(aux->suffix[i]!=s[pos+i]){
					found=true;
					pair2.first=i;
					pair2.first=pos+i;
					pair.second=pair2;
				}
			}
			pos=pos+aux->suffix.size();
			if(!found){
				placeInTree(s,aux,pos);
			}
		}
		pair.first=aux;
		return pair;
	}
}


//funcion para crear el arbol de sufijos
void C_Farach::createTree(vector<int> s){

	this->root->parent=NULL;
	root->childrenCount=0;
	vector<int> vect;
	int c = 1;

	for(int i=0;i<s.size();i++){
		vect.clear();
		for(int j=0;j<c;j++){
			vect.push_back(s[s.size()-1-i+j]);
		}
		pair<S_node*,pair<int,int> > pos = placeInTree(vect,root,0);

		S_node* posn = pos.first;		//posicion del nodo
		int posl1 = pos.second.second;
		int posl = pos.second.first;			//posicion del numero en el vector
		S_node* newNode = new S_node;
		newNode->index=c;
		if(pos.first==NULL){
			root->children[root->childrenCount]=newNode;
			root->childrenCount=root->childrenCount+1;
			newNode->suffix=vect;
			newNode->parent=root;
			cout << "se agrega nodo con:" << '\n';
			for(int i=0;i<newNode->suffix.size();i++){
				cout << newNode->suffix[i] << '\n';
			}
			std::cout << "con index: "<<newNode->index << '\n';

		}

		else{
			vector<int> v;
			S_node* newNode2 = new S_node;
			std::cout << "x "<<posn->suffix.size()<< '\n';
			for(int x=posn->suffix.size()-posl-1;x<posn->suffix.size();x++){
				v.push_back(posn->suffix[x]);
			}
			for(int x=posn->suffix.size()-1;x>posl;x--){
				posn->suffix.erase(posn->suffix.begin()+x);
			}
			newNode2->suffix=v;
			newNode2->parent=posn;
			newNode2->index=posn->index;
			newNode2->childrenCount=0;
			newNode->childrenCount=0;
			posn->children[posn->childrenCount]=newNode;
			posn->children[posn->childrenCount]=newNode2;
			posn->index=0;
			posn->childrenCount=posn->childrenCount+2;
			newNode->parent=posn;

			vector<int> v2;
			for(int x=s.size()-posl1-1;x<s.size();x++){
				v2.push_back(s[x]);
			}
			newNode->suffix=v2;
			cout << "se agrega nodo con:" << '\n';
			for(int i=0;i<newNode->suffix.size();i++){
				cout << newNode->suffix[i] << '\n';
			}
			std::cout << "con index: "<<newNode->index << '\n';
			std::cout << ".........." << '\n';
			cout << "se agrega nodo con:" << '\n';
			for(int i=0;i<newNode2->suffix.size();i++){
				cout << newNode2->suffix[i] << '\n';
			}
			std::cout << "con index: "<<newNode2->index << '\n';

		}
		c++;
		std::cout << ".........." << '\n';
	}

}

int main(void){
	string s = ("81818");
	C_Farach f;
	f.createOddTree(s);
}
