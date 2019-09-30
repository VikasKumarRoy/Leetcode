//Problem - 18
// https://leetcode.com/problems/4sum/

// Time Complexity O(n^3) and O(1) space complexity

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector <vector<int>> ans;
        int n = nums.size();
        if(n < 4)
            return ans;
        for(int i = 0; i < n-3; i++) {
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            for(int j = i+1; j < n-2; j++) {
                if(j > i+1 && nums[j] == nums[j-1])
                    continue;
                int st = j+1, en = n-1;
                while(st < en) {
                    int sum = nums[st] + nums[en] + nums[i] + nums[j];
                    if(sum < target) 
                        st++;
                    else if(sum > target) 
                        en--;
                    else {
                        ans.push_back({nums[i], nums[j], nums[st], nums[en]});
                        while(en > j && nums[en] == nums[en-1])
                            en--;
                        while(st < n-1 && nums[st] == nums[st+1])
                            st++;
                        en--;
                        st++;
                    }
                }
            }
        }
        return ans;
    }
};


