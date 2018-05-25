#include "Accion.h"


ostream & Acción_Engine::operator<<(ostream & o)
{
	// TODO: insertar una instrucción return aquí
	return a->print_options();
}

ostream & Gestión_tropas::print_options(ostream & o)
{
	// TODO: insertar una instrucción return aquí
	switch (submenu)
	{		
	case1:
		{
			return o << "1) Atacar\n 2) Defender" << endl;
		}

	case2:
		{
			return o << "Seleccione región " << endl;
		}
	}
}

int Gestión_tropas::get_option(istream& i)
{
	int option;

	{
		switch (submenu)
		{
		case 1:
		{	
			i >> option;
			if (GestiónTropas::check())//si vale el país 
			{

			}
		}
		}
	}
	return option;
}
