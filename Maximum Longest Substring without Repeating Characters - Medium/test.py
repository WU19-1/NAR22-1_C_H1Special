arr = [False for _ in range(255)]

def lengthOfLongestSubstring(s: str) -> int:
    length = len(s)
    if length == 0:
        return 0
    if length == 1:
        return 1
    
    left = 0
    right = 1

    arr[ord(s[left])] = True

    l = 1
    ml = 0

    while right <= length - 1:
        if arr[ord(s[right])] == False:
            arr[ord(s[right])] = True
            l += 1
            if l > ml:
                ml = l
            right += 1
        else:
            arr[ord(s[left])] = False
            left += 1
            l -= 1

    return ml

print(lengthOfLongestSubstring("abcabcbb"))
print(lengthOfLongestSubstring("bbbbb"))
print(lengthOfLongestSubstring("pwwkew"))
print(lengthOfLongestSubstring(""))