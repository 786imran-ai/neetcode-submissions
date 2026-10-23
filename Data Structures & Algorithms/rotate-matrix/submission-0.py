
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        l, r = 0, len(matrix) - 1

        while l < r:
            for i in range(r - l):
                top, bottom = l, r

                topLeft = matrix[top][l + i]

                # Bottom-left -> Top-left
                matrix[top][l + i] = matrix[bottom - i][l]

                # Bottom-right -> Bottom-left
                matrix[bottom - i][l] = matrix[bottom][r - i]

                # Top-right -> Bottom-right
                matrix[bottom][r - i] = matrix[top + i][r]

                # Top-left -> Top-right
                matrix[top + i][r] = topLeft

            l += 1
            r -= 1
