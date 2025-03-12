//============================================================================
// Name        : C++_for_DSA_pratice.cpp
// Author      : G.D Yu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
// Reference   : http://alrightchiu.github.io/SecondRound/queue-yi-arrayshi-zuo-queue.html#circular
//============================================================================
#include <iostream>
using namespace std;

class QueueArrayCircular {
private:
	int capacity, front, back;
	int *queue;

public:
	QueueArrayCircular() :
			capacity(5), front(0), back(0) { // 從0開始
		queue = new int[capacity];
	}
	void Push(int x);
	void Pop();
	bool IsEmpty();
	bool IsFull();
	int getFront();
	int getBack();
	int getSize();
	int getCapacity();
};

void QueueArrayCircular::Push(int x) {
	if (IsFull())
		cout << "Queue is full!" << endl;
	else {
		back = (back + 1) % capacity;
		queue[back] = x;
	}
}
void QueueArrayCircular::Pop() {
	if (IsEmpty())
		cout << "Queue is empty!" << endl;
	else {
		queue[front] = { };
		front = (front + 1) % capacity;
	}
}
bool QueueArrayCircular::IsEmpty() {
	return front == back;
}
bool QueueArrayCircular::IsFull() {
	return (back + 1) % capacity == front;
}
int QueueArrayCircular::getFront() {
	return front;
}
int QueueArrayCircular::getBack() {
	return back;
}
int QueueArrayCircular::getSize() {
	if(back < front)
		return back - front;
	else
		return capacity - (front - back);//當front > back --> back - front = 目前空的空間，總空間 - 目前空的空間 = 已使用的空間
}
int QueueArrayCircular::getCapacity() {
	return capacity;
}

void printCircularQueue(QueueArrayCircular queue) {
	cout << "front: " << queue.getFront() << "    back: " << queue.getBack()
			<< "\n" << "capacity: " << queue.getCapacity()
			<< "  number of elements: " << queue.getSize() << "\n\n";
}

int main() {

	QueueArrayCircular q;
	if (q.IsEmpty()) {
		cout << "Queue is empty.\n\n";
	}
	q.Push(24);
	cout << "After push 24:\n";
	printCircularQueue(q);
	q.Push(8);
	q.Push(23);
	cout << "After push 8, 23:\n";
	printCircularQueue(q);
	q.Pop();
	cout << "After pop 24:\n";
	printCircularQueue(q);
	q.Push(13);
	cout << "After push 13:\n";
	printCircularQueue(q);
	q.Pop();
	cout << "After pop 8:\n";
	printCircularQueue(q);
	q.Push(35);
	cout << "After push 35:\n";
	printCircularQueue(q);
	q.Push(9);
	cout << "After push 9:\n";
	printCircularQueue(q);
	q.Push(64);
	cout << "After push 64:\n";
	printCircularQueue(q);
	return 0;
}
