#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *left;
    struct node *right;

};
struct node *newNode(int val)
{
    struct node *node= (struct node*) malloc(sizeof(struct node));
    node->data=val;
    node->left=node->right=NULL;
    return (node);
}

void preorder(node *root,vector<int> &preord)
{
    if(root==NULL)
        return;
    preord.push_back(root->data);
    preorder(root->left,preord);
    preorder(root->right,preord);
}
void inorder( node *root,vector<int> &inord)
{
    if(root==NULL)
        return;
    inorder(root->left,inord);
    inord.push_back(root->data);
    inorder(root->right,inord);
}
void postorder(node *root,vector<int> &postord)
{
    if(root==NULL)
        return;
    postorder(root->left,postord);
    postorder(root->right,postord);
    postord.push_back(root->data);
}

int main()
{
    struct node *root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    root->right->right=newNode(7);
    root -> left -> right -> left = newNode(8);
    root -> right -> right -> left = newNode(9);
    root -> right -> right -> right = newNode(10);
    vector<int> preord,inord,postord;
    preorder(root,preord);
    inorder(root,inord);
    postorder(root,postord);
    cout<<"PREORDER:\n";
    for(auto it: preord)
        cout<<it<<" ";
    cout<<"\nINORDER:\n";
    for(auto it: inord)
        cout<<it<<" ";
    cout<<"\nPOSTORDER:\n";
    for(auto it: postord)
        cout<<it<<" ";
    

}