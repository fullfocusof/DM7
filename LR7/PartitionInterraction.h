#pragma once
#include <iostream>
#include <sstream>

#include <vector>
#include <string>

#include <algorithm>

#include <Windows.h>
#include <conio.h>

using namespace std;

class PartitionInterraction
{

public:

	PartitionInterraction();

	void printQuit();

	void genParts(vector<vector<int>>& result, int n);
	vector<vector<int>> convertToSets(vector<int> part);

	void printStTriangleII(vector<vector<int>>& triangle, int str);
	void printStTriangleIIRecurrent(vector<vector<int>>& triangle, int str);

	vector<vector<int>> genAllPerm(int n);
	void printStTriangleI(vector<vector<int>>& triangle, int str);
	void printStTriangleIRecurrent(vector<vector<int>>& triangle, int str);
};