/*
You are given an integer array score of size n, where score[i] is the score of the ith athlete in a competition. All the scores are guaranteed to be unique.

The athletes are placed based on their scores, where the 1st place athlete has the highest score, the 2nd place athlete has the 2nd highest score, and so on. The placement of each athlete determines their rank:

The 1st place athlete's rank is "Gold Medal".
The 2nd place athlete's rank is "Silver Medal".
The 3rd place athlete's rank is "Bronze Medal".
For the 4th place to the nth place athlete, their rank is their placement number (i.e., the xth place athlete's rank is "x").
Return an array answer of size n where answer[i] is the rank of the ith athlete.

 

Example 1:

Input: score = [5,4,3,2,1]
Output: ["Gold Medal","Silver Medal","Bronze Medal","4","5"]
Explanation: The placements are [1st, 2nd, 3rd, 4th, 5th].
Example 2:

Input: score = [10,3,8,9,4]
Output: ["Gold Medal","5","Bronze Medal","Silver Medal","4"]
Explanation: The placements are [1st, 5th, 3rd, 2nd, 4th].

 

*/
typedef struct ValueToIndexPair {
    int value;
    int index;
} ValueToIndexPair;

char *createRankString(int rank);

int cmpfunc (const void * a, const void * b) {
   const ValueToIndexPair* i1 = (ValueToIndexPair*) a;
   const ValueToIndexPair* i2 = (ValueToIndexPair*) b; 

   return (i2->value - i1->value );        // if done i1- i2, ascending sort happens, in this case descending is done
}

char **findRelativeRanks(int* score, int scoreSize, int* returnSize) {
  char **ranks = malloc(scoreSize * sizeof(char*));
  *returnSize = scoreSize;
  ValueToIndexPair scoreToIndexList[scoreSize];  
  for (int i = 0; i < scoreSize; i++) {
      scoreToIndexList[i].value = score[i];
      scoreToIndexList[i].index = i;
  }
  
  //  ***** inbuilt C library function from stdlib.h ********** 
  // last argument is cmpfunc user needs to define
  qsort(scoreToIndexList, scoreSize, sizeof(ValueToIndexPair), cmpfunc);
  
  for (int i = 0; i < scoreSize; i++) {
      char *rankStr = createRankString(i);
      int currentScoreOrignalIndex = scoreToIndexList[i].index;
      ranks[currentScoreOrignalIndex] = rankStr;
  }

  return ranks;
}

char *createRankString(int rank) {
  char firstRankStr[12] = "Gold Medal";
  char secondRankStr[13] = "Silver Medal";
  char thirdRankStr[15] = "Bronze Medal";

  char *rankStr;
  if (rank == 0) {
      rankStr = malloc(12 * sizeof(char));
      strcpy(rankStr, firstRankStr);
  } else if (rank == 1) {
      rankStr = malloc(13 * sizeof(char));
      strcpy(rankStr, secondRankStr);
  } else if (rank == 2) {
      rankStr = malloc(15 * sizeof(char));
      strcpy(rankStr, thirdRankStr);
  } else {
      rankStr = malloc(6 * sizeof(char));
      sprintf(rankStr, "%d", rank + 1);
  }
  return rankStr;
}
