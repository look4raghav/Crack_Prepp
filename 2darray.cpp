#include<iostream>
using namespace std;

int **getArray(int n , int m){
	int **arr = new int*[n];
	for(int i = 0; i<n; i++){
		arr[i] = new int[m];
		for(int j = 0; j<m; j++){
			arr[i][j] = i+j;
		}
	}
	return arr;
}

int main()
{
	int **ans;
	int row = 4;
	int col = 4;
	ans = getArray(row,col);
	for(int i = 0; i<row; i++){
		for(int j = 0; j<col; j++){
			cout<<ans[i][j];
		}
		cout<<endl;
	}
	return 0;
}