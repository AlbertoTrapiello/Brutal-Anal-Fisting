#pragma once
#include "Mundo.h"




class Turno
{


public:
	static const char * dibuja(Mundo *world);
	static void teclado(Mundo *world, unsigned char key);
	static void raton(Mundo *world, float x, float y);
	static void acciones(Mundo * world);
};