#include <iostream>
using namespace std;

struct node {
    int key;
    struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *Node) 
{
    if (Node != NULL) 
    {
        traverseInOrder(Node->left);
        cout << Node->key << " ";
        traverseInOrder(Node->right);
    }
}

// Insert a node
struct node *insertNode(struct node *Node, int key) 
{
    if (Node == NULL) //check if the current Node is null
    {
        /*create a new node with the given key*/
        struct node *newNode = new node;
        newNode->key = key;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    if (key < Node->key) // check if the given key is less than the current key
        Node->left = insertNode(Node->left, key);// insert the key into the left subtree
    else if (key > Node->key) // check if the given key is greater than the current key
        Node->right = insertNode(Node->right, key);// insert the key into the right subtree
    return Node;
}

// Deleting a node
struct node *deleteNode(struct node *Node, int key) 
{
    if (Node == NULL) 
        return Node;
    if (key < Node->key) // check if the given key is less than current key
        Node->left = deleteNode(Node->left, key); //delete the node from left subtree
    else if (key > Node->key)// check if the given key is greater than current key
    Node->right = deleteNode(Node->right, key);//delete the node from right subtree
    else // current key is equal to given key
    {
        if (Node->left == NULL) // if the current node has no left child
        {
            struct node *temp = Node->right; //replace it with right child
            delete Node;
            return temp;
        } 
        else if (Node->right == NULL) //if the current node has no right child
        {
        struct node *temp = Node->left; // replace it with left child
        delete Node;
        return temp;
        }
        struct node *temp = Node->right;
        while (temp->left != NULL) // if node has both left and right child
            temp = temp->left;
        Node->key = temp->key;
        Node->right = deleteNode(Node->right, temp->key);
    }
    return Node;
}

// Driver code
int main() 
{
    struct node *root = NULL;
    
    int operation;
    int operand;
    cin >> operation;
    
    while (operation != -1) 
    {
        switch(operation) 
        {
            case 1: // insert
            cin >> operand;
            root = insertNode(root, operand);
            cin >> operation;
            break;
            case 2: // delete
            cin >> operand;
            root = deleteNode(root, operand);
            cin >> operation;
            break;
            default:
            cout << "Invalid Operator!\n";
            return 0;
        }
    }

    traverseInOrder(root);
}
