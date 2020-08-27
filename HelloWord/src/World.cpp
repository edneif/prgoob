/*
 * World.cpp
 *
 *  Created on: 26 de mar de 2020
 *      Author: pc
 */

#include "World.h"

World::World() {
	// TODO Auto-generated constructor stub
	_nome = "World";
}

void World::sayHello() {
		cout << "Hello2 " << _nome << endl;
}

void World::sayGoodbye() {
		cout << "Goodbye " << _nome << endl;
}

void World::sayHi() {
		cout << "Hi " << _nome << endl;
}



World::~World() {
	// TODO Auto-generated destructor stub
}

