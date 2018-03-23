#include <iostream>
#include <cstdlib>
#include "doubly-list.h"

using namespace std;

DoublyLinkedList<int>::~DoublyLinkedList()
{
	while (first)
	{
		Node* term = first->next;
		delete first;
		first = term;
	}
	count = 0;
}

void DoublyLinkedList<int>::Insert(int item, int pos)
{
	if ((pos < 0) || (pos >(count - 1))) {
		cout << "Incorrect position" << endl;
		count = count;
	}
	else {
		Node* term1 = FindNodeByPos(pos);
		Node* term2 = new Node(item);
		term2->next = term1->next;
		term1->next->prev = term2;
		term2->prev = term1;
		term1->next = term2;

		count++;
		cout << "Item " << item << " added after " << pos << " position" << endl;
	}
}

void DoublyLinkedList<int>::Delete(int pos)
{
	if ((pos < 0) || (pos >(count - 1))) {
		cout << "Incorrect position" << endl << endl;
		count = count;
	}
	else {
		Node* term1 = FindNodeByPos(pos - 1);
		Node* term2 = FindNodeByPos(pos);
		term1->next = term2->next;
		term2->next->prev = term1;
		delete term2;
		count--;
		cout << "Item" << " deleted on " << pos << " position" << endl;
	}
}

void DoublyLinkedList<int>::Sort()
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
		cout << "List is sorted" << endl;
	}
	else {
		cout << "Error" << endl;
	}
}

void DoublyLinkedList<int>::Push(int item)
{
	Node* term = new Node(item);
	if (first == nullptr) {
		first = term;
	}
	else if (count == 1) {
		last = term;
		first->next = last;
		last->prev = first;
	}
	else {
		last->next = term;
		term->prev = last;
		last = term;
	}
	count++;
	cout << "Item " << item << " is pushed" << endl;
}

void DoublyLinkedList<int>::Pop()
{
	if (count <= 1) {
		last = nullptr;
		count = 0;
	}
	if (count == 2) {
		first->next = nullptr;
		first->prev = nullptr;
		count = 1;
	}
	if (count > 2) {
		Node* term1 = FindNodeByPos(count - 2);
		Node* term2 = FindNodeByPos(count - 3);
		last = term1;
		last->next = nullptr;
		last->prev = term2;
		count--;
		cout << "Item is popped" << endl;
	}
}

void DoublyLinkedList<int>::Unshift(int item)
{
	Node* term = new Node(item);
	if (first == nullptr) {
		first = term;
	}
	else if (count == 1) {
		last = first;
		first = term;
		first->next = last;
		last->prev = first;
	}
	else {
		term->next = first;
		first->prev = term;
		first = term;
	}
	count++;
	cout << "Item " << item << " is unshifted" << endl;
}

void DoublyLinkedList<int>::Shift()
{
	if (count <= 1) {
		first = nullptr;
		count = 0;
	}
	if (count == 2) {
		last->prev = nullptr;
		count = 1;
	}
	if (count > 2) {
		Node* term = first->next;
		term->prev = nullptr;
		first = term;
		count--;
		cout << "Item is shifted" << endl;
	}
}

void DoublyLinkedList<int>::Print()
{
	Node* term = first;
	if (first == nullptr) {
		cout << "List is empty" << endl;
	}
	else {
		cout << "NULL <- ";
		while (term) {
			cout << term->data << " <=> ";
			term = term->next;
		}
		cout << "NULL" << endl;
	}
	cout << "Amount of elements: " << count << endl << endl;
}
