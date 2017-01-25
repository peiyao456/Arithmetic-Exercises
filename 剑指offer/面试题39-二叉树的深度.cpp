//求二叉树的深度
#include<iostream>
using namespace std;
#include<cassert>
struct BinaryNode
{
    int _data;
    BinaryNode* _left;
    BinaryNode* _right;
    BinaryNode(int x = 0)
       :_data(x)
       ,_left(NULL)
       ,_right(NULL)
    {}
};
class BinaryTreeOfDepth
{
    typedef BinaryNode Node;
public:
    BinaryTreeOfDepth(int arr[],int len,const int& invalid)
    {
       size_t index = 0;
       _root = _Create(arr,len,index,invalid);
    }
    size_t GetDepth()
    {
       return _GetDepth(_root);
    }
protected:
    Node* _Create(int arr[], int len, size_t& index, const int& invalid)
    {
       assert(arr);
       Node* root = NULL;
       if(index < len && invalid != arr[index])
       {
           root = new Node(arr[index]);
           root->_left = _Create(arr,len,++index,invalid);
           root->_right = _Create(arr,len,++index,invalid);
       }
       return root;
    }
    size_t _GetDepth(Node* root)
    {
       if(root == NULL)
           return 0;
       int left = _GetDepth(root->_left);//求左子树的高度
       int right = _GetDepth(root->_right);//求右子树的高度
       return left > right ? (left + 1):(right + 1);
    }
protected:
    Node* _root;
};
int main()
{
    //int arr[] = {2,3,6,12,'#','#','#',7,8,10};
    //int arr[] = {1};
    int arr[] = {1,2,3,4,5};
    BinaryTreeOfDepth bt(arr,sizeof(arr)/sizeof(arr[0]),'#');
    cout<<bt.GetDepth()<<endl;
    system("pause");
    return 0;
}
//判断二叉树是否是平衡二叉树
#include<iostream>
using namespace std;
#include<cassert>
struct BinaryNode
{
    int _data;
    BinaryNode* _left;
    BinaryNode* _right;
    BinaryNode(int x = 0)
       :_data(x)
       ,_left(NULL)
       ,_right(NULL)
    {}
};
//判断是否是平衡二叉树
class Soluation
{
    typedef BinaryNode Node;
public:
    Soluation(int arr[],int len,const int& invalid)
    {
       size_t index = 0;
       _root = _Create(arr,len,index,invalid);
    }
    bool IsBalance()
    {
       int depth = 0;
       return _IsBalance(_root,depth);
    }
protected:
    Node* _Create(int arr[], int len, size_t& index, const int& invalid)
    {
       assert(arr);
       Node* root = NULL;
       if(index < len && invalid != arr[index])
       {
           root = new Node(arr[index]);
           root->_left = _Create(arr,len,++index,invalid);
           root->_right = _Create(arr,len,++index,invalid);
       }
       return root;
    }
    //每次判断是否是AVL的时候，传一个整形数，防止多遍历一次二叉树
    bool _IsBalance(Node* root, int& depth)
    {
       if(root == NULL)
       {
           depth = 0;
           return true;
       }
       int left = 0;
       int right = 0;
       if(_IsBalance(root->_left,left) && _IsBalance(root->_right,right))
       {
           int diff = left - right;
           if(diff >= -1 && diff <= 1)
           {
               depth = (left > right ) ? (left + 1):(right + 1);
               return true;
           }
       }
       return false;
    }
protected:
    Node* _root;
};
int main()
{
    //int arr[] = {2,3,6,12,'#','#','#',7,8};
    //int arr[] = {1};
    int arr[] = {1,2,3,4,5};
    //int arr[] = { 1, 2, 3, '#', '#', 4, '#' , '#', 5, 6 };
    Soluation bt(arr,sizeof(arr)/sizeof(arr[0]),'#');
    cout<<bt.IsBalance()<<endl;
    system("pause");
    return 0;
}
