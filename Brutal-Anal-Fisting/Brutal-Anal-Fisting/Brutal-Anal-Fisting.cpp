// Brutal-Anal-Fisting.cpp: define el punto de entrada de la aplicación de consola.
//
#include <iostream>
#include "Accion.h"


using namespace std;

int main()
{
	Gestión_tropas g;
	int option=0;
	g.print_options();
	do
	{
		option=g.get_option(cin);
		cin.clear();
	system("PAUSE");
	} while (option == -1);
	return 0;
}