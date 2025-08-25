class LRUCache {
public:
class Node
{
    public:
    int key;
    int val;
    Node* prev;
    Node* next;
        Node(int k, int v)
        {
            key = k;
            val = v;
            prev = next = NULL;
        }
};
Node* head = new Node(-1,-1);
Node* tail = new Node(-1,-1);

unordered_map<int,Node*>mpp;
int limit;


void addNode(Node* newNode)
{
    Node* oldnext = head->next;
    head->next = newNode;
    oldnext->prev = newNode;
    newNode->next = oldnext;
    newNode->prev = head;
}
void delNode(Node* oldNode)
{
    Node* oldprev = oldNode->prev;
    Node* oldnext = oldNode->next;

    oldprev->next = oldnext;
    oldnext->prev = oldprev;

}

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mpp.find(key) == mpp.end())
        {
            return -1;
        }
        Node* ansNode = mpp[key];
        int ans = ansNode->val;
        mpp.erase(key);
        delNode(ansNode);
        addNode(ansNode);
        mpp[key] = ansNode;

        return ans;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end())
        {
            Node* oldnode = mpp[key];
            delNode(oldnode);
            mpp.erase(key);
        }
        if(mpp.size() == limit)
        {
            mpp.erase(tail->prev->key);
            delNode(tail->prev);
        }
        Node* newnode = new Node(key,value);
        addNode(newnode);
        mpp[key] = newnode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */