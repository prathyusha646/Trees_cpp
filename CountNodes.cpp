#include<iostream>
#include<queue>
#include "TreeNode.h"
using namespace std;
int countNodes(TreeNode<int>* root) {
	int ans=1;
	for(int i=0;i<root->children.size();i++) {
		ans+=countNodes(root->children[i]);
	}
	return ans;
}
void printLevelWise(TreeNode<int> *root) {
	if (root == NULL) {
		return;
	}
	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while(pendingNodes.size()!=0) {
		TreeNode<int> *front=pendingNodes.front();
		cout<<front->data<<":";
		pendingNodes.pop();
		for(int i=0;i<root->children.size();i++) {
			pendingNodes.push(root->children[i]);
			if(root->children.size()-1!=i) {
				cout<<root->children[i]->data<<",";
			} else {
				cout<<root->children[i]->data;
			}
		}
		root=pendingNodes.front();
		cout<<endl;
	}
}
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
	TreeNode<int> *root=takeInputLevelWise();
	printLevelWise(root);
	int res=countNodes(root);
	cout<<"Number of Nodes: "<<res<<endl;
}
