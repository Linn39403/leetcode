#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
void myassert(char * result, char * expected, char * printStr);

/*
    Given an encoded string, return its decoded string.
    The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times.
    Note that k is guaranteed to be a positive integer.
    You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc.
    Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k.
    For example, there will not be input like 3a or 2[4].
    The test cases are generated so that the length of the output will never exceed 10^5.
    
    Constraints:
    1 <= s.length <= 30
    s consists of lowercase English letters, digits, and square brackets '[]'.
    s is guaranteed to be a valid input.
    All the integers in s are in the range [1, 300].
*/
#define IS_ASCII_INT(x)  ((x)>='0' && (x)<='9')

char * decodeString(char * s){
    int ilen = strlen(s);
    int idx = 0, sIdx = 0;

    char* stack = (char*)calloc(10000, sizeof(char));
    while(idx < ilen){
        if(s[idx] != ']'){
            stack[sIdx++] = s[idx];
        }else{
            int stop = strlen(stack) - 1; //go back to '[' 
            int start = stop;
            while(start > 0 && stack[start--]!='[');
            start++;
            //get the string len in between [ ]
            int iStrLen = stop - start; 
            char * cptr = calloc((iStrLen)+1, sizeof(char));
            strncpy(cptr, (const char *)&stack[start+1], iStrLen);

            //get the interger 
            if(start)  start -- ;
            int iCnt = 0, iPower = 0;
            while( start >= 0 && IS_ASCII_INT(stack[start]))
            {
                iCnt += ( stack[start] - '0' ) * pow(10,iPower);
                iPower++;
                start--;
            }

            if(start != 0)  start++;

            if(iCnt == 0) iCnt = 1;

            char * sptr = calloc((iStrLen * iCnt )+1, sizeof(char));
            while(iCnt--)
            {
                strcat(sptr,cptr);
            }
            
            //copy back to the original array
            memset(&stack[start],0,(stop-start)+1);
            strcpy(&stack[start],sptr); 
            sIdx = strlen(stack);
            free(cptr);
            free(sptr);        
        }
        idx++;
    }

    return stack;
}
 
char ans1[] = "aaabcbc";
char ans2[] = "accaccacc";
char ans3[] = "abcabccdcdcdef";
char ans4[] = "acdcdcdcdcdcdcdcdcdcdcdcdacdcdcdcdcdcdcdcdcdcdcdcdacdcdcdcdcdcdcdcdcdcdcdcd";
char ans5[] = "leetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcode";
char ans6[] = "zzzyypqjkjkefjkjkefjkjkefjkjkefyypqjkjkefjkjkefjkjkefjkjkefef";
char ans7[] = "abcds";
int main(void)
{   
    #if 1     
    myassert(decodeString("3[a]2[bc]"),ans1,"Tese Case 1.");
    myassert(decodeString("3[a2[c]]"),ans2,"Tese Case 2.");
    myassert(decodeString("2[abc]3[cd]ef"),ans3,"Tese Case 3.");
    myassert(decodeString("3[a12[cd]]"),ans4,"Tese Case 4.");
    myassert(decodeString("100[leetcode]"),ans5,"Tese Case 5.");
    myassert(decodeString("3[z]2[2[y]pq4[2[jk]e1[f]]]ef"),ans6,"Tese Case 6.");
    #endif
    myassert(decodeString("1[a1[b1[c]d]s]"),ans7,"Tese Case 7.");
    return 0;
}
void myassert(char * result, char * expected, char * printStr)
{
    if(strcmp(result, expected) != 0)
    { 
        printf("ERROR: Expected %s, result =  %s, %s\r\n",expected, result, printStr);
    }
    else
    {
        printf("%s OK\r\n",printStr);
    }
    free(result);
}
