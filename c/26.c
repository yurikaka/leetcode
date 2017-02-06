#include "stdio.h"

int removeDuplicates(int* nums, int numsSize) {
    if (0 == numsSize)
        return 0;
    int pos = 1;
    int now = nums[0];
    int i = 0;
    int m;
    for (i = 1; i < numsSize; i++){
        m = nums[i];
        if (m > now){
            now = m;
            nums[pos++] = now;
        }
    }
    return pos;
}

int main(){
    int nums[3] = {1,1,2};
    printf("%d\n",removeDuplicates(nums,3));
}