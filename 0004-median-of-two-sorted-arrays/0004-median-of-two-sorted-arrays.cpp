class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1>n2) return findMedianSortedArrays(nums2,nums1);//swap if n1>n2

        int n = n1+n2;
        int left = (n1+n2+1)/2;//for both odd and even they are same formulae

        int low = 0, high = n1;// taking max elements n1 is possible
        while(low<=high){
            int mid1 = (low+high) >>1;
            int mid2 = left - mid1;

            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if(mid1<n1) r1 = nums1[mid1];//assign r1
            if(mid2<n2) r2 = nums2[mid2];//assign r2
            if(mid1-1>=0)l1 = nums1[mid1-1];//assign l1
            if(mid2-1>=0)l2 = nums2[mid2-1];//assignl2

            if(l1<=r2 && l2<=r1){
                if(n%2==1) return max(l1,l2);//for odd
                else return ((double)(max(l1,l2)+min(r1,r2)))/2.0;//for even
            }

            else if(l1>r2) high = mid1 - 1;
            else low = mid1+1;

        }
        return 0;
        
    }
};