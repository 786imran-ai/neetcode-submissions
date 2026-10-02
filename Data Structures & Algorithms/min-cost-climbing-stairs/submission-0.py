class Solution:
    def minCostClimbingStairs(self, cost):
        dp = {}

        def fun(i):
            if i >= len(cost):
                return 0

            if i in dp:
                return dp[i]

            a1 = cost[i] + fun(i + 1)
            a2 = cost[i] + fun(i + 2)

            ans = min(a1, a2)
            dp[i] = ans

            return ans

        return min(fun(0), fun(1))
        