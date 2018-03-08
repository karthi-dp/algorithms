/*
 * Problem: Given a binary tree with an additional pointer right brother which is Null by default. Write a function such that right brother points to the node on the right, in the same level
 * Author: Kartheek Diwakar Pingali
 *
 */

#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int val;
	Node* left;
	Node* right;
	Node* rb; //Right Brother

	Node(int value)
	{
		val = value;
		left = NULL;
		right = NULL;
		rb = NULL;
	}
};




void RightBrother(Node* root)
{

	queue<Node* >q;

	q.push(root);

	while(!q.empty())
	{
		
		Node* t = q.front();
		q.pop();

		if(t->left && t->right)
		{
			t->left->rb = t->right;

			if(t->rb)
			{
				if(t->rb->left)
				{
					t->right->rb = t->rb->left;
				}
				else if(t->rb->right)
				{
					t->right->rb = t->rb->right;
				}
			}

			q.push(t->left);
			q.push(t->right);

		}
		else if(t->left && !(t->right))
		{
			if(t->rb)
			{
				if(t->rb->left)
				{
					t->left->rb = t->rb->left;
				}
				else if(t->rb->right)
				{
					t->left->rb = t->rb->right;
				}
			}

			q.push(t->left);

		}
		else if(t->right && !(t->left))
		{
			if(t->rb)
			{
				if(t->rb->left)
				{
					t->right->rb = t->rb->left;
				}
				else if(t->rb->right)
				{
					t->right->rb = t->rb->right;
				}
			}

			q.push(t->right);

		}



	}


}

void verifyRB(Node* root) 
{

	cout << "prints only those nodes that are connected by right brother" << "\n";
	queue<Node* >q;
	q.push(root);
	
	while(!q.empty())
	{
		
		Node* t = q.front();
		q.pop();

		if(t->rb)
		{
			cout << t->val << "->" << t->rb->val << " ";
		}

		if(t->left)
		{
			q.push(t->left);
		}
		if(t->right)
		{
			q.push(t->right);
		}


	}

	cout << "\n";


}


int main()
{

	Node* n = new Node(1);
	n->left = new Node(2);
	n->right = new Node(3);
	n->left->left = new Node(4);
	n->left->right = new Node(5);
	n->right->left = new Node(6);
	n->right->right = new Node(7);

	RightBrother(n);
	verifyRB(n);
	return 0;


}
