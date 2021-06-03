#include "Animal.h"
#include <iostream>
#include <fstream>

void Animal::Read(std::ifstream& istream)
{
	istream >> m_name;
	istream >> m_lifespan;
}

void Animal::Write(std::ofstream& ostream)
{
	ostream << m_name << std::endl;
	ostream << m_lifespan << std::endl;
}

void Animal::Read(std::ostream& ostream, std::istream& istream)
{
	ostream << "enter name: ";
	istream >> m_name;

	ostream << "enter lifespan: ";
	istream >> m_lifespan;
}

void Animal::Write(std::ostream& ostream)
{
	ostream << "name: " << m_name << std::endl;
	ostream << "lifespan: " << m_lifespan << std::endl;
}

std::istream& operator>>(std::istream& istream, Animal& animal)
{
	animal.Read(std::cout, istream);

	return istream;
}

std::ostream& operator<<(std::ostream& ostream, Animal& animal)
{
	animal.Write(ostream);

	return ostream;
}

std::ifstream& operator>>(std::ifstream& istream, Animal& animal)
{
	animal.Read(istream);

	return istream;

}

std::ofstream& operator<<(std::ofstream& ostream, Animal& animal)
{
	animal.Write(ostream);

	return ostream;
}
