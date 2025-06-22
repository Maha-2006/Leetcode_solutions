class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.length();
        vector<string> res;
        string str = "";
        for(int i=0;i<n;i++){
            str+=s[i];
            if(str.length()==k){
                res.push_back(str);
                str = "";
            }
        }
        if(str.length()!=0)
        {
            while(str.length()<k) str += fill;
            res.push_back(str);
        }
        return res;
    }
};