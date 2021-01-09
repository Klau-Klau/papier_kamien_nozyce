#pragma once
#include<iostream>
#include<ctime>
#include<cmath>
#include <windows.h> 
#include "Funkcje_mem.h"
#include "punkty.h"

using namespace std;

int licznik = 0;
int pole = 0, pole_1=0, pole_2=0, i_zas1 = 0, i_zas2 = 0, j_zas1 = 0, j_zas2 = 0, pocz_i = 0, pocz_j = 0, x = 0;
int pkt_g = 0, pkt_k = 0;

int wolne_pola[16]; int licznik_wol_pol = 0;

void ruchy_komp(char tab_mem[][4], char tab_mem_znak[][4], int tab_pole[][4], char odkryte_pola[][4], int wolne_pola[]);
void wyswietlanie(char odkryte_pola[][4], char tab_mem[][4]);
int punkty(int pkt);

void ruchy(char tab_mem[][4], char tab_mem_znak[][4], int tab_pole[][4], char odkryte_pola[][4], int wolne_pola[]) {

	
	cout << "wybierz dwie liczby od 0 do 15 " << endl;


	while (licznik < 8) {

		cout << "pierwsze pole: "; cin >> pole_1;
		cout << "drugie_pole: "; cin >> pole_2;

		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j) {
				if (pole_1 == tab_pole[i][j]) {
					i_zas1 = i;
					j_zas1 = j;
				}
				if (pole_2 == tab_pole[i][j]) {

					i_zas2 = i;
					j_zas2 = j;
				}

			}

		}

		


		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j) {
				if (odkryte_pola[i][j] != ' ')
					cout << odkryte_pola[i][j] << " ";
				else if ((i == i_zas1 && j == j_zas1) || (i == i_zas2 && j == j_zas2))
					cout << tab_mem_znak[i][j] << " ";
				else	cout << tab_mem[i][j] << " ";
			}
			cout << "\n";
		}
		Sleep(4000);
		system("cls");


		
		if (tab_mem_znak[i_zas1][j_zas1] == tab_mem_znak[i_zas2][j_zas2]) {
			cout << "brawo, zdobywasz punkt" << endl;
			pkt_g++;

			odkryte_pola[i_zas1][j_zas1] = tab_mem_znak[i_zas1][j_zas1];
			odkryte_pola[i_zas2][j_zas2] = tab_mem_znak[i_zas2][j_zas2];
			wolne_pola[licznik_wol_pol] = pole_1;
			licznik_wol_pol++;
			wolne_pola[licznik_wol_pol] = pole_2;
			
			licznik++;
			cout << "LICZNIK " <<licznik<< endl;
			licznik_wol_pol++;
wyswietlanie(odkryte_pola, tab_mem);
		}
		else {
			cout << "nie udalo sie" << endl;

			wyswietlanie(odkryte_pola, tab_mem);

			ruchy_komp(tab_mem, tab_mem_znak, tab_pole, odkryte_pola, wolne_pola);
		}
		
	}
	system("cls");
	tablica_wynikow(pkt_g, pkt_k);
}

void ruchy_komp(char tab_mem[][4], char tab_mem_znak[][4], int tab_pole[][4], char odkryte_pola[][4], int wolne_pola[]) {

	

	while (licznik < 8) {
		cout << "pierwsze pole: ";
		do {
			 pole_1 = (0 + (rand() % (15 - 0 + 1)));
			for (int i = 0; i < 16; i++)
				if (pole_1 == wolne_pola[i])
					x = i;
		} while (wolne_pola[x] == pole_1);
			cout << pole_1 << endl;
			cout << "drugie pole: ";
		do {
			 pole_2 = (0 + (rand() % (15 - 0 + 1)));
			for (int i = 0; i < 16; i++)
				if (pole_2 == wolne_pola[i])
					x = i;
		} while ((wolne_pola[x] == pole_2) || (pole_1==pole_2));
		cout << pole_2 << endl;
		

		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j) {
				if (pole_1 == tab_pole[i][j]) {
					i_zas1 = i;
					j_zas1 = j;
				}
				if (pole_2 == tab_pole[i][j]) {

					i_zas2 = i;
					j_zas2 = j;
				}

			}

		}


		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j) {
				if (odkryte_pola[i][j] != ' ')
					cout << odkryte_pola[i][j] << " ";
				else if ((i == i_zas1 && j == j_zas1) || (i == i_zas2 && j == j_zas2))
					cout << tab_mem_znak[i][j] << " ";
				else	cout << tab_mem[i][j] << " ";
			}
			cout << "\n";
		}
		Sleep(4000);
		system("cls");


		
		if (tab_mem_znak[i_zas1][j_zas1] == tab_mem_znak[i_zas2][j_zas2]) {

			cout << "brawo, zdobywasz punkt" << endl;
			pkt_k++;

			odkryte_pola[i_zas1][j_zas1] = tab_mem_znak[i_zas1][j_zas1];
			odkryte_pola[i_zas2][j_zas2] = tab_mem_znak[i_zas2][j_zas2];
			wolne_pola[licznik_wol_pol] = pole_1;
			licznik_wol_pol++;
			wolne_pola[licznik_wol_pol] = pole_2;
			licznik++;
			cout << "LICZNIK " <<licznik<< endl;
			licznik_wol_pol++;

		wyswietlanie(odkryte_pola, tab_mem);
		}
		else {
			cout << "nie udalo sie" << endl;
			wyswietlanie(odkryte_pola, tab_mem);
			ruchy(tab_mem, tab_mem_znak, tab_pole, odkryte_pola,wolne_pola);

		}
		

		
	}
	system("cls");
	tablica_wynikow(pkt_g, pkt_k);
}

void wyswietlanie(char odkryte_pola[][4], char tab_mem[][4]) {

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j) {
			if (odkryte_pola[i][j] != ' ')
				cout << odkryte_pola[i][j] << " ";
			else	cout << tab_mem[i][j] << " ";
		}
		cout << "\n";
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
}


