#include "Accion.h"


ostream & Acci�n_Engine::operator<<(ostream & o)
{
	// TODO: insertar una instrucci�n return aqu�
	return a->print_options();
}

ostream & Gesti�n_tropas::print_options(ostream & o)
{
	// TODO: insertar una instrucci�n return aqu�
	switch (submenu)
	{		
	case1:
		{
			return o << "1) Atacar\n 2) Defender" << endl;
		}

	case2:
		{
			return o << "Seleccione regi�n " << endl;
		}
	}
}

int Gesti�n_tropas::get_option(istream& i)
{
	int option;

	{
		switch (submenu)
		{
		case 1:
		{	
			i >> option;
			if (Gesti�nTropas::check())//si vale el pa�s 
			{

			}
		}
		}
	}
	return option;
}
