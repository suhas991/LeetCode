ListNode* fast=head;
string ans="";
while(fast->next!=NULL){
ans=ans+to_string(fast->val);
fast=fast->next;
}
ans=ans+to_string(fast->val);
string cpy=ans;
reverse(ans.begin(),ans.end());
if(ans==cpy){
return 1;
}
return 0;
}