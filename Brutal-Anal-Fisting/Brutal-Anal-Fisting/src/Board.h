#pragma once

#include <iostream>
#include "Jugadores.h"

using namespace std;

class Board {

protected:
	const int N;		//NxN board
	Jugadores ** tab;

public:
	Board(int n) :N(n) 
	{
		if (N > NUM_MÁX_JUG)
			cout << "Error número máximo de jugadores: " << NUM_MÁX_JUG << endl;
		
		else
		{
			tab = new Jugadores*[N];
			for (int i = 0; i < N; i++) {
				tab[i] = new Jugadores[N];			//initially empty
			}

			//set initial position
			for(int i=0; i<N;i++)
				switch (i)
				{
				case 1:
				{
					tab[i]->set_Casa(Stark);
					tab[i]->set_nombre("PEPE");
					tab[i]->set_titulo("Condemor");
					break;
				}
				case 2:
				{
					tab[i]->set_Casa(Stark);
					tab[i]->set_nombre("PEPE");
					tab[i]->set_titulo("Condemor");
					break;
				}
				case 3:
				{
					tab[i]->set_Casa(Stark);
					tab[i]->set_nombre("PEPE");
					tab[i]->set_titulo("Condemor");
					break;
				}
				case 4:
				{
					tab[i]->set_Casa(Stark);
					tab[i]->set_nombre("PEPE");
					tab[i]->set_titulo("Condemor");
					break;
				}
				case 5:
				{
					tab[i]->set_Casa(Stark);
					tab[i]->set_nombre("PEPE");
					tab[i]->set_titulo("Condemor");
					break;
				}
				case 6:
				{
					tab[i]->set_Casa(Stark);
					tab[i]->set_nombre("PEPE");
					tab[i]->set_titulo("Condemor");
					break;
				}
				case 7:
				{
					tab[i]->set_Casa(Stark);
					tab[i]->set_nombre("PEPE");
					tab[i]->set_titulo("Condemor");
					break;
				}
				case 8:
				{
					tab[i]->set_Casa(Stark);
					tab[i]->set_nombre("PEPE");
					tab[i]->set_titulo("Condemor");
					break;
				}
				case 9:
				{
					tab[i]->set_Casa(Stark);
					tab[i]->set_nombre("PEPE");
					tab[i]->set_titulo("Condemor");
					break;
				}
				case 10:
				{
					tab[i]->set_Casa(Stark);
					tab[i]->set_nombre("PEPE");
					tab[i]->set_titulo("Condemor");
					break;
				}

				}
		}
	}
	~Board() {
		for (int i = 0; i<N; i++)
			delete[] tab[i];
		delete[] tab;
	}

	int getSize() { return N; }
	Jugadores** getTab() { return tab; }
};

