//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


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
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
public:
    int minTime(Node* root, int start) {
        map<Node*, Node*> parentMap;
        Node* target = bfsToMapParents(root, parentMap, start);
        int maxi = findMaxDistance(parentMap, target);
        return maxi;
    }

    Node* bfsToMapParents(Node* root, map<Node*, Node*> &parentMap, int start) {
        queue<Node*> q;
        q.push(root);
        Node* res = nullptr;

        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            if (node->data == start) res = node;
            if (node->left) {
                parentMap[node->left] = node; 
                q.push(node->left);
            }
            if (node->right) {
                parentMap[node->right] = node; 
                q.push(node->right);
            }
        }
        return res;
    }

    int findMaxDistance(map<Node*, Node*> &parentMap, Node* target) {
        queue<Node*> q;
        q.push(target);
        map<Node*, int> visited;
        visited[target] = 1;
        int maxi = 0;

        while (!q.empty()) {
            int n = q.size();
            int change = 0;
            for (int i = 0; i < n; i++) {
                auto node = q.front();
                q.pop();
                if (node->left && !visited[node->left]) {
                    q.push(node->left);
                    visited[node->left] = 1;
                    change = 1;
                }
                if (node->right && !visited[node->right]) {
                    q.push(node->right);
                    visited[node->right] = 1;
                    change = 1;
                }
                if (parentMap[node] && !visited[parentMap[node]]) {
                    q.push(parentMap[node]);
                    visited[parentMap[node]] = 1;
                    change = 1;
                }
            }
            if (change) maxi++;
        }
        return maxi;
    }
};


//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    
cout << "~" << "\n";
}


    return 0;
}

// } Driver Code Ends