//Problem - 15
// https://leetcode.com/problems/3sum/

// Time Complexity O(n^2) and O(1) space

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector <vector<int>> ans;
        if(nums.empty())
            return ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < nums.size(); i++) {
            int st = i+1;
            int en = nums.size()-1;
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            while(st < en) {
                
                if(nums[i] + nums[en] + nums[st] < 0)
                    st++;
                else if(nums[i] + nums[en] + nums[st] > 0)
                    en--;
                else {
                    ans.push_back({nums[i], nums[st], nums[en]});
                   
                    while(st < n-1 && nums[st] == nums[st+1])
                        st++;
                    while(en > 0 && nums[en] == nums[en-1])
                        en--;
                     st++, en--;
                }
            }
        }
        
        
        return ans;
    }
};


