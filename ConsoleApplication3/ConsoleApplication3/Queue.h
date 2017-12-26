#pragma once

#include "targetver.h"
#include <stdio.h>
#include <tchar.h>


template<typename T>
class Queue
{
private:
	T *queuePtr;
	const int capacity; //the maximum number of items in the queue
	int head,       //start of queue
		tail;        //end of queue
	int count;        //item counter
public:
	Queue(int = 7);
	~Queue();


	int Length() const;
	void Enqueue(const T &);
	T Peek() const;
	void Dequeue();
	bool Contains(const T&) const;
	void PrintQueue() const;
};

