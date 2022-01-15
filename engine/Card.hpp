#pragma once

enum class Month
{
	January, February, March, April, May, June, July, August, September, October, November, December
};

class Card
{
public:
	Card(Month month, int type);

	inline Month GetSuit() { return suit; }
	inline int GetType() { return type; }

private:
	Month suit;
	int type;
};