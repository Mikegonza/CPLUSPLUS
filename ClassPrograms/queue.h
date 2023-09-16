#pragma once
void enqueue(SensorData* node,SensorData* root);
SensorData* dequeue(SensorData* &root);
int qsize(SensorData* root);
bool isEmpty(SensorData* root);