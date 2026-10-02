class Solution:
    def rob(self, nums):
        n = len(nums)
        dp = {}

        def fun(i):
            if i >= n:
                return 0

            if i in dp:
                return dp[i]

            a1 = nums[i] + fun(i + 2)
            a2 = fun(i + 1)

            dp[i] = max(a1, a2)

            return dp[i]

        return fun(0)