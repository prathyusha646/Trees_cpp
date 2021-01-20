#include<iostream>
#include<queue>
#include "TreeNode.h"
using namespace std;

void printTree(TreeNode<int> *root) {
	if (root == NULL) {
		return;
	}

	cout << root->data << ":";
	for (int i = 0; i < root->children.size(); i++) {
		cout << root->children[i]->data << ",";
	}
	cout << endl;
	for (int i = 0; i < root->children.size() ; i++) {
		printTree(root->children[i]);
	}
}
/*TreeNode<int>* takeInput() {
	int rootData;
	cout<<"Enter root: "<<endl;
	cin>>rootData;
	TreeNode<int> *root=new TreeNode<int>(rootData);
	int n;
	cout<<"Enter num of children"<<rootData<<endl;
	cin>>n;
	for(int i=0;i<n;i++) {
		TreeNode<int> *child=takeInput();
		root->children.push_back(child);
	}
	return root;
}*/
TreeNode<int>* takeInputLevelWise() {
	int rootData;
	cout<<"Enter root Data: "<<endl;
	cin>>rootData;
	TreeNode<int> *root = new TreeNode<int>(rootData);
	
	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	
	while(pendingNodes.size()!=0) {
		TreeNode<int> *front=pendingNodes.front();
		pendingNodes.pop();
		cout<<"Enter num of children of "<<front->data<<endl;
		int n;
		cin>>n;
		for(int i=0;i<n;i++) {
			int childData;
			cout<<"Enter "<<i<<" th child of"<<front->data<<endl;
			cin>>childData;
			TreeNode<int> *child=new TreeNode<int>(childData);
			front->children.push_back(child);
			pendingNodes.push(child);
		}
	}	
	return root;
}
int main() {
/*	TreeNode<int> *root=new TreeNode<int>(1);
	TreeNode<int> *node1=new TreeNode<int>(2);
	TreeNode<int> *node2=new TreeNode<int>(3);
	root->children.push_back(node1);
	root->children.push_back(node2);*/
	TreeNode<int> *root=takeInputLevelWise();
	printTree(root);
}
