#include "string.h"
#include "stdio.h"
void myassert(char * result, char * expected, char * printStr);

char * longestCommonPrefix(char ** strs, int strsSize){
    static char c_str[200] = "";
    memset(c_str,0, sizeof(c_str));
    char * c_ptr = strs[0];
    int i_smallestStringLen = 0;
    
    //check string size and initilaize the c_ptr;
    if(strsSize == 1) return c_ptr;
    else c_ptr = &c_str[0];

    //get the smallest string size
    i_smallestStringLen = strlen(strs[0]);
    for(int i=1; i<strsSize; i++)
    {
        int i_temp = strlen(strs[i]);
        i_smallestStringLen =  i_temp < i_smallestStringLen ? i_temp : i_smallestStringLen;
    }

    for(int j=0; j<i_smallestStringLen; j++)
    {
        char c_temp = strs[0][j]; //just ref the first string 
        for(int i=0; i<strsSize;i++)
        {
            if(strs[i][j] != c_temp)
                return c_ptr;
        }
        //copy to the c_str
        c_str[j] = c_temp;
    }
    return c_ptr;
}

char * c_inputStr1[3] = {"flower","flow","flight"};
char * c_inputStr2[3] = {"dog","racecar","car"};
char * c_inputStr3[8] = {"eager","eagle","eagre","eared","earls","early","earns","earth"};
char * c_inputStr4[4] = {"flower","flow","a","flight"};
int main(void)
{
    myassert(longestCommonPrefix(c_inputStr1,3),
    "fl",
    "c_inputStr1 should returns fl");
    myassert(longestCommonPrefix(c_inputStr2,3),
    "",
    "c_inputStr2 should returns NULL");
    myassert(longestCommonPrefix(c_inputStr3,8),
    "ea",
    "c_inputStr3 should returns ea");   
    myassert(longestCommonPrefix(c_inputStr4,4),
    "",
    "c_inputStr4 should returns NULL");         
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
}

