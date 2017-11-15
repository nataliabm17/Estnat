#include<string>
#include<iostream>
#include<vector>
#include <iomanip>
using namespace std;

struct S_node{
	int dato;
	S_node *derecha;
	S_node *izquierda;
};

class C_BinTree {
	private:
		S_node* root = NULL;
		void insertBST(int numero, S_node* paux){

			if(numero<paux->dato){
				if(paux->izquierda!=NULL){
					insertBST(numero, paux->izquierda);
				}
				else{
					S_node* nuevo = new S_node;
					nuevo->dato=numero;
					paux->izquierda=nuevo;

				}
			}
			else{
				if(paux->derecha!=NULL){
					insertBST(numero, paux->derecha);
				}
				else{
					S_node* nuevo = new S_node;
					nuevo->dato=numero;
					paux->derecha=nuevo;

				}
			}
		}

		void Destructor(S_node* ptr){
			if(ptr){
				Destructor(ptr->izquierda);
				Destructor(ptr->derecha);
				delete ptr;
			}
		}

		void preorder(S_node* paux){
			if(paux){
				std::cout << paux->dato<< '\n';
				preorder(paux->izquierda);
				preorder(paux->derecha);
			}
		}

		void inorder(S_node* paux){
			if(paux){
				inorder(paux->izquierda);
				std::cout << paux->dato<< '\n';
				inorder(paux->derecha);
			}
		}

		void postorder(S_node* paux){
			if(paux){
				postorder(paux->izquierda);
				postorder(paux->derecha);
				std::cout << paux->dato<< '\n';
			}
		}

		int height(S_node* nodo){
			if(nodo==NULL){
				return 0;
			}
			else{
				int lHeight=height(nodo->izquierda);
				int rHeight=height(nodo->derecha);
				if(lHeight>rHeight){
					return lHeight+1;
				}
				else{
					return rHeight+1;
				}
			}
		}
		void borrar(int numero, S_node* nodo, int lado, S_node* paux2){

			if(nodo==NULL){
			}
			else if(nodo->dato==numero){
					if(nodo->izquierda==NULL&&nodo->derecha==NULL){
						if(lado==1){
							std::cout << "lala1" << '\n';
							paux2->izquierda=NULL;

						}
						else if(lado==2){

							paux2->derecha=NULL;
						}
						else{

						}
						delete paux2->derecha;

					}
					else if(nodo->izquierda==NULL&&nodo->derecha!=NULL&&nodo->derecha->derecha==NULL&&nodo->derecha->izquierda==NULL){

						nodo->dato=nodo->derecha->dato;
						nodo->derecha=NULL;
					}
					else if(nodo->derecha==NULL&&nodo->izquierda!=NULL&&nodo->izquierda->derecha==NULL&&nodo->izquierda->izquierda==NULL){

						nodo->dato=nodo->izquierda->dato;
						nodo->izquierda=NULL;
					}
					else{
						S_node* paux = new S_node;
						paux = nodo;
						while(nodo->izquierda!=NULL){
							nodo=nodo->izquierda;
							lado=1;
						}
						while(nodo->derecha!=NULL){
							nodo=nodo->derecha;
							lado=2;
						}
						paux = nodo;
						delete nodo;
					}
			}
			else{
				if(nodo){
				paux2=nodo;
				borrar(numero,nodo->derecha,2,paux2);
				borrar(numero,nodo->izquierda,1,paux2);

				}
			}
	}
	void insertComplete(int numero, S_node* nodo, int ci, int cd, int bandera, S_node* paux ,S_node* paux2){
		paux = nodo->derecha;
		while(paux->derecha!=NULL&&paux->izquierda!=NULL&&bandera==0){
			cd = cd+1;
			insertComplete(numero,paux->derecha,ci,cd+1,0, paux, paux2);
			insertComplete(numero,paux->izquierda,ci,cd+1,0, paux, paux2);
		}
		bandera=1;
		paux2 = nodo->izquierda;
		while(paux2->derecha!=NULL&&paux2->izquierda!=NULL&&bandera==0){
			ci = ci+1;
			insertComplete(numero,paux2->derecha,ci,cd+1,0, paux, paux2);
			insertComplete(numero,paux2->izquierda,ci,cd+1,0, paux, paux2);
		}
		S_node* nuevo = new S_node;
		nuevo->dato=numero;
		if (ci>cd){
			if(paux2->izquierda==NULL){
				paux2->izquierda=nuevo;
			}
			else{
				paux2->derecha=nuevo;
			}
		}
		else{
			if(paux->izquierda==NULL){
				paux->izquierda=nuevo;
			}
			else{
				paux->derecha=nuevo;
			}
		}
	}
	void imprimir(S_node* root, int height, int profundidad){
					vector<int> vector;
					linea(root,profundidad, vector);
					cout << setw((height-profundidad)*2);
					bool lado = true;
					if (vector.size() > 1) {
						for (int i=0 ;i<vector.size();i++) {
							if (vector[i] != '_') {
								if (lado){
									cout << "/" << "  ";
								}
								else{
									cout << "\\" << "  ";
								}
							}
							else{
								std::cout << setw(profundidad*2.5);
							}
							lado = !lado;
						}
					cout << endl;
					cout << setw((height-profundidad)*1.9);
					}
					for (int i=0 ; i<vector.size();i++) {
						if (vector[i] != '_'){
							cout << vector[i] << "   ";
						}
						else{
							std::cout << setw(profundidad*2.5);
						}
					}
					cout << endl;
	}

	void linea(S_node* root,int profundidad,vector<int>& numeros){
		if (profundidad == 0 && root != NULL) {
			 numeros.push_back(root->dato);
			 return;
		}
		if (root->izquierda != NULL){
			 linea(root->izquierda, profundidad-1, numeros);
		}
		else if (profundidad-1 == 0){
			numeros.push_back('_');
		}
		if (root->derecha != NULL){
			linea(root->derecha, profundidad-1, numeros);
		}
		else if (profundidad-1 == 0){
			numeros.push_back('_');
		}
	}

	bool buscarElemento(int numero, S_node* nodo, bool* bandera){
		if(nodo){
			if(nodo->dato==numero){
				*bandera= true;
				return *bandera;
			}
			else{
				buscarElemento(numero,nodo->derecha,bandera);
				buscarElemento(numero,nodo->izquierda,bandera);
			}
		}
		return *bandera;
	}

	int max(S_node* root){
		if(root->derecha!=NULL){
			max(root->derecha);
		}
		else{
			return root->dato;
		}
	}

	int min(S_node* root){
		if(root->izquierda!=NULL){
			min(root->izquierda);
		}
		else{
			return root->dato;
		}
	}

	public:
		~C_BinTree(void){
			Destructor(this->root);
		}

		void insertBST(int numero){
			if(root){
				insertBST(numero,this->root);
			}
			else{
				S_node* nuevo = new S_node;
				nuevo->dato=numero;
				root=nuevo;
			}
		}

		void preorder(void){
			preorder(this->root);
		}

		void inorder(void){
			inorder(this->root);
		}

		void postorder(void){
			postorder(this->root);
		}

		int height(void){
			return height(this->root);
		}

		void borrar(int numero){
			S_node* paux2 = new S_node;
			borrar(numero,this->root,0,paux2);
		}

		void insertComplete(int numero){
			S_node* paux = new S_node;
			S_node* paux2 = new S_node;
			insertComplete(numero,this->root,0,0,0,paux,paux2);
		}

		void printTree(void){
	 		for (int i = 0 ; i < height(); i ++) {
				imprimir(this->root, height(), i);
	 		}
		}

		bool buscarElemento(int numero){
			bool bandera = false;
			buscarElemento(numero,this->root,&bandera);
		}
		int max(void){
			max(this->root);
		}

		int min(void){
			min(this->root);
		}
};
