#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
int** alloc2DInt(int row, int col)
{
	if(row <= 0 || col <= 0) 
	{
		return NULL;
	}
	int** mat = new int*[row];
		for(int i=0; i<row; i++)
		{
			mat[i] = new int[col];
		}
	return mat;
}

void free2DInt(int** mat, int row, int col = 0)
{
	if(mat != NULL){
		for(int i=0; i<row; i++)
		{
			delete[] mat[i];
		}
	delete[] mat;
	}
}

void set2D(int **mat, int row, int col)
{
	for (int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			mat[i][j]=(i+1)*(j+1);
		}
	}
}

void print2DInt(int **mat, int row, int col)
{
	printf("\n\n");
	for(int i=0;i<row;i++)
	{
		for(int j=0; j<col; j++)
		{
			printf("%4d", mat[i][j]);
		}
		printf("\n");
	}
}


int main()
{
	int** mat;
	
	class Matsize{
		public:
			int row, col;
			Matsize(int r=0, int c=0){
				row = r;
				col = c;
		}
		
		void setSize(int r,int c){
			row = r;
			col = c;
		}
	};
	
	Matsize s[4];
	s[0].setSize(3,4);
	s[1].setSize(7,10);
	s[2].setSize(12,6);
	s[3].setSize(16,8);
	
	
	for (int i=0; i<4; i++)
	{
		printf("%d row %d col \n", s[i].row, s[i].col);
		mat = alloc2DInt(s[i].row, s[i].col); //2차원 배열을 동적으로 할당하는 함수
		set2D(mat, s[i].row, s[i].col); //mat[i][j]=(i+1)*(j+1)
		print2DInt(mat, s[i].row, s[i].col); //2차원 배열 출력함수
		free2DInt(mat, s[i].row, s[i].col); //동적할당되었던 2차원 배열 삭제함수
	
		cout<<endl;
	}
	
	return 0;
}