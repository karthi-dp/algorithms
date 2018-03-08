/*
 * Problem: Given a tree obtain its mirror image, check the correctness using inorder traversal
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

	Node(int value)
	{
		val = value;
		left = NULL;
		right = NULL;
	}

};


void MakeMirrorImage(Node* root)
{

	if(!root)
	{
		return;
	}
	else
	{

		Node* temp = root->left;
		root->left = root->right;
		root->right = temp;
		MakeMirrorImage(root->left);
		MakeMirrorImage(root->right);

	}


}


/*void Inorder(Node* root)
{
	if(!root)
	{
		return;
	}
	else
	{
		Inorder(root->left);
		cout << root->val << " ";
		Inorder(root->right);
	}
} */



void LevelOrder(Node* root)
{
	queue<Node* >q;
	q.push(root);
	while(!q.empty())
	{
		Node* t = q.front();
		q.pop();

		cout << t->val << " ";
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
	Node* root = n;
	cout << " Level Order Traversals " << "\n";
	cout<< "Original tree: ";
	LevelOrder(root);
	//Inorder(root);
	//cout << "\n";
	cout << "Mirrored tree: ";
	MakeMirrorImage(n);
	LevelOrder(root);
	//Inorder(root);
	//cout << "\n";


	return 0;
}
