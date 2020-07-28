// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}
void deletionBT(struct Node* root, int key);
void inn(Node *node)
{
    if(node==NULL)
        return;
    
    inn(node->left);
    cout<<node->data<<" ";
    inn(node->right);
}

int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        int k;
        scanf("%d ",&k);
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
		deletionBT(root,k);
		inn(root);
		cout<<endl;
    }
    return 0;
}

void deletionBT(struct Node* root, int key)
{
    //finding right most and bottommost node
    queue<Node *> q;
    q.push(root);
    Node *todelete=NULL,*rightMost=NULL,*parentOfLast=NULL;
    while(!q.empty())
    {
        Node *tmp=q.front();
        q.pop();
        if(tmp->data==key)
            todelete=tmp;
        if(tmp->left)
        {
            q.push(tmp->left);
            if(tmp->left->left==NULL && tmp->left->right==NULL)
            {
                parentOfLast=tmp;
                rightMost=tmp->left;
            }
        }
        if(tmp->right)
        {
            q.push(tmp->right);
            if(tmp->right->left==NULL && tmp->right->right==NULL)
            {
                parentOfLast=tmp;
                rightMost=tmp->right;
            }
        }
    }
    cout<<todelete->data<<" "<<rightMost->data<<endl;
    if(rightMost)
    {
        todelete->data=rightMost->data;
        if(parentOfLast->right==rightMost)
            parentOfLast->right=NULL;
        else
            parentOfLast->left=NULL;
    }
}
