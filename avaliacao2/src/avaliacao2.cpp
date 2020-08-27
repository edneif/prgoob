//============================================================================
// Name        : avaliacao2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
//#include "..\inc\ednei_p2.h"
using namespace std;


#include <iostream>
#include <vector>
#include <math.h>

const double PI = 3.141592653589793238463;

class Funcao {
public:
	Funcao() {}
	Funcao(Funcao* f) { }
	double operator() (double x = 0) {
		return x;
	}
	double integrar (Funcao* f, double x0, double x1, double step){	}
	virtual ~Funcao() {}
};


class Constante : public Funcao {

public:
	Constante() : _value(0) {cout << "(" << this << ") Constante(x)=(" << _value << ") " << endl;}
	Constante(double val) : _value(val) { cout << "(" << this << ") Constante(x)=(" << _value << ") " << endl; }
	double operator()(double x) {

		return (_value);
	}
	virtual ~Constante() {}

private:
	double _value;
};


class Seno : public Funcao {
public:
	Seno() :  _value(0) {cout << "(" << this << ") Seno(x)=(" << _value << ") " << endl;}
	Seno(double val, Funcao* f) {}
	Seno(Funcao* f) {}
	Seno(double val) : _value(val) {cout << "(" << this << ") Seno(x)=(" << sin(_value) << ") " << endl;}
	double operator()(double x) {
		return (sin(x));
	}
private:
	double _value;
};

class Coseno : public Funcao {
public:
	Coseno() : _value(1) {cout << "(" << this << ") Coseno(x)=(" << _value << ") " << endl;}
	Coseno(double val, Funcao* f) {}
	Coseno(Funcao* f) {}
	Coseno(double val) : _value(val) {cout << "(" << this << ") Coseno(x)=(" << cos(_value) << ") " << endl;}
	double operator()(double x) {
		return (cos(x));
	}
private:
	double _value;
};


class Escalar : public Funcao {
public:
	Escalar() : _value(0) {cout << "(" << this << ") Escalar(x)=(" << _value << ") " << endl;}
	Escalar (double val,Funcao *f): _value(val), f(f){}
	Escalar(Funcao* f) : f(f){ }
	Escalar(double val) : _value(val) { cout << "(" << this << ") Escalar(x)=(" << _value << ") " << endl; }
		double operator()(double x) {  }
private:
	double _value;
	Funcao* f;
};


class Potencial : public Funcao {
public:
	Potencial() : _value(1) {cout << "(" << this << ") Potencia(x)=(" << _value << ") " << endl;}
	Potencial(double val, Funcao *f): _value(val), f(f){}
	Potencial(Funcao* f) : f(f) {}
	Potencial(double val , double exp) : _value(val), _exp(exp) { cout << "(" << this << ") Potencial(x)=(" << pow(_value,_exp) << ") " << endl; }
	double operator()(double x){}
private:
	double _value;
	double _exp;
	Funcao* f;
};


class Exponencial : public Funcao {
public:
	Exponencial() : _value(1) {cout << "(" << this << ") Exponencia(x)=(" << _value << ") " << endl;}
	Exponencial(double val, Funcao* f) : _value(val), f(f) {}
	Exponencial(Funcao* f) : f(f) {}
	Exponencial(double val) : _value(val) { cout << "(" << this << ") Escalar(x)=(" << exp(_value) << ") " << endl; }
	double operator()(double x) {}

private:
	double _value;
	Funcao* f;
};


class FuncaoAgregada : public Funcao {
public:
	void agrega(Funcao *f){
		_vecFuncao.push_back(f);
		cout << "funcao   " << f << "   Agregada" << endl;
	}
	double operator()(const double x) {	}


private:
	vector <Funcao*> _vecFuncao;
	vector <Funcao*> ::iterator it;
};


int main() {

	cout << "ver 0.1" << endl;
	Constante(5);
	Constante();
	Seno();
	Seno(PI/2);
	Coseno();
	Coseno(PI/4);
	Escalar();
	Escalar(19.0);
	Potencial();
	Potencial(2.0,2.0);
	Exponencial();
	Exponencial(5.0);

	cout << "Funcao " << endl;
	Constante c(5);
	Seno s(PI/2);

	cout << "Agrega " << endl;
	FuncaoAgregada f;
	f.agrega(&c); f.agrega(&s);







	return 0;
}
