def fun(s1, s2, n, m, i, j, dp):
    if i == n or j == m:
        return 0

    if dp[i][j] != -1:
        return dp[i][j]

    if s1[i] == s2[j]:
        dp[i][j] = 1 + fun(s1, s2, n, m, i + 1, j + 1, dp)
        return dp[i][j]

    c1 = fun(s1, s2, n, m, i, j + 1, dp)
    c2 = fun(s1, s2, n, m, i + 1, j, dp)

    dp[i][j] = max(c1, c2)
    return dp[i][j]


class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        n = len(text1)
        m = len(text2)

        dp = [[-1] * m for _ in range(n)] 

        return fun(text1, text2, n, m, 0, 0, dp)