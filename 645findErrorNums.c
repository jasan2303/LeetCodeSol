/**
 * Note: The returned array must be malloced, assume caller calls free().
 
 
 You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.

 

Example 1:

Input: nums = [1,2,2,4]
Output: [2,3]
Example 2:

Input: nums = [1,1]
Output: [1,2]
 
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize){

    *returnSize = 2;
    int * retArr = (int*) malloc(2 * sizeof(int));

    int i;

    int index;
    
    // using -ve marking at the index approach to mark the presence of the number
    // and traversing along the nums and if the number is repeated I.E, already been marked negative 
    // will be the number that is there two times in nums and is the first entry of the return array 
    for( i=0; i<numsSize; i++)
    {
        index = abs(nums[i])-1;
        if( nums[ index] < 0)
        {
            retArr[0] = abs(nums[i]);
            //break;
        }
        else
            nums[ index] = -nums[ index];
    }

    // SO now to find the second number which is missing due to duplicacy! we just traverse through the nums to find the 
    // positive number bcz that is the index+1 which was missing and was not marked neagtive, so that is out second entry to return array
    for( i=0; i<numsSize; i++)
    {
        if( nums[i] > 0)
        {
            retArr[1] = i+1;
            break;
        }
    }

    return retArr;

}
