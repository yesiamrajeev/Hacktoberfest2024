/*Perform searching operation on the basis of position and value

*/

#include<iostream>

using namespace std;

int main()
{
	int array[2][2];
	int choice, pos1,pos2, value, i, j,w,z, row,column;
	while (true)
	{
		for (int i = 0; i < 2; i++)
			for(int j=0;j<2;j++)
		{
			cout << "Enter value in row  "<< i + 1 << endl;
			cout << "Enter value in coloumn  " << j + 1 << endl;
			cin >> array[i][j];
		}

		cout << "Press 1 for searching on the basis of position" << endl;
		cout << "Press 2 for searching on the basis of value " << endl;
		cout << "Press any key to exit" << endl;
		cin >> choice;

		if (choice == 1)
		{
			
			cout << "Enter the row number you want to search" << endl;
			cin >> row;
			cout << "Enter the column number you want to search" << endl;
			cin >> column;
	cout << "The value in your searched position is  " << array[row - 1][column -1] << endl;

	exit(0);
		}
		else if (choice == 2)
		{

			cout << "Enter the value you want to search" << endl;
			cin >> value;
			pos1 = 0;
			pos2 = 0;
			for (int x = 0;x < 2; x++)
				for (int y = 0; y < 2; y++)
				if (value == array[x][y])
				{
					pos1 = x + 1;
					pos2 = y + 1;
				}
			if (pos1 == 0 || pos2 == 0)
			{
				cout << "Value not found in array" << endl;
			}
			else
			{
				cout << "Value is present at row " << pos1 << " and column " << pos2 << endl;
			}
			break;
		}

		else
		{
			cout << "Program is terminated" << endl;
			exit(0);
		}

	}
}
