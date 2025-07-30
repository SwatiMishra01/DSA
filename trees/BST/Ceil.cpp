https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1

/* struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};  */

int findCeil(Node* root, int input) {
    int ceil=-1;
    while(root){
        if(root->data==input){
            ceil=root->data;
            return ceil;
        }
        
        if(input>root->data) root=root->right;
        else {
            ceil=root->data;
            root=root->left;
        }
    }
    return ceil;
    
}
T.C=O(LOG N)
S.C=O(1)
