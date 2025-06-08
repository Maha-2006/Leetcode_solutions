class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        int currnum = 1;
        for(int i=0;i<n;i++){
            res.push_back(currnum);
            if(currnum * 10 <= n) currnum *= 10;
            else{ 
                while(currnum % 10 == 9 || currnum >= n)
                {
                    currnum /= 10;
                }    
                currnum+=1;    

            }
        }
        return res;
    }
};