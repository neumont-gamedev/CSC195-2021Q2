#pragma once

#define SHOP_NAME "Blimpies"
#define PI 3.1415f

enum Type
{
	Italian,
	Turkey
};

void f2();

class Sandwich
{
public:
	void Read();
	void Write();

private:
	char name[32];
	float price;
	bool isHot;

	static const float TAX;
};