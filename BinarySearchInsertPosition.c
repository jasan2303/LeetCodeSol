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
