#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};
static int idx=-1;
Node* buildtree(vector<int>&v){
    idx++;
    if(v[idx]==-1)return NULL;
    Node* root=new Node(v[idx]);
    root->left=buildtree(v);
    root->right=buildtree(v);
    return root;
}
//Preorder
void Preorder(Node* root){
    if(root==NULL)return;
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}
//Inorder
void Inorder(Node* root){
    if(root==NULL)return;
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}
//Postorder
void Postorder(Node* root){
    if(root==NULL)return;
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}
//Level order 
void Levelorder(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(q.size()>0){
        Node* cur=q.front();
        q.pop();
        if(cur==NULL){
            if(!q.empty()){
                cout<<endl;
                q.push(NULL);
                continue;
            }
            else break;
        }
        cout<<cur->data<<" ";
        if(cur->left!=NULL)q.push(cur->left);
        if(cur->right!=NULL)q.push(cur->right);
    }
}
int main(){
    vector<int> v = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root=buildtree(v);
    //Create Binary Tree
    cout<<root->data<<endl;
    cout<<root->left->data<<endl;
    cout<<root->right->data<<endl;
    //For Traversal
    Preorder(root);
    cout<<endl;
    Inorder(root);
    cout<<endl;
    Postorder(root);
    cout<<endl;
    Levelorder(root);
    cout<<endl;
    return 0;
}
