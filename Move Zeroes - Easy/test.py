from typing import List

def moveZeroes(nums: List[int]) -> None:
    """
    Do not return anything, modify nums in-place instead.
    """
    last = 0
    for i, num in enumerate(nums):
        if num != 0:
            nums[last] = num
            last += 1
    for i in range(last, len(nums)):
        nums[i] = 0
    return nums

print(moveZeroes([0,1,0,14,12]))