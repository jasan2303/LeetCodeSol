/**

118. Pascal's Triangle
Easy
9.8K
316
Companies
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


 

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]


 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){

     
    *returnSize = numRows; 

    *returnColumnSizes = malloc( numRows * sizeof(int));

    int **retArrays = malloc( numRows * sizeof(int*));
    int i,j;
    
    // Using NEsted for loops to fill the rows
    // For Each row First and the Last element are filled directly 1, which means
    // the inner for loop is skipped for first 2 Rows, and from 3rd row it uses the previous 
    // rows and coputes the current row.
    for( i=0; i<numRows; i++)
    {
        (*returnColumnSizes)[i] = i+1;
        retArrays[i] = malloc( (i+1) * sizeof(int));
        retArrays[i][0] = 1; // filling up the first element
        for( j=1; j<(i+1)-1; j++)
        {
            retArrays[i][j] =  retArrays[i-1][j-1] + retArrays[i-1][j];
        }
        retArrays[i][i] = 1;  // filling up the last element
    }

    return retArrays;
}
