/********************************************************************
* Filename: matrix.cpp
* Author: Pete Sripitak
* Description: This program takes in two matrices with the dimensions of
* the two as the input. The output is the transpose of matrix A, A*B, if B
* is symmetric, and A+B.
********************************************************************/

#include <iostream>

using namespace std;

const int maxR = 10, maxC = 10;

//function to input and output matrix A
void matrixA(int arrayA[][maxC], int &row, int &col);
//function to input and output matrix B
void matrixB(int arrayB[][maxC], int &row, int &col);
//prints out the tranposed matrix of matrix A
void transposedA(int arrayA[][maxC], int row, int col);
//prints out the product of A*B
void multiplication(int arrayA[][maxC], int arrayB[][maxC], int rowA, int colA, int rowB, int colB);
//checks if matrix B is symmetric
bool symmetricB(int arrayB[][maxC], int rowB, int colB);
//prints out the sum of A+B
void addMatrix(int arrayA[][maxC], int arrayB[][maxC], int rowA, int colA, int rowB, int colB);

int main()
{
	int rowA, colA, rowB, colB;	//the rows and columns of matrix A and B
	int arrayA[maxR][maxC]; //creating array A
	int arrayB[maxR][maxC]; //creating arrayB
	
	rowA = colA = rowB = colB = 0;	//initialize all the rows and columns
	
	matrixA(arrayA, rowA, colA);	//function call to matrixA (input/output)
	
	matrixB(arrayB, rowB, colB);	//function call to matrixB (input/output)
	
	transposedA(arrayA, rowA, colA);	//function call to the transposed matrix A
	
	cout << endl;
	
	multiplication(arrayA, arrayB, rowA, colA, rowB, colB);	//function call to A*B matrix
	
	cout << endl;
	
	//if matrix B is symmetric
	if(symmetricB(arrayB, rowB, colB))
	{
		cout << "B is symmetric!" << endl << endl;
	}
	//if matrix B is not symmetric
	else
		cout << "B is NOT symmetric!" << endl << endl;

	
	addMatrix(arrayA, arrayB, rowA, colA, rowB, colB);	//function call to A+B matrix
	cout << endl;
	
	return 0;
}
//function to input and output matrix A
void matrixA(int arrayA[][maxC], int &row, int &col)
{
	//Matrix A input section.
	cout << "Input the dimensions for matrix A\n";
	//input into the row and collumn number of matrix A unless redirected from a file
	cin >> row >> col;
	
	cout << "Input matrix A\n";
	//input/output the matrix
	for(int x = 0; x < row; x++)
	{	//loops and provide input/output for arrayA
		for(int y = 0; y < col; y++)
		{
			cin >> arrayA[x][y];
			cout << arrayA[x][y] << " ";
		}
		cout << endl;
	}
	
	cout << endl;
}
//function to input and output matrix B
void matrixB(int arrayB[][maxC], int &row, int &col)
{
	//Matrix B input section.
	cout << "Input the dimensions for matrix B\n";
	//input into the row and collumn number of matrix B unless redirected from a file
	cin >> row >> col;
	
	cout << "Input matrix B\n";
	//input/output the matrix
	for(int x = 0; x < row; x++)
	{	//loops and provide input/output for arrayB
		for(int y = 0; y < col; y++)
		{
			cin >> arrayB[x][y];
			cout << arrayB[x][y] << " ";
		}
		cout << endl;
	}
	
	cout << endl;
}
//prints out the tranposed matrix of matrix A
void transposedA(int arrayA[][maxC], int row, int col)
{
	//Transpose of array A
	cout << "The transpose of A is:\n";
	int transposedA[maxR][maxC];  //temporary array to transpose arrayA
	for(int x = 0; x < row; x++)
	{	//loops and sets the transposed matrix of A
		for(int y = 0; y < col; y++)
		{
			transposedA[y][x] = arrayA[x][y];
		}
	}
	
	//output of the transposedA array
	for(int x = 0; x < col; x++)
	{	//loops and provides output to the transposed matrix of A
		for(int y = 0; y < row; y++)
		{
			cout << transposedA[x][y] << " ";
		}
		cout << endl;
	}
}
//prints out the product of A*B
void multiplication(int arrayA[][maxC], int arrayB[][maxC], int rowA, int colA, int rowB, int colB)
{
	//A*B
	cout << "A*B is:\n";
	//check to see if it is possible to get the product
	if(colA == rowB)
	{	int productArray[maxR][maxC];	// A*B array
		for(int x = 0; x < rowA; x++)
		{
			for(int y = 0; y < colB; y++)
			{
				productArray[x][y] = 0;
				//loops and sets the product of A*B into a third array
				for(int z = 0; z < colA; z++)
				{
					productArray[x][y] = productArray[x][y] + (arrayA[x][z] * arrayB[z][y]);
				}
				//prints out the product of A*B
				cout << productArray[x][y] << " ";
			}
			cout << endl;
		}
	}
	
	//if it is not possible to get the product of the array
	else
		cout << "not possible" << endl;
}
//checks if matrix B is symmetric
bool symmetricB(int arrayB[][maxC], int rowB, int colB)
{
	//Is B symmetric?
	if(rowB == colB)
	{	//loops and checks if the matrix is symmetric
		for(int x = 0; x < rowB; x++)
		{	//loops and checks if the matrix is symmetric
			for(int y = 0; y < colB; y++)
			{	//checks if in the main diagonal of the matrix
				if(x != y)
				{
					if(arrayB[x][y] == arrayB[y][x])
					{
						//keep checking if it is symmetric
					}
						
					else
						return false;	//returns false if the array is not symmetric
				}
			}
		}
	}
	//if B is not symmetric
	else
		return false;	//returns false if the array is not a square
	
	return true;	//returns true after checking if it is symmetric
}
//prints out the sum of A+B
void addMatrix(int arrayA[][maxC], int arrayB[][maxC], int rowA, int colA, int rowB, int colB)
{
	//A+B
	cout << "A+B is:\n";
	
	int addition[maxR][maxC];
	//check if the dimensions of matrix A and B are the same
	if(rowA == rowB && colA == colB)
	{
		for(int x = 0; x < rowA; x++)
		{
			for(int y = 0; y < colA; y++)
			{
				addition[x][y] = 0;
				addition[x][y] += (arrayA[x][y] + arrayB[x][y]);
			}
		}
	}
	//if the dimensions are not the same
	else
	{
		cout << "not possible" << endl;
		return;
	}
	//prints out the sum of A+B
	for(int x = 0; x < rowA; x++)
	{
		for(int y = 0; y < colA; y++)
		{
			cout << addition[x][y] << " ";
		}
		
		cout << endl;
	}
}
