// Problem - 1779

// https://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/

// O(n) time complexity and O(1) space solution

class Solution {
    public int distance(int x1, int y1, int x2, int y2) {
        return Math.abs(x2-x1) + Math.abs(y2-y1);
    }
    
    public int nearestValidPoint(int x, int y, int[][] points) {
        int n = points.length;
        int min = Integer.MAX_VALUE, ind = n;
        for(int i = 0; i < n; i++) {
            if(points[i][0] == x || points[i][1] == y) {
                int d = distance(points[i][0], points[i][1], x, y);
                // System.out.println(d);
                if(d < min) {
                    ind = i;
                    min = d;
                }
            }
        }
        return min == Integer.MAX_VALUE ? -1 : ind;
    }
}
