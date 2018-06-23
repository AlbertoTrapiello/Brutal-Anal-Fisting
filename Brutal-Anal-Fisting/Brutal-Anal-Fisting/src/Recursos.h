#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

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
	Recursos(int ataque, int comida, int oro, int diplomacia, int defensa) :ataque(ataque), comida(comida), oro(oro), diplomacia(diplomacia), defensa(defensa) {}
	//virtual ~Recursos();
	virtual ostream & print(ostream&);
	virtual void read_file();
	friend class Gestion_tropas;
	friend class Comercio;
	friend class Diplomacia;
	friend class Mejorar;
};

enum tropas
{
	arquero = 1, caballero = 2, mago = 5, especial = 10
};