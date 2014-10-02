/*
围着矩阵一层一层的向里面打印
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int M = 103;
int matrix[M][M];



void solve(const int row, const int col){
	int count = 1;
	int matrix[M][M];
	memset(matrix, -1, sizeof(matrix));
	matrix[0][0] = count;
	int i = 0, j = 0;
	while(count < row * col){
		//cout << count << endl;
		while(j + 1 < col && matrix[i][j + 1] == -1){
			matrix[i][++j] = ++count;
		}
		while(i + 1 < row && matrix[i + 1][j] == -1){
			matrix[++i][j] = ++count;
		}
		while(j - 1 >= 0 && matrix[i][j - 1] == -1){
			matrix[i][--j] = ++count;
		}
		while(i - 1 >= 0 && matrix[i - 1][j] == -1){
			matrix[--i][j] = ++count;
		}
	}
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int main(){
	
	int row = 3, col = 11;

	solve(row, col);

	return 0;
}
