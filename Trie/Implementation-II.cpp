https://www.naukri.com/code360/problems/implement-trie_1387095
QUESTION->
#include <bits/stdc++.h> 
class Trie{

    public:

    Trie(){
        // Write your code here.
    }

    void insert(string &word){
        // Write your code here.
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
    }

    void erase(string &word){
        // Write your code here.
    }
};
---------------------------------------------------------------------------------------------------------------------------------------------------------------------
  #include <bits/stdc++.h> 
struct Node{
    // links to child nodes
    Node* links[26];
     // Counter for number of words that end at this node
    int cntEndWith = 0;
    // Counter for number of words that have this node as a prefix
    int cntPrefix = 0; 

     bool containsKey(char ch) {
        // Check if the link corresponding
        // to the character exists
        return (links[ch - 'a'] != NULL); 
    }

    Node* get(char ch) {
        // Return the link corresponding to the character
        return links[ch - 'a']; 
    }

    void put(char ch, Node* node) {
         // Set the link corresponding to the character to the provided node
        links[ch - 'a'] = node;
    }

    
    void increaseEnd() {
        cntEndWith++; 
    }

    
    void increasePrefix() {
        cntPrefix++;
    }

    void deleteEnd() {
        cntEndWith--; 
    }

    void reducePrefix() {
        cntPrefix--; 
    }
};
class Trie{

 private:
 Node* root; 
    
    public:

    Trie(){
        root = new Node(); 
    }

    void insert(string &word){
        Node* node = root; 
        for (int i = 0; i < word.size(); i++) { 
            if (!node->containsKey(word[i]))
                node->put(word[i], new Node()); 
             // Move to the child node corresponding to the character
            node = node->get(word[i]);
            // Increment the prefix count for the node
            node->increasePrefix(); 
        }
        // Increment the end count for the last node of the word
        node->increaseEnd(); 
    }



    int countWordsEqualTo(string &word){
         Node* node = root;
        for (int i = 0; i < word.size(); i++) { 
            if (node->containsKey(word[i])) { 
                // Move to the child node corresponding to the character
                node = node->get(word[i]); 
            } else {
                 // Return 0 if the character is not found
                return 0;
            }
        }
        return node->cntEndWith;
    }




    int countWordsStartingWith(string &word){
        Node* node = root;
        for (int i = 0; i < word.size(); i++) { 
            if (node->containsKey(word[i])) { 
                node = node->get(word[i]); 
            } else {
                // Return 0 if the character is not found
                return 0; 
            }
        }
        // Return the count of words with the prefix
        return node->cntPrefix; 
    }



    void erase(string &word){
        Node* node = root;
        for (int i = 0; i < word.size(); i++) { 
            if (node->containsKey(word[i])) {
                node = node->get(word[i]);
                // Decrement the prefix count for the node
                node->reducePrefix(); 
            } else {
                // Return if the character is not found
                return; 
            }
        }
        // Decrement the end count for the last node of the word
        node->deleteEnd();
    }
};

