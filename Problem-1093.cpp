//Problem  - 1093
// https://leetcode.com/problems/statistics-from-a-large-sample/


class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        vector <double> ans(5, 0.00000);
        if(count.size() == 0)
            return ans;
        double mean = 0, mode = 0, mx = DBL_MIN, mn = DBL_MAX, mode_num = 0, med = 0;
        int cnt = 0;
        bool flag = 0;
        for(int i = 0; i < count.size(); i++) {
            if(count[i] != 0) {
                if(!flag){
                    mn = i;
                    flag = 1;
                }
                mx = i;
                cnt += count[i];
                mean += count[i]*i;
               if(count[i] > mode_num) {
                   mode_num = count[i];
                   mode = i;
               }
            }
        }
        mean = mean/cnt;
        
        if(cnt & 1) {
            cnt = floor(cnt/2) + 1;
            for(int i = 0; i < count.size(); i++) {
                if(count[i]) {
                    cnt -= count[i];
                    if(cnt <= 0) {
                        med = i;
                        break;
                    }
                }
            }
        } else {
            cnt = floor(cnt/2);
            double a, b;
            bool check = 0;
            for(int i = 0; i < count.size(); i++) {
                if(count[i] > 0) {
                    if(check) {
                        b = i;
                        break;
                    }
                    cnt -= count[i];
                    if(cnt < 0) {
                        a = b = i;
                        break;
                    }
                    if(cnt == 0) {
                        a = i;
                        check = 1;
                    }
                }
            }
            med = (a + b) / 2; 
        }
        ans[0] = mn;
        ans[1] = mx;
        ans[2] = mean;
        ans[3] = med;
        ans[4] = mode;
        return ans;
    }
};