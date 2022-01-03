def testing(x: int):
    a = str(x)
    half = len(a)//2
    print(a)
    print(a[:half])
    b = a[-half:]
    print(b[::-1])


class Solution:
    def isPalindrome(self, x: int) -> bool:
        half = len(x) // 2
        b = x[-half:]
        return x[half:] == b[::-1]


testing(1)