#include <iostream>
using namespace std;
int uniquePaths(int row, int col)
{ 
       int matrix[row][col];
        int i=0,j=0;
       // set the initial conditions
      if(row == 1)
        return 1;
      else if(col == 1)
        return 1;
      else if(row >1 && col>1)
      {
       for(i=0;i < row;i++)
          matrix[i][col-1]=1;

       for(j=0;j < col;j++)
          matrix[row-1][j]=1;
       // there is no path when we have reached
       //  the destination
       matrix[i][j]=0;
       
       // starting from the diagonal position and
       // moving upwards and leftwards
      //else if(row >1 && col>1)
       for (i = row-2; i >= 0; i--)
       {
         for (int j = col-2; j >= 0; j--)
         {
              matrix[i][j] = matrix[i+1][j] + matrix[i][j+1];
         }
       }
     }
       return matrix[0][0];
} 
int main(int argc, char const *argv[])
{
  int A,B,q;
  cin>>A>>B;
  q = uniquePaths(A,B);
  cout<<q;
  return 0;
}