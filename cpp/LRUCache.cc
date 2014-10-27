// https://oj.leetcode.com/problems/lru-cache/

// checklist to implement correct LRUCache
// 1) unordered_map + bi-linked list
// 2) In the node, you must keep key besides value, therefore when getting a node, you can delete it from map
// 3) Deal with value update (set to an existing key with a new value)
// 4) Deal with eviction when max capacity is reached
// 5) When removing a node, remember to delete it thus the memory is released
// 6) When using the itertor of a map, "it->second" is the value
// 7) Remember to update the position of node in the bi-linked list when implementing "set"
namespace LRUCache {
    class CacheNode {
    public:
        CacheNode(int k, int value): key(k), val(value){}
        int key;
        int val;
        CacheNode * prev;
        CacheNode * next;
    };
    
    class BiLinkedList {
    private:
        CacheNode dummy;
        CacheNode * head = &dummy;
        
    public:
        BiLinkedList():dummy(-1, -1){
            head->next = head;
            head->prev = head;
        }
        
        int size = 0;
        
        void push_front(CacheNode* node) {
            node->next = head->next;
            head->next->prev = node;
            head->next = node;
            node->prev = head;
            size++;
        }
        
        void remove(CacheNode* node) {
            if (node == NULL || node == &dummy) {
                return;
            }
            
            node->prev->next = node->next;
            node->next->prev = node->prev;
            size--;
        }
        
        CacheNode* removeTail() {
            if (head->next == head) {
                return NULL;
            }
            
            CacheNode * tail = head->prev;
            remove(tail);
            
            return tail;
        }
    };
    
    
    class LRUCache{
    public:
        const int cap;
        BiLinkedList list;
        unordered_map<int, CacheNode*> hash;
        
        LRUCache(int capacity): cap(capacity) {
            
        }
        
        int get(int key) {
            unordered_map<int, CacheNode*>::iterator it = hash.find(key);
            if (it == hash.end()) {
                return -1;
            } else {
                CacheNode * node = it->second;
                int res = node->val;
                list.remove(node);
                list.push_front(node);
                return res;
            }
        }
        
        void set(int key, int value) {
            unordered_map<int, CacheNode*>::iterator it = hash.find(key);
            if (it != hash.end()) {
                CacheNode * node = it->second;
                node->val = value;
                list.remove(node);
                list.push_front(node);
            } else {
                CacheNode * node = new CacheNode(key, value);
                list.push_front(node);
                hash[key] = node;
            }
            
            if (list.size > cap) {
                CacheNode * tail = list.removeTail();
                hash.erase(tail->key);
                delete tail;
            }
            
        }
    };
}
