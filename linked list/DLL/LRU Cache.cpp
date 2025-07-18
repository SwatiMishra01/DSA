https://leetcode.com/problems/lru-cache/description/
LEETCODE-146

class LRUCache {
public:
class Node{
    public:
    int key;
    int val;
    Node*next;
    Node*prev;
    Node(int _key, int _val){
        key=_key;
        val=_val;
    }
};
//declaring head, tail
Node*head= new Node(-1,-1);
Node*tail=new Node(-1,-1);

//initialization
int cap;
unordered_map<int,Node*>m;

    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
      //delete node function

      void deletenode(Node* delnode){
        Node*delprev=delnode->prev;
        Node*delnext=delnode->next;
        delprev->next=delnext;
        delnext->prev=delprev;

      }

      //add node function 
      void addnode(Node*newnode){
         Node*temp=head->next;
         newnode->next=temp;
         newnode->prev=head;
         temp->prev=newnode;
         head->next=newnode;
      }


    int get(int key) {
        if(m.find(key)!=m.end()){
            Node*resnode=m[key];
            int res=resnode->val;
            m.erase(key);
            deletenode(resnode);
            addnode(resnode);
            m[key]=head->next;
            return res;
        }
        return -1;
    
    }
    
    void put(int key, int value) {
        //if node already exists->delete it
        if(m.find(key)!=m.end()){
            Node*existingnode=m[key];
            m.erase(key);
            deletenode(existingnode);
        }
        //delete last node if capacity is full
        if(m.size()==cap){
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        //addnode
        addnode(new Node(key,value));
        m[key]=head->next;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
