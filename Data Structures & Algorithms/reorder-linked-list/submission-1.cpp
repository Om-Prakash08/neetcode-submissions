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
        ListNode* prev=nullptr;
        ListNode* curr = head;
        while(curr){
            ListNode* temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
         int n = 0;
         ListNode* curr = head;
         while(curr!=nullptr){
            n++;
            curr = curr ->next;
         }
         int count = 0;
         curr = head;
         ListNode* prev;
         while(count<(n+1)/2){
            prev = curr;
            curr = curr -> next;
            count++;
         }
         prev -> next = nullptr;
         ListNode* head2 = reverse(curr);
         ListNode* dummy_node = new ListNode();
         curr = dummy_node;
         while(head!=nullptr && head2!=nullptr){
           curr -> next = head;
           curr = head;
           head = head->next;
           curr -> next = head2;
           curr = head2;
           head2 = head2->next;
         }
        if(head){
            curr -> next = head;
            head = head -> next;
            curr = curr -> next;
        }
        if(head2){
            curr -> next = head2;
            head2 = head2 -> next;
            curr = curr -> next;
        }
      //  return dummy_node -> next;
    }
};
