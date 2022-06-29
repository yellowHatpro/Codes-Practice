class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* temp = head;
        while(temp != NULL){
            
            ListNode* dup = temp;
            while(dup != NULL && temp->val == dup->val){
                dup = dup->next;
            }
            
            temp->next = dup;
            temp = temp->next;
        }
        
        return head;
        
    }
};