#include "Header.h"

int main()
{
	while (whoWin()=='.')
	{
		printMatrix();
		play();
	}
	printMatrix();
	if (whoWin() == 'z')
		cout << " Game Over! \n No winner yet \n";
	else
		cout << " The winner is player ( " << whoWin() << " ) \n" << endl;

	system("pause");

	return 0;
}