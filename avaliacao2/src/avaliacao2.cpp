//============================================================================
// Name        : avaliacao2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
// Código construido com Auxilio Leonardo Benitz


#include <iostream>
#include "..\inc\ednei_p2.h"
using namespace std;

void teste (void){
	double y;

    cout << "ver 0.1" << endl;

	Potencial f0 = Potencial(2);
	Constante f1 = Constante(-1);
	Escalar f2 = Escalar(2);
	FuncaoAgregada f3 = FuncaoAgregada();
	f3.agrega(&f1);
	f3.agrega(&f2);
	Seno f4 = Seno(&f3);
	Escalar f5 = Escalar(5, &f4);
	Constante f6 = Constante(5);
	FuncaoAgregada f = FuncaoAgregada();
	f.agrega(&f0);
	f.agrega(&f5);
	f.agrega(&f6);


	y= Funcao::integrar(&f, 0, 5, 0.01);
	cout << "Integral from 0 to 5: " << y << " (expected 70.29525)\n";

	for (double x=0; x<5; x+=0.01){
		cout << "f(" << x << ") = " << f(x) << endl;
	}



}


int main() {

    teste();
	return 0;
}





