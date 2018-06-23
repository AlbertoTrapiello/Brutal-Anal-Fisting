#pragma once
#include "Recursos.h"
#include "Regiones.h"

using namespace std;

enum Casas
{
	Stark = 1, Tully = 2, Arryn = 3, Targaryen = 4, Greyjoy = 5, Lannister = 6, Tyrrel = 7, Baratheon = 8, Martell = 9
};

class Jugadores :protected Recursos, Regiones
{
protected:
	Casas casa;
	string nombre;
	string titulo;
	//string vasallos;
public:
	Jugadores();//constructor por defecto
	Jugadores(Zonas reg, int ataque, int comida, int oro, int diplomacia, int defensa, Casas casa, string nombre, string titulo) :Regiones(reg), Recursos(ataque, comida, oro, diplomacia, defensa), casa(casa), nombre(nombre), titulo(titulo) {}
	//constructor en el que se introducen los parámetros
	Jugadores(const Jugadores &);
	ostream & print(ostream &);
	void read_file();
	//virtual ~Jugadores();
	Casas stringtoCasas(string e);
};