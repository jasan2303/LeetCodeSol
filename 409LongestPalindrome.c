/*
        Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

*/

int longestPalindrome(char * s){
    int hash[52] = {0};
    
    int distinctLetters=0;
    int i=0, len = strlen(s);
    if( len == 1)
        return 1;
    
    while( s[i] != '\0')
    {
        if( s[i] < 'a')
        {
            //hash[ s[i] - 'A'] = ~hash[ s[i] - 'A'];
            if(hash[ s[i] - 'A']==1)
                hash[ s[i] - 'A'] = 0;
            else
                hash[ s[i] - 'A'] = 1;
        }
        else
        {
           // hash[ s[i] - 71] = ~hash[ s[i] - 71];
            if( hash[ s[i] - 71]==1)
                hash[ s[i] - 71] = 0;
            else
                hash[ s[i] - 71] = 1;
        }
        i++;
    }

    for( int j=0; j<52; j++)
    {
        if( hash[j] != 0)
            distinctLetters++;
    }

    if(distinctLetters==0)
        return len;

    if( (len - distinctLetters) >= 0 )
        return (len - distinctLetters) +1;
    else
        return 0;
}
