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
    ListNode* reverse(ListNode* head){
        
        ListNode* PREV=NULL;
        ListNode* CURR=head;
        ListNode* NEXT=head;
        
        while(CURR!=NULL){
            NEXT=CURR->next;
            CURR->next=PREV;
            PREV=CURR;
            CURR=NEXT;
        }
        
        return PREV;
    } 
    bool isPalindrome(ListNode* head) {
    
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode* firstH=head;
        ListNode* secondH=reverse(slow->next);
        
        while(firstH!=NULL && secondH !=NULL){
            if(firstH->val != secondH->val){
                return false;
            }
            firstH=firstH->next;
            secondH=secondH->next;
        }
        
        return true; 
    }
        
};

// ListNode* fast=head;
        
//         string ans="";
//         while(fast->next!=NULL){
//             ans=ans+to_string(fast->val);
//             fast=fast->next;
//         }
//         ans=ans+to_string(fast->val);
        
//         string cpy=ans;
//         reverse(ans.begin(),ans.end());
        
        
//         if(ans==cpy){
//             return 1;
//         }
        
//         return 0;