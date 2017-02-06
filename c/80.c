#include "stdio.h"
#include "stdbool.h"

int removeDuplicates(int* nums, int numsSize) {
    if (0 == numsSize)
        return 0;
    int pos = 1;
    int now = nums[0];
    int i = 0;
    int m;
    bool twice = false;
    for (i = 1; i < numsSize; i++){
        m = nums[i];
        if (twice){
            if (m > now) {
                now = m;
                nums[pos++] = now;
                twice = false;
            }
        }
        else {
            if (m > now){
                now = m;
                nums[pos++] = now;
            }
            else if (m == now){
                nums[pos++] = now;
                twice = true;
            }
        }
    }
    return pos;
}

int main(){
    int nums[] = {1,1,2,2};
    printf("%d\n",removeDuplicates(nums,4));
}