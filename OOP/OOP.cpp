#include <iostream>
using namespace std;

class Animal
{
public:
	Animal() 
	{ 
		cout << "Animal()\n";
		m_count++; 
	}
	Animal(int lifespan) : m_lifespan{ lifespan }
	{
		m_count++;
	}
	virtual ~Animal() { cout << "~Animal()\n"; }

	virtual void Speak() { cout << "???" << endl; }
	void Write() { cout << "lifespan: " << m_lifespan << endl; }

	static int GetCount() { return m_count; }

protected:
	int m_lifespan = 0;
	float m_speed = 5.0f;
	static int m_count;
};

int Animal::m_count = 0;

class Bird : public Animal
{
public:
	Bird() 
	{
		cout << "Bird()\n";
	}
	Bird(int lifespan, bool canFly) : Animal(lifespan), m_canFly(canFly) {}
	~Bird() { cout << "~Bird()\n"; }

	void Speak() override { cout << "Cheep!" << endl; }

private:
	bool m_canFly = true;
};

int main()
{
	Animal* robin = new Bird(); //Bird(10, true);
	cout << sizeof(Animal) << endl;
	cout << Animal::GetCount() << endl;

	robin->Speak();
	robin->Write();

	delete robin;
}
