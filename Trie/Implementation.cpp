https://leetcode.com/problems/implement-trie-prefix-tree/description/
LEETCODE-208
  
struct Node{
    Node *links[26];
    bool flag=false;
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL); //key does exists
    }
    //put new node
    void put(char ch,Node*node){
        links[ch-'a']=node;
    }
   //if node already exists
    Node*get(char ch){
       return links[ch-'a'];
    }
    //node reached end
    void setEnd(){
        flag=true;
    }
    //has reached end or not
    bool isEnd(){
        return flag;
    }
};



class Trie {
    private:
    Node *root;
public:
    Trie() {
        root=new Node();
    }
    



    void insert(string word) {    //T.C->O(length)
        Node*node=root;
        for(int i=0; i<word.length(); i++){
         if(!node->containsKey(word[i])){ //doesnt contain word->put it
              node->put(word[i], new Node());
         }
         //moves to the refernce trie
         node=node->get(word[i]);
        }
        node->setEnd(); //reaches last
    }
    





    bool search(string word) {    //T.C->O(length)
        Node*node=root;
        for(int i=0; i<word.length(); i++){
            if(!node->containsKey(word[i])) return false;
            node=node->get(word[i]);
        }
        return node->isEnd(); 
    }
    



    bool startsWith(string prefix) {       //T.C->O(length)
        Node*node=root;
        for(int i=0; i<prefix.length(); i++){
            if(!node->containsKey(prefix[i])) return false;
            node=node->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
