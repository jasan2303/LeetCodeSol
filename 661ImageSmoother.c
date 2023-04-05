/**


Input: img = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[0,0,0],[0,0,0],[0,0,0]]
Explanation:
For the points (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
For the points (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
For the point (1,1): floor(8/9) = floor(0.88888889) = 0

Input: img = [[100,200,100],[200,50,200],[100,200,100]]
Output: [[137,141,137],[141,138,141],[137,141,137]]
Explanation:
For the points (0,0), (0,2), (2,0), (2,2): floor((100+200+200+50)/4) = floor(137.5) = 137
For the points (0,1), (1,0), (1,2), (2,1): floor((200+200+50+200+100+100)/6) = floor(141.666667) = 141
For the point (1,1): floor((50+200+200+200+200+100+100+100+100)/9) = floor(138.888889) = 138


 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

// int checkValidNeighbour( int dir , int x, int y, int m, int n)
// {
//     int dirs[8][2] = { {-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};

//     x = x + dirs[dir][0];
//     y = y + dirs[dir][1];

//     if ( x < 0 || y < 0  || x > m || y > n)
//         return -1;
//     else
//         return 1;

// }
int** imageSmoother(int** img, int imgSize, int* imgColSize, int* returnSize, int** returnColumnSizes){
    *returnSize = imgSize;
    int mColSize = imgColSize[0];
    int **ret = malloc(sizeof(int*)*imgSize);
    *returnColumnSizes = malloc(sizeof(int)*imgSize);
    for (int i = 0; i < imgSize; i++)
    {
        ret[i] = malloc(sizeof(int)*mColSize);
        (*returnColumnSizes)[i] = mColSize;
    }
    
    
    int dirs[8][2] = { {-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};

    int tempSum;
    int count;
    int row, col;
    for(int i=0; i<imgSize; i++)
    {
        for( int j=0; j<mColSize; j++)
        {
            tempSum =img[i][j];
            count = 1;
            for(int k=0; k<8; k++)
            {
                row = i + dirs[k][0]; col =  j + dirs[k][1];
                if ( row < 0 || col < 0  || row >= imgSize || col >= mColSize)
                    continue;
                
                tempSum += img[ row][ col ];
                count++; 

            }
            ret[i][j] = tempSum/count;

        }
    }

    return ret;
}
