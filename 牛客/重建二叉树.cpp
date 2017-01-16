//根据给定的先序序列和中序序列，求出后序序列.
//树中的结点由A~Z表示，不会重复.
#include<iostream>
using namespace std;
#include<string>

struct BinaryTreeNode
{
	char _data;
	BinaryTreeNode* _left;
	BinaryTreeNode* _right;
	BinaryTreeNode(const char x)
		:_data(x)
		,_left(NULL)
		,_right(NULL)
	{}
};
class Rebuild
{
	typedef BinaryTreeNode Node;
public:
	Rebuild(char pre[],char in[],int len)
	{
		_root = NULL;
		_Rebuild(pre,in,len,_root);
	}
	void PostOrder()
	{
		_PostOrder(_root);
		cout<<endl;
	}
protected:
	void _Rebuild(char pre[],char in[],int len,Node*& root)
	{
		if(len <= 0)
			return;
		int index = 0;
		for(index = 0; index < len; ++index)
		{
			if(pre[0] == in[index])
				break; 
		}
		if(root == NULL)
			root = new Node(in[index]);
		//
		_Rebuild(pre + 1, in, index,root->_left);
		_Rebuild(pre + index+1, in+index+1, len-index-1, root->_right);
	}
	void _PostOrder(Node* root)
    {
       if(NULL == root)
           return;
      
       _PostOrder(root->_left);
       _PostOrder(root->_right);
	    cout<<root->_data;
    }

private:
	Node* _root;
};
void rebuidTree()
{
	string pre,in;
	
	while(cin>>pre>>in)
	{
		Rebuild r((char*)pre.c_str(),(char*)in.c_str(),in.size());
		r.PostOrder();
	}
}
int main()
{
	rebuidTree();
	return 0;
}