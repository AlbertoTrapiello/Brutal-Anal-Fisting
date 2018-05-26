#pragma once
#include "Jugadores.h"
#include "Recursos.h"
#include "Mapita.h"
#include "Regiones.h"

using namespace std;



class Mundo
{
	float x_ojo;
	float y_ojo;
	float z_ojo;
	Jugadores jug;
	//Mapita map;
	Regiones regi;
public:
	Mundo();
	Mundo(Jugadores jug) :jug(jug) {}
	//~Mundo();
	void tecla(unsigned char key);
	//void teclaEspecial(unsigned char key);
	//void inicializa();
	//void mueve();
	void dibuja();
};
