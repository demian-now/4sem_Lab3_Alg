#pragma once
#include <fstream>
#include "List.cpp"

class Graph
{
private:
	BiList<string> Node, Info;
	int** matrix;
	size_t size;
	void summarize();

public:
	Graph();
	~Graph();
	void input(string filename = "test.txt");
	size_t BellFord(size_t, size_t);
	void clear();
};