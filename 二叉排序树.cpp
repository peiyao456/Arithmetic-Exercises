//输入一系列整数，建立二叉排序数，并进行前序，中序，后序遍历。 
//递归实现的代码

#include<iostream>
using namespace std;

struct BinaryNode
{
	int _data;
	BinaryNode* _left;
	BinaryNode* _right;
	BinaryNode* _parent;
	BinaryNode(int x = 0)
		:_data(x)
		,_left(NULL)
		,_right(NULL)
		,_parent(NULL)
	{}
};
void PreOrder(BinaryNode* root)
{
	if(root == NULL)
		return;
	cout<<root->_data<<" ";
	PreOrder(root->_left);
	PreOrder(root->_right);
}
void InOrder(BinaryNode* root)
{
	if(root == NULL)
		return;
	
	InOrder(root->_left);
	cout<<root->_data<<" ";
	InOrder(root->_right);
}
void PostOrder(BinaryNode* root)
{
	if(root == NULL)
		return;
	
	PostOrder(root->_left);
	PostOrder(root->_right);
	cout<<root->_data<<" ";
}
void BinarySearchTree(int num,BinaryNode* root)
{
	if(num == root->_data)
		return;
	if(num < root->_data)
	{
		if(root->_left == NULL)
			root->_left = new BinaryNode(num);
		else
			BinarySearchTree(num,root->_left);
	}
	else
	{
		if(root->_right == NULL)
			root->_right = new BinaryNode(num);
		else
			BinarySearchTree(num,root->_right);
	}
}
int main()
{
	int n = 0;
	while(cin>>n)
	{
		int* pNum = new int[n];
		cin>>pNum[0];
		BinaryNode root(pNum[0]);
		for(int i = 1; i < n; ++i)
		{
			cin>>pNum[i];
			BinarySearchTree(pNum[i],&root);
		}
		PreOrder(&root);
		cout<<endl;
		InOrder(&root);
		cout<<endl;
		PostOrder(&root);
		cout<<endl;
	}
	
	return 0;
}