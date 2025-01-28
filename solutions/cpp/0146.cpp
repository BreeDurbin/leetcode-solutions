class LRUCache {

        public:

        class Node {
            public:
            Node *left, *right;
            int key;
            int val;
            Node(int k, int v): key(k) , val(v){};
        };

        unordered_map<int, Node*> m;
        Node* left = new Node(-1, -1); //most recently used
        Node* right = new Node(-1, -1); // least recently used
        int capacity = 0; // max amount of nodes allowed, current capacity used is m.size()

        LRUCache(int c) {
            capacity = c;
            left->right = right;
            right->left = left;
        }
        
        int get(int key) {
            if(m.find(key) == m.end()) return -1;
            //update key to be mru
            Node* node = m[key];
            remove(node);
            insert(node);
            return node->val;
        }
        
        void put(int key, int val) {
            if(m.find(key) != m.end()){
                remove(m[key]); //if exists remove, we will reinsert which will make it mru
            }
            if(capacity == m.size()){
                //evict lru cause full
                remove(right->left);
            }
            //insert as mru
            insert(new Node(key, val));
        }

        void insert(Node* node){
            // put into mru position
            node->right = left->right;
            left->right->left = node;
            left->right = node;
            node->left = left;
            //add to cache
            m[node->key] = node;
        }

        void remove(Node *node){
            m.erase(node->key); // remove target from m cache
            node->left->right = node->right;//stitch left of lru to right of lru 
            node->right->left = node->left;// stitch right of lru to left of lru
        }

};
