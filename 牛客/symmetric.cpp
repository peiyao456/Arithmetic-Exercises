#include<iostream>
using namespace std;

template<typename T>
struct BinaryNode
{
	T _data;
	BinaryNode* _left;
	BinaryNode* _right;
	BinaryNode(const T& x = T())
		:_data(x)
		,_left(NULL)
		,_right(NULL)
	{}
};

template<typename T>
class BinaryTree
{
	typedef BinaryNode<T> Node;
public:
	BinaryTree(T arr[],int size,const T& invalid)
	{
		int index = 0;
		_root = _Create(arr,size,index,invalid);
	}
	bool Symmetric()
	{
		return _Symmetric(_root,_root);
	}
	bool _Symmetric(Node* leftRoot,Node* rightRoot)
	{
		if(leftRoot == NULL && leftRoot == NULL)//访问到的都是NULL
			return true;
		if(leftRoot == NULL || leftRoot == NULL)//一个是NULL，一个不是
			return false;

		if(leftRoot->_data != rightRoot->_data)
			return false;

		return _Symmetric(leftRoot->_left,rightRoot->_right)
			&& _Symmetric(leftRoot->_right,rightRoot->_left);
	}
protected:
	Node* _Create(T arr[],int size,int& index,const T& invalid)
	{
		Node* root = NULL;
		if(index < size && arr[index] != invalid)
		{
			root = new Node(arr[index]);
			root->_left = _Create(arr,size,++index,invalid);
			root->_right = _Create(arr,size,++index,invalid);
		}
		return root;
	}
protected:
	Node* _root;
};



void Test()
{
	int arr[] = {6,5,7,'#','#',3,'#','#',5,3,'#','#',7};
	//int arr[] = {6,6,6,'#','#',6,'#','#',6,6,'#','#',6};
	BinaryTree<int> bt(arr,sizeof(arr)/sizeof(arr[0]),'#');
	cout<<(bt.Symmetric())<<endl;
}
int main()
{
	Test();
	system("pause");
	return 0;
}