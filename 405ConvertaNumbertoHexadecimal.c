/*
   Given an integer num, return a string representing its hexadecimal representation. For negative integers, two’s complement method is used.

All the letters in the answer string should be lowercase characters, and there should not be any leading zeros in the answer except for the zero itself.

Note: You are not allowed to use any built-in library method to directly solve this problem.

 

Example 1:

Input: num = 26
Output: "1a"
Example 2:

Input: num = -1
Output: "ffffffff"   
*/



char * toHex(int num){
    
    int hexNibbles[8]={0}; // as the range specified is -2^31 <= num <= 2^31 - 1
                           // so 8 nibbles should be enough represent the num
    int nibbleCount=0;

    unsigned int n = num; // key step which converts the negative number to their unsigned equivalents

    if(num==0)
        return "0";

    int rem=0;
    while(n)
    {
        hexNibbles[nibbleCount++] = n%16;
        n = n/16;
    }

    
    char* answer = (char*) malloc( (nibbleCount + 1)* sizeof(char));
    answer[nibbleCount] = '\0';
    for(int i=nibbleCount-1; i>=0; i--)
    {
        if( hexNibbles[i] < 10)
        {
            answer[nibbleCount-i-1] = '0' + hexNibbles[i];
        }
        else
            answer[nibbleCount-i-1] = 'a' + (hexNibbles[i] - 10);

    }
    return answer;
}
