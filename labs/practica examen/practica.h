#include "pila.h"

template <typename T>
class C_cola2{
	protected:
		C_pila<int> p1;
		C_pila<int> p2;
	public:
		C_cola2(void){
			p1 = p1;
			p2 = p2;
		}
		~C_cola2(void){
		}

		void agregar(int numero){
			if(p1.count()==0&&p2.count()==0){
				p1.agregar(numero);
			}
			else{
				if(p1.count()==0){
					while(p2.count()!=0){
						p2.agregar(p2.quitar());
					}
					p1.agregar(numero);
					while(p1.count()!=0){
						p2.agregar(p1.quitar());
					}
				}
				else{
					if(p2.count()==0){
						while(p1.count()!=0){
							p2.agregar(p1.quitar());
						}
						p2.agregar(numero);
						while(p2.count()!=0){
							p1.agregar(p2.quitar());
						}
					}
				}
			}
		}
		int quitar(void){
			if(p1.count()!=0){
				return p1.quitar();
			}
			else{
				return p2.quitar();
			}
		}
};
/*
void C_cola::agregar(int numero){
	if(p1.count()==0&&p2.count()==0){
		p1.agregar(numero);
	}
	else{
		if(p1.count()==0){
			while(p2.count()!=0){
				p2.agregar(p2.quitar(0));
			}
			p1.agregar(numero)
			while(p1.count()!=0){
				p2.agregar(p1.quitar());
			}
		}
		else{
			if(p2.count()==0){
				while(p1.count()!=0){
					p2.agregar(p1.quitar(0));
				}
				p2.agregar(numero)
				while(p2.count()!=0){
					p1.agregar(p2.quitar());
				}
			}
		}
	}
}

int C_cola::quitar(void){
	if(p1.count()!=0){
		return p1.quitar();
	}
	else{
		return p2.quitar();
	}
}*/
