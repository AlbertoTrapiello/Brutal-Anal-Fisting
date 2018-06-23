#include "Region.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;


Region::Region(string s)
{
	ifstream f("Regiones.txt", istream::in);
	string str;
	string aux;
	string aux1;
	char token;
	
	if (!f)
	{
		cout << "el fichero no se ha abierto correctamente" << endl;
		return;
	}
	else
	{

		do
		{

			getline(f, aux1);
			if (s == aux1)
			{
				z = new Zones*[1];
				getline(f, aux);
				lenght = 0;
				do
				{
					stringstream sstr;
					getline(f, aux, '(');
					getline(f, str);
					sstr << str;
					cout << "lenght=" << lenght << " aux:" << aux << " str:" << str;
					z[lenght] = new Zones;
					sstr >> z[lenght]->x1 >> z[lenght]->y1 >> z[lenght]->x2 >> z[lenght]->y2;
					cout << " x1:" << z[lenght]->x1 << " y1:" << z[lenght]->y1 << " x2:" << z[lenght]->x2 << " y2:" << z[lenght]->y2 << endl;
					lenght++;
				} while (aux != "end");
			}
		} while (token!=EOF);
		
	}
}


Region::~Region()
{
	for (int i = 0; i < lenght; i++)
		delete[] z[i];
	delete[]z;
}

