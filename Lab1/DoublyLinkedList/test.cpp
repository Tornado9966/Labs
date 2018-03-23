#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include "doubly-list.h"

using namespace std;

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
