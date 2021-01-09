#pragma once
#include<iostream>
#include<ctime>
#include<cmath>
#include <windows.h> 
#include "ruchy.h"

using namespace std;

void ruchy(char tab_mem[][4], char tab_mem_znak[][4], int tab_pole[][4], char odkryte_pola[][4], int wolne_pola[]);

void plansza() {

	// wymiary planszy 4x4

	char tab_mem[4][4];

	for(int i=0; i<4; i++)
		for (int j = 0; j < 4; j++) {
			tab_mem[i][j] ='X';
		}

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
			cout << tab_mem[i][j] << " ";
		cout << "\n";
	}
	



	srand(time(NULL));

	char tab_mem_znak[4][4];
	int i, j,m=2, koniec_tablicy=0, kod_ASCII=33,x=0;

	for ( i = 0; i < 4; i++)
		for ( j = 0; j < 4; j++) {
			tab_mem_znak[i][j] = 'f';
		}
	//cout << tab_mem_znak[1][3] << endl;
	//tab_mem_znak[1][1] = (char)kod_ASCII;
	//cout << tab_mem_znak[1][1]  << endl;

	while(koniec_tablicy<8){
		m--;
		while (m != 2) {
			//m--;
			i =(0 + (rand() % (3 - 0 + 1)));
			//cout <<"i"<< i << endl;
			j = (0 + (rand() % (3 - 0 + 1)));
			//cout << "j" << j << endl;
			if (tab_mem_znak[i][j] == 'f') {
				tab_mem_znak[i][j] = (char)kod_ASCII;
				do {
					i = (0 + (rand() % (3 - 0 + 1)));
					//cout << "i2" << i << endl;
					j = (0 + (rand() % (3 - 0 + 1)));
					//cout << "j2" << j << endl;
					if (tab_mem_znak[i][j] == 'f') {
						tab_mem_znak[i][j] = (char)kod_ASCII;
						x = 1;
					}
				} while (x==0);
				x = 0;
					//if (tab_mem_znak[i][j] == 'f') {
						//tab_mem_znak[i][j] = (char)kod_ASCII;
						//x = 1;
					//}
					//x = 0;
				
				kod_ASCII++;
				koniec_tablicy ++;
				m++;
			}
			//m--;
		}
	}
	//cout << i << endl;
	//cout << j << endl;
	cout <<  endl;

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
			cout << tab_mem_znak[i][j] << " ";
		cout << "\n";
	}
		
	int tab_pole[4][4];
	char odkryte_pola[4][4];
	int pole = 0;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j) {
			tab_pole[i][j] = pole;
			pole++;
		}
		cout << "\n";
	}


	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
			odkryte_pola[i][j] = ' ';
	}

	for (int i = 0; i < 16; ++i)
	{
		wolne_pola[i] = 16;
	}


	pole = 0;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j) {
			cout << pole << " ";
			pole++;
		}
		cout << "\n";
	}
	ruchy(tab_mem, tab_mem_znak, tab_pole, odkryte_pola, wolne_pola);
}
