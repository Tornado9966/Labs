#include <iostream>
#include <cassert>
#include "list.h"

using namespace std;

LinkedList<int>::~LinkedList()
{
	while (first)
	{
		Node* term = first->next;
		delete first;
		first = term;
	}
	count = 0;
}

void LinkedList<int>::Insert(int item, int pos)
{
	if ((pos <= 0) || (pos > (count - 1))) {
		assert((pos <= 0) || (pos > (count - 1)));
		count = count;
	}
	else {
		Node* term1 = FindNodeByPos(pos);
		Node* term2 = new Node(item);
		term2->next = term1->next;
		term1->next = term2;
		count++;
	}
}

int LinkedList<int>::Delete(int pos)
{
	if ((pos <= 0) || (pos > (count - 1))) {
		assert((pos <= 0) || (pos > (count - 1)));
		count = count;
		return 0;
	}
	else {
		Node* term1 = FindNodeByPos(pos - 1);
		Node* term2 = FindNodeByPos(pos);
		term1->next = term2->next;
		return term2->data;
		delete term2;
		count--;
	}
}

void LinkedList<int>::Sort()
{
	if (count >= 2) {
		Node* term1 = first;
		Node* term2 = first->next;
		while (term1->next) {
			while (term2) {
				if ((term1->data) > (term2->data)) {
					swap((term1->data), (term2->data));
					term2 = term2->next;
				}
				else {
					term2 = term2->next;
				}
			}
			term1 = term1->next;
			term2 = term1->next;
		}
	}
	else {
		assert(count < 2);
	}
}

void LinkedList<int>::Push(int item)
{
	Node* term = new Node(item);
	if (first == nullptr) {
		first = term;
	}
	else if (count == 1) {
		last = term;
		first->next = last;
	}
	else {
		last->next = term;
		last = term;
	}
	count++;
}

void LinkedList<int>::Pop()
{
	if (count <= 1) {
		last = nullptr;
		count = 0;
	}
	else {
		Node* term = FindNodeByPos(count - 2);
		last = term;
		last->next = nullptr;
		count--;
	}
}

void LinkedList<int>::Unshift(int item)
{
	Node* term = new Node(item);
	if (first == nullptr) {
		first = term;
	}
	else if (count == 1) {
		last = first;
		first = term;
		first->next = last;
	}
	else {
		term->next = first;
		first = term;
	}
	count++;
}

void LinkedList<int>::Shift()
{
	if (count <= 1) {
		first = nullptr;
		count = 0;
	}
	else {
		Node* term = first->next;
		first = nullptr;
		first = term;
		count--;
	}
}

void LinkedList<int>::Print()
{
	Node* term = first;
	if (first == nullptr) {
		cout << "List is empty" << endl;
	}
	else {
		while (term) {
			cout << term->data << " -> ";
			term = term->next;
		}
		cout << "NULL" << endl;
	}
}

/*int main() {
	
	LinkedList<int> list;
	int arr[] = { 10, 20, 5, 15, 40, 2, 14, 60 };
	for (int i = 0; i < 8; i++) {
		list.Push(arr[i]);
	}
	list.Print();
	list.Sort();
	list.Print();
	list.Insert(25, -3);
	list.Print();
	list.Sort();
	list.Print();
	list.Pop();
	list.Pop();
	list.Pop();
	list.Print();
	list.Unshift(17);
	list.Print();
	list.Shift();
	list.Print();
	list.Delete(8);
	list.Print();
	list.~LinkedList();
	list.Print();


	system("pause");
	return 0;
}*/
