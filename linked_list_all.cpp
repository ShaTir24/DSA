#include <bits/stdc++.h>
using namespace std;
//class is similar to struct in C
class node
{
public:
	int data;
	node *next;

	node(int val)	//same as constructor used in Java
	{
		data = val;
		next = NULL;
	}
};
void insertFront(node *&head, int val)
{ //method to insert nodes from front
	node *n = new node(val);
	n->next = head;
	head = n;
}
//method to insert a node after the specified position
void insertAtN(node *&head, int pos, int val)
{
	node *n = new node(val);
	node *temp = head;
	if (pos == 1)
	{
		n->next = head;
		head = n;
		return;
	}
	for (int i = 1; i < pos - 1; i++)
		temp = temp->next;
	n->next = temp->next;
	temp->next = n;
}

void insertBack(node *&head, int val)
{ //method to insert nodes from back (default)
	node *n = new node(val);
	node *temp = head;
	if (head == NULL)
	{
		head = n;
		return;
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = n;
}

bool search(node *head, int key)
{ //method to search data element in node
	node *temp = head;
	while (temp != NULL)
	{
		if (temp->data == key)
			return true;
		temp = temp->next;
	}
	return false;
}

void disp(node *head)
{ //method to display the nodes
	node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout << "NULL"
		 << "\n";
}

void disp_rr(node *head)
{	//method to display linked list using recursive approach
	if (head == NULL)
		return;
	cout << head->data << " ";
	return disp_rr(head->next);
}

void disp_rev_rr(node *head)
{	//method to print linked list in reverse manner using recursion
	if (head == NULL)
		return;
	disp_rev_rr(head->next);
	cout << head->data << " ";
}

void deleteFront(node *&head)
{ //method to delete the node from front
	node *todel = head;
	head = todel->next;
	delete todel;
}
//method to delete a node from the specified position
void delete_at_n(node *&head, int pos)
{
	node *temp = head;
	if (pos == 1)
	{
		head = temp->next;
		delete temp;
		return;
	}
	for (int i = 1; i < pos - 1; i++)
		temp = temp->next;
	node *del = temp->next;
	temp->next = del->next;
	delete del;
}

void deletion(node *&head, int val)
{ //method to delete node from back (default)
	if (head == NULL)
		return;
	if (head->next == NULL)
	{
		if (head->data == val)
		{
			deleteFront(head);
			return;
		}
	}
	node *temp = head;
	while (temp->next->data != val)
		temp = temp->next;
	node *todel = temp->next;
	temp->next = todel->next;
	delete todel;
}

node *rev(node *&head)
{ //method to reverse the linked list
	node *prev = NULL;
	node *curr = head;
	node *nxt;
	while (curr != NULL)
	{
		nxt = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nxt;
	}
	return prev; //returns the head pointer
}

node *revK(node *&head, int k)
{ //method to reverse first k nodes of linked list
	node *prev = NULL;
	node *curr = head;
	node *nxt;
	int count = 0;
	while (curr != NULL && count < k)
	{
		nxt = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nxt;
		count++;
	}
	head->next = nxt;
	return prev;
}

int lenll(node *head)
{ //method to find length of linked list
	node *temp = head;
	int cl = 0;
	while (temp != NULL)
	{
		cl++;
		temp = temp->next;
	}
	return cl;
}

node *appnd(node *&head, int k)
{ // 1->2->3->4->5->6 => 4->5->6->1->2->3 (k = 3)
	node *newhead;
	node *newtail;
	node *tail = head;
	int count = 1;
	int l = lenll(head);
	k = k % l; //if k > l
	while (tail->next != NULL)
	{
		if (count == l - k)
			newtail = tail;
		if (count == l - k + 1)
			newhead = tail;
		tail = tail->next;
		count++;
	}
	newtail->next = NULL;
	tail->next = head;

	return newhead;
}

int cmn_node(node *&head1, node *&head2)
{ //method to check whether linked list are attached or not
  //checks if a common nide is present between two lists  
	node *ptr1;
	node *ptr2;
	int d = 0;
	int l1 = lenll(head1), l2 = lenll(head2);
	if (l1 > l2)
	{
		d = l1 - l2;
		ptr1 = head1;
		ptr2 = head2;
	}
	else
	{
		d = l2 - l1;
		ptr1 = head2;
		ptr2 = head1;
	}
	while (d--)
	{
		if (ptr1 == NULL)
			return -1;
		ptr1 = ptr1->next;
	}
	while (ptr1 != NULL && ptr2 != NULL)
	{
		if (ptr1 == ptr2)
			return ptr1->data;
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	return -1;
}
node* merged = NULL;	//stores the merged linked list
//merges two linked lists in increasing order
node *merge_inc(node *&head1, node *&head2)
{
	if(head1 == NULL)
		return head2;
	if(head2 == NULL)
		return head1;
	if(head1->data < head2->data) 
	{
		merged = head1;
		merged->next = merge_inc(head1->next, head2);
	}
	else
	{
		merged = head2;
		merged->next = merge_inc(head1, head2->next);
	}
	return merged; 
}
//main method to invoke other member methods
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//code
	node *head = NULL;
	insertBack(head, 1);
	insertBack(head, 2);
	insertBack(head, 3);
	insertBack(head, 4);
	insertFront(head, 5);
	insertBack(head, 6);
	insertAtN(head, 2, 10);
	disp(head);
	cout << "\n";
	disp_rev_rr(head);
	//disp_rr(head);
	cout << "\n";
	//node* n2 = revK(head, 2);
	//disp(n2);
	//node* n1 = rev(head);	//last reversed element is not printed as we perform head->next in revK method
	//disp(n1);
	//cout<<"\n";
	node *n2 = appnd(head, 3);
	//disp(n2);
	return 0;
}