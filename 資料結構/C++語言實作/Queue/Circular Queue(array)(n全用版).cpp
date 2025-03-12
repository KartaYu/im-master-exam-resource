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
	bool flag; //true : 為空  | false : 非空

public:
	QueueArrayCircular() :
			capacity(5), front(0), back(0), flag(true) {     // 從0開始, 第一個位置放掉
		queue = new int[capacity];
	}
	void Push(int x) {
		if (IsFull())
			cout << "Queue is full!" << endl;
		else {
			back = (back + 1) % capacity;
			queue[back] = x;
			if (back == front)//如果push之後 front = back --> 表示非空
				flag = false;
		}
	}
	void Pop() {
		if (IsEmpty())
			cout << "Queue is empty!" << endl;
		else {
			queue[front] = { };
			front = (front + 1) % capacity;
			if (front == back)//如果pop之後front = back --> 表示為空
				flag = true;
		}
	}
	bool IsEmpty() {
		if ((front == back) && (flag == true))
			return true;
		else
			return false;
	}
	bool IsFull() {
		if ((front == back) && (flag == false))
			return true;
		else
			return false;

	}
	int getFront() {
		return front;
	}
	int getBack() {
		return back;
	}
	int getSize() { //目前元素數量
		if (IsEmpty())
			return 0;
		if (IsFull())
			return capacity;
		if (back > front)//如果back大於front --> 直接減就是元素數量
			return back - front;
		else
			return capacity - (front - back);//如果front大於back --> front - back = 目前空的容量，capacity - 目前空的容量 = 目前已使用的容量
	}
	int getCapacity() {   // 目前容量
		return capacity;
	}
};

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
	q.Push(77);
	cout << "After push 77:\n";
	printCircularQueue(q);
	q.Pop();
	printCircularQueue(q);
	q.Pop();
	printCircularQueue(q);
	q.Pop();
	printCircularQueue(q);
	q.Pop();
	printCircularQueue(q);
	q.Pop();
	printCircularQueue(q);
	q.Push(100);
	cout << "After push 100:\n";
	printCircularQueue(q);
	q.Push(110);
	cout << "After push 110:\n";
	printCircularQueue(q);
	q.Push(120);
	cout << "After push 120:\n";
	printCircularQueue(q);
	q.Push(130);
	cout << "After push 130:\n";
	printCircularQueue(q);

	return 0;
}

