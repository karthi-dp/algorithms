/*
 * Problem: Given a tree obtain its mirror image using iterative algorithm
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

	queue<Node* >q;
	q.push(root);
	while(!q.empty())
	{
		Node* t = q.front();
		q.pop();
		swap(t->left, t->right);
		if(t->left)
		{
			q.push(t->left);
		}
		if(t->right)
		{
			q.push(t->right);
		}
	}
	

}

//BFS Traversal using queue
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
	cout << "  Level Order Traversal  " << "\n";
	//Node* root = n;
	cout << "Original Tree: ";
	LevelOrder(n);
	cout << "Mirrored Tree: ";
	MakeMirrorImage(n);
	LevelOrder(n);





	return 0;
}


