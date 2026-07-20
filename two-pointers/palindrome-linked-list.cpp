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
ListNode*reverseLL(ListNode*head){
    if(head==NULL || head->next==NULL)return head;
    ListNode*newHead=reverseLL(head->next);
    ListNode*front=head->next;
    front->next=head;
    head->next=NULL;
    return newHead;
}
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode*slow=head;
        ListNode*fast=head;
        if(head==NULL || head->next==NULL)return head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*newHead=reverseLL(slow->next);
        ListNode*left=head;
        ListNode*right=newHead;
        while(right!=NULL){
            if(left->val != right->val){
                reverseLL(newHead);
                return false;
            }
            left=left->next;
            right=right->next;
        }
        reverseLL(newHead);
        return true;
    }
};