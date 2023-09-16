#include "Node.h"
#include "Queue.h"
#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	// Some constraints
	int lengthOfZone = 5; // miles
	int zoneSpeed = 40; // mph
	int avgCarWidth = 20; // feet
	int carSpacing = avgCarWidth + (avgCarWidth * zoneSpeed / 10); // feet
	int maxCapacity = lengthOfZone * 5280 / carSpacing; // number of cars
	int carExitsPerMinute = (zoneSpeed * 5280) / (60 * carSpacing); // how many
	cars exit in a minute
		double arrivalFactor = 1.5; // ratio of cars entering over cars exiting
	int carArrivalsPerMinute = arrivalFactor * carExitsPerMinute; // multiple
	cars merging into the q in same minute
		int timeInZone = 60 * lengthOfZone / zoneSpeed; // minutes; how many minutes
	in the zone ?
		int maxSimTime = 60; // minutes; how long before simulation ends?
	int tick = 1; // minutes; increment time by this amount
	int id = 0;
	// Output headers
	cout << "Zone is " << lengthOfZone << " miles long, avg zone speed of " <<
		zoneSpeed << " mph" << endl;
	cout << "Max q capacity: " << maxCapacity << endl;
	cout << "Avg time in zone: " << timeInZone << endl;
	cout << setw(10) << "Time" << setw(10) << "Q size" << endl;
	cout << setw(10) << "====" << setw(10) << "======" << endl;
	// Start the simulation
	long timeElapsed = 0; // minutes
	Node* root = new Node;
	root->timeIn = timeElapsed;
	root->timeOut = timeElapsed + timeInZone;
	root->id = id;
	id++;
	while (qsize(root) <= maxCapacity && timeElapsed <= maxSimTime) {
		timeElapsed += tick;
		// Check if any cars are exiting
		for (int i = 0; i < carExitsPerMinute; i++) {
			if (root->timeOut <= timeElapsed) {
				Node* node = dequeue(root);
				delete node;
			}
		}
		// Check for new cars entering
		for (int i = 0; i < carArrivalsPerMinute; i++) {
			Node* node = new Node;
			node->timeIn = timeElapsed;
			node->timeOut = timeElapsed + timeInZone;
			node->id = id;
			id++;
			enqueue(node, root);
		}
		// Print number of cars in queue
		cout << setw(10) << timeElapsed << setw(10) << qsize(root) << endl;
	}
}