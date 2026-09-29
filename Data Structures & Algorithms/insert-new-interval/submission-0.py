class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:

        # Step 1: Insert newInterval at correct sorted position
        arr = []
        inserted = False

        for interval in intervals:

            if not inserted and newInterval[0] <= interval[0]:
                arr.append(newInterval)
                inserted = True

            arr.append(interval)

        # Agar newInterval sabse end mein aata hai
        if not inserted:
            arr.append(newInterval)


        # Step 2: Merge Intervals
        res = []

        start1 = arr[0][0]
        end1 = arr[0][1]

        for i in range(1, len(arr)):

            start2 = arr[i][0]
            end2 = arr[i][1]

            if end1 >= start2:
                start1 = start1
                end1 = max(end1, end2)

            else:
                res.append([start1, end1])

                start1 = start2
                end1 = end2

        res.append([start1, end1])

        return res