#pragma once
//HCER AQUÍ GESTIÓN DE GRAFOS QUE SE ENCARGUE DE VECINDADES ENTRE REGIONES ADYACENTES
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Mapita
{
	//bool vecinos[10][10];
	const int graph[10][10]= 
	{
		{ 0, 1, 2, 0, 3, 0, 0, 0, 0, 0 },
		{ 1, 0, 1, 0, 2, 1, 4, 2, 0, 3 },
		{ 2, 1, 0, 3, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 3, 0, 0, 0, 0, 3, 0, 2 },
		{ 3, 2, 0, 0, 0, 2, 4, 0, 0, 0 },
		{ 0, 1, 0, 0, 2, 0, 1, 0, 0, 0 },
		{ 0, 4, 0, 0, 4, 1, 0, 3, 2, 4 },
		{ 0, 2, 0, 3, 0, 0, 3, 0, 1, 1 },
		{ 0, 0, 0, 0, 0, 0, 2, 1, 0, 0 },
		{ 0, 3, 0, 2, 0, 0, 4, 1, 0, 0 }
	};
	int dist[10];//VECTOR DE SALIDA. dist[i]--> Minima distancia desde la fuente hasta i  
	int nodos[10];//nodos por los que se pasa hasta llegar al destino desde el origen
	bool sptSet[10];// sptSet[i] será true si el nodo i está incluido en el SPT o si la distancia más corta desde el origen (src) hasta i se ha terminado
	int  src;//nodo de origen
	int destino;//nodo de destino
//	ETSIDI::Vector2D posicion;
public:
	Mapita();
	Mapita(int src, int destino) :src(src), destino(destino) {
		for (int i = 0; i < 10; i++)// Inicializar todas las distancias como infintas y stpSet[] a false 
		{
			dist[i] = INT_MAX, sptSet[i] = false, nodos[i] = 0;//posibilidad de utilizar memoria dinamica para nodos
		}
	}
	int minDistance(int dist[], bool sptSet[]);//funcion auxiliar para hallar el vértice con la minima distancia desde los vértices no incluidos en en el SPT(shortest path tree)
	void printSolution(int n, int dist[], int nodos[], int destino);//función de impresión de las distancias 
	void dijkstra();//mediante esta funcion se implementa el algoritmo de Dijkstra con la matriz de adyacencia
	/*bool** read_Dimacs(string);
	void erase();
	void create();
	int * find_neighbors(int id);
	void erase_neighbors();
	ostream& print(ostream& o = cout);*/
	friend class Mundo;
};

