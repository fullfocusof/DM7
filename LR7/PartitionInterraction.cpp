#include "PartitionInterraction.h"

PartitionInterraction::PartitionInterraction()
{

}

void PartitionInterraction::printQuit()
{
	cout << endl << endl << "Backspace - возврат в меню";

	int answ = _getch();
	bool press = false;

	while (!press)
	{
		if (answ == 8)
		{
			press = true;
			break;
		}
		else
		{
			answ = _getch();
		}
	}

	system("cls");
}

void PartitionInterraction::genParts(vector<vector<int>>& result, int n)
{
	vector<int> a(n);
	vector<int> b(n, 1);
	int m = 1, j = n - 2;

	if (n == 1)
	{
		result.push_back(a);
	}

	while (j >= 0)
	{
		result.push_back(a);

		if (a[n - 1] != m) ++a[n - 1];
		else
		{
			while (a[j] == b[j])
			{
				--j;
			}

			if (j == 0) break;
			else ++a[j];

			m = b[j] + (a[j] == b[j]);
			++j;

			while (j < n)
			{
				a[j] = 0;
				b[j] = m;
				++j;
			}

			a[n - 1] = 0;
			j = n - 2;

		}
	}
}

vector<vector<int>> PartitionInterraction::convertToSets(vector<int> part)
{
	vector<vector<int>> onePart;
	vector<int> curBlock;

	vector<pair<int, int>> temp;
	for (int i = 0; i < part.size(); i++)
	{
		temp.push_back(make_pair(part[i], i));
	}
	sort(temp.begin(), temp.end());

	for (int i = 0; i < temp.size(); i++)
	{
		if (i == 0 || temp[i].first != temp[i - 1].first)
		{
			if (!curBlock.empty())
			{
				onePart.push_back(curBlock);
				curBlock.clear();
			}
		}
		curBlock.push_back(temp[i].second + 1);
	}

	if (!curBlock.empty())
	{
		onePart.push_back(curBlock);
	}
	

	return onePart;
}

void PartitionInterraction::printStTriangleII(vector<vector<int>>& triangle, int str)
{
	if (str == 0)
	{
		triangle.push_back(vector<int>{1});
		return;
	}

	printStTriangleII(triangle, str - 1);

	vector<int> result(str + 1);
	result[0] = 0;

	vector<int> blocks;
	vector<vector<int>> temp;
	genParts(temp, str);
		
	for (auto& row : temp)
	{
		auto cntOfBlocks = max_element(row.begin(), row.end());
		int cnt = *cntOfBlocks + 1;

		blocks.push_back(cnt);
	}

	for (int i = 0; i < blocks.size(); i++)
	{
		result[blocks[i]]++;
	}
	
	triangle.push_back(result);
}

void PartitionInterraction::printStTriangleIIRecurrent(vector<vector<int>>& triangle, int str)
{
	triangle[0][0] = 1;

	for (int i = 1; i < str; i++)
	{
		triangle[i][0] = 0;
		for (int j = 1; j <= i; j++)
		{
			triangle[i][j] = j * triangle[i - 1][j] + triangle[i - 1][j - 1];
		}
	}
}

vector<vector<int>> PartitionInterraction::genAllPerm(int n)
{
	vector<int> variety;

	for (int i = 0; i < n; i++)
	{
		variety.push_back(i + 1);
	}

	vector<vector<int>> result;
	result.push_back(variety);

	do
	{
		int i = variety.size() - 2;
		while (i >= 0 && variety[i] >= variety[i + 1])
		{
			i--;
		}

		if (i < 0)
		{
			reverse(variety.begin(), variety.end());
			break;
		}

		int lastId = variety.size() - 1;
		while (lastId > i && variety[lastId] <= variety[i])
		{
			lastId--;
		}

		swap(variety[i], variety[lastId]);
		reverse(variety.begin() + i + 1, variety.end());

		result.push_back(variety);

	} while (!is_sorted(variety.begin(), variety.end()));

	return result;
}

int countCycles(const vector<int>& perm) 
{
	int count = 0, n = perm.size();
	vector<bool> visited(n + 1);

	for (int i = 1; i <= n; i++) 
	{
		if (!visited[i]) 
		{
			int curr = i;
			while (!visited[curr]) 
			{
				visited[curr] = true;
				curr = perm[curr - 1];
			}
			count++;
		}
	}

	return count;
}

void PartitionInterraction::printStTriangleI(vector<vector<int>>& triangle, int str)
{
	if (str == 0)
	{
		triangle.push_back(vector<int>{1});
		return;
	}

	printStTriangleI(triangle, str - 1);

	vector<vector<int>> allPerm = genAllPerm(str);
	vector<int> cyclesVec;

	vector<int> result(str + 1);
	result[0] = 0;

	for (auto perm : allPerm)
	{
		int cntOfCycles = countCycles(perm);
		cyclesVec.push_back(cntOfCycles);
	}

	for (auto el : cyclesVec)
	{
		result[el]++;
	}

	triangle.push_back(result);
}

void PartitionInterraction::printStTriangleIRecurrent(vector<vector<int>>& triangle, int str)
{
	triangle[0][0] = 1;

	for (int i = 1; i < str; i++)
	{
		triangle[i][0] = 0;
		for (int j = 1; j <= i; j++)
		{
			triangle[i][j] = (i - 1) * triangle[i - 1][j] + triangle[i - 1][j - 1];
		}
	}
}