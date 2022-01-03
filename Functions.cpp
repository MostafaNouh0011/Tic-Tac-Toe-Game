#include "Header.h"

char matrix[3][3] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char player = 'x';

void printMatrix()
{
	system("cls");

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "\t" << matrix[i][j] << "\t";
		}
		cout << "\n\n";
	}
}

void play()
{
	char pos;
	cout << " Enter position of player ( " << player << " )" << endl;
	cin >> pos;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (matrix[i][j] == pos)
			{
				matrix[i][j] = player;
			}
		}
	}
	if (player == 'x')
		player = 'o';
	else
		player = 'x';
}
char whoWin()
{
	int xCount = 0;
	int oCount = 0;
	int counter = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (matrix[i][j] != 'x' && matrix[i][j] != 'o') {
				counter++;
			}
			if (matrix[i][j] == 'x') {
				xCount++;
			}
			else if (matrix[i][j] == 'o') {
				oCount++;
			}
			if (xCount == 3 || oCount == 3) {
				return xCount > oCount ? 'x' : 'o';
			}
		}
		xCount = 0;
		oCount = 0;
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (matrix[j][i] == 'x') {
				xCount++;
			}
			else if (matrix[j][i] == 'o') {
				oCount++;
			}
			if (xCount == 3 || oCount == 3)
				return xCount > oCount ? 'x' : 'o';
		}
		xCount = 0;
		oCount = 0;
	}

	if (matrix[0][0] == 'x' && matrix[1][1] == 'x' && matrix[2][2]=='x') {
		return 'x';
	}
	else if (matrix[0][2] == 'x' && matrix[1][1] == 'x' && matrix[2][0] == 'x') {
		return 'x';
	}
	else if (matrix[0][0] == 'o' && matrix[1][1] == 'o' && matrix[2][2] == 'o') {
		return 'o';
	}
	else if (matrix[0][2] == 'o' && matrix[1][1] == 'o' && matrix[2][0] == 'o') {
		return 'x';
	}

	if (counter == 0)
		return 'z';

	return '.';
}
