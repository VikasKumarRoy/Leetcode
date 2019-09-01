//Problem - 1176
// https://leetcode.com/problems/diet-plan-performance/

// O(n) time comlexity and cons space

class Solution {
public:
    int dietPlanPerformance(vector<int>& v, int k, int lower, int upper) {
        int pts = 0;
        int sum = 0;
        if(v.size() == 0)
            return 0;
        for(int i = 0; i < v.size(); i++) {
            sum += v[i];
            if(i >= k)
                sum -= v[i-k];
            if(i >= k-1) {
                if(sum < lower)
                    pts--;
                else if(sum > upper)
                    pts++;
            }
        }
        return pts;
    }
};
   