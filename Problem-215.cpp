// Problem - 215

// https://leetcode.com/problems/kth-largest-element-in-an-array/

// O(nlogk) time complexity and O(k) space complexity solution using min heap

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue <int, vector <int>, greater <int>> pq;
        int i = 0;
        for(; i < k; i++) {
            pq.push(nums[i]);
        }
        for(; i < n; i++) {
            if(nums[i] >= pq.top()) {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();;
    }
};

// OR O(n) AVERAGE time complexity and O(1) space complexity solution using quick select

class Solution {
public:
    int findPivot(vector <int>& nums, int l, int h) {
        int pivot = nums[h];
        int i = l;
        for (int j = l; j < h; j++) {
            if (nums[j] <= pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[h]);
        return i;
    }
    
    
    int quickSelect(vector <int>& nums, int k) {
        int l = 0, h = nums.size()-1;
        k = nums.size()-k;
        while(l < h) {
            int pv = findPivot(nums, l, h);
            cout << endl;
            if(pv == k)
                return nums[pv];
            else if(pv < k)
                l = pv+1;
            else
                h = pv-1;
        }
        return nums[k];   
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, k);
    }
};
