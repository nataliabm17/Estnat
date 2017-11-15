#include<string>
#include<iostream>
#include<vector>
#include <iomanip>
using namespace std;

struct S_node{
	int dato;
	S_node *derecha;
	S_node *izquierda;
	int height;
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
					paux->derecha->height=height(paux->izquierda);
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
					paux->derecha->height=height(paux->derecha);
				}
			}
		}


		S_node * insertAVL(S_node * node, int dato){
    	if(!node){
				node= new S_node;
				if(!node){
					cout<<"Memoria no asignada, se la comieron los gatitos" << endl;
					return NULL;
				}
				else{
					node->dato=dato;
					node-> height = 0;
					node->izquierda = node->derecha = NULL;
				}
			}
			else if(dato < node->dato){
				node->izquierda=insertAVL(node->izquierda, dato);
				if((heightNode(node->izquierda)-heightNode(node->derecha))>1){

					if(dato<node->izquierda->dato){
					node=rotateizquierda(node);
					}
					else{
					node=doubleRotateizquierda(node);
					}
				}
			}
			else if(dato > node->dato){
				node->derecha=insertAVL(node->derecha, dato);
				if((heightNode(node->derecha)-heightNode(node->izquierda))>1){

					if(dato>node->derecha->dato){
					node=rotatederecha(node);
					}
					else{
					node=doubleRotatederecha(node);
					}
				}
			}
			node->height=max(heightNode(node->izquierda),heightNode(node->derecha))+1;
			return node;
		}

		S_node * rotatederecha(S_node * node){
			S_node * paux = node->derecha;
			node->derecha=paux->izquierda;
			paux->izquierda=node;
			node->height=max(heightNode(node->izquierda),heightNode(node->derecha))+1;
			paux->height=max(heightNode(paux->izquierda),heightNode(paux->derecha))+1;
			return paux;
		}
		S_node * doubleRotatederecha(S_node * node){
			node->derecha=rotateizquierda(node->derecha);
			return rotatederecha(node);
		}
		S_node * rotateizquierda(S_node * node){
			S_node * paux = node->izquierda;
			node->izquierda=paux->derecha;
			paux->derecha=node;
			node->height=max(heightNode(node->izquierda),heightNode(node->derecha))+1;
			paux->height=max(heightNode(paux->izquierda),heightNode(paux->derecha))+1;
			return paux;
		}


		S_node * doubleRotateizquierda(S_node * node){
			node->izquierda=rotatederecha(node->izquierda);
			return rotateizquierda(node);
		}
		int heightNode(S_node * node){
			if(node){
				return node->height;
			}
			else{
				return -1;
			}
		}

		int max(int a, int b){
			if(a>b){
				return a;
			}
			else{
				return b;
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

		void imprimir(S_node* root, int height, int profundidad)		{
					vector<int> vector;
					linea(root,profundidad, vector);
					cout << setw((height-profundidad)*2);
					bool lado = true;
					if (vector.size() > 1) {
						for (int i=0 ;(unsigned)i<vector.size();i++) {
							if (vector[i] != '_') {
								if (lado){
									cout << "/" << "  ";
								}
								else{
									cout << "\\" << "  ";
								}
							}
							else{
								std::cout << "  " ;
							}
							lado = !lado;
						}
					cout << endl;
					cout << setw((height-profundidad)*1.9);
					}
					for (int i=0 ; (unsigned)i<vector.size();i++) {
						if (vector[i] != '_'){
							cout << vector[i] << "   ";
						}
						else{
							std::cout << "  " ;
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

		void linea(void){
			vector<int> vec;

			linea(this->root,2,vec);
		}

		int max(S_node* root){
			if(root->derecha!=NULL){
				return max(root->derecha);
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

		void borrar(int numero, S_node* nodo, int lado, S_node* paux2){
			if(nodo==NULL){
			}
			else if(nodo->dato==numero){
					if(nodo->izquierda==NULL&&nodo->derecha==NULL){
						if(lado==1&&paux2!=NULL){
							paux2->izquierda=NULL;
						}
						else if(lado==2&&paux2!=NULL){
							paux2->derecha=NULL;
						}
						else{
							delete nodo;
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
						S_node* paux3 = new S_node;
						int eliminado = max(nodo->izquierda);
						paux = nodo;
						nodo=nodo->izquierda;
						while(nodo->derecha!=NULL&&nodo->dato!=eliminado){
							paux3=nodo;
							nodo=nodo->derecha;
							lado=2;

						}
						paux->dato = eliminado;
						if(lado==1){
							delete paux3->izquierda;
							borrar(nodo->dato,nodo,lado,paux2);
						}
						else{
							paux3->derecha=NULL;
							borrar(nodo->dato,nodo,lado,paux2);
						}
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


	public:

		void borrar(int numero){
			S_node* paux2 = new S_node;

			borrar(numero,this->root,0,paux2);
		}

		void insertAVL(int i){
			this->root=insertAVL(this->root, i);
		}

		void Destructor(S_node* ptr){
			if(ptr){
				Destructor(ptr->izquierda);
				Destructor(ptr->derecha);
				delete ptr;
			}
		}

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
		void preorder(S_node* paux){
			if(paux){
				std::cout << paux->dato<< '\n';
				preorder(paux->izquierda);
				preorder(paux->derecha);
			}
		}
		void inorder(void){
			inorder(this->root);
		}
		void inorder(S_node* paux){
			if(paux){
				inorder(paux->izquierda);
				std::cout << paux->dato<< '\n';
				inorder(paux->derecha);
			}
		}
		void postorder(void){
			postorder(this->root);
		}

		void postorder(S_node* paux){
			if(paux){
				postorder(paux->izquierda);
				postorder(paux->derecha);
				std::cout << paux->dato<< '\n';
			}
		}

		int height(void){
			return height(this->root);

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


		void printTree(void){
			for (int i = 0 ; i < height(); i ++) {
				imprimir(this->root, height(), i);
			}
		}

		void insertComplete(int numero){
			S_node* paux = new S_node;
			S_node* paux2 = new S_node;
			insertComplete(numero,this->root,0,0,0,paux,paux2);
		}


		bool buscarElemento(int numero){
			bool bandera = false;
			return buscarElemento(numero,this->root,&bandera);
		}

		int max(void){
			return max(this->root);
		}

		int min(void){
			return min(this->root);
		}

};
