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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode* curr = new ListNode(0);
        ListNode* dum=curr;
        
        while(l1!=NULL && l2!=NULL){
            
            if(l1->val <= l2->val){
                dum->next=l1;
                l1=l1->next;
            }else{
                dum->next=l2;
                l2=l2->next;
            }
            dum=dum->next;
        }
        while(l2!=NULL){
            dum->next=l2;
            l2=l2->next;
            dum=dum->next;
        }
        while(l1!=NULL){
            dum->next=l1;
            l1=l1->next;
            dum=dum->next;
        }
        
        return curr->next;

    }
};