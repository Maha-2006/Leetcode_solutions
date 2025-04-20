class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        unordered_map<int,int>map;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(map.find(answers[i]+1)==map.end())
            {
                ans+=answers[i]+1;
                if(answers[i]==0)
                continue;
                map[answers[i]+1]++;
            }
            else{
                map[answers[i]+1]++;
                int key = answers[i]+1;
                int freq = map[key];
                if(freq==key)
                map.erase(key);
            }
        }
        return ans;
    }
};