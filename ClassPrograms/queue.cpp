#include"queue.h"
#include"Node.h"
//Add new to tail

void enqueue(SensorData* newNode, SensorData* root) {
	SensorData* curNode = root;
	while (curNode->next != nullptr) {
		size++;
		curNode = curNode->next;
	}
	//We are at the tail
	curNode-> = newNode;
	newNode->next = nullptr;
	newNode->prev = curNode;
}

SensorData* dequeue(SensorData* root)
{
	return nullptr;
}

//Return old root and new root
SensorData* dequeue(SensorData* &root) {
	SensorData* curNode = root;
	root = curNode->next;
	curnode->next = nullptr;
	curNode->prev = nullptr;
	return curNode;
	

}


int qsize(SensorData* root);
{
	if (root == nullptr)return 0;
	SensorData* curNode = root;
	
	int size = 1;
	while (curNode->next != nullptr) {
		size++;
		curNode = curNode->next;
	}
}
int qsize(SensorData* root)
{
	return 0;
}
bool isEmpty(SensorData* root) {
	if (root == nullptr) return true;
	return false;
}