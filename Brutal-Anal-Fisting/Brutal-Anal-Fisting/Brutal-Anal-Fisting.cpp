// Brutal-Anal-Fisting.cpp: define el punto de entrada de la aplicación de consola.
//
#include <iostream>
#include "Mapita.h"


using namespace std;



int main()
{
	Mapita map;
	map.read_Dimacs("Mapa.txt");
	map.print();
	for (int i = 1; i <= map.nodes; i++)
	{
		map.find_neighbors(i);
	}
/*
	for (int i = 1; i <= map.nodes; i++)
		for (int j = 1; j <= map.nodes; j++)
			cout << "i = " << i << " j = " << j << " distance: " << map.find_distance(i, j) << endl;*/
	cout << "i = " << 3 << " j = " << 4 << " distance: " << map.find_distance(3, 4) << endl;
	system("PAUSE");
    return 0;
}

