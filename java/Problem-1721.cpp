// Problem - 1721.cpp

// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

// O(n) time complexity and O(1) space solution

class Solution {
    public ListNode swapNodes(ListNode head, int k) {
        if(k == 0)
            return head;
        int n = 0;
        ListNode curr = head;
        while(curr != null) {
            curr = curr.next;
            n++;
        }
        curr = head;
        ListNode first = null, second = null;
        int ctr = 1;
        while(ctr <= n) {
            if(ctr == k) {
                first = curr;
            }
            if(ctr == n-k+1) {
                second = curr;
            }
            ctr++;
            curr = curr.next;
        }
        if(first == null || second == null || first == second)
            return head;
        int temp = first.val;
        first.val = second.val;
        second.val = temp;
        return head;
    }
}
