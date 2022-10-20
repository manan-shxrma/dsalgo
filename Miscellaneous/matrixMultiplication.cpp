#include<iostream>
using namespace std;
int main()
{
    //Taking inputs of orders of matrices
    int m,n,p,q;
    cout<<"Enter the orders of the matrices\n";
    cin>>m>>n>>p>>q;
    //If no. of columns of matrix1 !=rows in matrix2
    //multiplication not possible
    if(n!=p){
        cout<<"Matrix multiplication not possible\n";
        return 0;
    }
    //Declare matrices
    int a[m][n], b[p][q], c[m][q];
    //Taking inputs of matrices
    cout<<"Input the matrix 1 along the row\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    cout<<"Input the matrix 2 along the row\n";
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            cin>>b[i][j];
        }
    }
    //Finding resultant matrix on multipication &
    //Printing it
    cout<<"The result of matrix multiplication is\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<q;j++){
            c[i][j]=0;
            for(int k=0;k<n;k++){
                c[i][j]+=a[i][k]*b[k][j];
            }
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
 return 0;
}