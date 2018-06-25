#include "Region.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;


Region::Region()
{
}


Region::~Region()
{
	if (z != NULL)
	{
		for (int i = 0; i < lenght; i++)
			delete[] z[i];
		delete[] z;
	}
}

void Region::read_file(std::string s)
{
	ifstream f("Regiones.txt", istream::in);
	string str;
	string aux;
	string aux1;

	if (!f)
	{
		cout << "el fichero no se ha abierto correctamente" << endl;
		return;
	}
	else
	{

		while (!f.eof())
		{
			getline(f, aux1);
			if (s == aux1)
			{
				stringstream sstr1;
				getline(f, aux1);
				sstr1 << aux1;
				sstr1>>lenght;
				z = new Zones*[1];
				for(int i=0; i<lenght;i++)
				{
					
					stringstream sstr;
					getline(f, str);
					
					sstr << str;
					cout << "lenght=" << lenght << " str:" << str;
					z[i] = new Zones;
					sstr >> z[i]->x1 >> z[i]->y1 >> z[i]->x2 >> z[i]->y2;
					cout << " x1:" << z[i]->x1 << " y1:" << z[i]->y1 << " x2:" << z[i]->x2 << " y2:" << z[i]->y2 << endl;
				}
			}
			
		}
		f.close();
	}
}


float menor(const float& lhs, const float& rhs)
{
	if (rhs == lhs)
		return -1;
	if (lhs < rhs)
		return lhs;
	else
		return rhs;
}
float mayor(const float& lhs, const float& rhs)
{
	if (rhs == lhs)
		return -1;
	if (lhs > rhs)
		return lhs;
	else
		return rhs;
}

bool Region::is_in(float x, float y)
{
	for (int i = 0; i < lenght; i++)
	{
		if ((x<menor(z[i]->x1,z[i]->x2) && x>mayor(z[i]->x1, z[i]->x2)) && (y<menor(z[i]->y1, z[i]->y2) && y>mayor(z[i]->y1, z[i]->y2)))
			return true;
	}
	return false;
}
