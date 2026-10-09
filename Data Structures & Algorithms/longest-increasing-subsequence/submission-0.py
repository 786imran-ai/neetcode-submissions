
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        def fun(a, n, i, prev, dp):
            if i == n:
                return 0

            if dp[i][prev + 1] != -1:
                return dp[i][prev + 1]

            if prev == -1 or a[i] > a[prev]:
                c1 = 1 + fun(a, n, i + 1, i, dp)
                c2 = fun(a, n, i + 1, prev, dp)
                dp[i][prev + 1] = max(c1, c2)
            else:
                dp[i][prev + 1] = fun(a, n, i + 1, prev, dp)

            return dp[i][prev + 1]

        n = len(nums)
        dp = [[-1 for j in range(n + 1)] for i in range(n)]

        return fun(nums, n, 0, -1, dp)
