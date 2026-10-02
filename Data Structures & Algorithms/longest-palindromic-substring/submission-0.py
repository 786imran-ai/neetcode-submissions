class Solution:
    def longestPalindrome(self, s: str) -> str:
        ans = ""

        def fun(left, right):
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1

            return s[left + 1:right]

        for i in range(len(s)):
            a1 = fun(i, i)
            a2 = fun(i, i + 1)

            if len(a1) > len(ans):
                ans = a1

            if len(a2) > len(ans):
                ans = a2

        return ans
        