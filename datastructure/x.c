/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize)
{
   for(int i=digitsSize-1;i>=0;i--)
   {
       if(digits[i]+1==10)
       {
           digits[i]=0;
       }
       else
       {
           digits[i]=digits[i]+1;
           *returnSize=digitsSize;
           return digits;
       }
   }
    *returnSize=digitsSize+1;
    int *ret=(int*)malloc(sizeof(int)*(digitsSize+1));
    memset(ret,0,sizeof(int)*(digitsSize+1));
    ret[0]=1;
    return ret;
}

作者：wind_shaw_24921808
链接：https://leetcode-cn.com/problems/plus-one/solution/66jia-yi-cyu-yan-by-xyh24921808-ysy8/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。