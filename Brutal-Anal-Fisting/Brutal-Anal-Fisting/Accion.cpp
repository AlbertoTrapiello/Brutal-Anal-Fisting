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

Gesti�n_tropas::Gesti�n_tropas()
{
	submenu = 1;
	id = 0;

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
			return o << "Seleccione region: \n 1) 2) 3) 4) 5) 6) 7) 8) 9) " << endl;
		}
	deafult:
		{
			return  o << "SEEEEISSSEEE \n 1) 2) 3) 4) 5) 6) 7) 8) 9) " << endl;
		}
	}
}

int Gesti�n_tropas::get_option(istream& i)
{
	int option=-1;
	int distance = 1;//esta variable sobra, per simula que se pide distancia a la regi�n que clacules, o lea la distancia a l a rei�n a atacar

	{
		switch (submenu)
		{
		case 1:
		{
			
				cout << "Seleccione el numero de tropas" << endl;
				int troops = 0;
				i.clear();
				i >> troops;
				cout << troops << endl;

				if (!check(troops))
				{
					cout << "detector de gilipolleces" << endl;
					return -1;
				}
				cout << "�Esta seguro de su eleccion (Y/N)?" << endl;
				char token;
				i.clear();
				i >> token;
				switch (token)
				{
					case 'y':
					{
						return troops;
					}
					case 'Y':
					{
						return troops;
					}
					case 'n':
					{
						return 0;
					}
					case 'N':
					{
						return 0;
					}
					default:
					{
						cout << "Error de respuesta" << endl;
						return -1;
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

bool Gesti�n_tropas::check(int option)
{
	if (option < 1 || option>9)
		return false;
	else
		return true;
}
