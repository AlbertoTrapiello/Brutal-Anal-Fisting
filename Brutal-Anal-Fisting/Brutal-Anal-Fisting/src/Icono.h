#pragma once
#include "ETSIDI.h"


enum Casas
{
	Stark = 1, Tully = 2, Arryn = 3, Targaryen = 4, Greyjoy = 5, Lannister = 6, Tyrrel = 7, Baratheon = 8, Martell = 9
};


const char * get_name(int casa)
{
	switch (casa)
	{
	case Stark:
	{
		return "images/Iconos/Icono Stark";
		break;
	}
	case Tully:
	{
		return "images/Iconos/Icono Tully";
		break;
	}
	case Arryn:
	{
		return "images/Iconos/Icono Arryn";
		break;
	}
	case Targaryen:
	{
		return "images/Iconos/Icono Targaryen";
		break;
	}
	case Greyjoy:
	{
		return "images/Iconos/Icono Greyjoy";
		break;
	}
	case Lannister:
	{
		return "images/Iconos/Icono Lannister";
		break;
	}
	case Tyrrel:
	{
		return "images/Iconos/Icono Tyrell";
		break;
	}
	case Baratheon:
	{
		return "images/Iconos/Icono Baratheon";
		break;
	}
	case Martell:
	{
		return "images/Iconos/Icono Martell";
		break;
	}
	}
}


using namespace std;
using ETSIDI::SpriteSequence;
using namespace ETSIDI;

class Icono
{
	SpriteSequence icono;
public:
	Icono(int casa):icono(get_name(casa),1){}
};