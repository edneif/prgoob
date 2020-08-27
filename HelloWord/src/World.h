/*
 * World.h
 *
 *  Created on: 26 de mar de 2020
 *      Author: pc
 */

#ifndef WORLD_H_
#define WORLD_H_

#include <iostream>
using namespace std;

class World {

private:
	string _nome;

public:
	World();


	void sayHello();
	void sayGoodbye();
	void sayHi();


	virtual ~World();
};

#endif /* WORLD_H_ */
