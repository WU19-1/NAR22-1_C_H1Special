from typing import List


candidates = [2,3,6,7]
solution = []
target = 8

def solve(remainder, arr, idx):
    if remainder < 0 or idx >= len(candidates):
        return
    elif remainder == 0:
        if arr not in solution:
            solution.append(arr.copy())
    else:
        arr.append(candidates[idx])
        solve(remainder - candidates[idx], arr, idx)
        del arr[len(arr) - 1]
        if idx < len(candidates) - 1:
            arr.append(candidates[idx + 1])
            solve(remainder - candidates[idx + 1], arr, idx + 1)
            del arr[len(arr) - 1]
            solve(remainder, arr, idx + 1)

solve(target, [], 0)

print(solution)