https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
LEETCODE-297

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        if(root==NULL) return s;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode*curr=q.front();
            q.pop();
            if(curr==NULL) s.append("#,");
            else s.append(to_string(curr->val)+",");

            if(curr!=NULL){
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return s;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode*root=new TreeNode(stoi(str));

        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode*node=q.front();
            q.pop();

            //left node
            getline(s,str,',');
            if(str=="#") node->left=NULL;
            else {TreeNode*leftNode=new TreeNode(stoi(str));
            node->left=leftNode;
            q.push(leftNode);
            }

            //right node
            getline(s,str,',');
            if(str=="#") node->right=NULL;
            else {TreeNode*rightNode=new TreeNode(stoi(str));
            node->right=rightNode;
            q.push(rightNode);
            }
        }
        return root;

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
