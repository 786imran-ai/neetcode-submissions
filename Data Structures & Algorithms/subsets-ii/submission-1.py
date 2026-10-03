class Solution:
    def subsetsWithDup(self, nums):
        nums.sort()
        n = len(nums)
        ans = []

        def fun(i, temp):
            if i == n:
                ans.append(temp[:])
                return

            # yes
            temp.append(nums[i])
            fun(i + 1, temp)
            temp.pop()

            # no
            j = i + 1
            while j < n and nums[j] == nums[i]:
                j += 1

            fun(j, temp)

        fun(0, [])
        return ans