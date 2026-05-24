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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy_node = new ListNode();
        ListNode* curr = dummy_node;
        int r = 0;
        while(l1 && l2){
            int sum = l1-> val + l2-> val + r;
            l1 -> val = sum%10;
            r = sum/10;
            curr -> next = l1;
            l1 = l1 -> next;
            l2 = l2 -> next;
            curr = curr -> next;
        }
        while(l1){
            int sum = l1-> val + r;
            l1 -> val = sum%10;
            r = sum/10;
            curr -> next = l1;
            l1 = l1 -> next;
            curr = curr -> next;
        }
        while(l2){
            int sum = l2-> val + r;
            l2 -> val = sum%10;
            r = sum/10;
            curr -> next = l2;
            l2 = l2 -> next;
            curr = curr -> next;
        }
        if(r)
         curr -> next = new ListNode(r);
        curr = dummy_node -> next;
        delete dummy_node;
        return curr;
    }
};
