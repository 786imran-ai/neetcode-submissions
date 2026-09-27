class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:

        rows = [set() for _ in range(9)]
        cols = [set() for _ in range(9)]
        boxes = [set() for _ in range(9)]

        for i in range(9):
            for j in range(9):

                if board[i][j] == ".":
                    continue

                num = board[i][j]

                # Row
                if num in rows[i]:
                    return False
                rows[i].add(num)

                # Column
                if num in cols[j]:
                    return False
                cols[j].add(num)
                # 3 x 3 box
                box = (i // 3) * 3 + (j // 3)

                if num in boxes[box]:
                    return False
                boxes[box].add(num)

        return True