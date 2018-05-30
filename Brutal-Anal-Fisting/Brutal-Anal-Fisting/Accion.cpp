#include "Accion.h"


ostream & Acción_Engine::operator<<(ostream & o)
{
	// TODO: insertar una instrucción return aquí
	return a->print_options();
}

ostream & Acción_Engine::print_options(ostream & o)
{
	// TODO: insertar una instrucción return aquí
	return a->print_options(o);
}

int Acción_Engine::get_option(istream & i)
{
	return a->get_option(i);
}

bool Acción_Engine::check(int option)
{
	return a->check(option);
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
			return o << "Seleccione región: \n 1) 2) 3) 4) 5) 6) 7) 8) 9) " << endl;
		}
	}
}

int Gestión_tropas::get_option(istream& i)
{
	int option;
	int distance = 1;//esta variable sobra, per simula que se pide distancia a la región que clacules, o lea la distancia a l a reión a atacar

	{
		switch (submenu)
		{
		case 1:
		{
				cout << "Seleccione el número de tropas" << endl;
				int troops;
				cin >> troops;
				cout << "¿Está seguro de su elección (Y/N)?" << endl;
				char token;
				cin >> token;
				switch (token)
				{
					case 'y':
					{
						return troops;
					}
					case 'n':
					{
						return 0;
					}
					default:
					{
						cout << "Error de respuesta" << endl;
						return 0;
					}
				}
				break;
		}
		case 2:
		{	
			i >> option;
			if (check(option))//si vale el país 
			{
				cout << "la acción tardará en efectuarse " << distance << " turnos.\n ¿Está seguro de que quiere realizar la acción (Y/N)?" << endl;
				char token;
				cin >> token;
				if (token == 'y')
					return option;
				else
					return 0;
			}
		}
		}
	}
	return option;
}
