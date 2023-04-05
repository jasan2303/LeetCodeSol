/**

66. Reshape the Matrix

In MATLAB, there is a handy function called reshape which can reshape an m x n matrix into a new one with a different size r x c keeping its original data.

You are given an m x n matrix mat and two integers r and c representing the number of rows and the number of columns of the wanted reshaped matrix.

The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the reshape operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.

Input: mat = [[1,2],[3,4]], r = 1, c = 4
Output: [[1,2,3,4]]

Input: mat = [[1,2],[3,4]], r = 2, c = 4
Output: [[1,2],[3,4]]

 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes){
        

        int **retMat = malloc( r*sizeof(int*)); 
        *returnColumnSizes = malloc(r*sizeof(int));
        int matColumnSize = matColSize[0];  // taking just the first columnsize as all the rows have same column size
        
        // checking if the given matrix Matrix product is equal to the requested reshaped matrix product (r*c)
        // if not we just update the returnSize and returncolumnSizes and RETURN the given MATRIX itself 
        if( matSize * (matColumnSize) != r*c) 
        {
             *returnSize = matSize;
             for( int i=0; i<r; i++)
             {
                
                (*returnColumnSizes)[i] = matColumnSize;
  
            }
            return mat;

        }   
        else          // AND if the matrix products are equal we initialize a new retMat matrix to reshape
        {
            *returnSize = r;
            for( int i=0; i<r; i++)
            {
                retMat[i] = malloc(sizeof(int)*(c));
                (*returnColumnSizes)[i] = c;
  
            }
        }



        int row=0, col =0;
        for( int i=0; i<r; i++)
        {
            for(int j=0; j< c ; j++)
            {
                retMat[i][j] = mat[row][col++];
                if( col == matColumnSize)
                {
                    col =0; row++;
                }   
            }
        }

        return retMat;
}
