#pragma once
#include "Jugadores.h"
#include "Mundo.h"



class Turno: public Mundo
{
	int pos;
	int idr;
public:
	Turno();
	void dibuja(int idr);
	
	void teclado();
};