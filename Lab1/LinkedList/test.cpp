#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include "list.h"

using namespace std;

TEST_CASE("Check descriptor") {
	LinkedList<int> list;
	list.~LinkedList();
	CHECK(list.begin().getNode() == nullptr);
	CHECK(list.end().getNode() == nullptr);
	CHECK((list.count) == 0);
}

TEST_CASE("Check Push") {
	LinkedList<int> list;
	SUBCASE("Check the first condition") {
		list.Push(10);
		CHECK(*list.begin() == 10);
		CHECK(list.end().getNode() == nullptr);
		CHECK((list.count) == 1);
	}
	SUBCASE("Check the second condition") {
		list.Push(10);
		list.Push(15);
		CHECK(*list.begin() == 10);
		CHECK(*list.end() == 15);
		CHECK((list.count) == 2);
	}
	SUBCASE("Check the third condition") {
		list.Push(10);
		list.Push(15);
		list.Push(20);
		CHECK(*list.end() == 20);
		CHECK((list.count) == 3);
	}
}

TEST_CASE("Check Pop") {
	LinkedList<int> list;
	SUBCASE("Check the first condition") {
		SUBCASE("count == 0") {
			list.Pop();
			CHECK(list.end().getNode() == nullptr);
			CHECK((list.count) == 0);
		}
		SUBCASE("count == 1") {
			list.Push(10);
			list.Pop();
			CHECK(list.end().getNode() == nullptr);
			CHECK((list.count) == 0);
		}
	}
	SUBCASE("Check the second condition") {
		list.Push(10);
		list.Push(15);
		list.Push(20);
		list.Push(25);
		list.Pop();
		CHECK(*list.end() == 20);
		CHECK((++list.end()).getNode() == nullptr);
		CHECK((list.count) == 3);
	}
}

TEST_CASE("Check Unshift") {
	LinkedList<int> list;
	SUBCASE("Check the first condition") {
		list.Unshift(10);
		CHECK(*list.begin() == 10);
		CHECK(list.end().getNode() == nullptr);
		CHECK((list.count) == 1);
	}
	SUBCASE("Check the second condition") {
		list.Unshift(10);
		list.Unshift(15);
		CHECK(*list.begin() == 15);
		CHECK(*list.end() == 10);
		CHECK((list.count) == 2);
	}
	SUBCASE("Check the third condition") {
		list.Unshift(10);
		list.Unshift(15);
		list.Unshift(20);
		CHECK(*list.begin() == 20);
		CHECK((list.count) == 3);
	}
}

TEST_CASE("Check Shift") {
	LinkedList<int> list;
	SUBCASE("Check the first condition") {
		SUBCASE("count == 0") {
			list.Shift();
			CHECK(list.begin().getNode() == nullptr);
			CHECK((list.count) == 0);
		}
		SUBCASE("count == 1") {
			list.Push(10);
			list.Shift();
			CHECK(list.begin().getNode() == nullptr);
			CHECK((list.count) == 0);
		}
	}
	SUBCASE("Check the second condition") {
		list.Push(10);
		list.Push(15);
		list.Unshift(20);
		list.Push(25);
		list.Shift();
		CHECK(*list.begin() == 10);
		CHECK(*(++list.begin()) == 15);
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
		CHECK(*list.getIter(list.FindNodeByPos(3)) == 30);
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
		CHECK(*(++list.getIter(list.FindNodeByPos(1))) == 25);
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
		CHECK((*list.getIter(list.FindNodeByPos(p))) <= (*(++list.getIter(list.FindNodeByPos(p)))));
	}
}
