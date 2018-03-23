template <typename T>
class LinkedList
{
private:
	struct Node
	{
		T data;
		Node* next;
		Node(T item) {
			data = item;
			next = nullptr;
		}
	};

	Node* first;
	Node* last;

public:
	int count = 0;

	LinkedList() {
		first = nullptr;
		last = nullptr;
	}
	~LinkedList();

	Node* FindNodeByPos(int pos) {
		Node* term = first;
		for (int i = 0; i < pos; i++) {
			term = term->next;
		}
		return term;
	}

	void Insert(int item, int pos);
	int Delete(int pos);
	void Sort();
	void Push(int item);
	void Pop();
	void Shift();
	void Unshift(int item);
	void Print();

	Node* begin() {
		return first;
	}

	Node* end() {
		return last;
	}

	friend class Iterator;

};

class Iterator
{
	LinkedList<int>::Node* temp;
public:
	Iterator() { temp = nullptr; }
	Iterator(LinkedList<int>::Node* node) {
		temp = node;
	}

	Iterator& operator =(const Iterator &it) {
		temp = it.temp;
		return *this;
	}

	Iterator& operator ++() {
		temp = temp->next;
		return *this;
	}

	Iterator& operator --() {
		temp = temp->next;
		return *this;
	}

	bool operator !=(const Iterator &smth) {
		return (temp != smth.temp);
	}

	bool operator ==(const Iterator &smth) {
		return (temp == smth.temp);
	}

	int& operator *() {
		return temp->data;
	}

	LinkedList<int>::Node* getNode() {
		return temp;
	}
};