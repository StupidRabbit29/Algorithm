#include "class.h"

using namespace std;

Eight_Puzzle::Eight_Puzzle()
{
	for (int i = 1; i < 10; i++)
		node.push_back(i);
}

Eight_Puzzle::Eight_Puzzle(vector<int> node)
{
	if (node.size == 9)
		for (auto it = node.begin(); it != node.end(); it++)
			this->node.push_back(*it);
	else
		Eight_Puzzle();
}

Eight_Puzzle::Eight_Puzzle(Eight_Puzzle& puzzle)
{
	for (auto it = puzzle.node.begin(); it != puzzle.node.end(); it++)
		this->node.push_back(*it);
}

bool Eight_Puzzle::Go_left()
{
	vector<int>::iterator it = find(node.begin(), node.end(), 9);
	if (node.begin() == it)
		return false;
	else
	{
		vector<int>::iterator left = it - 1;
		int temp = *it;
		*it = *left;
		*left = temp;

		return true;
	}
}

bool Eight_Puzzle::Go_right()
{
	vector<int>::iterator it = find(node.begin(), node.end(), 9);
	if (node.end() == it + 1)
		return false;
	else
	{
		vector<int>::iterator right = it + 1;
		int temp = *it;
		*it = *right;
		*right = temp;

		return true;
	}
}

bool Eight_Puzzle::Go_up()
{
	vector<int>::iterator it = find(node.begin(), node.end(), 9);

	int number = 1;
	for (auto i = node.begin(); i != node.end(); i++, number++)
		if (i == it)
			break;

	if (number<4)
		return false;
	else
	{
		vector<int>::iterator up = it - 3;
		int temp = *it;
		*it = *up;
		*up = temp;

		return true;
	}
}

bool Eight_Puzzle::Go_down()
{
	vector<int>::iterator it = find(node.begin(), node.end(), 9);

	int number = 1;
	for (auto i = node.begin(); i != node.end(); i++, number++)
		if (i == it)
			break;

	if (number > 6)
		return false;
	else
	{
		vector<int>::iterator down = it + 3;
		int temp = *it;
		*it = *down;
		*down = temp;

		return true;
	}
}
