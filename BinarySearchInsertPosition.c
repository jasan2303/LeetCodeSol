/*
35. Search Insert Position
Easy
13K
565
Companies
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4

*/
int searchInsert(int* nums, int numsSize, int target){
   // Optimized approach is BS
   int low =0, high = numsSize-1;
   
   // ****** VERY IMP TO DO THis *******
   int idx = numsSize;

    while( low <= high)
    {
        int mid = low + (high - low)/ 2;
         if(nums[mid] >= target)
         {
             idx = mid;
             high = mid - 1;
         }
         else
         {
             low = mid + 1;
         }
    }
   
  return idx;
}
