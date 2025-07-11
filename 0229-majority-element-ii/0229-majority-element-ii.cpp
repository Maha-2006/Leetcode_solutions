class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ele1 = INT_MIN;
        int ele2 = INT_MIN;
        int cnt1 =0, cnt2 = 0;

        for(int i=0;i<n;i++)
        {
            if(cnt1==0 && nums[i]!=ele2)
            {
                cnt1=1;
                ele1=nums[i];
            }
            else if(cnt2==0&&nums[i]!=ele1)
            {
                cnt2=1;
                ele2=nums[i];
            }
            else if(nums[i]==ele1) cnt1++;
            else if(nums[i]==ele2) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        vector<int> ls;
        cnt1=0,cnt2=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==ele1) cnt1++;
            if(nums[i]==ele2) cnt2++;
        }

        int min = int(n/3)+1;
        if(cnt1>=min) ls.push_back(ele1);
        if(cnt2>=min) ls.push_back(ele2);

        return ls;
    }
};