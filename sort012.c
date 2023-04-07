// Dutch National Flag problem
/*
    Input: 
N = 5
arr[]= {0 2 1 2 0}
Output:
0 0 1 2 2
Explanation:
0s 1s and 2s are segregated 
into ascending order.
Example 2:

Input: 
N = 3
arr[] = {0 1 0}
Output:
0 0 1
Explanation:
0s 1s and 2s are segregated 
into ascending order.
*/
void swap( int * a, int * b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void sort012(int a[], int n)
{
    
    int start = 0, mid = 0, end = n-1;
    
    
    while( mid<=end)
    {
        switch( a[mid])
        {
            case 0 :
                swap( &a[mid], &a[start]);
                start++;
                mid++;
                break;
            
            case 1 :
                mid++;    
                break;
                
            case 2 :
                swap( &a[mid], &a[end]);
                end--;                   // In this case we do not incremnet middle because we are not sure if the 
                                         // swapped element is 1 or 0, So we come back again to check that  
                break;
            
        }
    }
    
    
}
