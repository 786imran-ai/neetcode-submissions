class Solution {
public:
    vector<vector<string>> ans;
    vector<string> curr;
    bool ispalindrome(string &s, int start, int end ){
        while(start< end){
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    void dfs(string &s, int idx){
        if(idx==s.size()){
            ans.push_back(curr);
            return;
        }
        for(int end= idx; end<s.size();end++){
            if(ispalindrome(s,idx, end)){
                curr.push_back(s.substr(idx,end-idx+1));
                dfs(s, end+1);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        
        dfs(s, 0);
        return ans;
    }
};
