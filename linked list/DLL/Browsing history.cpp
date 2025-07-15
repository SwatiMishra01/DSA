https://leetcode.com/problems/design-browser-history/description/
LEETCODE-1472


class Node {
public:
    // Stores the URL of the page
    string data;
    // Pointer to the next page in history
    Node* next;
    // Pointer to the previous page in history
    Node* back;

    // Default constructor
    Node() : data(""), next(nullptr), back(nullptr) {}; 
    // Constructor with data
    Node(string x) : data(x), next(nullptr), back(nullptr) {};
    // Constructor with data and pointers
    Node(string x, Node* next, Node* random) :
                data(x), next(next), back(random) {}; 
};


class BrowserHistory {
    Node*curr;
public:
    BrowserHistory(string homepage) {
        curr=new Node(homepage);
    }
    
    void visit(string url) {
        Node* newNode= new Node(url);
        newNode->back=curr;   // new page to the current page
        curr->next=newNode;   // current page to the new page
        curr=newNode;         // Update the current page to the new page
    }
    
    string back(int steps) {
        // While there are steps and a previous page exists
        while(steps && curr->back){
            steps--;
            curr=curr->back;  // Move to the previous page
        }
        return curr->data;
    }
    
    string forward(int steps) {
        while(steps && curr->next){
            steps--;
            curr=curr->next;   // While there are steps and a next page exists
        }
        return curr->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

T.C=O(steps)
S.C=O(N) //N=no. of webpages visit
