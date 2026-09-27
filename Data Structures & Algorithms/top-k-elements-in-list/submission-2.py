class Solution:
    def topKFrequent(self, nums: list[int], k: int) -> list[int]:
        freq={}
        for i in nums:
            freq[i]= freq.get(i,0)+1
        heap=[]
        for element,fre in freq.items():
            curr=(fre,element)
            if len(heap)<k:
                heapq.heappush(heap,curr)
            else:
                if curr[0]<heap[0][0]:
                    continue
                heapq.heappop(heap)
                heapq.heappush(heap,curr)
        ans=[]
        while heap:
            ans.append(heapq.heappop(heap)[1])
        return ans
