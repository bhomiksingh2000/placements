/*
We will maintain a doubly linked list (DLL) , now for each put or get(if present in map),we will make that page/cache/key the latest i.e recently used cache, i.e we will make that page near the head of the DLL , coz all the recently used cache will be stored near the head of the DLL, and the least recently used cache will be stored near tail, 

We are maintaining a map that will store the address of the node and the key  so  that if we will encounter get operation then we will check that whether it is present in the map or not means it is currently in the DLL or not, if it will be present in the map we will first delete it from the DLL and then put it next to the head because this will be the recently used cache 

and in put operation he will do the same but if  the size of the map will be equal to the capacity means the main memory size  will be full then we will have to delete some cache  that is do page replacement from the main memory , i.e delete the least recently used cache from the past from the DLL therefore we will delte the node that is nearest to the tail , the node->next will be tail.
*/
class LRUCache {
public:
    class node{
        
        public:
            int key;
            int val;
            node* prev;
            node* next;
            node(int key_, int val_){
                key=key_;
                val=val_;
            }
    };
    
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);
    
    map<int,node*> mp;
    
    int size;
    
    
    LRUCache(int capacity) {
        size=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void addNode(node* newNode){
        node * temp=head->next;
        head->next=newNode;
        newNode->next=temp;
        newNode->prev=head;
        temp->prev=newNode;
        
    } 
    
    void deleteNode(node* delNode){
        node * prevNode=delNode->prev;
        node * nextNode=delNode->next;
        
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
        
    }
    
    int get(int key) {
        
        if(mp.find(key)!=mp.end()){
            
            node* curr=mp[key];
            int res=curr->val;
            deleteNode(curr);
            mp.erase(key);
            
            addNode(curr);
            mp[key]=head->next;
            return res;
            
        }
        
        else
            return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            node *curr=mp[key];
            mp.erase(key);
            deleteNode(curr);
        }
        
        if(mp.size()==size){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);   
        }
            
        
        node * newNode= new node(key,value);
        addNode(newNode);
        mp[key]=head->next;
        
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */