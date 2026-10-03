class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        n= len(nums)
        ans=[]
        def fun(i,temp):
            if i==n:
                ans.append(temp[:])
                return
            yes= temp+[nums[i]]
            fun(i+1,yes)
            no= temp
            fun(i+1,no)
        fun(0,[])
        return ans










# EPISODE 8 IMPORTANT


#this is memoization

# class Solution:
#     def perfectSum(self, arr, sum):
#         n = len(arr)
#         dp = [[-1] * (sum + 1) for _ in range(n + 1)]

#         def fun(i, sum):
#             if i == n:
#                 if sum == 0:
#                     return 1
#                 return 0

#             if dp[i][sum] != -1:
#                 return dp[i][sum]

#             if arr[i] > sum:
#                 dp[i][sum] = fun(i + 1, sum)
#                 return dp[i][sum]

#             c1 = fun(i + 1, sum - arr[i])
#             c2 = fun(i + 1, sum)

#             dp[i][sum] = c1 + c2

#             return dp[i][sum]

#         return fun(0, sum)


#     2. Tabulation (Bottom-Up DP)
# class Solution:
#     def perfectSum(self, arr, sum):
#         n = len(arr)
#         dp = [[0] * (sum + 1) for _ in range(n + 1)]

#         dp[n][0] = 1

#         for i in range(n - 1, -1, -1):
#             for j in range(sum + 1):
#                 if arr[i] > j:
#                     dp[i][j] = dp[i + 1][j]
#                 else:
#                     dp[i][j] = dp[i + 1][j - arr[i]] + dp[i + 1][j]

#         return dp[0][sum]