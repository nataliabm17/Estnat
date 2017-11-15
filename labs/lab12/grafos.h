#include<string>
#include<iostream>
#include<vector>
#include <queue>
#include <cstdlib>
#include <utility>
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

		void edge(int v1, int v2, int peso){
			matriz[v1][v2]=peso;
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

	vector< vector<int> > caminoCorto(int vertice){

			queue<int> q;
			vector < vector<int> > tabla;
			tabla.resize(matriz.size());
			for(int i=0;i<matriz.size();i++){
				tabla[i].resize(3,-1);
			}
			q.push(vertice);
			tabla[vertice][1]=0;
			while(!q.empty()){
				int v = q.front();
				q.pop();
				for(int j=0;j<matriz.size();j++){
					if(matriz[v][j]==1){
						if(tabla[j][1]==-1){
							tabla[j][1]=tabla[v][1]+1;
							tabla[j][2]=v;
							q.push(j);
						}
					}
				}
			}
			return tabla;
		}

		vector< vector<int> > caminoCortoPeso(int vertice){
				priority_queue<pair<int,int> , vector<pair<int,int> >, greater<pair<int,int> > > q;
				vector < vector<int> > tabla;
				tabla.resize(matriz.size());
				for(int i=0;i<matriz.size();i++){
					tabla[i].resize(3,-1);
				}
				pair< int,int> p = make_pair(0,vertice);
				q.push(p);
				tabla[vertice][1]=0;
				while(!q.empty()){

					pair<int,int> v = q.top();
					q.pop();
					for(int j=0;j<matriz.size();j++){
						int distance = matriz[v.second][j] + v.first;
						if(matriz[v.second][j]!=0){
							if(tabla[j][1]>distance||tabla[j][1]==-1){
								tabla[j][1]=distance;
								tabla[j][2]=v.second;
								q.push(make_pair(distance,j));
							}
						}
					}
				}
				return tabla;
			}


	};
