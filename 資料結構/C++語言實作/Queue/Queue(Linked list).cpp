//============================================================================
// Name        : C++_for_DSA_pratice.cpp
// Author      : G.D Yu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
// Reference   : http://alrightchiu.github.io/SecondRound/queue-introjian-jie-bing-yi-linked-listshi-zuo.html
//============================================================================

#include <iostream>
#include <stack>
using namespace std;

struct QueueNode{
    int data;
    QueueNode *next;
    QueueNode():data(0),next(nullptr){};
    QueueNode(int x):data(x),next(nullptr){};
};

class QueueList{
private:
    QueueNode *front;
    QueueNode *back;
    int size;
public:
    QueueList():front(nullptr),back(nullptr),size(0){};

    void Push(int x){
    	if(IsEmpty()){
    		front = new QueueNode(x);
    		back = front;
    		return;
    	}

    	back->next = new QueueNode(x);
    	back = back->next;
    	size++;

    }

    void Pop(){
    	if(size == 0){
    		cout << "Queue is empty.\n" << endl;
    		return ;
    	}
    	QueueNode* free_node = front;
    	front = front->next;
    	delete free_node;
    	free(free_node);
    	size--;
    }

    bool IsEmpty(){
    	return (size == 0);
    }

    int getFront(){
    	return front->data;
    }

    int getBack(){
    	return back->data;
    }

    int getSize(){
    	return size;
    }
};

int main() {
    QueueList q;
    if (q.IsEmpty()) {
        std::cout << "Queue is empty.\n";
    }
    q.Push(24);
    std::cout<< "\nAfter push 24: \n";
    std::cout << "front: " << q.getFront() << "    back: " << q.getBack() << "\n";
    q.Push(8);
    std::cout<< "\nAfter push 8: \n";
    std::cout << "front: " << q.getFront() << "    back: " << q.getBack() << "\n";
    q.Push(23);
    std::cout<< "\nAfter push 23: \n";
    std::cout << "front: " << q.getFront() << "    back: " << q.getBack() << "\n";
    q.Push(13);
    std::cout<< "\nAfter push 13: \n";
    std::cout << "front: " << q.getFront() << "    back: " << q.getBack() << "\n";
    q.Pop();
    std::cout<< "\nAfter pop the front element: \n";
    std::cout << "front: " << q.getFront() << "     back: " << q.getBack() << "\n";
    q.Push(35);
    std::cout<< "\nAfter push 35: \n";
    std::cout << "front: " << q.getFront() << "     back: " << q.getBack() << "\n";
    q.Pop();
    std::cout<< "\nAfter pop the front element: \n";
    std::cout << "front: " << q.getFront() << "    back: " << q.getBack() << "\n";
    q.Pop();
    std::cout<< "\nAfter pop the front element: \n";
    std::cout << "front: " << q.getFront() << "    back: " << q.getBack() << "\n";
    q.Pop();
    std::cout<< "\nAfter pop the front element: \n";
    std::cout << "front: " << q.getFront() << "    back: " << q.getBack() << "\n";
    q.Pop();
    std::cout<< "\nAfter pop the front element: \n";
    q.Pop();
    return 0;
}
