/*
151. Reverse Words in a String
Medium
5.7K
4.5K
Companies
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces
*/

char * reverseWords(char * s){
    int len = strlen(s);
    int i=0, j= len-1;
    char * retS;
    int wordStartFlag = 0; // Is 1 if the worsd has been started and we look for space to collect it
    
    int wordStartPos, wordEndPos;
    retS = (char *)malloc( (len +1)* sizeof(char));
    retS[len] = '\0';

    // Aproaching using a state machine based solution as the space character is responsible for the 
    // start and end of the word hence using it two track the start and end of word
    // Lastly, if the while loop exits I.E when j == -1, we check for the wordStartFlag and see if there is 
    // a word remaining to copied and that is done and then the string is returned
    while( j >= 0)
    { 
        if( s[j] == ' ')
        {
            
            if( wordStartFlag)
            {
                wordStartFlag = 0;
                wordStartPos = j+1;

                // adding a space before the start of the word except for the first word
                if( i != 0)
                {
                    retS[i] = ' '; 
                    i++;
                }  

                // Now copy the word into the space
                while( wordStartPos <= wordEndPos)
                {
                    retS[i] = s[wordStartPos];
                    i++;
                    wordStartPos++;
                }

            }
            
        }
        else
        {
            if( wordStartFlag == 0) 
            {
                wordStartFlag =1;
                wordEndPos = j;      
            }
        }
        j--;
    }

    if( wordStartFlag == 1)
    {
        j++;
        wordStartPos = j;

        
        // adding a space before the start of the word except for the first word
        if( i != 0)
        {
            retS[i] = ' '; 
            i++;
        }  
        
        while( wordStartPos <= wordEndPos)
        {
            retS[i] = s[wordStartPos];
            i++;
            wordStartPos++;
        }
        
    }
    retS[i] = '\0';
    return retS;

}

// ****** IMPORTANT LEARNINGS FROM THE CODE ***
// 1. String is returned only at the very END,which makes it easier to understand and DEBUG the Code 
// 2. Using State Machine to build up the logic and a single WordStartFlag to toggle between the States!!
