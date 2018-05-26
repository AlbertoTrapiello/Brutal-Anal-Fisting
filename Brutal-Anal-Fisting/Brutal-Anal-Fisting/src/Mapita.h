#pragma once
//HCER AQUÍ GESTIÓN DE GRAFOS QUE SE ENCARGUE DE VECINDADES ENTRE REGIONES ADYACENTES
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Mapita
{
	bool** vecinos;
	int* neighbors;
	int edges;
	int nodes;
//	ETSIDI::Vector2D posicion;
public:
	bool** read_Dimacs(string);
	void erase();
	void create();
	int * find_neighbors(int id);
	void erase_neighbors();
	ostream& print(ostream& o = cout);
	friend class Mundo;
};

