https://leetcode.com/problems/lfu-cache/description/
LEETCODE-460
  HARD

struct Node {
    int key, val;
    int cnt;
    Node *prev, *next;
    Node(int _key, int _val) {
        key = _key;
        val = _val;
        cnt = 1;
    }
};

struct List {
    int size;
    Node *head, *tail;

    List() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
 // function to add node
    void addFront(Node *node) {
        Node *temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++;
    }
//function to delete node
    void removeNode(Node *node) {
        Node *delPrev = node->prev;
        Node *delNext = node->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
        size--;
    }
};

class LFUCache {
public:
//initialization
    unordered_map<int, Node*> keyNode;
    unordered_map<int, List*> freqListMap;
    int maxSizeCache;
    int minFreq;
    int curSize;

    LFUCache(int capacity) {
        maxSizeCache = capacity;
        minFreq = 0;
        curSize = 0;
    }
 

  //updating the freq function
    void updateFreqListMap(Node *node) {
        keyNode.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);

        if (node->cnt == minFreq && freqListMap[node->cnt]->size == 0) {
            minFreq++;
        }

        node->cnt += 1;
        List *newList;
        if (freqListMap.count(node->cnt)) {
            newList = freqListMap[node->cnt];
        } else {
            newList = new List();
            freqListMap[node->cnt] = newList;
        }

        newList->addFront(node);
        keyNode[node->key] = node;
    }

    int get(int key) {
        if (keyNode.count(key) == 0) return -1;

        Node *node = keyNode[key];
        int val = node->val;
        updateFreqListMap(node);
        return val;
    }

    void put(int key, int value) {
        if (maxSizeCache == 0) return;

        if (keyNode.count(key)) {
            Node *node = keyNode[key];
            node->val = value;
            updateFreqListMap(node);
        } else {
            if (curSize == maxSizeCache) {
                List *list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                list->removeNode(list->tail->prev);
                curSize--;
            }

            curSize++;
            minFreq = 1;
            List *listFreq;
            if (freqListMap.count(minFreq)) {
                listFreq = freqListMap[minFreq];
            } else {
                listFreq = new List();
                freqListMap[minFreq] = listFreq;
            }

            Node *node = new Node(key, value);
            listFreq->addFront(node);
            keyNode[key] = node;
        }
    }
};
