#include<iostream>
#pragma once

using namespace std;

class gracz {
public:
	string nazwa;

	void PodajNazwe();
};

void gracz::PodajNazwe() {
	cout << "Nazwa: "; cin >> nazwa;
}
