#include <iostream>
#include <vector>

#define MAX 100001;

using namespace std;

struct Node {
    char c;
    Node *left = NULL;
    Node *right = NULL;
};
vector<Node> node(26);

void preorder(Node *root)
{
    cout << root->c;

    if (root->left)
        preorder(root->left);
    if (root->right)
        preorder(root->right);
}

void inorder(Node *root)
{
    if (root->left)
        inorder(root->left);

    cout << root->c;

    if (root->right)
        inorder(root->right);
}

void postorder(Node *root)
{
    if (root->left)
        postorder(root->left);

    if (root->right)
        postorder(root->right);

    cout << root->c;
}

int main()ls

{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N;
    cin >> N;

    char parent, left, right;
    Node *root;
    

    for (int i = 0; i < N; i++)
    {
        cin >> parent >> left >> right;       

        node[parent - 'A'].c = parent;
        if (left != '.')
        {
            node[parent - 'A'].left = &node[left - 'A'];
        }
        if (right != '.')
        {
            node[parent - 'A'].right = &node[right - 'A'];
        }
    }

    root = &node[0];

    preorder(root);
    cout << "\n";
    inorder(root);
    cout << "\n";
    postorder(root);
}