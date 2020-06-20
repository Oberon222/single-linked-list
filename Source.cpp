#include <iostream>
using namespace std;
template <class T_list>

class List
{
private:
	struct Node
	{
		T_list value;
		Node* next;
	};

	Node* head;
	int size;

	void DeleteAll()
	{
		if (head != nullptr)
		{
			while (!IsEmpty())
			{
				DeleteHead();
			}
		}
	}
public:
	List() : head(nullptr) { }

	List(const List &other) // copy c-tor
	{
		Node* current = other.head;
		while (current != nullptr)
		{
			AddToTail(current->value);
			current = current->next;

		}
	}

	List(List&& other) // move c-tor
	{
		this->size = other.size;
		this->head = other.head;
		other.head = nullptr;
		other.size = 0;
	}

	~List()
	{
		DeleteAll();
	}

	bool IsEmpty() const
	{
		return head == nullptr;
	}

	// додати елемент до голови
	void AddToHead(T_list value)
	{
		Node* newElem = new Node;
		newElem->value = value;
		newElem->next = head;
		head = newElem;
	}

	// додати елемент до хвоста
	void AddToTail(T_list value)
	{
		Node* newElem = new Node;
		newElem->value = value;
		newElem->next = nullptr;

		if (head == nullptr)
		{
			head = newElem;
		}
		else
		{
			Node* current = head;
			while (current->next != nullptr)
			{
				// move to next
				current = current->next;
			}

			current->next = newElem;
		}
	}

	void AddPosition(T_list value, int pos)
	{
		if (pos <= 0 || pos > size + 1) return;
		if (pos == 1)
		{
			AddToHead(value);
		}
		if (pos == size + 1)
		{
			AddToTail(value);
			return;
		}

		Node* newElem = new Node;
		newElem->value = value;

		Node* current = head;
		for (int i = 0; i < pos - 2; ++i)
		{
			current = current->next;
		}

		newElem->next = current->next;
		current->next = newElem;
		++size;
	}


	// видалити елемент з голови
	void DeleteHead()
	{
		if (head == nullptr) return;

		Node* temp = head->next;
		delete head;

		if (temp == nullptr)
			head = nullptr;
		else
			head = temp;
	}

	// видалити елемент з хвоста
	void DeleteTail()
	{
		if (head == nullptr) return;

		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
		}
		else
		{
			Node* current = head;
			while (current->next->next != nullptr)
			{
				// move to next
				current = current->next;
			}

			// видаляємо останній елемент
			delete current->next;
			current->next = nullptr;
		}
	}

	void DeletePosition(int pos)
	{
		if (pos <= 0 || pos > size) return;

		if (pos == 1)
		{
			DeleteHead();
			return;
		}

		if (pos == size)
		{
			DeleteTail();
			return;
		}

		Node* current = head;
		for (int i = 0; i < pos - 2; ++i)
		{
			current = current->next;
		}
		current->next = current->next->next;
		delete current->next;
		--size;
	}

	int Find(int pos) const // serch element
	{
		Node* current = head;
		int counter = 0;
		for (int i = 0; i < size; ++i)
		{
			current = current->next;
			++count;
			if (count == pos - 1)
			{
				return current->value;
			}

		}
	}

	
	void Show() const
	{
		Node* current = head;
		while (current != nullptr)
		{
			// print current value
			cout << current->value << ", ";

			// move to next
			current = current->next;
		}
	}


	List operator=(const List& other)
	{
		if (this == &other) return *this;
		this->~List();
		Node* current = other.head;
		while (current != nullptr)
		{
			AddToTail(current->value);
			current = current->next;
		}
	}
};

int main()
{
	List <int> ls;

	ls.AddToHead(10);
	ls.AddToHead(15);
	ls.AddToHead(5);
	ls.AddToHead(20);

	ls.Show(); cout << endl;

	ls.DeleteHead();
	ls.AddToTail(777);

	ls.Show(); cout << endl;

	ls.DeleteTail();
	ls.DeleteTail();

	ls.Show(); cout << endl;

	return 0;
}