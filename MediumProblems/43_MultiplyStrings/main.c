#define ARR_LEN 1024
char* multiply(char* a, char* b)
{
  char arrayA[ARR_LEN] = "";
  char arrayB[ARR_LEN] = "";
  static char RevResult[ARR_LEN] = "";
  char tempResult[ARR_LEN] = "";
  unsigned char temp = 0;
  int tempResultIndex = 0;
  int LenA = 0, LenB = 0;
  unsigned char carry = 0;
  int ShiftIndex = 0;
  memset(RevResult, 0, ARR_LEN);
  LenA = strlen(a);
  LenB = strlen(b);

  /* Convert ASCII to Decimal */
  for (int i = 0; i < LenA; i++)
  {
    arrayA[i] = a[i] - '0';
  }
  for (int i = 0; i < LenB; i++)
  {
    arrayB[i] = b[i] - '0';
  }

  for (int i = LenB - 1; i >= 0; i--)
  {
    memset(tempResult, 0, ARR_LEN);
    tempResultIndex = LenB - i -1;   
    ShiftIndex++;         
    for (int j = LenA - 1; j >= 0; j--)
    {   /* multiply one arrayB to all values in arrayA*/
      temp = (arrayA[j] * arrayB[i])+carry;
      carry = 0;
      if (temp >= 10)
      {
        tempResult[tempResultIndex++] = temp % 10;
        carry = temp / 10;
        if (j == 0) {
          tempResult[tempResultIndex++] = carry;
        }

      }
      else
      {
        tempResult[tempResultIndex++] = temp;
      }
    }
    carry = 0;
    for (int j = 0; j < ARR_LEN; j++)
    {
      unsigned char temp = RevResult[j] + tempResult[j] + carry;
      carry = 0;
      if (temp >= 10)
      {
        RevResult[j] = temp % 10;
        carry = temp / 10;
      }
      else
      {
        RevResult[j] = temp;
      }
    }
    
  }

  /* Convert Dec to String */ 
  char firstDigitNotZero = 0;
  int revIndexCnt = 0;
  memset(tempResult, 0, sizeof(tempResult) / sizeof(char));
  memcpy(tempResult, RevResult, sizeof(RevResult) / sizeof(char));
  memset(RevResult, 0, sizeof(RevResult) / sizeof(char));
  for (int j = ARR_LEN - 1; j >= 0; j--)
  {
    if (tempResult[j] != 0 || firstDigitNotZero != 0)
    {
      firstDigitNotZero = 1;
    }
    if (firstDigitNotZero)
    {   /* Reverse the result. */
      RevResult[revIndexCnt++] = tempResult[j] + '0';
    }
  }
  if (RevResult[0] == 0) RevResult[0] += '0';
  return (char*)RevResult;
}