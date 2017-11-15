#include<string>
#include<iostream>
#include<vector>
using namespace std;

class C_Heap{
protected:

	private:
		int tamano;
		int tipo;
	  vector<int> arreglo;


		int leftChild(int i){
			if(this->arreglo[2*i+1] && this->arreglo[2*i+1]!=-1){
				return this->arreglo[2*i+1];
			}
			else{
				return -1;
			}
		}

		int rightChild(int i){
			if(this->arreglo[2*i+2]){
				return this->arreglo[2*i+2];
			}
			else{
				return -1;
			}
		}

		void percolateDown(int p){
			int p2=p;
		  int dato=arreglo[p];
		  if (tipo==0) {
		    if (leftChild(p)>arreglo[p2]&&leftChild(p)!=-1) {
		      p2=2*p+1;
		    }
		    if (rightChild(p)>arreglo[p2]) {
		      p2=2*p+2;
		    }
		    if (arreglo[p2]>arreglo[p]) {
		      arreglo[p]=arreglo[p2];
		      arreglo[p2]=dato;
		      percolateDown(p2);
		    }
		  }

		  else if (tipo==1) {
		    if (leftChild(p)<arreglo[p2]&&p<arreglo.size()&&p2<arreglo.size()) {
		      p2=2*p+1;
		    }
		    if (rightChild(p)<arreglo[p2]&&p<arreglo.size()&&p2<arreglo.size()) {
		      p2=2*p+2;
		    }
		    if (arreglo[p2]<arreglo[p]&&p<arreglo.size()&&p2<arreglo.size()) {
		      arreglo[p]=arreglo[p2];
		      arreglo[p2]=dato;
		      percolateDown(p2);
		    }
		  }
		}

/*

			int p1;
			if(tipo==0){
				if(leftChild(i)>rightChild(i)){
					p1=2*i+1;
					if(p1>arreglo[i]){
						int num = arreglo[i];
						arreglo[i]=arreglo[2*i+1];
						arreglo[2*i+1]=num;
						percolateDown(2*i+1);
					}
				}
				if(leftChild(i)<rightChild(i)){
					p1=2*i+2;
					if(p1>arreglo[i]){
						int num = arreglo[i];
						arreglo[i]=arreglo[2*i+2];
						arreglo[2*i+2]=num;
						percolateDown(2*i+2);
					}
				}
			}
				if(tipo==1){
					if(leftChild(i)<rightChild(i)){
						p1=2*i+1;
						if(p1<arreglo[i]){
							int num = arreglo[i];
							arreglo[i]=arreglo[2*i+1];
							arreglo[2*i+1]=num;
							percolateDown(2*i+1);
						}
					}
					if(leftChild(i)>rightChild(i)){
						p1=2*i+2;
						if(p1<arreglo[i]){
							int num = arreglo[i];
							arreglo[i]=arreglo[2*i+2];
							arreglo[2*i+2]=num;
							percolateDown(2*i+2);
						}
					}
				}
		}*/

	public:
		C_Heap(int tamano, int tipo){
			this->arreglo.resize(tamano);
			this->tamano=tamano;
			this->tipo=tipo;
			for(int i=0;i<tamano;i++){
				this->arreglo[i]=-1;
			}
		}

		C_Heap(void){
			this->arreglo.resize(1,-1);
			this->tamano=1;
			this->tipo=0;
		}

		~C_Heap(){
		}


		int getMax(void){
			int numero=this->arreglo[0];
			for(int i=0;i<arreglo.size();i++){
				if(this->arreglo[i]>numero){
					numero = this->arreglo[i];
				}
				return numero;
			}
		}
		void delMax(void){
			for(int i=0;i<this->arreglo.size();i++){
				if(this->arreglo[i]==getMax()){
					this->arreglo[i]=-1;
				}
		}
	}
		void insert(int numero){
			int posicion=0;
		  while (this->arreglo[posicion]!=-1) {
		    posicion+=1;
		  }
		  this->arreglo[posicion]=numero;
		  for (int i = (((posicion+1)/2)-1); i >= 0; i--) {


			  percolateDown(i);
		  }
		}

		int capacity(vector<int>* arreglo){
			return this->arreglo.size();
		}
		void resize(int tamano){
			this->arreglo.resize(tamano);
		}

		int count(void){
			int contador=0;
			for(int i=0;i<this->arreglo.size();i++){
				if(this->arreglo[i]!=-1){
					contador++;
				}
			}
			return contador;
		}


		void imprimir(void){
			for(int i=0;i<this->arreglo.size();i++){
				if(this->arreglo[i]!=-1){
					std::cout << this->arreglo[i] << '\n';
				}
				else{
					std::cout << "-" << '\n';
				}
			}
		}
};
