class Solution:
    def minMeetingRooms(self, intervals: List[Interval]) -> int:

        if not intervals:
            return 0

        start = []
        end = []

        n = len(intervals)

        for i in range(n):
            start.append(intervals[i].start)
            end.append(intervals[i].end)

        start.sort()
        end.sort()

        room = 0
        res = 0

        i = 0
        j = 0

        while i < n and j < n:

            if start[i] < end[j]:
                room += 1
                res = max(res, room)
                i += 1

            else:
                room -= 1
                j += 1

        return res








# class Solution:
#     def minMeetingRooms(self, intervals: List[List[int]]) -> int:

#         n = len(intervals)

#         start = []
#         end = []

#         for i in range(n):
#             start.append(intervals[i][0])
#             end.append(intervals[i][1])

#         start.sort()
#         end.sort()

#         room = 0
#         res = 0

#         i = 0
#         j = 0

#         while i < n and j < n:

#             if start[i] < end[j]:
#                 room += 1
#                 res = max(res, room)
#                 i += 1

#             else:
#                 room -= 1
#                 j += 1

#         return res