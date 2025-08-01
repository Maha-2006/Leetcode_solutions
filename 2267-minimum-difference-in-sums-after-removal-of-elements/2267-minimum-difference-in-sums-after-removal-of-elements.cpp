class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int N = nums.size();
        int n = N/3;

        vector<long long> leftMinSum(N,0);
        vector<long long> rightMaxSum(N,0);

        // left side: keep n smallest from first 2n

        priority_queue<int> maxHeap;
        long long leftSum = 0;
        for(int i=0;i<2*n;i++){
            maxHeap.push(nums[i]);
            leftSum += nums[i];

            if(maxHeap.size()>n){
                leftSum-=maxHeap.top();
                maxHeap.pop();
            }
            if(maxHeap.size()==n)
            leftMinSum[i] = leftSum;
        }
      priority_queue<int, vector<int>,greater<int>> minHeap;
      long long rightSum = 0;
      for(int i=N-1;i>=n;i--){
        minHeap.push(nums[i]);
        rightSum+=nums[i];

        if(minHeap.size()>n){
            rightSum -= minHeap.top();
            minHeap.pop();
        }
        if(minHeap.size()==n)
        rightMaxSum[i] = rightSum;
      }

      //now calculate the minimum difference
      long long result = LLONG_MAX;

      for(int i=n-1;i<2*n;i++){
        result = min(result,leftMinSum[i]-rightMaxSum[i+1]);
      }
      return result;

    }
};