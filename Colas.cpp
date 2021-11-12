#include <iostream>
#include <ctime>
using namespace std;
class nodo
{
public:
    nodo(int v, nodo *sig = NULL)
    {
        valor = v;
        siguiente = sig;
    }
private:
    int valor;
    nodo *siguiente;
    friend class cola;
};
typedef nodo *pnodo;
class cola
{
private:
    pnodo ultimo;
    pnodo primero;

public:
    cola() : ultimo(NULL), primero(NULL) {}
    ~cola();
    void Push(int v);
    bool esvacia();
    int maximo;
    int Pop();
    void vaciar();// vacia e imprime los datos de una cola
};
void cola::vaciar()
{
    while(!esvacia())
        cout<<Pop()<<"\t";
        
        cout<<endl;
}
bool cola::esvacia()
{
   //  cout<<"primero"<<primero<<' '<<"segundo"<<ultimo<<endl;
    return (primero == NULL && ultimo == NULL);
}
cola::~cola()
{
    while (!esvacia())
        Pop();
}
void cola::Push(int v)
{
    pnodo nuevo;
    nuevo = new nodo(v);
    if (ultimo != NULL) //HAY MAS NODOS
    {
        ultimo->siguiente = nuevo;
    }
    ultimo = nuevo;
    if (primero == NULL)
        primero = nuevo;
}
int cola::Pop()
{
    if (esvacia())
    {  
        return 0;
    }
    else
    {
        pnodo nodo;
        int v;
        nodo = primero;
        primero = nodo->siguiente;
        v = nodo->valor;
        delete nodo;       
        if (primero==NULL) // por si la cola queda vacia
        {
             ultimo = NULL;
        }      
        return v;
    }
}
int main()
{
   // cola a, b;
//Utilice la clase colas para: Escribir un programa en el que se generen 100 n´umeros aleatorios en el rango –25 ..
//+25 y se guarden en una cola. Una vez creada la cola, haga una funcion que forme otra cola con los n´umeros
//negativos que tiene la cola original e imprimala.
/*
srand(time(0));
for(int i=0;i<100;i++)
    a.Push(rand()%51-25);
int temp;
    for(int i=0;i<100;i++)
    {      
          temp=a.Pop();
        if(temp<0)
        {
            b.Push(temp);
        }
           else
           a.Push(temp); 
    }
       b.vaciar();    

*/
cola a,b,c;
// codigo para iniciar los valores de las colas para que queden de mayor a  menor
cout<<"valores de la cola a"<<endl;
for(int i=10; i>0;i=i-1)
    a.Push(i);
cout<<"valores de la cola b"<<endl;
for(int i=20;i>4;i=i-2)
    b.Push(i);

int temp1,temp2;

   temp1=a.Pop();
    temp2=b.Pop();
while( !(a.esvacia()) && !(b.esvacia())) // el ciclo funciona hasta que una de las 2 colas este vacia
{
    if(temp1==temp2)
    {
        cout<<temp1<<' '<<temp2<<endl;;
         c.Push(temp1);
        c.Push(temp2);
        if(!a.esvacia()) temp1=a.Pop();
        if(!b.esvacia()) temp2=b.Pop();//se actualizan los valores temporales
    }
    else if (temp1>temp2)
    {
        cout<<temp1<<' '<<temp2<<endl;;
        c.Push(temp1);
        if(!a.esvacia()) temp1=a.Pop();
    }
    else// temp2>temp1
    {
        cout<<temp1<<' '<<temp2<<endl;;
        c.Push(temp2);
         if(!b.esvacia()) temp2=b.Pop();
    }
}
//terminamos de insertar los valores restantes de una las colas en la cola C
while(!a.esvacia())
    c.Push(a.Pop());
while(!b.esvacia())
    c.Push(b.Pop());
cout<<"Los valores de la cola C son"<<endl;
c.vaciar();





    /*
    a.Push(5);
    a.Push(3);
    a.Push(4);
    a.Push(1);
    cout << "sacamos un dato de la cola" << a.Pop() << endl;
    cout << "sacamos un dato de la cola" << a.Pop() << endl;
    cout << "sacamos un dato de la cola" << a.Pop() << endl;
    cout << "sacamos un dato de la cola" << a.Pop() << endl;
    cout << "sacamos un dato de la cola" << a.Pop() << endl;*/
}