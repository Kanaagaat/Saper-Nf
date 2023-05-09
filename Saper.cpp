#include <iostream>
#include <algorithm>
#include <windows.h>

using namespace std;

const int v = 10, sh = 10;
char sap[v][sh], sap1[v][sh];
void music() {
	Beep(247, 500);
	Beep(417, 500);
	Beep(417, 500);
	Beep(370, 500);
	Beep(417, 500);
	Beep(329, 500);
	Beep(247, 500);
	Beep(247, 500);
	Beep(247, 500);
	Beep(417, 500);
	Beep(417, 500);
	Beep(370, 500);
	Beep(417, 500);
	Beep(497, 500);
	Sleep(500);
	Beep(497, 500);
	Beep(277, 500);
	Beep(277, 500);
	Beep(440, 500);
	Beep(440, 500);
	Beep(417, 500);
	Beep(370, 500);
	Beep(329, 500);
	Beep(247, 500);
	Beep(417, 500);
	Beep(417, 500);
	Beep(370, 500);
	Beep(417, 500);
	Beep(329, 500);
}
void game(char a[v][sh])
{
	char cnt = 43;
	int point = 0;
	system("cls");
	char ch = '#';
	srand(time(NULL));
	string str = "0123456789";//таблица
	string stl = "0123456789";//таблица


	for (int i = 0; i < v; i++)//таблица решеток
	{
		for (int j = 0; j < sh; j++)
		{

			sap[i][j] = ch;
			cout << ' ' << sap[i][j] << " ";
		}
		cout << endl;
	}


	for (int i = 0; i < v; i++)//
	{
		for (int j = 0; j < sh; j++)
		{
			sap1[i][j] = sap[i][j];
		}
	}


	for (int i = 0; i < 15; i++)//рандомный генератор бомб
	{
		int k, j;
		k = rand() % 10;
		j = rand() % 10;

		sap1[k][j] = '*';
	}


	//for (int i = 0; i < v; i++)//таблица решеток
	//{
	//	for (int j = 0; j < sh; j++)
	//	{

	//		cout  << ' ' << sap1[i][j] << " ";
	//	}
	//	cout << endl;
	//}


	while (true)
	{
		int x, y;
		cout << "Write cordinat that you want (x, y) -> ";
		cin >> x >> y;

		cout << endl;

		if (sap1[x][y] == '*')
		{
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_RED | FOREGROUND_RED);
			cout << "YOU LOSS";
			Sleep(2000);
			music();
			system("cls");
			break;

		}


		else
		{
			system("cls");
			sap[x][y] = cnt;
			point++;

			for (int i = 0; i < v; i++)//таблица решеток
			{
				for (int j = 0; j < sh; j++)
				{
					cout << ' ' << sap[i][j] << " ";
				}
				cout << endl;
			}

			cout << "SCORE : " << point << endl;

		}

	}




}


int main()
{
	while (true)
	{
		setlocale(LC_ALL, "ru");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);


		cout << "Choice Option: \n\n";
		cout << " 1 -> Start Game\n";
		cout << " 2 -> About\n";
		cout << " 3 -> Quit\n\n";
		cout << "Write your option -> ";


		int op;
		cin >> op;

		if (op == 3)
		{
			return 0;
		}
		else if (op == 2)
		{
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "Made by Dobryi(kana)\n";
			cout << "Trun back (y): ";
			char yn; cin >> yn;
			if (yn == 'y')
			{
				system("cls");
			}


		}
		else if (op == 1)
		{
			game(sap);

		}


	}
}