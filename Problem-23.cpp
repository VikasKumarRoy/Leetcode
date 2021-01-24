// Problem  - 23

// https://leetcode.com/problems/merge-k-sorted-lists/

// O(nlogk) time complexity and O(k) solution

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() < 1)
            return NULL;
        priority_queue <pair <int, ListNode*>, vector <pair <int, ListNode*>>, greater<pair <int, ListNode*>> > pq;
        for(int i = 0; i < lists.size(); i++) {
            if(lists[i])
                pq.push({lists[i]->val, lists[i]});
        }
        ListNode *head = new ListNode(21);
        ListNode *curr = head;
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            curr->next = top.second;
            if(top.second->next)
                pq.push({top.second->next->val, top.second->next});
            curr = curr->next;
        }
        curr->next = NULL;
        return head->next;   
    }
};
