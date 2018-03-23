#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include "list.h"

using namespace std;

TEST_CASE("Check descriptor") {
	LinkedList<int> list;
	list.~LinkedList();
	Iterator start = list.begin();
	Iterator finish = list.end();
	CHECK(start.getNode() == nullptr);
	CHECK(finish.getNode() == nullptr);
	CHECK((list.count) == 0);
}

TEST_CASE("Check Push") {
	LinkedList<int> list;
	SUBCASE("Check the first condition") {
		list.Push(10);
		Iterator start = list.begin();
		Iterator finish = list.end();
		CHECK(*start == 10);
		CHECK(finish.getNode() == nullptr);
		CHECK((list.count) == 1);
	}
	SUBCASE("Check the second condition") {
		list.Push(10);
		list.Push(15);
		Iterator start = list.begin();
		Iterator finish = list.end();
		CHECK(*start == 10);
		CHECK(*finish == 15);
		CHECK((list.count) == 2);
	}
	SUBCASE("Check the third condition") {
		list.Push(10);
		list.Push(15);
		list.Push(20);
		Iterator finish = list.end();
		CHECK(*finish == 20);
		CHECK((list.count) == 3);
	}
}

TEST_CASE("Check Pop") {
	LinkedList<int> list;
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
		++finish;
		CHECK(finish.getNode()== nullptr);
		CHECK((list.count) == 3);
	}
}

TEST_CASE("Check Unshift") {
	LinkedList<int> list;
	SUBCASE("Check the first condition") {
		list.Unshift(10);
		Iterator start = list.begin();
		Iterator finish = list.end();
		CHECK(*start == 10);
		CHECK(finish.getNode() == nullptr);
		CHECK((list.count) == 1);
	}
	SUBCASE("Check the second condition") {
		list.Unshift(10);
		list.Unshift(15);
		Iterator start = list.begin();
		Iterator finish = list.end();
		CHECK(*start == 15);
		CHECK(*finish == 10);
		CHECK((list.count) == 2);
	}
	SUBCASE("Check the third condition") {
		list.Unshift(10);
		list.Unshift(15);
		list.Unshift(20);
		Iterator start = list.begin();
		CHECK(*start == 20);
		CHECK((list.count) == 3);
	}
}

TEST_CASE("Check Shift") {
	LinkedList<int> list;
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
		Iterator start1 = ++start;
		CHECK(*start1 == 15);
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
}
