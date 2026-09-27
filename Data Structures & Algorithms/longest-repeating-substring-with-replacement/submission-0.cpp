class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int l=0, res=0, maxfreq=0;
        for(int r=0;r<s.size();r++){
            int idx= s[r]-'A';
            freq[idx]++;
            maxfreq= max(maxfreq,freq[idx]);

            while((r-l+1)-maxfreq >k){
                freq[s[l]-'A']--;
                l++;
            }
            res= max(res, r-l+1);
        }
        return res;
    }
};
