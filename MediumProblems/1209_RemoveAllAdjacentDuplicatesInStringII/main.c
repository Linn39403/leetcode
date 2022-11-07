#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
void myassert(char * result, char * expected, char * printStr);
/*
    You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them, 
    causing the left and the right side of the deleted substring to concatenate together.
    We repeatedly make k duplicate removals on s until we no longer can.
    Return the final string after all such duplicate removals have been made. 
    It is guaranteed that the answer is unique.
*/
char char1[20] = {0};
int int1[20] = {0};
char * removeDuplicates(char * s, int k)
{
    int ktemp = 0;
    int iStrLen = strlen(s);
    char * cptrAns = malloc(sizeof(char) * (iStrLen+1));
    int * kCnt = malloc(sizeof(int) * (iStrLen+1));
    int top = 0;
    if(iStrLen==1){
        cptrAns[0] = s[0];
        return cptrAns;
    }
    
    cptrAns[top] = s[0];
    kCnt[top] = 1;
    top++;

    for(int i=1;i<iStrLen;i++){
        ktemp = ((top > 0 ) && s[i] == cptrAns[top-1]) ? (kCnt[top-1]+1) : 1; //check the current char is equal to the char in stack? if yes increase ktemp
        //push
        cptrAns[top] = s[i];
        kCnt[top] = ktemp;
        if(kCnt[top] == k){
            top-=k;
        }
        top++;
       
    }     
    cptrAns[top] = '\0';
    return cptrAns;
}
/*

*/

char ans1[] = "abcd";
char ans2[] = "aa";
char ans3[] = "ps";
char ans4[] = "aa";
int main(void)
{        
    myassert(removeDuplicates("abcd",2),ans1,"Tese Case 1.");
    myassert(removeDuplicates("deeedbbcccbdaa",3),ans2,"Tese Case 2.");
    myassert(removeDuplicates("pbbcggttciiippooaais",2),ans3,"Tese Case 3.");
    myassert(removeDuplicates("deeedbbcccbdaa",3),ans4,"Test Case 4");
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
        printf("OK: Expected %s, result =  %s\r\n",expected, result);
    }
    free(result);
}
