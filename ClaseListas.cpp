	#include <iostream>
using namespace std;

class nodo{
public:
//constructor
nodo(int v, nodo *sig=NULL)
{
    valor=v;
    siguiente=sig;
}
private:
    int valor;
    nodo *siguiente;
    friend class lista;
};
typedef nodo *pnodo;
class lista{
public:
    lista()
    {
        primero=NULL;
    }
~lista();
void ins_primero(int v);
void ins_final(int v);
void borrar_primero();
void borrar_final();
void imprime();
void borrar_vref(int vref);
void ins_lista_n(int , int)
private:
    pnodo primero;
};
int main()
{
 

    

    return 0;
}