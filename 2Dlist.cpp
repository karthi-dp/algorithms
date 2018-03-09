/*
 *
 * Problem: Create a new data structure: 2Dimensional doubly linked list
 * supported operations: Create a new node, Display all nodes, Search a value,
 * Traversal
 * Author: Kartheek Diwakar Pingali
 *
 */


#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int val;
	int row, col;
	Node* right;
	Node* left;
	Node* up;
	Node* down;

	Node(int value, int r, int c)
	{
		val = value;
		row = r;
		col = c;
		right = NULL;
		left = NULL;
		up = NULL;
		down = NULL;
	}

};


//Update the links of new node and neighbouring nodes
Node* updateLinks(Node* root, Node** n, unordered_map<Node*, bool> &visited)
{
	if(!root)
	{
		return (*n);
	}
	if(visited[root])
	{
		return (*n);
	}
	
	visited[root] = true;

	int row_diff = (*n)->row - root->row;
	int col_diff = (*n)->col - root->col;
	bool same_row = root->row & (*n)->row;
	bool same_col = root->col & (*n)->col;

	if(root->col == (*n)->col && row_diff == 1)
	{
		root->down = (*n);
		(*n)->up = root;

	}

	if(root->col == (*n)->col && row_diff == -1)
	{
		(*n)->down = root;
		root->up = (*n);

	}

	if(root->row == (*n)->row && col_diff == 1)
	{

		(*n)->left = root;
		root->right = (*n);

	}

	if(root->row == (*n)->row && col_diff == -1)
	{
		(*n)->right = root;
		root->left = (*n);

	}

	updateLinks(root->left,n,visited);
	updateLinks(root->right,n,visited);
	updateLinks(root->up,n,visited);
	updateLinks(root->down,n,visited);
	return (*n);

}

//check for new node with already existing row,col
void duplicate_RowCol(Node* root, Node* n, bool& check_row_col,unordered_map<Node*, bool>&visited)
{
	if(!root)
	{
		return;
	}
	if(visited[root])
	{
		return;
	}
	visited[root] = true;
	if(root->row == n->row && root->col == n->col)
	{
		check_row_col = false;
		return;
	}
	else
	{
		duplicate_RowCol(root->up,n,check_row_col,visited);
		duplicate_RowCol(root->down,n,check_row_col,visited);
		duplicate_RowCol(root->left,n,check_row_col,visited);
		duplicate_RowCol(root->right,n,check_row_col,visited);
	}
}

//create a node
void createNode(Node* root)
{

	int val;
	int row;
	int col;
	cout << "val row col: ";
	cin >> val;
	cin >> row;
	cin >> col;
	Node* n = new Node(val, row, col);
	unordered_map<Node*, bool> visited;
	bool check = true;
	duplicate_RowCol(root,n,check,visited);
	if(check)
	{
		unordered_map<Node*, bool> visited;
		Node* t = updateLinks(root,&n,visited);
		if(t->up || t->down || t->left || t->right)
		{
			return;
		}
		else
		{
			cout << "   Invalid row,col " << "\n";
		}
	}
	else
	{
		//cout << "Cann't create a new Node as a Node is already with the current row and col." << "\n" << "Try different row and column" << "\n";
		cout << "   Row, Col already in use, try different row,col  " << "\n";
	
	}
}


//Display all nodes of the list
void display(Node* root, unordered_map<Node*, bool>&visited)
{

	if(!root)
	{
		return;
	}

	if(visited[root])
	{
		return;
	}

	visited[root] = true;
	cout << root->val << " ";

	display(root->left, visited);
	display(root->right,visited);
	display(root->up, visited);
	display(root->down, visited);


}

//Search for the elements
void search(Node* root, int n, unordered_map<Node*, bool>&visited, bool &found)
{
	if(!root)
	{
		return;
	}
	if(visited[root])
	{
		return;
	}
	visited[root]=true;
	if(root->val == n)
	{
		found = true;
		return;
	}
	else
	{
		search(root->left,n,visited,found);
		search(root->right,n,visited,found);
		search(root->up,n,visited,found);
		search(root->down,n,visited,found);
	}
}


//Traverse the list
void traverse(Node* root, string str)
{
	int n = str.size();
	bool flag = true;

	for(int i=0; i<n; i++)
	{
		if(str[i] == 'L')
		{
			if(root->left)
			{
				root = root->left;
			}
			else
			{
				cout << "   Invalid Traversal ";
				flag = false;
				break;
			}
		}
		else if(str[i] == 'R')
		{
			if(root->right)
			{
				root = root->right;
			}
			else
			{
				cout << "   Invalid Traversal ";
				flag = false;
				break;
			}
		}
		else if(str[i] == 'U')
		{
			if(root->up)
			{
				root = root->up;
			}
			else
			{
				cout << "   Invalid Traversal ";
				flag = false;
				break;
			}
		}
		else if(str[i] == 'D')
		{
			if(root->down)
			{
				root = root->down;
			}
			else
			{
				cout << "   Invalid Traversal ";
				flag = false;
				break;
			}
		}
		else
		{
			cout << "   Invalid Request" ;
			break;
		}
	}

	if(root && flag)
	{
		cout << "   Landing Node Value: " << root->val;
	}
	else if(flag)
	{
		cout << "   Reached an island: hahaha";
	}
	cout << "\n";
}

int main()
{
	Node* root = new Node(0,0,0);
	int ch;
	bool flag = true;
	bool found = false;
	unordered_map<Node*, bool> visited;
	int n;
	string str;
    	while(flag)
	{

	    cout << "1.CreateNode 2.Display 3.Search 4.Traverse 5.Exit" << "  YOUR CHOICE:  ";
    	    cin >> ch;	    
	    switch(ch)
	    {

		//Create Node
		case 1: createNode(root);break;

		//Display Nodes	
		case 2:
	        cout << "   The elements of 2D list are: ";
	        display(root, visited);
		cout << "\n";
	        visited.clear();
		break;

		//Search	
		case 3: cout << "  Enter the search value: ";
		cin >> n;
		found = false;
		search(root,n,visited,found);
		if(found)
		{
			cout << "  SEARCH SUCCESS   ";
		}
		else
		{
			cout << "  SEARCH FAILED    ";
		}
		cout << "\n";
		break;


		//Traverse List	
		case 4:
		cout << "  Enter the traversal pattern eg: LUDR:   "; 
		cin >> str;
		traverse(root, str);
		break;
	
		default: flag = false;

	    }
	}

	return 0;
}
