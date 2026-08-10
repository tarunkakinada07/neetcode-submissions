class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int s = nums.size();
        vector<int> ans(s, 1);
        int prefix = 1;
        for (int i = 0; i < s; i++){
            ans[i] = prefix;
            prefix = prefix*nums[i];
        }

        int suffix = 1;
        for (int i = s-1; i >= 0; i--){
            ans[i] = ans[i]*suffix;
            suffix = suffix*nums[i];
        }
        return ans;
    }
};
