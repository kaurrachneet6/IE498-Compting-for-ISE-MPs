// //Rachneet Kaur
// IE 498 HW 8 Ques 2
// Doubly Linked List
#include <iostream>
using namespace std;
class Node 
{
	int data;
	Node *next;
	Node *prev;
	
public:
	Node() { data = 0; next = 0; prev = 0; }
	void setData(int d) { data = d; }
	void setNext(Node *n) { next = n; }
	void setPrev(Node *p) { prev = p; }
	int getData() { return data; }
	Node* getNext() { return next; }
	Node* getPrev() { return prev; }
};
class DList
{
	Node *head;
	Node *tail;
public:
	DList() { head = 0; tail = 0; }
	void printDList(); 
	void InsertHead(int d); 
	void InsertTail(int d);
	void Delete(int d); 
};

void DList::printDList()     // Printing the entire list
{
	if (head == 0)
	{
		return;
	}
	Node *curr = head;   // Curr is pointing to start of list
	while (curr != 0)    // Until we reach end of list
	{ 
		cout << curr->getData() << " ";  
		curr = curr->getNext();   // Points to the next item in the list
	}
}

void DList::InsertHead(int d)    // Inserting element at the beginning of list
{
	Node *node = new Node();
	node->setData(d);             // New node's next becomes the first node 'head' of list
	node->setNext(head);        
	if (head == 0)               // Empty list scenario
	{
		head = node;
		tail = node;

	}
	else
	{
		head->setPrev(node);           // Atleast 1 element in the list, so we assign head's prev to new node
		head = node;                   // New node becomes the 'head' node 
	}
}

void DList::InsertTail(int d)    // Inserting an element at the end of the list
{
	Node *node = new Node();
	node->setData(d);
	node->setPrev(tail);          // New node's prev becomes the last node 'tail' of list
	if (head == 0)                // Empty list scenario
	{
		head = node;
		tail = node;

	}
	tail->setNext(node);           // Atleast 1 element in the list, so we assign tail's next to new node
	tail = node;                   // New node becomes the 'tail' node 
}

void DList::Delete(int d)          // Deletes all the elements with value 'd' in the list
{
	Node *temp;
	while (head != 0 && head->getData() == d)    // If head node needs to be deleted
	{
		head = head->getNext();                  // Move pointer to next node
		head->setPrev(0);                       // Set the new head's prev as NULL
	}
	if (head == 0)     // Empty list, delete nothing
	{   
		return;
	}
	while (tail != 0 && tail->getData() == d)  // If tail node needs to be deleted
	{
		tail = tail->getPrev();                // Move pointer to prev node
		tail->setNext(0);                      // Set the new tail's next as NULL
	}
	if (tail == 0)       // Empty list, delete nothing
	{  
		return;
	}
	
	Node *curr = head;
	Node *currN = head->getNext();    // curr as head and currN as head's next

	while (currN != 0) {
		if (currN->getData() == d)   // If data at currN needs to be deleted 
		{
			currN = currN->getNext();    //Set currN to currN->next
			curr->setNext(currN);        
			currN->setPrev(curr);
		}
		else {                      // If data at currN need not to be deleted
			curr = currN;            
			currN = currN->getNext();      // We move pointer to next node
		}
	}
}

int main()
{
	DList list1;
	for (int i = 0; i < 5; i++)
	{
		list1.InsertHead(i);      // Inserting at beginning
		list1.InsertTail(3);      // Inserting at the end
	}
	list1.printDList();           // Printing list
	cout << endl;
	list1.Delete(3);              // Deleting all occurances of 3
	list1.printDList();           // Printing modified list
	cout << endl;
	return 0;
}