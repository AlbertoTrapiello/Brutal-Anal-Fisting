#include "Accion.h"
#include "ListaJugadores.h"


ostream & Acci�n_Engine::operator<<(ostream & o)
{
	// TODO: insertar una instrucci�n return aqu�
	return a->print_options(o);
}

ostream & Gesti�n_tropas::print_options(ostream & o)
{
	// TODO: insertar una instrucci�n return aqu�
	if (!submenu)
		return o << "Generar Tropas" << endl;
	else
		return o << "1) Atacar\n 2) Defender" << endl;
}

int Gesti�n_tropas::get_option(istream& i)
{
	int option;
	i >> option;
	if (option == this->id);
	{
		if (!submenu)
			submenu = 1;
		else
		{
			cout << "Seleccione onjetivo: " << Lista << endl;//conseguir que list ase sepa transformar en flujo y que aqu� se llame 

		}
	}
	return 0;
}
