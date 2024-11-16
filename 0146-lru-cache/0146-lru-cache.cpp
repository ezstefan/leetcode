class LRUCache {
public:
    class Node{
        public:

        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int key,int val) {
            this->key = key;
            this->val = val;
        }

    };

    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    int cap;
    unordered_map<int, Node*> mpp;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
        
    }

    void addNode(Node* newNode) {
        Node* temp = head->next;

        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(Node* delNode) {
        Node* prevNode = delNode->prev;
        Node* nextNode = delNode->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    
    int get(int key) {
        if(mpp.find(key) != mpp.end()) {
            Node* node = mpp[key];
            int ans = node->val;

            deleteNode(node);
            addNode(node);
            return ans;
        }
        return -1;
        
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()) {
            Node* node = mpp[key];
            node->val = value;
            deleteNode(node);
            addNode(node);
        }
        else{
            if(mpp.size() == cap) {
                Node* node = tail->prev;
                mpp.erase(node->key);
                deleteNode(node);
            }

            Node* node = new Node(key,value);
            mpp[key] = node;
            addNode(node);
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */