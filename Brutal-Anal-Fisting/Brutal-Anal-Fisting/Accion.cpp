#include "Accion.h"
#include "ListaJugadores.h"


ostream & Acción_Engine::operator<<(ostream & o)
{
	// TODO: insertar una instrucción return aquí
	return a->print_options(o);
}

ostream & Gestión_tropas::print_options(ostream & o)
{
	// TODO: insertar una instrucción return aquí
	if (!submenu)
		return o << "Generar Tropas" << endl;
	else
		return o << "1) Atacar\n 2) Defender" << endl;
}

int Gestión_tropas::get_option(istream& i)
{
	int option;
	i >> option;
	if (option == this->id);
	{
		if (!submenu)
			submenu = 1;
		else
		{
			cout << "Seleccione onjetivo: " << Lista << endl;//conseguir que list ase sepa transformar en flujo y que aquí se llame 

		}
	}
	return 0;
}
