class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        low=0
        high=0
        res=0
        f={}
        n= len(s)
        for high in range(n):
            f[s[high]]=f.get(s[high],0)+1
            k= high-low+1
            while len(f)<k:
                f[s[low]]-=1
                if f[s[low]]==0:
                    del f[s[low]]
                low+=1
                k= high-low+1
            Len= high-low+1
            res= max(Len,res)
        if res==0:
            return 0
        return res
    