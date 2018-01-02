#include "stdafx.h"
#include "Queue.h"
#include <iostream>
#include <cassert>   
#include <string>

#ifndef QUEUE_H
#define QUEUE_H

using namespace std;

//constructor
template<typename T>
Queue<T>::Queue(int sizeQueue) : capacity(sizeQueue), head(0), tail(0), count(0)
{
	queuePtr = new T[capacity];
}

// конструктор копии
template<typename T>
Queue<T>::Queue(const Queue &otherQueue) :
	capacity(otherQueue.capacity), head(otherQueue.head),
	tail(otherQueue.tail),queuePtr(new T[capacity]),
	count(otherQueue.count)
{
	for (int i = 0; i < capacity; i++)
		queuePtr[i] = otherQueue.queuePtr[i]; // копируем очередь
}

// деструктор
template<typename T>
Queue<T>::~Queue()
{
	delete[] queuePtr;
}

//return queue length
template<typename T>
int Queue<T>::Length() const
{
	return count;
}

//adding an item to the queue
template<typename T>
void Queue<T>::Enqueue(const T &el)
{
	if (count >= capacity)
		throw "Queue overflow";

	queuePtr[tail++] = el;
	count++;
	// circular buffer
	if (tail >= capacity)
		tail = 0;
}

// функция удаления элемента из очереди
template<typename T>
void Queue<T>::Dequeue()
{
	if (count <= 0)
		throw "There are no items in the queue";

	T returnValue = queuePtr[head++];
	count--;

	// circular buffer
	if (head >= capacity)
		head = 0;
}

//retrieving an item from the queue
template<typename T>
T Queue<T>::Peek() const
{
	if (count <= 0)
		throw "There are no items in the queue";
	return queuePtr[head];
}

//find an item in the queue
template<typename T>
bool Queue<T>::Contains(const T &el) const
{
	if (count <= 0)
		throw "There are no items in the queue";

	int cnt = 0;
	for (int i = head; cnt < count; cnt++)
	{
		if (queuePtr[i] == el)
			return true;
		else
		{
			i++;
			if (i >= capacity)
				i = 0;
		}
	}
	return false;
}

//print queue
template<typename T>
void Queue<T>::PrintQueue() const
{
	int cnt = 0;
	cout << "Queue: ";

	if (count == 0)
		cout << " is empty\n";
	else
	{
		for (int i = head; cnt<count; cnt++)
		{
			cout << queuePtr[i] << " ";
			i++;
			if (i >= capacity)
				i = 0;
		}
		cout << endl;
	}
}

#endif//QUEUE_H