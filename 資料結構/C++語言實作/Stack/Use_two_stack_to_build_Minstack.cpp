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

class MinStack {
private:
    stack<int> datastack;
    stack<int> minstack;
public:
    MinStack(){};

    void Push(int x){
    	datastack.push(x);
    	if(minstack.empty() || (x < datastack.top())){
    		minstack.push(x);
    	}else{
    		minstack.push(minstack.top());//如果沒有比最小的小則在push minstack top 一次
    	}
    }

    void Pop(){
    	if(datastack.empty()){
    		cout << "stack is empty" << endl;
    		return;
    	}else{
    		datastack.pop();
    		minstack.pop();
    	}
    }

    bool IsEmpty(){
    	return datastack.empty();
    }
    int Top(){
    	if(IsEmpty()){
    		cout << "Stack is empty.\n" << endl;
    		return -1;
    	}

    	return datastack.top();
    }
    int getSize(){
    	if(IsEmpty()){
    	    cout << "Stack is empty.\n" << endl;
    	    return -1;
    	 }

    	return (int)datastack.size();
    }
    int getMin(){
    	if(IsEmpty()){
    	    cout << "Stack is empty.\n" << endl;
    	    return -1;
    	}

    	return minstack.top();
    }
};
int main() {
    MinStack s;
    s.Pop();
    s.Push(6);
    std::cout << "\ntop: " << s.Top() << "\nmin: " << s.getMin() << std::endl;

    s.Push(13);
    std::cout << "\ntop: " << s.Top() << "\nmin: " << s.getMin() << std::endl;

    s.Push(4);
    std::cout << "\ntop: " << s.Top() << "\nmin: " << s.getMin() << std::endl;

    s.Push(9);
    std::cout << "\ntop: " << s.Top() << "\nmin: " << s.getMin() << std::endl;

    s.Push(1);
    std::cout << "\ntop: " << s.Top() << "\nmin: " << s.getMin() << std::endl;

    s.Pop();
    std::cout << "\ntop: " << s.Top() << "\nmin: " << s.getMin() << std::endl;

    s.Pop();
    std::cout << "\ntop: " << s.Top() << "\nmin: " << s.getMin() << std::endl;

    s.Pop();
    std::cout << "\ntop: " << s.Top() << "\nmin: " << s.getMin() << std::endl;

    s.Pop();
    std::cout << "\ntop: " << s.Top() << "\nmin: " << s.getMin() << std::endl;

    s.Pop();
    std::cout << "\ntop: " << s.Top() << "\nmin: " << s.getMin() << std::endl;

    return 0;
}
