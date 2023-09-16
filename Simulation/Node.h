#pragma once
struct Node {
	int id;
	long timeIn;
	long timeOut;
	Node* prev = nullptr;
	Node* next = nullptr;
};
