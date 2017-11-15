#include<string>
#include<iostream>
#include<vector>
#include <queue>
#include <cstdlib>
using namespace std;

class C_Grafo{
protected:
	vector< vector<int> > matriz;
	int vertices;
	vector<int> lista;

	private:
		void DFS(int pos){
			std::cout << pos << '\n';
				lista[pos]=1;
				for(int i=0;i<vertices;i++){
					if(matriz[pos][i]==1){
						if(lista[i]==0){
						DFS(i);
						}
					}
				}
		}

	public:
		C_Grafo(int vertices){
			this->vertices=vertices;
			this->matriz=matriz;
			this->matriz.resize(vertices);
			for(int i=0;i<this->matriz.size();i++){
				this->matriz[i].resize(vertices);
			}

		}
		~C_Grafo(){
		}

		void DFS(void){
			lista.resize(vertices);
			DFS(0);
		}
		void edge(int v1, int v2){
			matriz[v1][v2]=1;
		}

		void BFS(void){
			queue<int> cola;
			vector<int> lista(vertices,0);
			for(int i=0;i<vertices;i++){
				for(int j=0;j<vertices;j++){
					if(matriz[i][j]==1&&lista[i]==0){
						cola.push(i);
						lista[i]=i;
					}
				}
				for(int i=0;i<cola.size();i++){
					std::cout <<cola.front()<< '\n';
					cola.pop();
				}
			}
		}
		
	};
