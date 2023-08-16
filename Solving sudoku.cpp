#include <bits/stdc++.h>
using namespace std;


class sodokuSolver {
public:
	
void print(int arr[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}
 

bool isSafe(int grid[9][9], int row,
                       int col, int num)
{
 
    for (int x = 0; x <8; x++)
        if (grid[row][x] == num)
            return false;
 
   
    for (int x = 0; x <= 8; x++)
        if (grid[x][col] == num)
            return false;
 
    int startRow = row - row % 3,
            startCol = col - col % 3;
   
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j +
                            startCol] == num)
                return false;
 
    return true;
}
 

bool solveSudoku(int grid[9][9], int row, int col)
{
    
    if (row == 9 - 1 && col == 9)
        return true;
 
    if (col == 9) {
        row++;
        col = 0;
    }
   
 
    if (grid[row][col] > 0)
        return solveSudoku(grid, row, col + 1);
 
    for (int num = 1; num <= 9; num++)
    {
         
 
        if (isSafe(grid, row, col, num))
        {
             
 
            grid[row][col] = num;
           
          
            if (solveSudoku(grid, row, col + 1))
                return true;
        }
       
     
        grid[row][col] = 0;
    }
    return false;
}
};



// sodoku solver driver code
main()
{
int sudoku[9][9];

      cout<<"\n1st Matrix Input:\n";
	  for(int i=0;i<9;i++)
	  {
	  	for(int j=0;j<9;j++)
	  	{
	  		cout<<"\nmatrix1["<<i<<"]["<<j<<"]=  ";
	  		cin>>sudoku[i][j];
		}
	  } 
	  
	  sodokuSolver solve;
	   if (solve.solveSudoku(sudoku, 0, 0))
        solve.print(sudoku);
    else
        cout << "no solution  exists " << endl;
 
    return 0;
	  

	  
	  
}
