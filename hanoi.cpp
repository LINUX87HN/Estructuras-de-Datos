#include <iostream>
using namespace std;
class nodo {
	private:
   int valor;
   nodo *siguiente;
   friend class pila;
   public:
    nodo(int v, nodo *sig = NULL) {//inicializa el nodo con el valor v y el puntero a null. 
       valor = v;
       siguiente = sig;
    }
};
typedef nodo *pnodo;
class pila {
   private:
    pnodo ultimo;
    bool vacia()
    {
    	if(ultimo==NULL)
    	return 1;
    	else
    	return 0;
    }
   public:
    pila()
	 {
	 ultimo=NULL; 
	 }
    ~pila();
    void push(int v);
    int pop();
   };
   
void pila::push(int v) 
{

   pnodo nuevo; 
   /* Crear un nodo nuevo */
   nuevo = new nodo(v, ultimo);
   /* Ahora, el comienzo de nuestra pila es en nuevo nodo */
   ultimo = nuevo;
}

int pila::pop() 
{
   if(vacia()==1) 
   {
   		return 0;
   }
   
   pnodo nodo; /* variable auxiliar para manipular nodo */
   int v;      /* variable auxiliar para retorno */
    /* Si no hay nodos en la pila retornamos 0 */
   /* Nodo apunta al primer elemento de la pila */
   nodo = ultimo;
   /* Asignamos a pila toda la pila menos el primer elemento */
   ultimo = nodo->siguiente;
   /* Guardamos el valor de retorno */
   v = nodo->valor; 
   /* Borrar el nodo */
   delete nodo;
   return v;
}

pila::~pila(){
     while(vacia()==0) pop();
	 }

	struct torre
	{
	pila pilas;
	int num;
	};


void Paso(int , torre* , torre* , torre* );
int main() 
{

  torre torre1,torre2,torre3;
	  torre1.num=1;
      torre2.num=2;
      torre3.num=3;
  int D=5;
  //cin>>D;
   for (int i=D; i>=1;i-- )
   {
     torre1.pilas.push(i);
    }
   Paso(D,&torre1,&torre2, &torre3);
	 for (int i=D; i>=1;i-- )
   {
  cout<<"torre 3 valor"<<i<<"= "<<torre3.pilas.pop()<<endl;
    }	 
     return 0;
   }
int mov=0;
void Paso(int disco , torre* O,torre* A, torre* D)
{
	
if (disco==1)
	{	   
		D->pilas.push(O->pilas.pop());
		cout<<++mov <<"/tmueve de la torre"<<O->num<<"mueve de la torre"<<D->num<<endl;
	}
		else
		{
	Paso(disco-1, O ,D, A);	
	D->pilas.push(O->pilas.pop());
	cout<<++mov<<"/tmueve de la torre"<<O->num<<"mueve de la torre"<<D->num<<endl;
	Paso(disco-1, A, O,D);	
}
}    

