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
    bool vacia()
    {
    	if(ultimo==NULL)// esta vacia
    	return 1;
    	else
    	return 0;
    }
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
  //nuevo->valor=v; 
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
int main()
{
pila pila1;


pila1.push(5);
pila1.push(1);
pila1.push(2);
cout<<pila1.pop()<<endl;
cout<<pila1.pop()<<endl;
cout<<pila1.pop()<<endl;


	return 0;	
}

