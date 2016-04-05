#include <iostream>
using namespace std;

class Tree{
private:
	class Node{
	public:
		int val;
		Node* parent;
		Node* left;
		Node* right;
	
		Node(int v,Node* parent,Node* left,Node* right):val(v),parent(parent),left(left),right(right){}

		void inorder()
		{
			if(left!=NULL)
				left->inorder();
			cout<<val<<' ';
			if(right!=NULL)
				right->inorder();
		}

		void preorder()
		{
			cout<<val<<' ';
			if(left!=NULL)
				left->preorder();
			if(right!=NULL)
				right->preorder();
		}

		void postorder()
		{
			if(left!=NULL)
				left->postorder();
			if(right!=NULL)
				right->postorder();
			cout<<val<<' ';
		}
	};
	Node* root;

public:
	Tree(){root=NULL;}

	void add(int v)
	{
		if(root==NULL)
		{
			root=new Node(v,NULL,NULL,NULL);
			return;
		}
		Node* p=root;
		while(true)
		{
			if(v>p->val)
			{
				if(p->right==NULL)
				{
					p->right=new Node(v,p,NULL,NULL);
					return;
				}
				
				p=p->right;
			}
			else{
				if(p->left==NULL)
				{
					p->left=new Node(v,p,NULL,NULL);
					return;
				}
				p=p->left;
			}
		}

	}

	void inorder(){
		if(root==NULL)
			return;
		root->inorder();
		cout<<endl;
	}

	void preorder(){
		if(root==NULL)
			return;
		root->preorder();
		cout<<endl;
	}

	void postorder(){
		if(root==NULL)
			return;
		root->postorder();
		cout<<endl;
	}
};

int main()
{
	Tree tree;
	int vals[5]={3,5,4,2,1};
	for(int i=0;i<5;i++)
	{
		tree.add(vals[i]);
	}
	tree.inorder();
	tree.preorder();
	tree.postorder();
}
