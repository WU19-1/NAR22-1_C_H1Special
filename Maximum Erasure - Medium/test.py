from typing import List

# nums = [4,2,4,5,6]
nums = [5,2,1,2,5,2,1,2,5]
arr = [False for _ in range(max(nums) + 1)]

def maximumUniqueSubarray(nums: List[int]) -> int:
    left = 0
    right = 1
    length = len(nums)
    sum = nums[left]
    arr[nums[left]] = True
    max_sum = sum
    while right <= length - 1:
        if arr[nums[right]] == False:
            arr[nums[right]] = True
            sum += nums[right]
            if sum > max_sum:
                max_sum = sum
            right += 1
        elif arr[nums[right]] == True:
            sum -= nums[left]
            arr[nums[left]] = False
            left += 1
    return max_sum

print(maximumUniqueSubarray(nums))