#include <bits/stdc++.h>
using namespace std;
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        int cnt = 0;
        if (nums.size()==0) return 0;
        ListNode* temp = head;
        int res = 0;
        while(temp){
          vector<int>::iterator it =  find(nums.begin(), nums.end(), temp->val);
          if (it!=nums.end())
          {
              cnt++;
          } else{
            if (cnt!=0 )
            {
                res++;
               
            }
            cnt=0;
          }
          temp=temp->next;
        }
        if (cnt!=0)
        {
            res++;
        }
        return res;
    }
};