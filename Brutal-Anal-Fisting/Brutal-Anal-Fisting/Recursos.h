#pragma once
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "glut.h"
#include "ETSIDI.h"

using namespace std;

class Recursos
{
protected:	
	int ataque;
	int comida;
	int oro;
	int diplomacia;
	int defensa;
public:
	Recursos();//valores por defecto igual a 0.
	Recursos(int ataque, int comida, int oro, int diplomacia, int defensa):ataque(ataque), comida(comida), oro(oro), diplomacia(diplomacia), defensa(defensa){}
	//virtual ~Recursos();
	ostream & print(ostream&);
	void read_file();
};

enum tropas
{
	arquero=1, caballero=2, mago=5, especial=10
};