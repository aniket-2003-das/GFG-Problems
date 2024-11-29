//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str) {
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
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

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

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution {
public:
    void marksParent(Node* root, unordered_map<Node*, Node*> &parent_track, int target, Node* &tgt){
        queue<Node*> queue;
        queue.push(root);
        while(!queue.empty()){
            Node* current = queue.front();
            queue.pop();
            if(current->data==target) tgt = current;
            if(current->left){
                parent_track[current->left] = current;
                queue.push(current->left);
            }
            if(current->right){
                parent_track[current->right] = current;
                queue.push(current->right);
            }
        }
    }
    
    vector<int> KDistanceNodes(Node* root, int target, int k) {
        unordered_map<Node*, Node*> parent_track;
        Node* tgt = NULL;
        marksParent(root, parent_track, target, tgt);

        unordered_map<Node*, bool> visited;
        queue<Node*> queue;
        queue.push(tgt);
        visited[tgt] = true;
        int curr_level = 0;

        while(!queue.empty()){
            int size = queue.size();
            if(curr_level==k) break;
            curr_level++; 
            for(int i=0; i<size; i++){
                Node* current = queue.front(); queue.pop();
                if(current->left && !visited[current->left]){
                    queue.push(current->left);
                    visited[current->left] = true;
                }
                if(current->right && !visited[current->right]){
                    queue.push(current->right);
                    visited[current->right] = true;
                }
                if(parent_track[current] && !visited[parent_track[current]]){
                    queue.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
        }
        vector<int> result;
        while(!queue.empty()){
            Node* current = queue.front(); queue.pop();
            result.push_back(current->data);
        }
        sort(result.begin(),result.end());
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    getchar();

    Solution x = Solution();

    while (t--) {
        string s;
        getline(cin, s);
        Node* head = buildTree(s);

        int target, k;
        cin >> target >> k;
        getchar();

        vector<int> res = x.KDistanceNodes(head, target, k);

        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends