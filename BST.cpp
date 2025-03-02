#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *left,*right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
Node* insertbst(Node *root,int val){
    if(root==NULL){
        return new Node(val);
    }
    if(val<root->data){
        root->left=insertbst(root->left,val);
    }
    else{
        root->right=insertbst(root->right,val);
    }
    return root;
}
void inorder(Node *root){
    if(root==NULL)return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    Node *root=NULL;
    root=insertbst(root,5);
    insertbst(root,1);
    insertbst(root,6);
    insertbst(root,12);
    insertbst(root,41);
    insertbst(root,11);
    inorder(root);
    cout<<endl;
    return 0;
}
