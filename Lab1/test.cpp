/*
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
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
	if ((pos < 0) || (pos >(count - 1))) {
		cout << "Incorrect position" << endl;
		count = count;
	}
	else {
		Node* term1 = FindNodeByPos(pos);
		Node* term2 = new Node(item);
		term2->next = term1->next;
		term1->next = term2;

		count++;
		cout << "Item " << item << " added after " << pos << " position" << endl;
	}
}

void LinkedList<int>::Delete(int pos)
{
	if ((pos < 0) || (pos >(count - 1))) {
		cout << "Incorrect position" << endl << endl;
		count = count;
	}
	else {
		Node* term1 = FindNodeByPos(pos - 1);
		Node* term2 = FindNodeByPos(pos);
		term1->next = term2->next;
		delete term2;
		count--;
		cout << "Item" << " deleted on " << pos << " position" << endl;
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
		cout << "List is sorted" << endl;
	}
	else {
		cout << "Error" << endl;
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
	cout << "Item " << item << " is pushed" << endl;
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
		cout << "Item is popped" << endl;
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
	cout << "Item " << item << " is unshifted" << endl;
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
		cout << "Item is shifted" << endl;
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
	cout << "Amount of elements: " << count << endl << endl;
}

TEST_CASE("Check descriptor") {
	LinkedList<int> list;
	list.~LinkedList();
	CHECK((list.first) == nullptr);
	CHECK((list.last) == nullptr);
	CHECK((list.count) == 0);
}

TEST_CASE("Check Push") {
	LinkedList<int> list;
	SUBCASE("Check the first condition") {
		list.Push(10);
		CHECK((list.first->data) == 10);
		CHECK((list.last) == nullptr);
		CHECK((list.count) == 1);
	}
	SUBCASE("Check the second condition") {
		list.Push(10);
		list.Push(15);
		CHECK((list.first->data) == 10);
		CHECK((list.last->data) == 15);
		CHECK((list.count) == 2);
	}
	SUBCASE("Check the third condition") {
		list.Push(10);
		list.Push(15);
		list.Push(20);
		CHECK((list.last->data) == 20);
		CHECK((list.count) == 3);
	}
}

TEST_CASE("Check Pop") {
	LinkedList<int> list;
	SUBCASE("Check the first condition") {
		SUBCASE("count == 0") {
			list.Pop();
			CHECK((list.last) == nullptr);
			CHECK((list.count) == 0);
		}
		SUBCASE("count == 1") {
			list.Push(10);
			list.Pop();
			CHECK((list.last) == nullptr);
			CHECK((list.count) == 0);
		}
	}
	SUBCASE("Check the second condition") {
		list.Push(10);
		list.Push(15);
		list.Push(20);
		list.Push(25);
		list.Pop();
		CHECK((list.last->data) == 20);
		CHECK((list.last->next) == nullptr);
		CHECK((list.count) == 3);
	}
}

TEST_CASE("Check Unshift") {
	LinkedList<int> list;
	SUBCASE("Check the first condition") {
		list.Unshift(10);
		CHECK((list.first->data) == 10);
		CHECK((list.last) == nullptr);
		CHECK((list.count) == 1);
	}
	SUBCASE("Check the second condition") {
		list.Unshift(10);
		list.Unshift(15);
		CHECK((list.first->data) == 15);
		CHECK((list.last->data) == 10);
		CHECK((list.count) == 2);
	}
	SUBCASE("Check the third condition") {
		list.Unshift(10);
		list.Unshift(15);
		list.Unshift(20);
		CHECK((list.first->data) == 20);
		CHECK((list.count) == 3);
	}
}

TEST_CASE("Check Shift") {
	LinkedList<int> list;
	SUBCASE("Check the first condition") {
		SUBCASE("count == 0") {
			list.Shift();
			CHECK((list.first) == nullptr);
			CHECK((list.count) == 0);
		}
		SUBCASE("count == 1") {
			list.Push(10);
			list.Shift();
			CHECK((list.first) == nullptr);
			CHECK((list.count) == 0);
		}
	}
	SUBCASE("Check the second condition") {
		list.Push(10);
		list.Push(15);
		list.Unshift(20);
		list.Push(25);
		list.Shift();
		CHECK((list.first->data) == 10);
		CHECK((list.first->next->data) == 15);
		CHECK((list.count) == 3);
	}
}

TEST_CASE("Check Insert") {
	LinkedList<int> list;
	SUBCASE("Check the first condition") {
		SUBCASE("pos <= 0") {
			list.Push(10);
			list.Push(15);
			list.Unshift(20);
			list.Push(25);
			list.Insert(30, -2);
			list.Insert(30, 0);
			CHECK((list.count) == 4);
		}
		SUBCASE("pos > (count - 1)") {
			list.Push(10);
			list.Push(15);
			list.Unshift(20);
			list.Push(25);
			list.Insert(30, 6);
			CHECK((list.count) == 4);
		}
	}
	SUBCASE("Check the second condition") {
		list.Push(10);
		list.Push(15);
		list.Unshift(20);
		list.Push(25);
		list.Insert(30, 2);
		CHECK((list.FindNodeByPos(3)->data) == 30);
	}
}

TEST_CASE("Check Delete") {
	LinkedList<int> list;
	SUBCASE("Check the first condition") {
		SUBCASE("pos <= 0") {
			list.Push(10);
			list.Push(15);
			list.Unshift(20);
			list.Push(25);
			list.Delete(-3);
			list.Delete(0);
			CHECK((list.count) == 4);
		}
		SUBCASE("pos > (count - 1)") {
			list.Push(10);
			list.Push(15);
			list.Unshift(20);
			list.Push(25);
			list.Delete(5);
			CHECK((list.count) == 4);
		}
	}
	SUBCASE("Check the second condition") {
		list.Push(10);
		list.Push(15);
		list.Unshift(20);
		list.Push(25);
		CHECK(list.Delete(2) == 15);
		CHECK((list.FindNodeByPos(1)->next->data) == 25);
	}
}

TEST_CASE("Check Sort") {
	LinkedList<int> list;
	for (int i = 0; i < 10; i++) {
		int random = rand() % 100;
		list.Push(random);
	}
	list.Sort();
	for (int p = 0; p < 9; p++) {
		CHECK(((list.FindNodeByPos(p))->data) <= ((list.FindNodeByPos(p + 1))->data));
	}
}*/