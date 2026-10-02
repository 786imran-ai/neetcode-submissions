class Solution:
    def rob(self, nums):
        n = len(nums)

        if n == 1:
            return nums[0]

        def fun(start, end):
            dp = {}

            def solve(i):
                if i >= end:
                    return 0

                if i in dp:
                    return dp[i]

                a1 = nums[i] + solve(i + 2)
                a2 = solve(i + 1)

                dp[i] = max(a1, a2)
                return dp[i]

            return solve(start)

        return max(fun(0, n - 1), fun(1, n))