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
		say("Hellov2");
}

void World::sayGoodbye() {
	say("Goodbye");
}

void World::sayHi() {
	say("Hi");;
}

void World::say(string str) {
	cout << str << " " << _nome << endl;

}



World::~World() {
	// TODO Auto-generated destructor stub
}

