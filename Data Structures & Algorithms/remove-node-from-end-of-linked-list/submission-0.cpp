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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode* ptr1 = head;
       ListNode* ptr2 = head;
       ListNode* prev = nullptr;
       for(int i=0;i<n;i++){
         ptr1 = ptr1-> next;
       } 
       while(ptr1!=nullptr){
        ptr1 = ptr1-> next;
        prev = ptr2;
        ptr2 = ptr2 -> next;
       }
       if(prev==nullptr)
         {
            return ptr2-> next;
         }
       prev -> next = ptr2 -> next;
       free(ptr2);
       return head;
    }
};
