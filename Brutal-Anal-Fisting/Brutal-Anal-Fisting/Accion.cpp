#include "Accion.h"



Gestión_tropas::Gestión_tropas()
{
	id = 0;
	submenu = 0;

}

ostream & Gestión_tropas::print_options(ostream & o)
{
	// TODO: insertar una instrucción return aquí

	switch (submenu)
	{
	case 0:
	{
		return o << "Seleccione la acción a realizar:\n 1)Atacar 2)Defender" << endl;

		break;
	}
	case 1:
	{
		return o << "Seleccione el número de tropas a desplegar" << endl;
	}
	case 2:
	{
		return o << "Seleccione la región a atacar" << endl;
		
		break;
	}
	case 3:
	{
		return o << "Seleccione la región a defender" << endl;

		break;
	}
	default:
	{
		return o << "Menú no reconocido" << endl;
		break;
	}
	}
}


int Gestión_tropas::get_option(istream & i)
{

	int num = 0;
	switch (submenu)
	{
	case 0:
	{
		char aux;
		i >> aux;
		if (aux == '1')
			atacar = 1;
		if(aux=='2')
			atacar = 0;
		if (aux < '3' && aux > '0')
		{
			submenu++;
			return num = aux - '0';

		}
		else
		{
			cout << "ERROR" << endl;
			return -1;
		}

	}
	case 1:
	{
		char aux[3];
		i >> aux;
		
		for (int i = 0; i <= 2; i++)
		{
			cout << "Aux = " << aux[i] << "ooo" << endl;
			if (aux[i]<'9'&&aux[i]>'0')
				num = (aux[i] - '0')*pow(10, i);
			else
				return-1;
			cout << "Número = " << num << endl;
		}
		if (atacar)
			submenu = 2;
		else
			submenu = 3;
		return num;
		break;
	}
	case 2:
	{
		char aux;
		i >> aux;
		if (aux < '9' && aux >'0')
		{
			submenu++;
			return num = aux - '0';
		}
		else
		{
			cout << "ERROR" << endl;
			return -1;
		}
	}
	}

	return num;
}

int Gestión_tropas::check(int option)
{
	int dist = 1;;
	//llamada a dijstra o la función que sea capaz de calcular distancias

	return dist;
}
