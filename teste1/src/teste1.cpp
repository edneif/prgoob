//============================================================================
// Name        : teste1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class World{
private:
	string _nome;

public:
	World(){
		_nome = "World";

	}

	void sayHello(){
		cout << "Hello " << _nome << endl;

	}


};



int main() {

	World obj;

	obj.sayHello();

	return 0;
}
