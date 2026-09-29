class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        f={}
        low=0
        high=0
        res=-1
        n= len(s)
        
        def find(f):
            maxc=-1
            for i in range(256):
                for i in f:
                    maxc= max(maxc,f[i])
                return maxc

        for high in range(n):
            f[s[high]]= f.get(s[high],0)+1
            Len= high-low+1
            maxnum=find(f)
            diff=Len-maxnum
            while diff>k:
                f[s[low]]-=1
                if f[s[low]]==0:
                    del f[s[low]]
                low+=1
                maxnum= find(f)
                Len= high-low+1
                diff= Len-maxnum
            Len= high-low+1
            res= max(Len,res)
        return res