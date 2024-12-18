/*
We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left).
 Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. 
If two asteroids meet, the smaller one will explode. 
If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.
*/

/*
Constraints:
2 <= asteroids.length <= 104
-1000 <= asteroids[i] <= 1000
asteroids[i] != 0
*/
#include <stdlib.h>
#include <stdio.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize)
{
    int * ans = malloc(sizeof(int)*asteroidsSize);
    int PushTheStack = 0;
    int top = -1;
    for(int i=0; i<asteroidsSize; i++)
    {
      int current = asteroids[i];
      while(top >= 0 &&
      ans[top] > 0 && /*the one from the stack is moving right*/
      current < 0     /*current is moving left */)
      {
         if (abs(ans[top]) < abs(current)) {
            top--;
         }else if(abs(current) == abs(ans[top])){
            PushTheStack = 1;
            top--;
            break;
         }else{
            PushTheStack = 1;
            break;
         }
      }
      if(PushTheStack == 0){
         ans[++top] = current;
      }
      PushTheStack = 0;
    }
    *returnSize = (top+1);
    return ans;
}

int test1[3] = {5,10,-5};
int test2[2] = {8,-8};
int test3[3] = {10,2,-5};
int test4[4] = {-2,-1,1,2};
int ansSize = 0;
int main(void)
{
   #if 1
   int * ans1 = asteroidCollision(test1, 3, &ansSize);
   printf("Answer 1 = { ");
   for(int i = 0; i < ansSize; i++){
      printf("%d,",ans1[i]);
   }
   printf(" }\n");
   #endif 

   #if 1
   int * ans2 = asteroidCollision(test2, 2, &ansSize);
   printf("Answer 2 = { ");
   for(int i = 0; i < ansSize; i++){
      printf("%d,",ans2[i]);
   }
   printf(" }\n");
   #endif

   #if 1
   int * ans3 = asteroidCollision(test3, 3, &ansSize);
   printf("Answer 3 = { ");
   for(int i = 0; i < ansSize; i++){
      printf("%d,",ans3[i]);
   }
   printf(" }\n");
   #endif   

   #if 1
   int * ans4 = asteroidCollision(test4, 4, &ansSize);
   printf("Answer 4 = { ");
   for(int i = 0; i < ansSize; i++){
      printf("%d,",ans4[i]);
   }
   printf(" }\n");
   #endif      
   return 0;
}
