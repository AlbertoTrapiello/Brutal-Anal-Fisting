#pragma once
#include "Recursos.h"

#define NUM_M�X_JUG 10

using namespace std;

enum Casas
{
	Stark=1, Tully=2, Arryn=3, Targaryen=4, Greyjoy=5, Lannister=6, Tyrrel=7, Baratheon=8, Martell=9
};

class Jugadores:protected Recursos
{
protected:
	Casas casa;
	string nombre;
	string titulo;
	//string vasallos;
public:
	Jugadores();//constructor por defecto
	Jugadores(int ataque, int comida, int oro, int diplomacia, int defensa, Casas casa, string nombre, string titulo):Recursos(ataque,comida,oro,diplomacia,defensa), casa(casa), nombre(nombre),titulo(titulo){}
	//constructor en el que se introducen los par�metros
	Jugadores (const Jugadores &); 
	ostream & print(ostream &);
	void read_file(Jugadores * );
	//virtual ~Jugadores();
	Casas stringtoCasas(string e);
	void set_Casa(Casas c) { casa = c; }
	void set_nombre(string s) { nombre = s; }
	void set_titulo(string t) { titulo = t; }
};


