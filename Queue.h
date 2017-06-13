#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

template <class Type>

class Queue
{
public:
    Queue();
	virtual ~Queue();

	bool empty() const;
	unsigned size() const;
	bool pop();
    void push(const Type & item);
    Type & getBack();

protected:
    struct Node
	{
		Type item;
		struct Node * next;
	};

    Node * front;
	Node * rear;
	unsigned items;
};

template <class Type>
Queue<Type>::Queue()
{
	front = rear = nullptr;
	items = 0;
}

template <class Type>
Queue<Type>::~Queue()
{
	Node * temp;

	while (front != nullptr)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}

template <class Type>
bool Queue<Type>::empty() const
{
	return items == 0;
}

template <class Type>
unsigned Queue<Type>::size() const
{
	return items;
}

template <class Type>
void Queue<Type>::push(const Type & item)
{
	Node * add = new Node;
	add->item = item;
	add->next = nullptr;
	items++;

	if (front == nullptr)
		front = add;
	else
		rear->next = add;

	rear = add;
}

template <class Type>
bool Queue<Type>::pop()
{
	if (front == nullptr)
		return false;

	items--;
	Node * temp = front;
	front = front->next;
	delete temp;

	if (items == 0)
		rear = nullptr;

	return true;
}

template <class Type>
Type & Queue<Type>::getBack()
{
    return rear->item;
}

#endif // QUEUE_H_INCLUDED
