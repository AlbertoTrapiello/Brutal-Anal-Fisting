#include "Turno.h"

void Turno::dibuja(int idr)
{
	if (click)
	{
		//Sacar
		player[pos].Icon_hide();
		menu_sure();
	}
	else
	{
		if (ok)
		{
			player[pos].Icon_hide();
			menu_hide();
			//no estoy seguro de esto pero no cuadra en ningún otro sitio
			player[pos].set_turno();
			player[pos].Icon_hide();
			if (player[pos].is_IA())
			{
				if (player[pos].pseudo_IA())
					pos++;
			}
			else
			{
				//gestion de las accciones a tomar po parte del jugador
				if (player[pos].mi_turno())
					if (player[pos].Turno(idr))
					{
						pos++;
					}
			}
		}
		else
		{
			menu_hide();
			player[pos].Icon();
		}
	}
	
}
