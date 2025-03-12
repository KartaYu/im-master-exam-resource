//============================================================================
// Name        : C++_for_DSA_pratice.cpp
// Author      : G.D Yu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
// Reference   : http://alrightchiu.github.io/SecondRound/stack-neng-gou-zai-o1qu-de-zui-xiao-zhi-de-minstack.html
//============================================================================

#include <iostream>
#include <stack>
using namespace std;

class QueueArraySequential{
private:
    int capacity, front, back;
    int *queue;
    void DoubleCapacity(){
    	capacity *= 2;
    	int *newqueue = new int [capacity];
    	int temp_back = 0;
    	for(int i = front + 1; i <= back; i++){
    		newqueue[temp_back] = queue[i];
    	}

    	front = -1;
    	back = temp_back;
    	delete [] queue;
    	queue = newqueue;
    	free(newqueue);
    }
public:
    QueueArraySequential():capacity(5),front(-1),back(-1){
        queue = new int[capacity];
    };

    void Push(int x){
    	if(IsFull()){
    		cout << "Queue is full, resize" << endl;
    		DoubleCapacity();
    	}
    	queue[++back] = x;
    }

    void Pop(){
    	if(IsEmpty()){
    		cout << "Queue is empty" << endl;
    		return;
    	}
    	cout << queue[front] << endl;
    	front++;
    }

    bool IsEmpty(){
    	return (front == back);
    }

    bool IsFull(){
    	return((back + 1) == capacity);
    }

    int getFront(){
    	return queue[front];
    }

    int getBack(){
    	return queue[back];
    }

    int getSize(){
    	return back - front;
    }

    int getCapacity(){
    	return capacity;
    }
};

void printSequentialQueue (QueueArraySequential queue){
    cout << "front: " << queue.getFront() << "    back: " << queue.getBack() << "\n"
    << "capacity: " << queue.getCapacity() << "  number of elements: " << queue.getSize() << "\n\n";
}

int main() {
    QueueArraySequential q;
    if (q.IsEmpty()) {
        cout << "Queue is empty.\n\n";
    }
    q.Push(24);
    cout << "After push 24: \n";
    printSequentialQueue(q);
    q.Push(8);
    q.Push(23);
    cout << "After push 8, 23: \n";
    printSequentialQueue(q);
    q.Pop();
    cout << "After pop 24: \n";
    printSequentialQueue(q);
    q.Push(13);
    cout << "After push 13: \n";
    printSequentialQueue(q);
    q.Pop();
    cout << "After pop 8: \n";
    printSequentialQueue(q);
    q.Push(35);
    cout << "After push 35: \n";
    printSequentialQueue(q);
    q.Push(9);
    cout << "After push 9: \n";
    printSequentialQueue(q);
    return 0;
}
