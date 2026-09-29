class Solution:
    def canAttendMeetings(self, intervals: List[Interval]) -> bool:
        if not intervals:
            return True

        intervals.sort(key=lambda x: x.start)

        start1 = intervals[0].start
        end1 = intervals[0].end

        for i in range(1, len(intervals)):

            start2 = intervals[i].start
            end2 = intervals[i].end

            if end1 > start2:
                return False

            start1 = start2
            end1 = end2

        return True