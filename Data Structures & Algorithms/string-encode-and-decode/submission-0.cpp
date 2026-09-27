class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(string s : strs){
            res+= to_string(s.size())+'#'+s;
            // if string is neet= 4#neet
        }
        return res;
    }

    vector<string> decode(string s) {
        int i=0;
        vector<string> result;
        while(i<s.size()){

            int j=i;
            while(s[j] != '#') j++;

            // before word the length is
            int len= stoi(s.substr(i, j-i));
            // now the word
            string str= s.substr(j+1,len);
            result.push_back(str);
            i=j+1+len;
        }
        return result;
    }
};
