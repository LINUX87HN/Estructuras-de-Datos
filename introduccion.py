import networkx as nx
import matplotlib.pyplot as plt
from networkx.algorithms.cluster import triangles
from networkx.classes.function import edges
from networkx.classes.graph import Graph
from networkx.convert_matrix import from_numpy_matrix
from numpy.lib.function_base import append, insert
from numpy.matrixlib import matrix
import numpy as np

def matrixadj( G1=nx.Graph() ):
    n=len(G1.nodes())
    m=np.array(np.zeros(n*n).reshape(n,n))
    for arista in G1.edges:
        m[arista[0],arista[1]]=1
    return np.array(m)

A = np.array([[0,1,1],[0,0,1],[1,0,0]])
#A = np.array([[1,0,0],[0,1,0],[0,0,1]])
print(A)
G=nx.from_numpy_array(A)
#nx.draw(G)
plt.show()


#plt.show()

# hacer un grafo 
G=nx.Graph()
#insertar un nodo
G.add_node("A")
G.add_node("B")
G.add_node("C")
G.add_node("D")
G.add_node("F")
G.add_node("H")

#insertar una arista
G.add_edge("A","B")
G.add_edge("C","B")
G.add_edge("A","D")
G.add_edge("H","B")
G.add_edge("H","D")
G.add_edge("C","F")
G.add_edge("F","D")

#Contar y listar los nodos

nx.draw(G,with_labels=True)
plt.show()
#print ("los nodos", G.nodes(), G.number_of_nodes())  
#print("las aristas", G.edges(), G.number_of_edges())
#Verificar si son adyacentes
#print(G.has_edge("A","B"))
#print(G.has_edge("C","B"))




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
#print(G2.edges)
##plt.show()





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
Gdir.add_edge("d","a")
nx.draw(Gdir,with_labels=True)
plt.show()
print(nx.dijkstra_path(Gdir,"a","e"))
print(nx.dijkstra_path(Gdir,"a","d"))

print(nx.dijkstra_path_length(Gdir,"a","e"))
print(nx.dijkstra_path_length(Gdir,"c","e"))
print(nx.dijkstra_path_length(Gdir,"e","d"))
#print(nx.dijkstra_predecessor_and_distance(Gdir,"a"))
print( matrixadj(Gdir))

#print(Gdir.has_edge("a","b"))
#print(Gdir.has_edge("b","a"))
#print(Gdir.has_edge("c","b"))
#print(Gdir.has_edge("b","c"))
#print(Gdir.has_edge("e","c"))

#Grafo aleatorio
import random
Grandom=nx.Graph()
n=4
p=.9
for i in range(n+1):
    Grandom.add_node(i)

for i in range(n+1):
    for j in range(i):
        if(random.random()<p):
            Grandom.add_edge(i,j)
nx.draw(G,with_labels =True)

print("matriz adj",matrixadj(Grandom))
plt.show()

#print( G2.edges)
G3=nx.complete_graph(3)
print( matrixadj(G3))







#plt.show()
# distrubucion  de grado de un grafo.
grados=[]
for nodo in Grandom.nodes:
    grados.append(Grandom.degree(nodo))
#print(grados)
plt.hist(grados)#grafica un histograma a partir de una lista de datos.
#plt.show()



