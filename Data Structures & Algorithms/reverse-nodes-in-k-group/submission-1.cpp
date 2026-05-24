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
        if(head==nullptr || head->next==nullptr)
          return head;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr){
            ListNode* temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* prev;
        for(int i=0;i<k;i++){
           if(curr!=nullptr){
            prev = curr;
            curr = curr -> next;
           }
           else{
           return head;
           }
        }
        ListNode* temp = reverseKGroup(curr, k);
        prev -> next = nullptr;
        ListNode* newHead = reverse(head);
        head -> next = temp;
        return newHead;
    }
};
