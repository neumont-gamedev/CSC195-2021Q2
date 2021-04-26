#include "Sandwich.h"
#include <iostream>

const float Sandwich::TAX = 0.08f;

void Sandwich::Read()
{
	std::cout << "name: ";
	std::cin >> name;
}

void Sandwich::Write()
{
	std::cout << name << std::endl;
	std::cout << TAX << std::endl;
}


void f2()
{

}