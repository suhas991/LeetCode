/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        
        //length of A
        ListNode* temp=headA;
        int lenA=0;
        
        while(temp!=NULL){
            lenA++;
            temp=temp->next;
        }
        
        //length of B
        temp=headB;
        int lenB=0;
        
        while(temp!=NULL){
            lenB++;
            temp=temp->next;
        }
        
        //cout<<lenA<<" "<<lenB;
        int diff=abs(lenA-lenB);
        
        ListNode* t1=headA;
        ListNode* t2=headB;
        
        if(lenA>lenB){
            while(diff-- > 0){
                t1=t1->next;
            }
        }else{
            while(diff-- > 0){
                t2=t2->next;
            }    
        }
        
        while(t1 !=  t2){
             
            t1=t1->next;
            t2=t2->next;
            
            if(t1 == NULL || t2 == NULL){
                return NULL;
            }
        }
        
        return t1;
    }
};