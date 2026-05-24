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
    bool hasCycle(ListNode* head) {
         if(head==nullptr || head->next== nullptr || head->next->next==nullptr)
           return false;
         ListNode* fastptr = head;
         ListNode* slowptr = head;
         slowptr = head -> next;
         fastptr = slowptr -> next;
         while(slowptr!=nullptr && fastptr!=nullptr && fastptr->next!=nullptr){
            if(slowptr == fastptr)
              return true;
            slowptr = slowptr -> next;
            fastptr = fastptr -> next -> next;
         }
         return false;
    }
};
