#include "Queue.h"
#include <iostream>
using namespace std;
void enqueue(Node* newNode, Node* root) {
	if (root == nullptr || newNode == nullptr) {
		cout << "enqueue(): args cannot be null" << endl;
		exit(1);
	}
	Node* curNode = root;
	while (curNode->next != nullptr) {
		curNode = curNode->next;
	}
	curNode->next = newNode;
	newNode->prev = curNode;
	newNode->next = nullptr;
}
Node* dequeue(Node*& root) {
	if (root == nullptr) {
		cout << "dequeue(): arg cannot be null" << endl;
		exit(1);
	}
	Node* curNode = root;
	root = curNode->next;
	root->prev = nullptr;
	curNode->next = nullptr;
	curNode->prev = nullptr;
	return curNode;
}
int qsize(Node* root) {
	if (root == nullptr) {
		cout << "qaize(): arg cannot be null" << endl;
		exit(1);
	}
	int size = 1;
	Node* curNode = root;
	while (curNode->next != nullptr) {
		size++;
		curNode = curNode->next;
	}
	return size;
}
bool isEmpty(Node* root) {
	if (root == nullptr) return true;
	return false;
}
