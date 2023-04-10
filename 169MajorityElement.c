/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
 

*/

int majorityElement(int* nums, int numsSize){
    int counter=1;
    int element = nums[0]; 

    // the logic works onthe principle that the Majority element occurs more than n/2 times
    // and the maximum possibility of cancelling(missing) this number while counting is n/2 -1 
    // i.e still leaving us the particular element at the end 
    for(int i = 1; i<numsSize; i++)
    {
        if( element == nums[i] )
        {
            counter++;
        }
        else
        {
            counter--;
            if(counter==0)
            {
                element=nums[i];
                counter=1;
            }
        }
    }
    return element;
}
