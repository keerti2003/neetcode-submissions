class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, n = nums.size();
        int sum = 0, ans = INT_MAX;

        for(int right=0; right<n; right++){
            sum = sum + nums[right];
            while(left <= right && sum >= target){
                ans = min(right-left+1, ans);
                sum = sum - nums[left];
                left++;
            }
        }

        if (ans == INT_MAX)
            return 0;
        return ans;
    }
};