#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Eight_Puzzle
{
public:
	Eight_Puzzle();
	Eight_Puzzle(vector<int>node);
	Eight_Puzzle(Eight_Puzzle& puzzle);

	bool Go_left();
	bool Go_right();
	bool Go_up();
	bool Go_down();
private:
	vector<int>node;
};