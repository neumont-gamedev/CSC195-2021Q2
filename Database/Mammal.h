#pragma once
#include "Animal.h"

class Mammal : public Animal
{
public:
	eType GetType() override { return eType::Mammal; }

	void Read(std::ifstream& istream) override;
	void Write(std::ofstream& ostream) override;

	void Read(std::ostream& ostream, std::istream& istream) override;
	void Write(std::ostream& ostream) override;

protected:
	int m_numLegs{ 0 };
};

