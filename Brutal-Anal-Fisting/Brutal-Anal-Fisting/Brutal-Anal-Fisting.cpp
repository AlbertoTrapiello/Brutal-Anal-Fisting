// Brutal-Anal-Fisting.cpp: define el punto de entrada de la aplicación de consola.
//
#include <iostream>
#include "Accion.h"


using namespace std;

int main()
{
	Gestión_tropas g;
	g.print_options();
	g.get_option(cin);
	system("PAUSE");
	return 0;
}