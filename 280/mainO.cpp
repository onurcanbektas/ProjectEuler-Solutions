// in leeaveFood method, count the left foods, so you don't need checkSuccess method at all
#include <stdio.h>
#include "mainO.h"

static constexpr int MaxExp = 10;//5000000;
static int ExpNumber = 1;

FILE * file = fopen("testO.txt", "w"); // a+

int main(int argc, char const *argv[])
{

	while(ExpNumber <= MaxExp)
	{
		Sim Ant;
		Ant.Run();
	}

	fclose(file);
	return 0;
}

Sim::Sim() 
{
	this->move = Sim::None;
}

void Sim::Run()
{
	do
	{
		this->move = (Sim::direction) dist(gen);
		if ( moveToDirection() )
		{
			this->AntStepCount++;
		}
		if (this->currentPos[1] == 4 && grid[this->currentPos[0]][4] == true && this->AntsBag == false)
		{
			CarryFood();
		}
		if (this->currentPos[1] == 0 && grid[this->currentPos[0]][0] == false && this->AntsBag == true)
		{
			LeftFood();
		}
		checkSuccess();

	}while(!(this->Success));

	ShowResult();
	ExpNumber++;
}

void Sim::ShowResult()
{	
	fprintf(file, "%d %d\n", ExpNumber, this->AntStepCount);
}

void Sim::CarryFood()
{
	this->AntsBag = true;
	grid[this->currentPos[0]][4] = 0;
}

void Sim::LeftFood()
{
	AntsBag = false;
	grid[this->currentPos[0]][0] = 2;
	this->leftFoodCount++;
}

bool Sim::checkMovability()
{
	if (this->move == Sim::None)
	{
		fprintf(stderr, "this->move is set to None\n");
		return false;
	}
	switch(this->move)
	{
		case Sim::Up:
		{
			if(this->currentPos[1]==0){
				return false;
			}
			break;
		}
		case Sim::Left:
		{
			if (this->currentPos[0]==0)
			{
				return false;
			}
			break;
		}
		case Sim::Right:
		{
			if (this->currentPos[0]==4)
			{
				return false;
			}
			break;
		}
		case Sim::Down:
		{
			if (this->currentPos[1]==4)
			{
				return false;
			}
			break;
		}
		default:
		{
			printf("Wrong direction input is given!!\n");
			return false;
			break;
		}
	}
	return true;
}

bool Sim::moveToDirection()
{
	if ( !checkMovability() )
	{
		return false;
	}

	switch(this->move){
		case Sim::Up:
		{
			this->currentPos[1] -= 1;
			break;
		}
		case Sim::Left:
		{
			this->currentPos[0] -= 1;
			break;
		}
		case Sim::Right:
		{
			this->currentPos[0] += 1;
			break;
		}
		case Sim::Down:
		{
			this->currentPos[1] += 1;
			break;
		}
		default:
		{
			printf("I'm stunned!\n");
			return false;
			break;
		}
	}
	this->move = Sim::None;
	return true;
}

bool Sim::checkSuccess()
{
	if (this->leftFoodCount == 5)
	{
		this->Success = true;
		return true;
	}
	return false;
}

Sim::~Sim() {	}