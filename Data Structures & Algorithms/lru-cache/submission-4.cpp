class ListNode{
  public:
    int key, value;
    ListNode* next;
    ListNode* prev;
    ListNode(int key, int value){
     this->key = key;
     this->value = value;
    }
};
class LRUCache {
public:
    int cap;
    ListNode* head;
    ListNode* last;
    unordered_map<int,ListNode*> mp;
    LRUCache(int capacity) {
        cap = capacity;
        head = last = nullptr;
        mp.clear();
    }
    void insertAtHead(ListNode* node)
    {   if(head==nullptr){
           head = node;
           last = node;
           return;
        }
        node -> next = head;
        node -> prev = nullptr;
        head -> prev = node;
        head = node;
    }
    void removeNode(ListNode* node){
        if(node->prev!=nullptr)
          node->prev -> next = node -> next;
        else
          head = node -> next;
        if(node->next!=nullptr)
          node -> next -> prev = node -> prev;
        else
          last = node -> prev;
    }
    int get(int key) {
        if(mp.find(key)==mp.end())
          return -1;
        removeNode(mp[key]);
        insertAtHead(mp[key]);
        return mp[key]->value;
    }
    
    void put(int key, int value) {
        if(mp.find(key)==mp.end()){
         ListNode* node = new ListNode(key,value);
         node -> next = nullptr;
         node -> prev = nullptr;
         insertAtHead(node);
         mp[key] = node;
         if(mp.size()>cap){
            mp.erase(last->key);
            ListNode* temp = last;
            removeNode(last);
            delete temp;
         }
        }else{
          mp[key]->value = value;
          removeNode(mp[key]);
          insertAtHead(mp[key]);
        }
    }
};
