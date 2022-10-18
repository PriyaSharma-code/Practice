//https://practice.geeksforgeeks.org/problems/lru-cache/1?page=2&company[]=Samsung&sortBy=submissions

class LRUCache
{
    private:

    public:
    class node{
        public:
        int key, value;
        node *prev=NULL, *next=NULL;
        
        node(int _key, int _val){
            key = _key;
            value = _val;
        }
    };
    
    node *head = new node(-1,-1);
    node *tail = new node(-1,-1);
    int cap;
    map<int, node*> m; //unordered
    
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int capa)
    {
        // code here
        cap = capa;
        head->next = tail;
        tail->prev = head;
    }
    
    void addnode(node* temp){
        node* dummy = head->next;
        head->next = temp;
        temp->prev = head;
        temp->next = dummy;
        dummy->prev = temp;
    }
    void delnode(node* temp){
        node* delnext = temp->next;
        node* delprev = temp->prev;
        delnext->prev = delprev;
        delprev->next = delnext;
    }
    //Function to return value corresponding to the key.
    int get(int key)
    {
        // your code here
        if(m.find(key)!=m.end()){
            node* res = m[key];
            m.erase(key);
            int ans = res->value;
            delnode(res);
            addnode(res);
            m[key] = head->next;
            return ans;
        }
        return -1;
        
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        // your code here   
        if(m.find(key)!=m.end()){
            node* exist = m[key];
            m.erase(key);
            delnode(exist);
        }
        if(m.size()==cap){
            m.erase(tail->prev->key);
            delnode(tail->prev);
        }
        addnode(new node(key, value));
        m[key] = head->next;
    }
};