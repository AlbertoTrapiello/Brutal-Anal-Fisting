#pragma once
#define MAX_JUGADORES 10
#include "Jugadores.h"

class ListaJugadores
{
public:
	ListaJugadores();
	~ListaJugadores();
	Jugadores * lista[MAX_JUGADORES];
	int id;
};
