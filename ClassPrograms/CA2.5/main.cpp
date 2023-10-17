//test our queue using a LL
#include <iostream>
#include "Node.h"
#include"queue.h"
using namespace std;
int main() {
	sensorData sd1 = { 1,1,1,1,nullptr,nullptr };
	sensorData sd2 = { 2,2,2,2,nullptr,nullptr };
	sensorData sd3 = { 3,3,3,3,nullptr,nullptr };

	sensorData* root = &sd1;
	cout << "Size of queue: " << qsize(root) << endl;

	enqueue(&sd2, root);
	enqueue(&sd3, root);

	cout << "Size of queue: " << qsize(root) << endl;

	SensorData* node = dequeue(root);
	cout << "Node: " node->val1 << endl;
	node = dequeue(root);
	cout << "Node: " node->val1 << endl;
	node = dequeue(root);
	cout << "Node: " node->val1 << endl;
	node = dequeue(root);



}