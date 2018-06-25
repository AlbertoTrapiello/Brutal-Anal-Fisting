#pragma once
#include <string>

struct Zones
{
	int x1, x2;
	int y1, y2;
	Zones() { x1 = x2 = y1 = y2 = 0; }
	Zones(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
};


class Region
{
	Zones **z;
	int lenght;
public:
	Region();
	~Region();
	void read_file(std::string s);
	bool is_in(float x, float y);
	
};