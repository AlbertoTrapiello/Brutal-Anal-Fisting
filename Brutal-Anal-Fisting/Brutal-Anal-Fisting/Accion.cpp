#include "Accion.h"


ostream & Acci�n_Engine::operator<<(ostream & o)
{
	// TODO: insertar una instrucci�n return aqu�
	return a->print_options();
}

ostream & Acci�n_Engine::print_options(ostream & o)
{
	// TODO: insertar una instrucci�n return aqu�
	return a->print_options(o);
}

int Acci�n_Engine::get_option(istream & i)
{
	return a->get_option(i);
}

bool Acci�n_Engine::check(int option)
{
	return a->check(option);
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
			return o << "Seleccione regi�n: \n 1) 2) 3) 4) 5) 6) 7) 8) 9) " << endl;
		}
	}
}

int Gesti�n_tropas::get_option(istream& i)
{
	int option;
	int distance = 1;//esta variable sobra, per simula que se pide distancia a la regi�n que clacules, o lea la distancia a l a rei�n a atacar

	{
		switch (submenu)
		{
		case 1:
		{
				cout << "Seleccione el n�mero de tropas" << endl;
				int troops;
				cin >> troops;
				cout << "�Est� seguro de su elecci�n (Y/N)?" << endl;
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
			if (check(option))//si vale el pa�s 
			{
				cout << "la acci�n tardar� en efectuarse " << distance << " turnos.\n �Est� seguro de que quiere realizar la acci�n (Y/N)?" << endl;
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
