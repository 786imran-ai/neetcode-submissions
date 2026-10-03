class Solution:
    def permute(self, nums):
        n = len(nums)
        ans = []

        def fun(temp):
            if len(temp) == n:
                ans.append(temp[:])
                return

            for i in range(n):
                if nums[i] not in temp:
                    temp.append(nums[i])
                    fun(temp)
                    temp.pop()

        fun([])
        return ans