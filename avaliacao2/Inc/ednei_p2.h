/*
 * ednei_2.h
 * Código construido com Auxilio Leonardo Benitz
 *  Created on: 28 de ago de 2020
 *      Author: pc
 */

#ifndef EDNEI_P2_H_
#define EDNEI_P2_H_

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

const double PI = 3.141592653589793238463;

class Funcao {
public:
	Funcao() {}
	Funcao(Funcao* f) { }
	virtual double operator()(double x) = 0;
	static double integrar (Funcao* f, double x0, double x1, double step){
		double total = 0;
		    for (double x=x0; x<x1; x+=step){
		        total += (*f)(x)*step;
		    }
		    return total;
	}
	virtual ~Funcao() {} //destrutor padrao
private:
	Funcao *_f;
};


class Constante : public Funcao {

public:
	Constante() : _value(0) {cout << "(" << this << ") Constante(x)=(" << _value << ") " << endl;}
	Constante(double val) : _value(val) { }
	double operator()(double x) {

		return (_value);
	}
	virtual ~Constante() {}

private:
	double _value = 0;
};


class Seno : public Funcao {
public:
	Seno() :  _value(0) {cout << "(" << this << ") Seno(x)=(" << _value << ") " << endl;}
	Seno(double val, Funcao* f) : _value(val), _f(f) {}
	Seno(Funcao* f) : _f(f){}
	Seno(double val) : _value(val) {}
	double operator()(double x) {
	if (_f!=NULL)
		return (_value*sin((*_f)(x)));
	else
		return (_value*sin(x));
	}
private:
	double _value = 1;
	Funcao* _f = NULL;
};





class Coseno : public Funcao {
public:
	Coseno() : _value(1) {cout << "(" << this << ") Coseno(x)=(" << _value << ") " << endl;}
	Coseno(double val, Funcao* f) :_value(val), _f(f) {}
	Coseno(Funcao* f) : _f(f) {}
	Coseno(double val) : _value(val) {}
	double operator()(double x) {
		if (_f!=NULL)
			return (_value*cos((*_f)(x)));
		else
			return (_value*cos(x));
	}
private:
	double _value = 1;
	Funcao* _f = NULL;
};


class Escalar : public Funcao {
public:
	Escalar() : _value(0) {cout << "(" << this << ") Escalar(x)=(" << _value << ") " << endl;}
	Escalar (double val,Funcao *f): _value(val), f(f){}
	Escalar(Funcao* f) : f(f){ }
	Escalar(double val) : _value(val) {}
	double operator()(double x) {
		double _escalar ;
		if (f!= NULL){
			_escalar = _value*(*f)(x);
		} else{
		_escalar = _value*x;
		}
		return (_escalar);
	}
private:
	double _value = 0;
	Funcao* f = NULL;
};


class Potencial : public Funcao {
public:
	Potencial() : _value(1) {cout << "(" << this << ") Potencia(x)=(" << _value << ") " << endl;}
	Potencial(double val, Funcao *f): _value(val), _f(f){}
	Potencial(Funcao* f) : _f(f) {}
	Potencial(double val) : _value(val) {}
	double operator()(double x){
		if (_f!=NULL)
		   return pow((*_f)(x), _value);
		else
           return pow(x, _value);
	}
private:
	double _value = 1;
	Funcao* _f = NULL;
};

class Exponencial : public Funcao {
public:
	Exponencial() : _value(1) {cout << "(" << this << ") Exponencia(x)=(" << _value << ") " << endl;}
	Exponencial(double val, Funcao* f) : _value(val), _f(f) {}
	Exponencial(Funcao* f) : _f(f) {}
	Exponencial(double val) : _value(val) {}
	double operator()(double x) {
		if (_f!=NULL)
			return pow(_value,(*_f)(x));
		else
			return pow(_value, x);

	}
private:
	double _value = 1;
	Funcao* _f = NULL;
};


class FuncaoAgregada : public Funcao {
public:
	void agrega(Funcao *f){
		_vecFuncao.push_back(f);
		cout << "funcao   " << f << "   Agregada" << endl;
	}
	double operator()(const double x) {
		double _valorAgregada=0;
		for (it = _vecFuncao.begin(); it != _vecFuncao.end(); it++) {
			_valorAgregada += (*static_cast<Funcao*>(*it))(x);
		}
		return _valorAgregada;

	}
private:
	vector <Funcao*> _vecFuncao;
	vector <Funcao*> ::iterator it;
};








#endif /* EDNEI_P2_H_ */
