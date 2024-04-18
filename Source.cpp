#include <iostream>
using namespace std;

const int ROWS = 6;
const int COLUMNS = 13;
int findRowIndex(int thisRow);
int findSeatIndex(char thisSeat);
void displaySeatColumn(char seats[][COLUMNS], int column);

int main()
{
	char seats[ROWS][COLUMNS];

	for (int i = 0; i < COLUMNS - 1; i++)
	{
		seats[0][i] = 'D';


	}


	for (int i = 0; i < COLUMNS - 1; i++)
	{
		seats[1][i] = 'C';

	}


	for (int i = 0; i < COLUMNS; i++)
	{
		if (i <= 8)
		{
			seats[2][i] = ' ';
		}
		else
		{
			seats[2][i] = '1';
		}

	}

	int j = 0;
	for (int i = 0; i < COLUMNS; i++)
	{
		if (i <= 8)
		{
			int temp = i + 1;
			char x = temp + 48;
			seats[3][i] = x; 
		}
		else
		{

			char y = j + 48;
			seats[3][i] = y;
			j++;
		}

	}


	for (int i = 0; i < COLUMNS; i++)
	{
		seats[4][i] = 'B';

	}
	cout << endl;

	for (int i = 0; i < COLUMNS; i++)
	{
		seats[5][i] = 'A';

	}
	while (true)
	{
		displaySeatColumn(seats, COLUMNS);
		cout << "Enter a seat or Q to quit: ";
		int row;
		char column;
		cin >> row >> column;
		if (cin.fail())
		{
			break;
		}
		int seatindex = findSeatIndex(column);
		if (seatindex == -1)
		{
			cout << "Sorry, no such seat exists on the CRJ 200." << endl;
		}
		int rowindex = findRowIndex(row);
		if (seatindex == 1 || seatindex == 0 && rowindex == 13)
		{
			cout << "Sorry, no such seat exists on the CRJ 200." << endl;
		}
		if (rowindex > 12 || rowindex < 0)
		{
			cout << "Sorry, no such seat exists on the CRJ 200." << endl;
		}
		if (seats[seatindex][rowindex] != 'X')
		{
			seats[seatindex][rowindex] = 'X';
		}
		else
		{
			cout << "Sorry, seat already assigned." << endl;
		}
		cout << endl;
	}
}

int findRowIndex(int thisRow)
{
	return thisRow - 1;
}


int findSeatIndex(char thisSeat)
{
	if (thisSeat == 'D')
	{
		return 0;
	}
	if (thisSeat == 'C')
	{
		return 1;
	}
	if (thisSeat == 'B')
	{
		return 4;
	}
	if (thisSeat == 'A')
	{
		return 5;
	}
	else
	{
		return -1;
	}
}

void displaySeatColumn(char seats[][COLUMNS], int column)
{
	for (int i = 0; i < COLUMNS - 1; i++)
	{
		cout << seats[0][i] << " ";
	}
	cout << endl;

	for (int i = 0; i < COLUMNS - 1; i++)
	{
		cout << seats[1][i] << " ";
	}
	cout << endl << endl;

	for (int i = 0; i < COLUMNS; i++)
	{
		cout << seats[2][i] << " ";
	}
	cout << endl;
	int j = 0;
	for (int i = 0; i < COLUMNS; i++)
	{
		cout << seats[3][i] << " ";
	}
	cout << endl << endl;

	for (int i = 0; i < COLUMNS; i++)
	{
		cout << seats[4][i] << " ";
	}
	cout << endl;

	for (int i = 0; i < COLUMNS; i++)
	{
		cout << seats[5][i] << " ";
	}
	cout << endl;
}