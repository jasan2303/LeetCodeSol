/*

412. Fizz Buzz

*  Given an integer n, return a string array answer (1-indexed) where:

answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
answer[i] == "Fizz" if i is divisible by 3.
answer[i] == "Buzz" if i is divisible by 5.
answer[i] == i (as a string) if none of the above conditions are true.
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** fizzBuzz(int n, int* returnSize){

    char ** answer = (char**)malloc( n*sizeof(char*));

    // this commented sections uses modulus(%) whhich slows the code  refer second 
    // part for optimized
    // for(int i=1; i<=n; i++)
    // {
      
    //     if( !(i%3) && !(i%5))
    //     {
    //         answer[i-1] = (char*)malloc(sizeof("FizzBuzz"));
    //         answer[i-1] = "FizzBuzz";
    //     } 
    //     else if( !(i%3))
    //     {
    //         answer[i-1] = (char*)malloc(sizeof("Fizz"));
    //         answer[i-1] = "Fizz";
    //     } 
    //     else if(!(i%5))
    //     {
    //         answer[i-1] = (char*)malloc(sizeof("Buzz"));
    //         answer[i-1] = "Buzz";
    //     }
    //     else 
    //     {
    //         answer[i-1] = (char*)malloc(28*sizeof(char));
    //         snprintf(answer[i-1], 28, "%d", i);
    //     }
        
    // }
    int fizz=3, buzz=5, fizzbuzz=15;
    for(int i=1; i<=n; i++)
    {
      
        if( i==fizzbuzz)
        {
            answer[i-1] = (char*)malloc(sizeof("FizzBuzz"));
            answer[i-1] = "FizzBuzz";
            fizzbuzz += 15;fizz += 3;buzz += 5;
        } 
        else if( i == fizz)
        {
            answer[i-1] = (char*)malloc(sizeof("Fizz"));
            answer[i-1] = "Fizz";
            fizz += 3;
        } 
        else if( i==buzz)
        {
            answer[i-1] = (char*)malloc(sizeof("Buzz"));
            answer[i-1] = "Buzz";
            buzz += 5;
        }
        else 
        {
            answer[i-1] = (char*)malloc(28*sizeof(char));
            snprintf(answer[i-1], 28, "%d", i);
        }
        
    }
    *returnSize = n;
        return answer;

}
