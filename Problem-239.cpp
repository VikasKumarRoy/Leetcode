//Problem - 239
// https://leetcode.com/problems/sliding-window-maximum/ns/

// O(n) time comlexity and O(n) space using queue data structure

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        vector <int> ans;
        deque <int> q;
        if(arr.size() == 0)
            return ans;
        
        for(int i = 0; i < k; i++) {
            while(!q.empty() && arr[q.back()] <= arr[i])
                q.pop_back();
            q.push_back(i);
        }
        ans.push_back(arr[q.front()]);
        for(int i = k; i < arr.size(); i++) {
            while(!q.empty() && i - q.front() >= k)
                q.pop_front();
            while(!q.empty() && arr[q.back()] <= arr[i])
                q.pop_back();
            q.push_back(i);
            ans.push_back(arr[q.front()]);
        }
        return ans;
    }
}; 