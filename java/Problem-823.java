// Problem - 823

// https://leetcode.com/problems/binary-trees-with-factors/

// O(n^2) time complexity and O(n) space complexity solution

class Solution {
    final double mod = 1e9 + 7;
    
    public int numFactoredBinaryTrees(int[] arr) {
        HashMap<Integer, Long> dp = new HashMap<Integer, Long>();
        int ans = 0;
        Arrays.sort(arr);
        for(int i = 0; i < arr.length; i++) {
            long ctr = 1;
            for(int j = 0; j < i; j++) {
                if(arr[i] % arr[j] == 0 && dp.containsKey(arr[i]/arr[j])) {
                    ctr = (ctr + (dp.get(arr[j]) * dp.get(arr[i]/arr[j]))%(int)mod)%(int)mod;
                }
            }
            dp.put(arr[i], ctr);
            ans = (ans + (int)ctr)%(int)mod;
        }
        return ans;
    }
}
