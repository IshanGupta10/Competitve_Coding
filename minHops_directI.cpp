#include <iostream>
#include <climits>
using namespace std ;

int min(int x, int y, int z)
{
   if (x < y)
      return (x < z)? x : z;
   else
      return (y < z)? y : z;
}

int minHops(int matrix[64][64], int m, int n)
{
    //add code to this function to solve the problem
    //don't write code in this editor
    //your code will not be saved across submissions
     int i, j;

     int leastValue[64][64];  //Matrix for storing paths
 
     leastValue[0][0] = matrix[0][0];   //Initializing values

     for (i = 1; i <= m; i++)           //Calcutaing Paths
        leastValue[i][0] = leastValue[i-1][0] + matrix[i][0];
 
     for (j = 1; j <= n; j++)           //Calculating Hops
        leastValue[0][j] = leastValue[0][j-1] + matrix[0][j];
 
     for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            leastValue[i][j] = min(leastValue[i-1][j-1], leastValue[i-1][j], leastValue[i][j-1]) + matrix[i][j];    //Finiding Minimums
    
    if(leastValue[m][n] == 0)   //Condition if Present.
        return 0;
    else
        return leastValue[m][n];
}

int main () {
    int tesleastValueases, rows, cols;
    int arr[64][64];
    cin >> tesleastValueases;

    int i, j, k;
    for (i = 0; i < tesleastValueases; i++)
    {
        cin >> rows;
        cin >> cols;

        for (j = 0; j < rows; j++)
            for (k = 0; k < cols; k++)
                cin >> arr[j][k];

        int result = minHops(arr,rows,cols);
        cout << result << endl;
    }
    return 0 ;
}
