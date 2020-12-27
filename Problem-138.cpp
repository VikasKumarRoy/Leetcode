// Problem - 138

// https://leetcode.com/problems/copy-list-with-random-pointer/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return head;
        Node *curr = head, *copy = NULL;
    while(curr) {
        Node *temp = curr->next;
        curr->next = new Node(curr->val);
        curr->next->next = temp;
        curr = temp;
    }
    curr = head;
    while(curr) {
        
        curr->next->random = curr->random ? curr->random->next : NULL;
        curr = curr->next->next;
    }
    
    curr = head; 
    copy = head->next;
    Node *temp = copy;
    while(curr) {
        curr->next = curr->next->next;
        copy->next = copy->next? copy->next->next : NULL;
        curr = curr->next;
        copy = copy->next;
    }
    return temp;
    }
};
