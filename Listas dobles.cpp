	#include <iostream>
using namespace std;
class nodo_doble {
   public:
    nodo_doble(int v, nodo_doble *sig = NULL,nodo_doble *ant = NULL) {//inicializa el nodo con el valor v y el puntero a null. 
       valor = v;
       siguiente = sig;
       anterior =ant;
    }
   private:
   int valor;
   nodo_doble *siguiente;
   nodo_doble *anterior;
   friend class lista_doble;
};
typedef nodo_doble *pnodo_doble;
class lista_doble {
   private:
		pnodo_doble primero;
   public:
	    lista_doble() 
		{
			primero=NULL;
			}
    ~lista_doble();
        void borrar_vref(int vref);
		void imprime();
		void ins_primero(int v);
		 void imp_ant_sig( int vref);//imprime el anterio y el siguiente valor de un nodo.
   };
lista_doble::~lista_doble() {
	pnodo_doble T,Q=primero;	
   while(Q!=NULL) 
   {
   	T=Q;
   	Q=Q->siguiente;
   	delete T;
   }
}

void lista_doble::ins_primero(int v) 
{
   pnodo_doble nuevo; //creamos el apuntado a nodo nuevo.
   nuevo = new nodo_doble(v);// inicialiazmo el apuntador con un valor v
   nuevo->siguiente=primero; // hacemos que el nuevo nodo apunte al primero.
   if(primero!=NULL)   primero->anterior = nuevo; // si la lista no esta vacia el primer nodo apunta a l nuevo
primero=nuevo;
}













void lista_doble::borrar_vref( int vref)
{
	if (primero!=NULL)
{
		pnodo_doble Q,T;
		bool band=1;
		Q=primero;
		while(Q->valor!=vref && band==1)
		{
		if(Q->siguiente!=NULL)
		{
			T=Q;
			Q=Q->siguiente;
		}
		else
			band=0;
		}
	if(band==0)
	{
	
		cout<<"No se encontro el valor "<<vref<<endl;
		return ;
	}
	else 
	{
		if(Q==primero)
		{
		
			primero=Q->siguiente;
			if(Q->siguiente!=NULL)
			Q->siguiente->anterior=NULL;
		}
		else if(Q->siguiente!=NULL)
		{
		
			T->siguiente=Q->siguiente;
			Q->siguiente->anterior=T;
	}
	else T->siguiente=NULL;	
	}
	delete Q;	
}
	else
	cout<<"Lista vacia"<<endl;
	}
 
 
 void lista_doble::imp_ant_sig( int vref)
{
	if (primero!=NULL)
{
		pnodo_doble Q;
		bool band=1;
		Q=primero;
		while(Q->valor!=vref && band==1)
		{
		if(Q->siguiente!=NULL)
		{
			Q=Q->siguiente;
		}
		else
			band=0;
		}
	if(band==0)
		cout<<"No se encontro el valor "<<vref<<endl;
	else 
	{
		if(Q==primero) cout<<"P->"<<Q->valor<<"->"<<Q->siguiente->valor<<"<->..."<<endl;		
		else if(Q->siguiente==NULL) cout<<"...<->"<<Q->anterior->valor<<"->"<<Q->valor<<"->NULL"<<endl;		
		else  cout<<"...<->"<<Q->anterior->valor<<"->"<<Q->valor<<"<->"<<Q->siguiente->valor<<"->..."<<endl;
	}	
}
	else
	cout<<"Lista vacia"<<endl;
	}
 
 
 
 
 
 
int main() 
{
lista_doble listad1;
listad1.imprime();
listad1.ins_primero(1);
listad1.ins_primero(2);
listad1.ins_primero(3);
listad1.ins_primero(4);

lista1.imprime();
   return 0;
}  



void lista_doble::imprime()
{
   pnodo_doble Q1;
    
   if(primero!=NULL)
	{
	   Q1=primero;

		   cout<<"Primero->"<<Q1->valor;
	   while(Q1->siguiente!=NULL)
	   {
	   		Q1=Q1->siguiente;
	   		if (Q1->siguiente==NULL || Q1==primero)
	   			cout<<"<->"<<Q1->valor<<"->NULL"<<endl;
   			else
   				cout<<"<->"<<Q1->valor;
  		}
	}
	else
		cout<<"LISTA  VACIA"<<endl;
}





