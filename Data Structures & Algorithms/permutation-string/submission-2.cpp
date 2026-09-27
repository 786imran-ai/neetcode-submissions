class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // sliding window approach
        vector<int> freq1(26,0), freq2(26,0);
        for(char c: s1) freq1[c-'a']++;
        int n1= s1.size();
        int n2= s2.size();
        for(int i=0;i<n1;i++){
            freq2[s2[i]-'a']++;
        }
        if(freq1==freq2) return true;
        // sliding window
        for(int i=n1;i<n2;i++){
            // add new char
            freq2[s2[i]-'a']++;
            // remove old char
            freq2[s2[i-n1]-'a']--;
            if(freq1==freq2) return true;
        }
        return false;
        
    }
};
