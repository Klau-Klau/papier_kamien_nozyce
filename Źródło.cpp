#include<iostream>
#include<cstdlib>
#include <ctime>
#include<Windows.h>
#include "gracze.h"
#include "funkcje.h"

using namespace std;

//int pkt_1 = 0, pkt_2 = 0;

//gracz* gracz_1 = new gracz;
//gracz* gracz_2 = new gracz;

void rozgrywka();
void rundy();
void tablica_wynikow();
void wynik();








int main()
{
	//srand(time(NULL));

	//gracz* gracz_1 = new gracz;
	//gracz* gracz_2 = new gracz;


	gracz_1->PodajNazwe();
	gracz_2->PodajNazwe();
	//cout << gracz_2->nazwa << endl;


rundy();


	return 0;
}