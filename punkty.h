#pragma once
#include<iostream>

using namespace std;

int punkty(int pkt) {

	pkt++;
	return pkt;
}

void tablica_wynikow(int& pkt_g, int& pkt_k)
{
	cout << "uzytkownik: " << pkt_g << " komputer: " << pkt_k << endl;
	if (pkt_g > pkt_k)
		cout << "WYGRYWA UZYTKOWNIK!" << endl;
	if (pkt_g < pkt_k)
		cout << "WYGRYWA KOMPUTER!" << endl;
	if (pkt_g == pkt_k) cout << "REMIS!" << endl;

	

}