#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class Rule {
private:
	string backType;
public:
	virtual void diamondPoints() = 0;
	virtual void emeraldPoints() = 0;
	virtual void fluoritePoints() = 0;
	virtual void rubyPoints() = 0;
	virtual void goldPoints() = 0;
	virtual void ironPoints() = 0;
};

class Rule1 : Rule {

};

class Rule2 : Rule {

};

class Rule3 : Rule {

};

class Rule4 : Rule {

};

class Rule5 : Rule {

};

class Rule6 : Rule {

};
