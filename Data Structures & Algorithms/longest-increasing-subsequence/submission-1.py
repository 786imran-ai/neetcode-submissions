class Solution:
    def lengthOfLIS(self, nums):
        n = len(nums)
        dp = [[-1] * (n + 1) for _ in range(n)]

        def fun(a, n, i, prev):
            if i == n:
                return 0

            if dp[i][prev + 1] != -1:
                return dp[i][prev + 1]

            if prev == -1 or a[i] > a[prev]:
                c1 = 1 + fun(a, n, i + 1, i)
                c2 = fun(a, n, i + 1, prev)

                dp[i][prev + 1] = max(c1, c2)
                return dp[i][prev + 1]

            dp[i][prev + 1] = fun(a, n, i + 1, prev)
            return dp[i][prev + 1]

        return fun(nums, n, 0, -1)