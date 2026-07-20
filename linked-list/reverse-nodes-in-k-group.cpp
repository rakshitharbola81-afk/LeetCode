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
ListNode*getK(ListNode*temp,int k){
    k-=1;
    while(temp!=NULL && k>0){
        k--;
        temp=temp->next;
    }
    return temp;
}
ListNode* reverseList(ListNode* head) {
        ListNode*temp=head;
        ListNode*prev=NULL;
        while(temp!=NULL){
            ListNode*front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*temp=head;
        ListNode*prev=NULL;
        while(temp!=NULL){
            ListNode*kNode=getK(temp,k);
            if(kNode==NULL){
                if(prev)prev->next=temp;
                break;
            }
            ListNode*nextNode=kNode->next;
            kNode->next=NULL;
            reverseList(temp);
            if(temp==head){
                head=kNode;
            }
            else{
                prev->next=kNode;
            }
            prev=temp;
            temp=nextNode;
        }
        return head;
    }
};