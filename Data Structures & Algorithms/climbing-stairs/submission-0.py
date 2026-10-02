class Solution:
    def climbStairs(self, n: int) -> int:
        dp = {}

        def fun(i, n):
            if i == n:
                return 1

            if i > n:
                return 0

            if i in dp:
                return dp[i]

            a1 = fun(i + 1, n)
            a2 = fun(i + 2, n)

            ans = a1 + a2
            dp[i] = ans

            return ans

        return fun(0, n)