#include<iostream>
#include<bitset>

using u8_t = unsigned char;
using u16_t = unsigned short;
using u32_t = unsigned int;

int main()
{
	u8_t b1 = 0b11110000;
	u8_t b2 = 0b00001111;
	u32_t b3 = 0xffffffff; // f = 1111
	// | OR
	// & AND
	// ^ XOR
	// ~ NOT

	std::cout << std::bitset<8>(b1) << std::endl;
	std::cout << std::bitset<8>(b2) << std::endl;
	std::cout << std::bitset<8>(b1 & ~b2) << std::endl;

	if (b1 || b2) {}

	u8_t shift = 3; // 11
	for (size_t i = 0; i < 8; i++)
	{
		//std::cout << std::bitset<8>(shift << i) << std::endl;
		std::cout << (shift << i) << std::endl;
	}


	u8_t upper = 0b10110011;
	u8_t lower = 0b11010110;
	std::cout << std::bitset<8>(upper) << std::endl;
	std::cout << std::bitset<8>(lower) << std::endl;
	u16_t pack = (upper << 8) | lower;
	std::cout << std::bitset<16>(pack) << std::endl;

	u8_t r = 128;
	u8_t g = 8;
	u8_t b = 20;
	u8_t a = 255;

	u32_t color = (r << 24) | (g << 16) | (b << 8) | a;
	std::cout << std::bitset<32>(color) << std::endl;

	u16_t b16 = (color >> 8) & 0xff;
	std::cout << std::bitset<16>(b16) << std::endl;
}