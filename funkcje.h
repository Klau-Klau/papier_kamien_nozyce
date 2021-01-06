#pragma once
#include<iostream>

using namespace std;

int pkt_1 = 0, pkt_2 = 0;

gracz* gracz_1 = new gracz;
gracz* gracz_2 = new gracz;

void rundy();

void tablica_wynikow(int& pkt_1, int& pkt_2)
{
	cout << gracz_1->nazwa << ": " << pkt_1 << " " << gracz_2->nazwa << ": " << pkt_2 << endl;
	if (pkt_1 > pkt_2)
		cout << "WYGRYWA " << gracz_1->nazwa << "!" << endl;
	if (pkt_2 > pkt_1)
		cout << "WYGRYWA " << gracz_2->nazwa << "!" << endl;
	if (pkt_1 == pkt_2) cout << "REMIS!" << endl;

	string odpowiedz;
	cout << "Czy chcesz zwiekszyc ilosc rund?" << endl; cin >> odpowiedz;
	if (odpowiedz == "tak")
		rundy();
	else cout << "koniec gry" << endl;

}

void wynik(int n, int m, int& i, int& X)
{

	switch (n)
	{
	case 1:
		if (m == 1) {
			cout << "remis" << endl; Sleep(2000);
			pkt_1++; pkt_2++;
		}
		if (m == 2) {
			cout << "punkt dla " << gracz_2->nazwa << endl; Sleep(2000);
			pkt_2++;
		}
		if (m == 3) {
			cout << "punkt dla " << gracz_1->nazwa << endl; Sleep(2000);
			pkt_1++;
		}
		if (i == X - 1)
			tablica_wynikow(pkt_1, pkt_2);
		break;
	case 2:
		if (m == 2) {
			cout << "remis" << endl; Sleep(2000);
			pkt_1++; pkt_2++;
		}
		if (m == 3) {
			cout << "punkt dla " << gracz_2->nazwa << endl; Sleep(2000);
			pkt_2++;
		}
		if (m == 1) {
			cout << "punkt dla " << gracz_1->nazwa << endl; Sleep(2000);
			pkt_1++;
		}
		if (i == X - 1)
			tablica_wynikow(pkt_1, pkt_2);
		break;
	case 3:
		if (m == 3) {
			cout << "remis" << endl; Sleep(2000);
			pkt_1++; pkt_2++;
		}
		if (m == 1) {
			cout << "punkt dla " << gracz_2->nazwa << endl; Sleep(2000);
			pkt_2++;
		}
		if (m == 2) {
			cout << "punkt dla " << gracz_1->nazwa << endl; Sleep(2000);
			pkt_1++;
		}
		if (i == X - 1)
			tablica_wynikow(pkt_1, pkt_2);
		break;
	}

}
void rozgrywka(int& i, int& X)
{
	int n, m;
	system("cls");
	cout << gracz_1->nazwa << endl;
	cout << "1-kamien" << endl;
	cout << "2-papier" << endl;
	cout << "3-nozyce" << endl;
	cout << "podaj cyfre: "; cin >> n;

	system("cls");
	cout << gracz_2->nazwa << endl;
	cout << "1-kamien" << endl;
	cout << "2-papier" << endl;
	cout << "3-nozyce" << endl;
	cout << "podaj cyfre: "; cin >> m;

	//int m = (rand() % 3) + 1;
	cout << "wybor " << gracz_1->nazwa << ": " << n << endl;
	cout << "wybor " << gracz_2->nazwa << ": " << m << endl;
	wynik(n, m, i, X);

}

void rundy()
{
	int X, i;
	cout << "Podaj ilosc rund: "; cin >> X;

	for (i = 0; i < X; i++)
		rozgrywka(i, X);
}

