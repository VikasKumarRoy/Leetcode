//Problem  - 1161
// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/


// O(n) solution usign dfs with queue
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if(!root)
            return 0;
        queue <TreeNode* > q;
        q.push(root);
        int mx = 0;
        int ans = 0;
        int ctr = 0;
        while(!q.empty()) {
            int level = q.size();
            int sum = 0;
            ctr++;
            while(level--) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            if(sum > mx) {
                mx = sum;
                ans = ctr;
            }
        }
        return ans;
            
    }
};

//another approach
class Solution {
public:
    
    //vector <int> levels(10000);
    int levels[10000] = {0};
    int max_level = 0;
    void findMax(TreeNode* root, int d) {
        if(!root)
            return;
        levels[d] += root->val;
        findMax(root->left, d+1);
        findMax(root->right, d+1);
        max_level = max(max_level, d);
    }
    
    int maxLevelSum(TreeNode* root) {
        if(!root)
            return 0;
        int ans = 0;
        int mx = 0;
        findMax(root, 1);
        vector <int> a(19);
        for(int i = 1; i <= max_level; i++) {
            if(mx < levels[i]) {
                mx = levels[i];
                ans = i;
            }
        }
        return ans;
    }
};