/*
 * Problem: Given two linked list s1, s2, s3...sn and f1, f2, f3...fm. Merge them such that new linked list is s1 f1 s2 f2...sn or fm
 * Author: Kartheek Diwakar Pingali
 *
 */



#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int val;
	Node* next;

	Node(int value)
	{
		val = value;
		next = NULL;
	}
};



void getInput(Node** head1, Node** head2)
{
	int n;
	cout << "Enter the number of elements in list 1: ";
	cin >> n;

	int m;
	cout << "Enter the number of elments in list 2: ";
	cin >> m;
	cout << "\n";
	
	if(n >= 1)
	{
	
	cout << "Enter elements for list 1: ";
	int k;
	cin >> k;
	Node* list1 = new Node(k);
	(*head1) = list1;
	Node* prev = list1;


	for(int i=1; i<n; i++)
	{
		cin >> k;
		list1 = new Node(k);
		prev -> next = list1;
		prev = list1;

	}
	
	}

	if(m >= 1)
	{	
	
	cout << "Enter elements for list 2: ";
	int k;
	cin >> k;
	Node* list2 = new Node(k);
	(*head2) = list2;
	Node* prev = list2;
	for(int i=1; i<m; i++)
	{
		cin >> k;
		list2 = new Node(k);
		prev->next = list2;
		prev = list2;
	}

	}

	cout << "\n";
}


void MergeList(Node* list1, Node* list2)
{




	while(list1 && list2)
	{
		Node* t1 = list1;
		list1 = list1->next;

		Node* t2 = list2;
		list2 = list2->next;

		t1->next = t2;
		if(list1)
		{
			t2->next = list1;
		}
	}


}


void printList(Node* list)
{

	while(list)
	{
		cout << list->val << "->";
		list = list->next;
	}
	cout << "END";
	cout << "\n" << "\n";
}



int main()
{
	Node* head1;
	Node* head2;
	getInput(&head1, &head2);
	MergeList(head1, head2);
	cout << "MERGED LIST: ";
	printList(head1);

	return 0;
}
