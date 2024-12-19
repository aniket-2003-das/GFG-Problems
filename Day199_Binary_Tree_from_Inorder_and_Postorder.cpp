//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL)
        return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution {
  public:

    // Function to return a tree created from postorder and inoreder traversals.
    
    Node* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size()) return NULL;
        map<int, int> hm;
        for(int i=0; i<inorder.size(); i++) hm[inorder[i]] = i;
        return buildTreePostIn(inorder, 0, inorder.size()-1, 
                                postorder, 0, postorder.size()-1, hm);
    }

    Node* buildTreePostIn(vector<int> &inorder, int is, int ie,
                            vector<int> &postorder, int ps, int pe, map<int, int> &hm){
        if(ps>pe || is>ie) return NULL;
        Node* root = new Node(postorder[pe]);
        int inRoot = hm[postorder[pe]];
        int numsLeft = inRoot-is;

        root->left = buildTreePostIn(inorder, is, inRoot-1,
                                    postorder, ps, ps+numsLeft-1, hm);
        
        root->right = buildTreePostIn(inorder, inRoot+1, ie, 
                                    postorder, ps+numsLeft, pe-1, hm);
        return root;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        vector<int> inorder;
        int number;
        while (ss >> number) {
            inorder.push_back(number);
        }

        getline(cin, input);
        stringstream ss2(input);
        vector<int> postorder;
        while (ss2 >> number) {
            postorder.push_back(number);
        }
        Solution obj;
        Node* root = obj.buildTree(inorder, postorder);
        preOrder(root);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends