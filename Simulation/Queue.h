#pragma once
#include "Node.h"
void enqueue(Node* newNode, Node* root);
Node* dequeue(Node*& root);
int qsize(Node* root);
bool isEmpty(Node* root);
