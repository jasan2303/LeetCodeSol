/*
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

 

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false
*/

bool isSubsequence(char * s, char * t){
    int sLen = strlen(s), tLen = strlen(t);

    int i=0, j=0;
    // we are using two pointers and for every character in s we are finding a
    // match in t and finally if all the character in S are found we return
    // true else false. 
    // As the loop is running for one character after one it automatically checks
    // for relative condition
    for(i = 0; i<tLen && j<sLen; i++)
    {
        if( t[i] == s[j])
            j++;
    }
    return (j==sLen);
}
