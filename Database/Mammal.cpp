#include "Mammal.h"
#include <iostream>
#include <fstream>

void Mammal::Read(std::ifstream& istream)
{
	Animal::Read(istream);

	istream >> m_numLegs;
}

void Mammal::Write(std::ofstream& ostream)
{
	Animal::Write(ostream);

	ostream << m_numLegs << std::endl;
}

void Mammal::Read(std::ostream& ostream, std::istream& istream)
{
	Animal::Read(ostream, istream);

	ostream << "enter number of legs: ";
	istream >> m_numLegs;
}

void Mammal::Write(std::ostream& ostream)
{
	Animal::Write(ostream);

	ostream << "number of legs: " << m_numLegs << std::endl;
}

