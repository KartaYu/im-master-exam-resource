//============================================================================
// Name        : C++_for_DSA_pratice.cpp
// Author      : G.D Yu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
// Reference   : http://alrightchiu.github.io/SecondRound/binary-tree-traversalxun-fang.html#ex_code
//============================================================================
#include <iostream>
#include <string>
#include <queue>
using namespace std;
class BinaryTree;
class TreeNode {
public:
	TreeNode *leftchild;
	TreeNode *rightchild;
	TreeNode *parent;
	string str;

	TreeNode():leftchild(0), rightchild(0), parent(0), str("") {};
	TreeNode(string s):leftchild(0), rightchild(0), parent(0), str(s) {};

	friend class BinaryTree;
};
class BinaryTree {
public:
	TreeNode *root;         // 以root作為存取整棵樹的起點
	BinaryTree():root(0) {}	;
	BinaryTree(TreeNode *node):root(node) {};

	void Preorder(TreeNode *current){
		if(current){
			cout << current->str;
			Preorder(current->leftchild);
			Preorder(current->rightchild);
		}
	}
	void Inorder(TreeNode *current){
		if(current){
			Inorder(current->leftchild);
			cout << current->str;
			Inorder(current->rightchild);
		}
	}
	void Postorder(TreeNode *current){
		if(current){
			Postorder(current->leftchild);
			Postorder(current->rightchild);
			cout << current->str;
		}
	}
	void Levelorder(){
	    std::queue<TreeNode*> q;
	    q.push(this->root);                     // 把root作為level-order traversal之起點
	                                            // 推進queue中
	    while (!q.empty()){                     // 若queue不是空的, 表示還有node沒有visiting

	        TreeNode *current = q.front();      // 取出先進入queue的node
	        q.pop();
	        std::cout << current->str << " ";   // 進行visiting

	        if (current->leftchild != NULL){    // 若leftchild有資料, 將其推進queue
	            q.push(current->leftchild);
	        }
	        if (current->rightchild != NULL){   // 若rightchild有資料, 將其推進queue
	            q.push(current->rightchild);
	        }
	    }
	}
	TreeNode* InorderSuccessor(TreeNode *current) {
		if (current->leftchild == nullptr && current->rightchild == nullptr) {
			while (current == current->parent->rightchild) {
				current = current->parent;
			}
			return current->parent;
		} else {
			return leftmost(current->rightchild);
		}
	}

	TreeNode* leftmost(TreeNode *current) {
		if (current == nullptr) {
			return nullptr;
		} else {
			while (current->leftchild != NULL) {
				current = current->leftchild;
			}
			return current;
		}
	}

};

// definition of BinaryTree::Inorder()
// definition of BinaryTree::Postorder()
// definition of BinaryTree::Levelorder()
int main() {
// TreeNode instantiation
	TreeNode *nodeA = new TreeNode("A");
	TreeNode *nodeB = new TreeNode("B");
	TreeNode *nodeC = new TreeNode("C");
	TreeNode *nodeD = new TreeNode("D");
	TreeNode *nodeE = new TreeNode("E");
	TreeNode *nodeF = new TreeNode("F");
	TreeNode *nodeG = new TreeNode("G");
	TreeNode *nodeH = new TreeNode("H");
	TreeNode *nodeI = new TreeNode("I");

// construct the Binary Tree
	nodeA->parent = nullptr;
	nodeA->leftchild = nodeB;
	nodeA->rightchild = nodeC;
	nodeB->parent = nodeA;
	nodeB->leftchild = nodeD;
	nodeB->rightchild = nodeE;
	nodeD->parent = nodeB;
	nodeG->parent = nodeE;
	nodeH->parent = nodeE;
	nodeE->parent = nodeB;
	nodeE->leftchild = nodeG;
	nodeE->rightchild = nodeH;
	nodeC->parent = nodeA;
	nodeC->leftchild = nodeF;
	nodeF->rightchild = nodeI;
	nodeF->parent = nodeC;
	nodeI->parent = nodeF;

	BinaryTree T(nodeA);

	TreeNode *temp = T.InorderSuccessor(T.root->leftchild->rightchild->rightchild);
	cout << temp->str << endl;

	return 0;
}
