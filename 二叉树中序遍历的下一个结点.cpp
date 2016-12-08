#include<iostream>
using namespace std;
#include<stack>

struct BinaryNode
{
	int _data;
	BinaryNode* _left;
	BinaryNode* _right;
	BinaryNode* _parent;
	BinaryNode(const int& x = 0)
		:_data(x)
		,_left(NULL)
		,_right(NULL)
		,_parent(NULL)
	{}
};
class GetNextNode
{
	typedef BinaryNode Node;
public:
	GetNextNode()
		:_root(NULL)
	{}
	GetNextNode(int a[],int n,const int& invalid)
	{
		int index = 0;
		Node* prev = NULL;
		_root = _Create(a,n,index,invalid,prev);
	}
	Node* GetNext(Node* node)
	{
		assert(node);
		Node* nextNode = NULL;
		//有右孩子
		if(node->_right != NULL)
		{
			//找右孩子的最左结点
			Node* cur = node->_right;
			while(cur && cur->_left)
			{
				cur = cur->_left;
			}
			nextNode = cur;
		}
		//向上遍历，直到找到结点是在哪个结点的左子树上
		else if(node->_parent != NULL)
		{
			Node* cur = node;
			Node* parent = node->_parent;
			while(parent != NULL && cur == parent->_right)
			{
				cur = parent;
				parent = parent->_parent;
			}
			if(parent == NULL && cur == parent->_right)
				nextNode = NULL;
			else
				nextNode = parent;
		}
		return nextNode;
	}
	Node* Find(const int& x)
	{
		if(_root == NULL)
			return NULL;
		Node* cur = _root;
		stack<Node*> s;
		while(cur || !s.empty())
		{
			while(cur)
			{
				s.push(cur);
				cur = cur->_left;
			}
			Node* top = s.top();
			if(top->_data == x)
				return top;
			s.pop();
			cur = top->_right;
		}
		return NULL;
	}
protected:
	Node* _Create(int a[],int n,int& index,const int& invalid,Node* prev)
	{
		Node* root = NULL;
		if(index < n && a[index] != invalid)
		{
			root = new Node(a[index]);
			root->_parent = prev;
			root->_left = _Create(a,n,++index,invalid,root);
			root->_right = _Create(a,n,++index,invalid,root);
		}
		return root;
	}
private:
	Node* _root;
};

void Test()
{
	int a[] = {6,8,'#','#',10,7,12};
	GetNextNode gn(a,7,'#');
	BinaryNode* ret = gn.GetNext(gn.Find(12));
	cout<<ret->_data<<endl;
}


int main()
{
	Test();
	cout<<"OK"<<endl;
	system("pause");
	return 0;
}

