#include "PartitionInterraction.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13
#define KEY_ESC 27
#define KEY_BACKSPACE 8

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

void GoToXY(short x, short y)
{
	SetConsoleCursorPosition(hStdOut, { x, y });
}

void ConsoleCursorVisible(bool show, short size)
{
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = show;
	structCursorInfo.dwSize = size;
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
}

int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleTitle(L"Размещения и сочетания");
	ConsoleCursorVisible(false, 100);
	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);

	PartitionInterraction test;

	int active_menu = 0;
	int keyInput;
	bool exitProg = false;

	while (!exitProg)
	{
		int x = 40, y = 12;
		GoToXY(x, y);

		vector<string> menu =
		{
			"Лексикографическая генерация разбиений",
			"Треугольник Стирлинга II рода",
			"Треугольник Стирлинга II рода(рекуррентное соотношение)",
			"Треугольник Стирлинга I рода",
			"Треугольник Стирлинга I рода(рекуррентное соотношение)",
			"Выход"
		};

		for (int i = 0; i < menu.size(); i++)
		{
			if (i == active_menu)
			{
				SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			}
			else
			{
				SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
			}

			GoToXY(x, y++);
			cout << menu[i] << endl;
		}

		keyInput = _getch();
		switch (keyInput)
		{
			case KEY_ESC:
				exit(0);

			case KEY_UP:
			{
				if (active_menu > 0)
				{
					active_menu--;
				}
			}
			break;

			case KEY_DOWN:
			{
				if (active_menu < menu.size() - 1)
				{
					active_menu++;
				}
			}
			break;

			case KEY_ENTER:
			{
				switch (active_menu)
				{
					case 0:
					{
						system("cls");

						int n;
						cout << "Введите количество элементов множества" << endl;
						cin >> n;

						while (n < 0)
						{
							system("cls");
							cout << "Неверные данные" << endl <<
									"Введите корректное количество элементов множества" << endl;
							cin >> n;
						}

						vector<vector<int>> allParts;
						test.genParts(allParts, n);

						system("cls");

						cout << "Разбиения " << n << "-множества" << endl;
						if (allParts.empty())
						{
							cout << "<пустое множество>";
						}

						for (auto row : allParts)
						{
							vector<vector<int>> temp = test.convertToSets(row);

							for (auto blockIt = temp.begin(); blockIt != temp.end(); ++blockIt)
							{
								for (auto elIt = blockIt->begin(); elIt != blockIt->end(); ++elIt)
								{
									cout << *elIt << " ";
								}

								if (blockIt != temp.end() - 1)
								{
									cout << " | ";
								}		
							}
							cout << endl;
						}

						test.printQuit();
					}
					break;

					case 1:
					{
						system("cls");

						int n;
						cout << "Введите количество выводимых строк треугольника Стирлинга II рода" << endl;
						cin >> n;

						while (n < 1)
						{
							system("cls");
							cout << "Неверные данные" << endl <<
								"Введите корректное количество выводимых строк треугольника Стирлинга II рода" << endl;
							cin >> n;
						}

						vector<vector<int>> result;
						test.printStTriangleII(result, n - 1);

						int maxLengthRow = 0;
						for (auto& row : result)
						{
							if (row.size() > maxLengthRow)
							{
								maxLengthRow = row.size();
							}
						}
					
						for (auto& row : result)
						{
							while (row.size() < maxLengthRow)
							{
								row.push_back(0);
							}
						}

						system("cls");
						for (auto& row : result)
						{
							for (auto el : row)
							{
								cout << el << "\t";
							}
							cout << endl;
						}

						test.printQuit();
					}
					break;

					case 2:
					{
						system("cls");

						int n;
						cout << "Введите количество выводимых строк треугольника Стирлинга II рода" << endl;
						cin >> n;

						while (n < 1)
						{
							system("cls");
							cout << "Неверные данные" << endl <<
								"Введите корректное количество выводимых строк треугольника Стирлинга II рода" << endl;
							cin >> n;
						}

						vector<vector<int>> result(n, vector<int>(n));
						test.printStTriangleIIRecurrent(result, n);

						system("cls");
						for (auto& row : result)
						{
							for (auto el : row)
							{
								cout << el << "\t";
							}
							cout << endl;
						}

						test.printQuit();
					}
					break;

					case 3:
					{
						system("cls");

						int n;
						cout << "Введите количество выводимых строк треугольника Стирлинга I рода" << endl;
						cin >> n;

						while (n < 1)
						{
							system("cls");
							cout << "Неверные данные" << endl <<
								"Введите корректное количество выводимых строк треугольника Стирлинга I рода" << endl;
							cin >> n;
						}

						vector<vector<int>> result;
						test.printStTriangleI(result, n - 1);

						int maxLengthRow = 0;
						for (auto& row : result)
						{
							if (row.size() > maxLengthRow)
							{
								maxLengthRow = row.size();
							}
						}

						for (auto& row : result)
						{
							while (row.size() < maxLengthRow)
							{
								row.push_back(0);
							}
						}

						system("cls");
						for (auto& row : result)
						{
							for (auto el : row)
							{
								cout << el << "\t";
							}
							cout << endl;
						}

						test.printQuit();
					}
					break;

					case 4:
					{
						system("cls");

						int n;
						cout << "Введите количество выводимых строк треугольника Стирлинга I рода" << endl;
						cin >> n;

						while (n < 1)
						{
							system("cls");
							cout << "Неверные данные" << endl <<
								"Введите корректное количество выводимых строк треугольника Стирлинга I рода" << endl;
							cin >> n;
						}

						vector<vector<int>> result(n, vector<int>(n));
						test.printStTriangleIRecurrent(result, n);

						system("cls");
						for (auto& row : result)
						{
							for (auto el : row)
							{
								cout << el << "\t";
							}
							cout << endl;
						}

						test.printQuit();
					}
					break;

					case 5:
					{
						exitProg = true;
					}
					break;
				}
			}
			break;
		}


	}
}