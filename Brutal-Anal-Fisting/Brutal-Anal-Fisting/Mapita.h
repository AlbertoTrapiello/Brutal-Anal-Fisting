#pragma once
//HCER AQUÍ GESTIÓN DE GRAFOS QUE SE ENCARGUE DE VECINDADES ENTRE REGIONES ADYACENTES
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


class Mapita
{
public:
	bool** vecinos;
	int* neighbors;
	int edges;	
	int nodes;
	int n_neighbors;//numero de vecinos que tiene cada uno de los jugadores, se actualiza al usar find_neighbor
	Mapita();
	~Mapita();
	bool** read_Dimacs(string);
	void erase();
	void create();
	int * find_neighbors (int id);
	void erase_neighbors();
	ostream& print(ostream& o = cout);
	int find_distance(int id, int id2, int start=1);

};

