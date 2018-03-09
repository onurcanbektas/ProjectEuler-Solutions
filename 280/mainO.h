#pragma once

#include <random>
/*
	1
2		3
	4
*/
class Sim
{
public:
	Sim();
	void Run();
	bool checkMovability(); // Call it after setting ´move´ varible
	bool moveToDirection();
	void CarryFood();
	void LeftFood();
	bool checkSuccess();
	void ShowResult();
	~Sim();
private:


public:
	int currentPos[2] = {2, 2};
	int leftFoodCount = 0;
	bool Success = false;
	bool AntsBag = false; // false := empty
	int AntStepCount = 0;


	std::mt19937 gen{std::random_device{}()};
    std::uniform_int_distribution<int> dist{1, 4};

	enum direction
	{
		None = 0,
		Up = 1,
		Left = 2,
		Right = 3,
		Down = 4
	}move;
	bool grid[5][5] = {
            {false, false, false, false, true},
            {false, false, false, false, true},
            {false, false, false, false, true},
            {false, false, false, false, true},
            {false, false, false, false, true}
        };
	
};