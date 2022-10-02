#include<bits/stdc++.h>
using namespace std;


bool isSafe(int mat[][9],int i,int j,int no,int n){

	//check for row and column
	for(int k=0;k<n;k++){
		if(mat[k][j]==no || mat[i][k]==no){
			return false;
		}
	}

	//check for subgrid
	int sx=(i/3)*3;

	int sy=(j/3)*3;

	for(int x=sx;x<sx;x++){
		for(int y=sy;y<sy+3;y++){
			if(mat[x][y]==no){
				return false;
			}
		}
	}
	return true;
}


bool solveSudoku(int mat[][9],int i,int j,int n){

	//base case
	if(i==n){

		//print the solution later
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				cout<<mat[i][j]<<" ";
			}
		}

		return true;
	}


	//recursive case
	if(j==n){

		return solveSudoku(mat,i+1,0,n);
	}

	if(mat[i][j]!=0){

		return solveSudoku(mat,i,j+1,n);
	}

	//cell to be filled
	//try out all possibilities
	for(int no=1;no<=n;no++){

		//whether it is safe to place the number or not
		if(isSafe(mat,i,j,no,n)){

			mat[i][j]=no;
			bool solveSudoku=solveSudoku(mat,i,j+1,n);

			if(solveSudoku==true){
				return true;
			}


		}

	}
	//if no option works
	mat[i][j]=0;
	return false;



	//calculation


}


int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	  int mat[9][9] =
        {
            {5, 3, 0, 0, 7, 0, 0, 0, 0},
            {6, 0, 0, 1, 9, 5, 0, 0, 0},
            {0, 9, 8, 0, 0, 0, 0, 6, 0},
            {8, 0, 0, 0, 6, 0, 0, 0, 3},
            {4, 0, 0, 8, 0, 3, 0, 0, 1},
            {7, 0, 0, 0, 2, 0, 0, 0, 6},
            {0, 6, 0, 0, 0, 0, 2, 8, 0},
            {0, 0, 0, 4, 1, 9, 0, 0, 5},
            {0, 0, 0, 0, 8, 0, 0, 7, 9}};
 

}
