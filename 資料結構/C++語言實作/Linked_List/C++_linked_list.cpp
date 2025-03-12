//============================================================================
// Name        : C++pratice.cpp
// Author      : G.D Yu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
using namespace std;

class node {
public:
	int data;
	node *rlink;
	//node* llink;

	node() {
		data = NULL;
		rlink = NULL;
		//llink = NULL;
	}

	node(int a) {
		data = a;
		rlink = NULL;
		//llink = NULL;
	}

	void Push_front(node *&p, int num) {//放頭
		node *new_push = new node(num);
		new_push->rlink = p;
		p = new_push;

	}

	void Push_back(node *p, int num) {//放尾
		while (p->rlink!= nullptr)
			p = p->rlink;

		node *new_push = new node(num);
		p->rlink = new_push;
		new_push->rlink = nullptr;

	}

	void print(node *p) {
		if(p == nullptr)//空印empty
			cout << "emtpy" ;

		while (p != nullptr) {
			cout << p->data << " ";
			p = p->rlink;
		}
		cout << endl;
	}

	void reverse(node *&p) {
		node *pre, *curr, *next;
		pre = nullptr;
		curr = p;
		next = p->rlink;
		while (next != nullptr) {
			curr->rlink = pre; // 把current->link轉向
			pre = curr; // previous往後挪到current位置
			curr = next; // current往後挪next位置
			next = next->rlink; // next往下next下一個移動
		}
		curr->rlink = pre; //當loop結束時，curr還未跟pre接上，因此指向pre
		p = curr;
	}

	void Delete(node* p, int num, node* &oh){//oh 為 oringinal head, p為copy之值
		node* pre = p;
		while (p->rlink != nullptr && p->data != num) {
			pre = p;
			p = p->rlink;
		}
		if(p == oh){//num為第一個node
			oh = p->rlink;
		}else{
			pre->rlink = p->rlink;
			delete p;
		}

	}

	void Clear(node* p, node* &oh){//刪全部
		while(p != nullptr){
			node* del = p;
			p = p->rlink;
			delete del;
		}

		oh = p;
	}

};

int main(int argc, char *argv[]) {
	node *head = nullptr;
	head->Push_front(head, 10);
	head->Push_front(head, 20);
	head->Push_front(head, 30);
	head->Push_front(head, 40);
	head->Push_back(head, 90);
	head->Delete(head, 40, head);
	head->print(head);
	head->reverse(head);
	head->print(head);
	head->Clear(head, head);
	head->print(head);
	head->Push_front(head, 50);
	head->Push_front(head, 60);
	head->Push_front(head, 70);
	head->Push_front(head, 80);
	head->print(head);
	/*
	 node* t = new node(3);
	 node* t1 = new node(6);
	 node* t2 = new node(9);
	 node* head = new node();
	 head->rlink = t;
	 t->rlink = t1;
	 t1->rlink = t2;
	 t2->rlink = nullptr;
	 head->print(head);
	 head->reverse(head);
	 head->print(head);
	 */
}
