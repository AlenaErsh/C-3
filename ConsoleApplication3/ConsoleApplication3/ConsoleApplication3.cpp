// _4a_3.cpp: определяет точку входа для консольного приложения.
//
/*Реализовать шаблон класса очередь (Queue<T>) хранящий элементы произвольного
типа. Класс долежн обязательно содержать методы:
- Вычисление длины очереди
- Добавление нового элемента в конец очереди
- Получение элемента из головы очереди
- Удаление элемента из головы
- Поиск элемента в очереди
- Печать очереди

Реализация с помощью массива (использование кольцевого буфера)*/



/*Implement a queue with an array*/

#include "stdafx.h"
#include "Queue.h"
#include "Queue.cpp"
#include <iostream>
#include <cassert>   
#include <string>

using namespace std;


template<typename T>
void Test(T* mas, T find, int size)
{
	Queue<T> q;
	for (int i = 0; i < size; ++i)
	{
		q.Enqueue(mas[i]);

	}
	cout << "Length of the queue : " << q.Length() << endl;
	q.PrintQueue();
	cout << q.Peek() << " first in queue" << endl;

	cout << q.Peek() << " exit" << endl;
	q.Dequeue();

	cout << "Length of the queue : " << q.Length() << endl;
	q.PrintQueue();

	bool resContains = q.Contains(find);
	char* s = (resContains == 1) ? "true" : "false";
	cout << find << " in queue: " << s << endl;
}

template<typename T>
void Menu(T q)
{
	int answ;

	cout << "Work with the queue." << endl;
	cout << "1)Add item to the queue" << endl
		<< "2)Remove an item from the queue" << endl
		<< "3)Find the item in the queue" << endl
		<< "4)Print the queue" << endl
		<< "5)Print the length of the queue" << endl
		<< "6)Exit from work with the queue" << endl;
	cin >> answ;
	switch (answ)
	{
	case 1:
	{
		int el;
		cout << "Enter item : ";
		cin >> el;
		try {
			q.Enqueue(el);
		}
		catch (char *er) {
			cout << "exception: " << er<<endl;
			Menu(q);
			break;
		}
		cout << "Item added" << endl;
		Menu(q);
		break;
	}
	case 2:
	{
		try {
			q.Dequeue();
		}
		catch (char *er) {
			cout << "exeption: " << er << endl;
			Menu(q);
			break;
		}
		cout << "Removed" << endl;
		Menu(q);
		break;
	}
	case 3:
	{
		int find;
		cout << "What element are we looking for in the queue ? " << endl;
		cin >> find;
		bool resContains;
		try {
			resContains = q.Contains(find);
		}
		catch (char *er) {
			cout << "exeption: " << er<<endl;
		}
		char* s = (resContains == 1) ? "true" : "false";
		cout << find << " in queue: " << s << endl;
		Menu(q);
		break;
	}
	case 4:
	{
		q.PrintQueue();
		Menu(q);
		break;
	}
	case 5:
	{
		cout << "Length of the queue : " << q.Length() << endl;
		Menu(q);
		break;
	}
	default:
		break;
	}
}

template<typename T>
void TestUser(T* mas)
{
	Queue<T> q;

	for (int i = 0; i < 4; i++)
	{
		q.Enqueue(mas[i]);
	}
	Menu(q);
}


void main()
{
	setlocale(LC_ALL, "Russian");
	cout << "TEST 1 int" << endl;
	int arrInt[] = { 1, 3, 4, 5 };
	Test(arrInt, 1, 4);
	cout << endl;


	cout << "TEST 2 string" << endl;
	string arrStr[] = { "qwerty", "good", "zxcvb" };
	Test(arrStr, (string)"good", 3);
	cout << endl;

	cout << "TEST 3 user type" << endl;
	int choose;
	do
	{
		cout << "Choose of type" << endl << "1) char" << endl << "2) bool" << endl << "3) float" << endl << "4) user(int)" << endl;
		cin >> choose;
	} while (choose < 1 || choose > 4);

	switch (choose)
	{
	case 1:
	{
		char arr[] = { 'a', 's', 'd', 'r','w','t' };
		Test(arr, 'r', 6);
		break;
	}
	case 2:
	{
		bool arr[] = { true, false, false, true };
		Test(arr, false, 4);
		break;
	}
	case 3:
	{
		float arr[] = { 1.5, 3.5, 4.5, 5.5 };
		Test(arr, (float)4.5, 4);
		break;
	}
	case 4:
	{
		int arr[4];
		cout << "Lead 4 whole numbers through a space : " << endl;
		for (int i = 0; i < 4; i++)
		{
			cin >> arr[i];
		}

		TestUser(arr);
		break;
	}
	default:
		break;
	}

	system("pause");
	return;
}
