/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       if(head == NULL) return head;

    ListNode* fast = head;
    ListNode* slow = head;

    // Move fast n steps ahead
    for(int i = 0; i < n; i++) {
        fast = fast->next;
    }

    // Edge case: remove head
    if(fast == NULL) {
        return head->next;
    }

    // Move both pointers
    while(fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    // Delete node
    ListNode* delNode = slow->next;
    slow->next = slow->next->next;
    delete delNode;   // C++ me free nahi, delete use kar

    return head;
    }
};