/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
       unordered_map<Node*,Node*>mp;
       Node* dummy_node = new Node(0);
       Node* curr1 = head;
       Node* curr2 = dummy_node;
       while(curr1){
         curr2 -> next = new Node(curr1->val);
         curr2 = curr2 -> next;
         mp[curr1] = curr2;
         curr1 = curr1-> next;
       }
       curr1 = head;
       curr2 = dummy_node->next;
       while(curr1){
        curr2-> random = mp[curr1->random];
        curr1 = curr1 -> next;
        curr2 = curr2 -> next;
       }
       return dummy_node->next;
    }
};
