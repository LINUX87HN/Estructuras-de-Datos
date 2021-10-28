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
    private:
    pnodo primero;
public:
    lista()
    {
        primero=NULL;
    }
~lista();
void insert_inicio(int v);
bool esvacia();
void ins_final(int v);
void borrar_primero();
void borrar_final();
void Imprime();
void borrar_vref(int vref);
void ins_lista_n(int , int);
};
lista::~lista()
{
    pnodo T,Q=primero;
    while(Q!=NULL)
    {
        T=Q;
        Q=Q->siguiente;
        delete T;
    }
}

void lista::insert_inicio(int v)
{
    pnodo nuevo;
    nuevo= new  nodo(v, primero );
    primero=nuevo;
}

bool lista::esvacia()
{
return primero==NULL;    
}

int main()
{

lista lista1;/// se ha creado la lista vacia

for(int i=0;i<10;i++)
{
    lista1.insert_inicio(i);
}
lista1.Imprime();

lista lista2;
if(lista2.esvacia())
    cout<<"lista 2 esta vacia";
    return 0;
}





void lista::Imprime()
{
 if( !esvacia())
 {
     pnodo Q=primero;
     cout<<"Primero->"<<Q->valor;
    while(Q->siguiente!=NULL )
    {
        Q=Q->siguiente;
        if(Q->siguiente==NULL || Q==primero)
             cout<<"->"<<Q->valor<<"->NULL"<<endl;
        else
             cout<<"->"<<Q->valor;
    }
 }
 else
 cout<<"La lista esta vacia";

}


