// UserDataTypes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Sandwich.h"
#include <iostream>

//typedef int currency;
typedef unsigned short byte;

struct RGB
{
	byte r;
	byte g;
	byte b;
};

using currency = double;

void f1();

int main()
{
	Sandwich sandwich;
	sandwich.Read();
	sandwich.Write();

	std::cout << SHOP_NAME << std::endl;

	f1();
	f2();
	//currency balance;

	enum class Type { Easy };
	enum class Difficulty
	{
		Easy,
		Medium,
		Hard
	};

	Difficulty difficulty = Difficulty::Easy;
}

void f1() {}
