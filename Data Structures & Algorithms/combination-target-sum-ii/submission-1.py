class Solution:
    def combinationSum2(self, candidates, target):
        n = len(candidates)
        candidates.sort()
        ans = []

        def fun(i, temp, sum):
            if sum == 0:
                ans.append(temp[:])
                return

            if i == n or sum < 0:
                return

            if i > 0 and candidates[i] == candidates[i - 1] and i > 0:
                pass

            # yes
            temp.append(candidates[i])
            fun(i + 1, temp, sum - candidates[i])

            temp.pop()

            # no
            j = i + 1
            while j < n and candidates[j] == candidates[i]:
                j += 1

            fun(j, temp, sum)

        fun(0, [], target)
        return ans