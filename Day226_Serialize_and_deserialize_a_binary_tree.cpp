//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Solution {
public:
    // Serialization function
    vector<int> serialize(Node *root) {
        vector<int> ans;
        if (!root) return ans;
        queue<Node*> q;
        q.push(root);
    
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
    
            if (curr == NULL) {
                ans.push_back(-1);  // Represent NULL as -1
            } 
            else {
                ans.push_back(curr->data);
                q.push(curr->left); // Push even NULL children to preserve structure
                q.push(curr->right);
            }
        }
        return ans;
    }
    
    // Deserialization function
    Node* deSerialize(vector<int> &arr) {
        if (arr.empty()) return NULL;
    
        Node* root = new Node(arr[0]);
        queue<Node*> q;
        q.push(root);
        int i = 1;
    
        while (!q.empty() && i < arr.size()) {
            Node* curr = q.front();
            q.pop();
    
            // Process left child
            if (arr[i]!=-1) {
                curr->left = new Node(arr[i]); // Create left child if value is not -1
                q.push(curr->left);
            }
            i++;
    
            // Process right child
            if (i<arr.size() && arr[i]!=-1) { // Ensure within bounds before accessing
                curr->right = new Node(arr[i]); // Create right child if value is not -1
                q.push(curr->right);
            }
            i++;
        }
        return root;
    }
};

//{ Driver Code Starts.

void inorder(Node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void _deleteTree(Node *node) {
    if (node == NULL)
        return;

    /* first delete both subtrees */
    _deleteTree(node->left);
    _deleteTree(node->right);

    /* then delete the node */
    // cout << "Deleting node: " << node->data << endl;
    delete node;
}

/* Deletes a tree and sets the root as NULL */
void deleteTree(Node **node_ref) {
    _deleteTree(*node_ref);
    *node_ref = NULL;
}

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);

        Solution serial, deserial;
        vector<int> A = serial.serialize(root);
        Node *temp = root;
        deleteTree(&root);
        Node *getRoot = deserial.deSerialize(A);
        inorder(getRoot);

        cout << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends