#ifndef MATRIZ_H
#define MATRIZ_H
/*******************************************************************************/
class C_matriz
{
public:
C_matriz(int=1, int=1);
//parámetros por defecto, estos son fila, columna
C_matriz(const C_matriz &);
//constructor de copia
~C_matriz();
float get(int fila, int columna) const;
 //retorna un elemento de la matriz

void set(int fila, int columna ,float dato); //graba un elemento en una posición de la  matriz
private:
int filas;
int columnas;
float *ptr_data;
};
/*********************************************************************************/
#endif
