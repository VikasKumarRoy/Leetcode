//Problem - 430
// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

// O(m*n) time complexity and O(m*n) space complexity sol

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head)   return head;
        stack <Node*> s;
        Node *curr = head, *pre = NULL;
        while(1) {
            if(curr == NULL) {
                if(s.empty())
                    break;
                curr = s.top();
                s.pop();
                curr->prev = pre;
                pre->next = curr;
            }
            if(curr->child == NULL) {
                pre = curr;
                curr = curr->next;
            }
            else {
                if(curr->next)
                    s.push(curr->next);
                pre = curr;
                curr = curr->child;
                pre->next = curr;
                curr->prev = pre;
                pre->child = NULL;
            }
        }
        return head;
    }
};