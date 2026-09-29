class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:

        intervals.sort()

        start1 = intervals[0][0]
        end1 = intervals[0][1]

        count = 0

        for i in range(1, len(intervals)):

            start2 = intervals[i][0]
            end2 = intervals[i][1]

            if end1 > start2:
                # overlap
                count += 1

                # keep the interval which ends earlier
                end1 = min(end1, end2)

            else:
                # no overlap
                start1 = start2
                end1 = end2

        return count