class Solution:

    def checkInclusion(self, s1: str, s2: str) -> bool:

        low = 0
        high = 0

        f = {}

        n = len(s2)
        k = len(s1)

        for high in range(n):

            f[s2[high]] = f.get(s2[high], 0) + 1

            # Window size > len(s1)
            if high - low + 1 > k:
                f[s2[low]] -= 1

                if f[s2[low]] == 0:
                    del f[s2[low]]

                low += 1

            # Check if window has same frequency
            if high - low + 1 == k:

                f1 = {}

                for ch in s1:
                    f1[ch] = f1.get(ch, 0) + 1

                if f == f1:
                    return True

        return False