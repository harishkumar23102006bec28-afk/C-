#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), compare);
    long closestSum = nums[0] + nums[1] + nums[2];
    
    for (int i = 0; i < numsSize - 2; i++) {
        int left = i + 1;
        int right = numsSize - 1;
        
        while (left < right) {
            long currentSum = nums[i] + nums[left] + nums[right];
            
            if (currentSum == target) {
                return currentSum;
            }
            
            if (labs(currentSum - target) < labs(closestSum - target)) {
                closestSum = currentSum;
            }
            
            if (currentSum < target) {
                left++;
            } else {
                right--;
            }
        }
    }
    return (int)closestSum;
}

int main() {
    int nums[] = {-1, 2, 1, -4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 1;
    
    int result = threeSumClosest(nums, numsSize, target);
    
    printf("Input Array: [-1, 2, 1, -4], Target: %d\n", target);
    printf("Output: %d\n", result);
    
    return 0;
}
