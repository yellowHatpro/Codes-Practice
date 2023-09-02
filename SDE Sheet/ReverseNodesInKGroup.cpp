struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

 int length(ListNode* head){
      int cnt = 0;
      while(head){
        cnt++;
        head=head->next;
    }
    return cnt;
 }


class Solution {
public:

    ListNode* reverseKGroup(ListNode* head, int k) {
      int n = length(head);
      int cnt = 0;
      ListNode* curr = head;
      ListNode* prev = nullptr;
      ListNode* next = nullptr;
      while(cnt<k && curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cnt++;
      }
      n-=k;
      //at this point, curr and next both are same
      if (curr && n>=k){
        head->next = reverseKGroup(curr, k);
      } else head->next = curr; //takes care of the case when : next = null, then null, otherwise if size<k, then next holds the address of the smaller list
      return prev;
    }
};
;


