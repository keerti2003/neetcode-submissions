class Solution {
public:
    int rob(vector<int>& nums) {
        int curr = nums[0], prev = 0;
        for(int i=1; i<nums.size(); i++){
            int ans = max(prev + nums[i], curr);
            prev = curr;
            curr = ans;
        }
        return curr;
    }
};
