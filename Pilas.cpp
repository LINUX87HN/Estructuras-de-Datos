#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
class nodo {
	private:
   int valor;
   nodo *siguiente;
   friend class pila;
   public:
    nodo(int v, nodo *sig = NULL) {
       valor = v;
       siguiente = sig;
    }
};
typedef nodo *pnodo;
class pila {
   private:
    pnodo ultimo;//es el nodo que esta en la cima de la pila
   public:
    bool vacia()    {    return (ultimo==NULL); }
    pila(){ ultimo=NULL;}
    ~pila();
    void push(int v);
    int pop();
   };
   
void pila::push(int v) 
{
   pnodo nuevo;  // se crea el nodo
	 nuevo = new nodo(v); //se inicializa el valor
  nuevo->siguiente=ultimo;
   ultimo = nuevo;
}
int pila::pop() 
{
   if(vacia()) 
   {
   		return 0;		
   }
   pnodo nodo; //creamos un nodo temporal
   int v;      
   nodo = ultimo;
   ultimo = nodo->siguiente;
   v = nodo->valor; 
   delete nodo;
   return v;
}
pila::~pila(){
     while(vacia()==0) pop();
	 }

struct torre
{
   pila pilas;
   int num;// identificador de pila
};
void paso(int, torre*, torre*, torre* );

int main()
{/*
pila pila1;
pila1.push(5);
pila1.push(1);
pila1.push(2);
cout<<pila1.pop()<<endl;
cout<<pila1.pop()<<endl;
cout<<pila1.pop()<<endl;*/
torre torre1,torre2,torre3;
torre1.num=1;
torre2.num=2;
torre3.num=3;
int D=4;
for(int i=D;i>=1;i--)
   torre1.pilas.push(i);
paso(D,&torre1,&torre2,&torre3);

while (!torre3.pilas.vacia())
{
cout<<"torre 3 valor"<<torre3.pilas.pop()<<endl;
}

	return 0;	
}





int mov=0;
void paso(int disco, torre* O, torre* A , torre*D )
{
if (disco==1)
{
   D->pilas.push(O->pilas.pop());
cout<<++mov <<"mueve de la torre"<<O->num<<"mueve de la torre"<<D->num<<endl;
}
else
{
   paso(disco-1,O,D,A);
   D->pilas.push(O->pilas.pop());
   cout<<++mov <<"mueve de la torre"<<O->num<<"mueve de la torre"<<D->num<<endl;
   paso(disco-1,A,O,D);
}
}