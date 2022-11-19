#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
void myassert(char * result, char * expected, char * printStr);

/*
    Given a string queryIP, return "IPv4" if IP is a valid IPv4 address, "IPv6" if IP is a valid IPv6 address or "Neither" if IP is not a correct IP of any type.
    A valid IPv4 address is an IP in the form "x1.x2.x3.x4" where 0 <= xi <= 255 and xi cannot contain leading zeros. 
    For example, "192.168.1.1" and "192.168.1.0" are valid IPv4 addresses while "192.168.01.1", "192.168.1.00", and "192.168@1.1" are invalid IPv4 addresses.

    A valid IPv6 address is an IP in the form "x1:x2:x3:x4:x5:x6:x7:x8" where:
    1 <= xi.length <= 4
    xi is a hexadecimal string which may contain digits, lowercase English letter ('a' to 'f') and upper-case English letters ('A' to 'F').
    Leading zeros are allowed in xi.
    For example, "2001:0db8:85a3:0000:0000:8a2e:0370:7334" and "2001:db8:85a3:0:0:8A2E:0370:7334" are valid IPv6 addresses, 
    while "2001:0db8:85a3::8A2E:037j:7334" and "02001:0db8:85a3:0000:0000:8a2e:0370:7334" are invalid IPv6 addresses.
*/
typedef enum{
    IPv4Format = 0,
    IPv6Format = 1,
    InvalidFormat = 2
}IPFormat;
#define IS_ASCII_ALPHABET(x)  (((x)>='a' && (x)<='f') || ((x)>='A' && (x)<='F'))
#define IS_ASCII_DECMIAL(x)    ((x)>='0' && (x)<='9')
IPFormat isIPv4Format(char * queryIP, int Len)
{
    IPFormat eReturn = 2;
    int i = 0; int iCnt = 1;
    int iOld = 0;
    char expectedDelimator, unexpectedDelimator;
    for(; i< Len; i++){
        if(queryIP[i] == ':'){ 
            expectedDelimator = ':'; unexpectedDelimator = '.';
            if(Len < 15){
                return InvalidFormat; 
            }
            eReturn = IPv6Format; break; 
        }
        else if(queryIP[i] == '.'){ 
            expectedDelimator = '.'; unexpectedDelimator = ':';
            if(Len < 7){
                return InvalidFormat; 
            }
            eReturn = IPv4Format; break; 
        }
    }

    iOld = i++;
    for(; i< Len;i++){
        if(queryIP[i] == expectedDelimator){
            iCnt ++;
            if((i-iOld == 1) || (i==Len-1)) { //previous '.' and current '.' mustn't be adj each other & must not be the last one 
                return InvalidFormat; 
            }
            iOld = i;
        }else if(queryIP[i] == unexpectedDelimator){;
            return InvalidFormat;
        } 
    }
    
    if(eReturn == IPv4Format && iCnt != 3 ) {
        eReturn = InvalidFormat;
    }else if(eReturn == IPv6Format && iCnt != 7 ) {
        eReturn = InvalidFormat;
    }
    return eReturn;
}

char * validIPAddress(char * queryIP)
{
    int iLen = strlen(queryIP);
    static char answerArr[3][8] = {{"IPv4"},{"IPv6"},{"Neither"}};
    char * ans = &answerArr[2][0]; /* assign to nothing */
    if(iLen == 0 && iLen > 39){
        return "Neither";
    }

    /* check all the '.' or ':' are valid?*/
    IPFormat ipformat = isIPv4Format(queryIP, iLen);
    if( InvalidFormat == ipformat) return "Neither";

    char delimiter[2] = {0,0};
    IPFormat State ; 
    if(ipformat == IPv4Format){
        delimiter[0] = '.'; State = IPv4Format;
    }else{
        delimiter[0] = ':'; State = IPv6Format;
    }
    char * token = strtok(queryIP,delimiter) ;
    while(token != NULL){
        int ilen = strlen(token);
        switch(State){
            case IPv4Format: 
                if((ilen > 3 ) || (token[0] == '0' && IS_ASCII_DECMIAL(token[1])) || (atoi(token) > 255)){
                    return "Neither"; /* each ip must not be greater than 3 */     /* no leading zero*/  /* must be between 0 and 255 */
                }
                for(int i=0; i<ilen; i++){  /* mustn't contain any alphabet */
                    if(IS_ASCII_DECMIAL(token[i]) == false ) return "Neither";
                }
            break;

            case IPv6Format: //for ipv6
                if(strlen(token) > 4 ) return "Neither"; /* each ip must not be greater than 4 */   
                for(int i=0; i<ilen; i++){  /* mustn't contain any alphabet */
                    if( (IS_ASCII_DECMIAL(token[i]) == false )  && (IS_ASCII_ALPHABET(token[i]) == false ) ){
                        return "Neither";
                    }
                }
            break;

            default: break;
        }
        token = strtok(NULL, delimiter);
    }
    return ((State == IPv4Format ) ? "IPv4" : "IPv6");
}


char queryIP1[] = "172.16.254.1";
char queryIP2[] = "2001:0db8:85a3:0:0:8A2E:0370:7334";
char queryIP3[] = "256.256.256.256";
char queryIP4[] = "256.256.256.df6";
char queryIP5[] = "2001:0db8:85a3::8A2E:037j:7334";
char queryIP6[] = "02001:0db8:85a3:0000:0000:8a2e:0370:7334";
char queryIP7[] = "2001:0db8:85a3:0:0:8A2E:0370:7334:";
char queryIP8[] = "12..33.4";
char queryIP9[] = "01.01.01.01";
char queryIP10[] =  "1.0.1.";
char queryIP11[] =  "12.12.12";
char queryIP12[] =  "2001:db8:85a3:0:8a2E:8a2E:7334:";
int main(void)
{
#if 1
    myassert(validIPAddress(queryIP1),"IPv4","Test Case 1");    
    myassert(validIPAddress(queryIP2),"IPv6","Test Case 2"); 
    myassert(validIPAddress(queryIP3),"Neither","Test Case 3");    
    myassert(validIPAddress(queryIP4),"Neither","Test Case 4");    
    myassert(validIPAddress(queryIP5),"Neither","Test Case 5");    
    myassert(validIPAddress(queryIP6),"Neither","Test Case 6");  
    myassert(validIPAddress(queryIP7),"Neither","Test Case 7");    
    myassert(validIPAddress(queryIP8),"Neither","Test Case 8");  
    myassert(validIPAddress(queryIP9),"Neither","Test Case 9");  
    myassert(validIPAddress(queryIP10),"Neither","Test Case 10");  
    myassert(validIPAddress(queryIP11),"Neither","Test Case 11");      
    #endif
    myassert(validIPAddress(queryIP12),"Neither","Test Case 12");  
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
}
