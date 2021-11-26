import networkx as nx
import matplotlib.pyplot as plt
from numpy.lib.function_base import append, insert
from numpy.matrixlib import matrix
# hacer un grafo 
G=nx.Graph()
#insertar un nodo
G.add_node("A")
G.add_node("B")
G.add_node("C")
G.add_node("D")
#insertar una arista
G.add_edge("A","B")
G.add_edge("C","B")
G.add_edge("A","D")
G.add_edge("A","C")
#Contar y listar los nodos

print ("los nodos", G.nodes(), G.number_of_nodes())  
print("las aristas", G.edges(), G.number_of_edges())
#Verificar si son adyacentes
print(G.has_edge("A","B"))
print(G.has_edge("C","B"))


#Grafo completo
G2= nx.Graph()
k=10
for i in range(0,k):
    G2.add_node(i)
for i in range(0,k):
    for j in range(0,k):
        if(i<j):
            G2.add_edge(i,j)
#nx.draw(G2)
print(G2.edges)
##plt.show()
G3=nx.complete_graph(5)

#nx.draw(G3)
#plt.show()
#circuito cerrado
G4=nx.Graph()
for i in range(0,10):
    G4.add_node(i)
for i in range(0,10):
    G4.add_edge(i,i+1)
G4.add_edge( 10,0)
#Graficar un grafo
#nx.draw(G4)
##plt.show()

# como dibujar un digrafo

Gdir=nx.DiGraph() 
nodos=["a","b","c","d","e"] # inserta nodos de una lista
Gdir.add_nodes_from(nodos)
Gdir.add_edge("a","b")
Gdir.add_edge("b","a")
Gdir.add_edge("c","b")
Gdir.add_edge("b","e")
Gdir.add_edge("a","e")
Gdir.add_edge("e","a")
#nx.draw(Gdir)
print(Gdir.has_edge("a","b"))
print(Gdir.has_edge("b","a"))
print(Gdir.has_edge("c","b"))
print(Gdir.has_edge("b","c"))
print(Gdir.has_edge("e","c"))
#plt.show()
#Grafo aleatorio
import random
Grandom=nx.Graph()
n=100
p=.5
for i in range(n+1):
    Grandom.add_node(i)

for i in range(n+1):
    for j in range(i):
        if(random.random()<p):
            Grandom.add_edge(i,j)
nx.draw(Grandom)
plt.show()
# distrubucion  de grado de un grafo.
grados=[]
for nodo in Grandom.nodes:
    grados.append(Grandom.degree(nodo))
print(grados)
plt.hist(grados)#grafica un histograma a partir de una lista de datos.
plt.show()



