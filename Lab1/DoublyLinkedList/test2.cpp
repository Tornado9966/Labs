#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include "doubly-list.h"

using namespace std;

/*DoublyLinkedList<int>::~DoublyLinkedList()
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
}*/

TEST_CASE("Check descriptor") {
	DoublyLinkedList<int> list;
	list.~DoublyLinkedList();
	Iterator start = list.begin();
	CHECK(start.getNode() == nullptr);
}

TEST_CASE("Check Push") {
	DoublyLinkedList<int> list;
	SUBCASE("Check the first condition") {
		list.Push(10);
		Iterator start = list.begin();
		CHECK(*start == 10);
		Iterator start1 = --start;
		CHECK(start1.getNode() == nullptr);
		Iterator finish = list.end();
		CHECK(finish.getNode() == nullptr);
		CHECK((list.count) == 1);
	}
	SUBCASE("Check the second condition") {
		list.Push(10);
		list.Push(15);
		Iterator start = list.begin();
		CHECK(*start == 10);
		Iterator start1 = --start;
		CHECK(start1.getNode() == nullptr);
		Iterator finish = list.end();
		CHECK(*finish == 15);
		Iterator finish1 = ++finish;
		CHECK(finish1.getNode() == nullptr);
		CHECK((list.count) == 2);
	}
	SUBCASE("Check the third condition") {
		list.Push(10);
		list.Push(15);
		list.Push(20);
		Iterator finish = list.end();
		CHECK(*finish == 20);
		Iterator finish1 = ++finish;
		CHECK(finish1.getNode() == nullptr);
		Iterator finish2 = list.end();
		Iterator finish3 = --finish2;
		CHECK(*finish3 == 15);
		CHECK((list.count) == 3);
	}
}

TEST_CASE("Check Pop") {
	DoublyLinkedList<int> list;
	SUBCASE("Check the first condition") {
		SUBCASE("count == 0") {
			list.Pop();
			Iterator finish = list.end();
			CHECK(finish.getNode() == nullptr);
			CHECK((list.count) == 0);
		}
		SUBCASE("count == 1") {
			list.Push(10);
			list.Pop();
			Iterator finish = list.end();
			CHECK(finish.getNode() == nullptr);
			CHECK((list.count) == 0);
		}
	}
	SUBCASE("Check the second condition") {
		list.Push(10);
		list.Push(15);
		list.Push(20);
		list.Push(25);
		list.Pop();
		Iterator finish = list.end();
		CHECK(*finish == 20);
		Iterator finish2 = ++finish;
		CHECK(finish2.getNode() == nullptr);
		Iterator finish1 = list.end();
		Iterator finish3 = --finish1;
		CHECK(*finish3 == 15);
		CHECK((list.count) == 3);
	}
}

TEST_CASE("Check Unshift") {
	DoublyLinkedList<int> list;
	SUBCASE("Check the first condition") {
		list.Unshift(10);
		Iterator start = list.begin();
		CHECK(*start == 10);
		Iterator start1 = --start;
		CHECK(start1.getNode() == nullptr);
		Iterator finish = list.end();
		CHECK(finish.getNode() == nullptr);
		CHECK((list.count) == 1);
	}
	SUBCASE("Check the second condition") {
		list.Unshift(10);
		list.Unshift(15);
		Iterator start = list.begin();
		CHECK(*start == 15);
		Iterator finish2 = list.end();
		Iterator start1 = ++start;
		CHECK(start1.getNode() == finish2.getNode());
		Iterator start2 = list.begin();
		Iterator start3 = --start2;
		CHECK(start2.getNode() == nullptr);
		Iterator finish = list.end();
		CHECK(*finish == 10);
		Iterator finish1 = ++finish;
		CHECK(finish1.getNode() == nullptr);
		Iterator start4 = list.begin();
		Iterator finish3 = list.end();
		Iterator finish4 = --finish3;
		CHECK(finish4.getNode() == start4.getNode());
		CHECK((list.count) == 2);
	}
	SUBCASE("Check the third condition") {
		list.Unshift(10);
		list.Unshift(15);
		list.Unshift(20);
		Iterator start = list.begin();
		CHECK(*start == 20);
		Iterator start1 = --start;
		CHECK(start1.getNode() == nullptr);
		CHECK((list.count) == 3);
	}
}

TEST_CASE("Check Shift") {
	DoublyLinkedList<int> list;
	SUBCASE("Check the first condition") {
		SUBCASE("count == 0") {
			list.Shift();
			Iterator start = list.begin();
			CHECK(start.getNode() == nullptr);
			CHECK((list.count) == 0);
		}
		SUBCASE("count == 1") {
			list.Push(10);
			list.Shift();
			Iterator start = list.begin();
			CHECK(start.getNode() == nullptr);
			CHECK((list.count) == 0);
		}
	}
	SUBCASE("Check the second condition") {
		list.Push(10);
		list.Push(15);
		list.Unshift(20);
		list.Push(25);
		list.Shift();
		Iterator start = list.begin();
		CHECK(*start == 10);
		Iterator start2 = list.begin();
		Iterator start3 = --start2;
		CHECK(start3.getNode() == nullptr);
		Iterator start1 = ++start;
		CHECK(*start1 == 15);
		CHECK((list.count) == 3);
	}
}

TEST_CASE("Check Insert") {
	DoublyLinkedList<int> list;
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
	DoublyLinkedList<int> list;
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
		CHECK((list.Delete(2)) == 15);
		CHECK((list.FindNodeByPos(1)->next->data) == 25);
		CHECK((list.FindNodeByPos(1)->prev->data) == 20);
	}
}

TEST_CASE("Check Sort") {
	DoublyLinkedList<int> list;
	for (int i = 0; i < 10; i++) {
		int random = rand() % 100;
		list.Push(random);
	}
	list.Print();
	list.Sort();
	list.Print();
	for (int p = 0; p < 9; p++) {
		CHECK(((list.FindNodeByPos(p))->data) <= ((list.FindNodeByPos(p + 1))->data));
	}
}