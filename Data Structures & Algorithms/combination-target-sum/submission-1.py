class Solution:
    def combinationSum(self, candidates, target):
        n = len(candidates)
        ans = []

        def fun(i, temp, sum):
            if sum == 0:
                ans.append(temp[:])
                return

            if i == n or sum < 0:
                return

            # yes: same element dobara le sakte hain
            temp.append(candidates[i])
            fun(i, temp, sum - candidates[i])

            # backtrack
            temp.pop()

            # no: next element par jao
            fun(i + 1, temp, sum)

        fun(0, [], target)
        return ans