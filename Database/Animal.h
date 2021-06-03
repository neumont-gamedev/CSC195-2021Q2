#pragma once
#include <string>
#include <memory>

class Animal
{
public:
	enum class eType
	{
		Mammal = 1,
		Bird
	};

	std::string GetName() { return m_name; }
	virtual eType GetType() = 0;

	virtual void Read(std::ifstream& istream);
	virtual void Write(std::ofstream& ostream);

	virtual void Read(std::ostream& ostream, std::istream& istream);
	virtual void Write(std::ostream& ostream);

	friend std::istream& operator >> (std::istream& istream, Animal& animal);
	friend std::ostream& operator << (std::ostream& ostream, Animal& animal);

	friend std::ifstream& operator >> (std::ifstream& istream, Animal& animal);
	friend std::ofstream& operator << (std::ofstream& ostream, Animal& animal);

	friend bool operator == (const std::unique_ptr<Animal>& animal, const std::string& name) { return name == animal->GetName(); }
	friend bool operator == (const std::unique_ptr<Animal>& animal, eType type) { return type == animal->GetType(); }

protected:
	std::string m_name;
	int m_lifespan = 0;
};

