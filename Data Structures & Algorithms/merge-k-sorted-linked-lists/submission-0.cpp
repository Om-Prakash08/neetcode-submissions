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
    ListNode* merge(ListNode* a, ListNode* b){
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        while(a&&b){
            if(a->val<=b->val){
                curr -> next  = a;
                a = a -> next;
                curr = curr -> next;
            }else{
                curr -> next  = b;
                b = b -> next;
                curr = curr -> next;
            }
        }
        while(a){
             curr -> next  = a;
                a = a -> next;
                curr = curr -> next;
        }
        while(b){
            curr -> next  = b;
                b = b -> next;
                curr = curr -> next;
        }
        return dummy -> next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return nullptr;
        }
        ListNode *head = lists[0];
        for(int i=1;i<lists.size();i++){
            head = merge(head,lists[i]);
        }
        return head;
    }
};
