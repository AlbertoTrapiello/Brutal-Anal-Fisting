#include "Turno.h"
#include <iostream>
#include <string>
#include <sstream>

#define OPC_1_X_MAX 588
#define OPC_1_X_MIN 507
#define OPC_1_Y_MAX 84
#define OPC_1_Y_MIN 75
#define OPC_2_X_MAX 658
#define OPC_2_X_MIN 508
#define OPC_2_Y_MAX 112
#define OPC_2_Y_MIN 102
#define OPC_3_X_MAX 676
#define OPC_3_X_MIN 507
#define OPC_3_Y_MAX 140
#define OPC_3_Y_MIN 131
#define OPC_4_X_MAX 676
#define OPC_4_X_MIN 507
#define OPC_4_Y_MAX 166
#define OPC_4_Y_MIN 157
#define OK_X_MAX 670
#define OK_X_MIN 647
#define OK_Y_MAX 165
#define OK_Y_MIN 152

using namespace std;



const char * Turno::dibuja( Mundo *world)
{
	if (world->click)
	{
		//Sacar
		world->player[world->pos].Icon_hide();
		world->menu_sure();
	}
	else
	{
		if (world->ok)
		{
			world->player[world->pos].Icon_hide();
			world->menu_hide();
			//no estoy seguro de esto pero no cuadra en ningún otro sitio
			world->player[world->pos].set_turno();
			world->player[world->pos].Icon_hide();
			if (world->player[world->pos].is_IA())
			{
				if (world->player[world->pos].pseudo_IA())
					world->pos++;
			}
			else
			{
				//gestion de las accciones a tomar po parte del jugador
				if (world->player[world->pos].mi_turno())
					world->draw_menus(world->idr);
			}
		}
		else
		{
			world->menu_hide();
			world->player[world->pos].Icon();
		}
	}

	if (world->idr==5||world->idr==6||world->idr==8||world->idr==9)
	{
		if ((world->error_region) && (world->ok))
			return "Seleccione otra ";
		if ((!world->error_region) && (world->ok))
		{
			const char * a;
			a = world->player[world->region].get_nombre();
			//cout << a;
			return a;
		}
	}
	return world->resultado;
}

void Turno::teclado(Mundo * world,unsigned char key)
{
	if (world->contador < 5)
	{
		switch (key)
		{
		case '1':
		{
			world->numero[world->contador] = '1';
			world->contador++;
			break;
		}
		case '2':
		{
			world->numero[world->contador] = '2';
			world->contador++;
			break;
		}
		case '3':
		{
			world->numero[world->contador] = '3';
			world->contador++;
			break;
		}
		case '4':
		{
			world->numero[world->contador] = '4';
			world->contador++;
			break;
		}
		case '5':
		{
			world->numero[world->contador] = '5';
			world->contador++;
			break;
		}
		case '6':
		{
			world->numero[world->contador] = '6';
			world->contador++;
			break;
		}
		case '7':
		{
			world->numero[world->contador] = '7';
			world->contador++;
			break;
		}
		case '8':
		{
			world->numero[world->contador] = '8';
			world->contador++;
			break;
		}
		case '9':
		{
			world->numero[world->contador] = '9';
			world->contador++;
			break;
		}
		case '0':
		{
			world->numero[world->contador] = '0';
			world->contador++;
			break;
		}
		}
		//cout << world->numero << endl;
		stringstream sstr;
		sstr << world->numero;
		sstr >> world->num;
		world->action.set_cantidad(world->num);
		//cout << "el world->numero en int es: " << world->num << endl;
		world->resultado = world->numero;
	}
	//else
		//cout << "superado el limite" << endl;
}

void Turno::raton(Mundo * world, float x, float y)
{
	if (world->idr == 2)
	{
		//cout << "eeey que he puesto la opcion: ";
		if ((x <= OPC_1_X_MAX && x >= OPC_1_X_MIN) && (y <= OPC_1_Y_MAX && y >= OPC_1_Y_MIN))
		{
			world->action.set_opcion(1);
			//cout << "1" << endl;
		}
		if ((x <= OPC_2_X_MAX && x >= OPC_2_X_MIN) && (y <= OPC_2_Y_MAX && y >= OPC_2_Y_MIN))
		{
			world->action.set_opcion(2);
			//cout << "2" << endl;
		}
		if ((x <= OPC_3_X_MAX && x >= OPC_3_X_MIN) && (y <= OPC_3_Y_MAX && y >= OPC_3_Y_MIN))
		{
			world->action.set_opcion(3);
			//cout << "3" << endl;
		}
		if ((x <= OPC_4_X_MAX && x >= OPC_4_X_MIN) && (y <= OPC_4_Y_MAX && y >= OPC_4_Y_MIN))
		{
			world->action.set_opcion(4);
			//cout << "4" << endl;
		}
		
	}
	if (world->idr == 5 || world->idr == 6 || world->idr == 8 || world->idr == 9)
	{
		if ((!world->error_region) && (world->ok))
		{
			if ((x <= OK_X_MAX && x >= OK_X_MIN) && (y <= OK_Y_MAX && y >= OK_Y_MIN))
			{
				world->click = 0;
			}
		}
	}

}

void Turno::acciones(Mundo * world)
{
	if (world->player[world->pos].is_IA())
	{
		if (world->player[world->pos].pseudo_IA())
			world->pos++;
	}
	else
	{
		//gestion de las accciones a tomar po parte del jugador
		if (world->player[world->pos].mi_turno())
		{
			if (world->check_action())
			{
				
				if (world->action.gestion_acc(world->player[world->pos],world->player[world->region]))//queda hacer lo que convenga para cada uno de los casos
					world->pos++;
			}
			//cout << "la opcion que tengo guardada es " << world->action.get_option() << endl;

		}
	}
	
}
