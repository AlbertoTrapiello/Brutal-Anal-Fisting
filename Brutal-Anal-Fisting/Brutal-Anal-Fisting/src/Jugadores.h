#pragma once
#include "Recursos.h"
#include "Region.h"
#include "ETSIDI.h"


#define NUM_MÁX_JUG 10


using namespace std;
using ETSIDI::SpriteSequence;
using namespace ETSIDI;

enum Casas
{
	Stark = 1, Tully = 2, Arryn = 3, Targaryen = 4, Greyjoy = 5, Lannister = 6, Tyrrel = 7, Baratheon = 8, Martell = 9
};


const char * Get_tit(int casa);

enum opc_menu 
{
	gest_tropas = 1, comercio = 2, Diplom = 3, mejorar = 4, Atacar = 5, Defender = 6, Generar_tropas = 7, Alianza = 8, Guerra = 9, Ataque = 10, Defensa = 11, Agricultura = 12
};



class Jugadores:protected Recursos
{
protected:

	Region region;
	Casas casa;
	string nombre;
	string titulo;
	SpriteSequence sprite, sprite_izq, sprite_dcha, arrow, arrow1,icono;
	int index;
	bool turno;
	bool IA;
	const char *S;
	char aux[25];
	bool relaciones[10];//Amistad=0. Enemistad=1
	//string vasallos;

public:

	Jugadores();//constructor por defecto
	Jugadores(int ataque, int comida, int oro, int diplomacia, int defensa, Casas casa, string nombre, string titulo):Recursos(ataque,comida,oro,diplomacia,defensa), casa(casa), nombre(nombre),titulo(titulo), sprite("images/sprite_GoT_recortado.png", 5, 7), sprite_izq("images/sprite_GoT_recortado.png", 5, 7), sprite_dcha("images/sprite_GoT_recortado.png", 5, 7), arrow("images/arrow.png", 1), arrow1("images/arrow_.png", 1), icono(Get_tit(casa),1)
	{
		for (int i = 0; i < 25; i++)
			aux[i] = ' ';
	}
	//constructor en el que se introducen los parámetros
	Jugadores (const Jugadores &); 
	bool is_IA() { return IA; }
	bool mi_turno() { return turno; }
	bool pseudo_IA();
	void set_turno() { turno = true; }
	ostream & print(ostream &o = cout);
	bool read_file(Jugadores * );
	//virtual ~Jugadores();
	Casas stringtoCasas(string e);
	void set_Casa(Casas c) { casa = c; }
	void set_nombre(string s) { nombre = s; }
	void set_titulo(string t) { titulo = t; }
	char * get_nombre();
	bool check_region(float x, float y);
	void dibuja(int dcha, int izq, Casas casa_dcha, Casas casa_izq);
	int getindex() { return index; }
	Casas getcasas() { return casa; }
	void Icon_hide() ;
	void Icon() ;
	friend class Gestion_tropas;
	friend class Diplomacia;
	friend class Comercio;
	friend class Mejorar;
	friend class Mundo;
};
