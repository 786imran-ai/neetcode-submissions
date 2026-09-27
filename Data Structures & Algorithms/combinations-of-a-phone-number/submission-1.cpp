class Solution {
public:
    vector<string> ans;
    void dfs(string &digits, unordered_map<char,string> mp,int idx,string &temp){
        if(idx>=digits.size()){
            ans.push_back(temp);
            return;
        }
        char ch=digits[idx];
        string str=mp[ch];
        for(int i=0;i<str.size();i++){
            temp.push_back(str[i]);
            dfs(digits,mp,idx+1,temp);
            temp.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return ans;
        unordered_map<char,string> mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        string temp="";
        dfs(digits, mp, 0,temp);
        return ans;
    }
};
