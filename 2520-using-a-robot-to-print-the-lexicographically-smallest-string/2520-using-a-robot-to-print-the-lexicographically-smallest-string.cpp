class Solution {
public:
    string robotWithString(string s) {
        unordered_map<char,int>cnt;
        int n = s.length();
        for(char c:s) cnt[c]++;

        stack<char> st;
        char minCh = 'a';
        string res = "";
        for(char c: s){
            st.push(c);
            cnt[c]--;
            while(minCh!='z' && cnt[minCh]==0) minCh++;
            while(!st.empty() && st.top()<=minCh){
                res += st.top();
                st.pop();
            }
        }
        return res;
    }
};