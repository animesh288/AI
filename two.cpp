#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Node
{
public:
    int data;
    Node *left = NULL;
    Node *right = NULL;
    Node(int num)
    {
        data = num;
    }
};

Node *createTree()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(8);
    root->right->right->left = new Node(9);
    return root;
}

void dfs(Node *root, int target)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data == target)
    {
        cout << "Number " << target << " found!" << endl;
    }
    if (root->left != NULL)
    {
        dfs(root->left, target);
    }
    if (root->right != NULL)
    {
        dfs(root->right, target);
    }
}

int main()
{
    Node *root = createTree();
    int x;

    cout << "Enter the Number to find" << endl;
    cin >> x;
    dfs(root, x);
}
