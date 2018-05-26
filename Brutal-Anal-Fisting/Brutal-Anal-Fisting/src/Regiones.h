#pragma once
#include <sstream>
#include <string>
#include <vector>


using namespace std;



enum Zonas
{
	North = 1, Riverrun = 2, Valley = 3, Pentos = 4, Iron_Islands = 5, Casterly_Rock = 6, Highgarden = 7, Stormlands = 8, Dorne = 9, Iron_throne = 10
};

class Regiones
{
protected:
	Zonas reg;
public:
	Regiones();
	Regiones(Zonas reg) :reg(reg) {}
	Zonas stringtoRegion(string);
	void draw();
	//virtual void leer_file()=0;//funcion virtual pura--> Clase Abstracta
	//virtual ostream & print(ostream&)=0;//funcion virtual pura--> Clase Abstracta
};


