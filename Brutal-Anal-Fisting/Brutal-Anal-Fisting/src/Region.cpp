#include "Region.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;


Region::Region()
{
	string str;
	stringstream sstr;
	ifstream f("Regiones.txt", istream::in);
	if (!f)
	{
		cout << "el fichero no se ha abierto correctamente" << endl;
		return;
	}
	else
	{
		z = new Zones*[1];
		do
		{
			lenght = 0;
			getline(f, str, ')');
			sstr << str;
			cout << str;
			z[lenght] = new Zones;
			sstr >> z[lenght]->x1 >> z[lenght]->y1 >> z[lenght]->x2 >> z[lenght]->y2;
			cout << z[lenght]->x1 << " " << z[lenght]->y1 << " " << z[lenght]->x2 << " " << z[lenght]->y2 << endl;
			lenght++;
		} while (str!="end");
	}
}

Region::~Region()
{
	for (int i = 0; i < lenght; i++)
		delete[] z[i];
	delete[]z;
}

