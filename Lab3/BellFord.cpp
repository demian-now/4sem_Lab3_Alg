#include "BellFord.h"
#include <iostream>

#define inf INT_MAX/2-1

using namespace std;

Graph::Graph()
{
	matrix = NULL;
	size = 0;
}

Graph::~Graph()
{
	clear();
}

void Graph::input(string filename)
{
	Info.clear(); Node.clear();
	if (filename == "")
		filename = "test.txt";
	string temp;
	ifstream filereader;
	filereader.open(filename.c_str(), ios::in);
	if (filereader.bad())
		throw "Bad File Name";
	while (!filereader.eof())
	{
		getline(filereader, temp);
		Info.push_back(temp);
	}
	summarize();
}

size_t Graph::BellFord(size_t first, size_t second)
{
	if (first == second)
		return 0;
	int* dist = new int[Node.get_size()];
	int* way = new int[Node.get_size()];
	for (size_t i = 0; i < Node.get_size(); i++)
	{
		if (i != first) dist[i] = matrix[first][i];
		else dist[i] = 0;
		way[i] = -1;
	}
	for (size_t k = 0; k < Node.get_size(); k++)
	{
		bool control = false;
		for (size_t i = 0; i < Node.get_size(); i++)
		{
			for (size_t j = 0; j < Node.get_size(); j++)
			{
				if (dist[i] > (dist[j] + matrix[j][i]) && i!=j)
				{
					dist[i] = dist[j] + matrix[j][i];
					way[k] = (int)j;
					control = true;
				}
			}
		}
		if (!control) break;
	}
	if (dist[second] == inf)
		cout << "Пути из " << Node.at(first) << " в " << Node.at(second) << " не существует" << endl;
	else
	{
	cout << "Путь из " << Node.at(first) << " в " << Node.at(second) << " стоит " << dist[second] << endl;
	cout << "Маршрут: " << Node.at(first);
		for (size_t i = 0; i < Node.get_size(); i++)
		{
			if (way[i] == -1 || way[i] == second)
				break;
			cout << " -> " << Node.at(way[i]);
		}
	cout << "->" << Node.at(second) << endl;
	}
	size_t result = dist[second];
	delete[] dist; delete[] way;
	return result;
}

void Graph::clear()
{
	Node.clear();
	Info.clear();
	for (size_t i = 0; i < size; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	matrix = NULL;
	size = 0;
}

void Graph::summarize()
{
	size_t iter = Info.get_size();
	int** tmp = new int* [iter];
	for (size_t i = 0; i < iter; i++)
		tmp[i] = new int[4];
	for (size_t i = 0; i < iter; i++)
	{
		string temp = Info.at(i), name = "";
		string way[4] = { "","","","" };
		size_t k = 0;
		for (size_t j = 0; j < temp.size(); j++)
		{
			if (temp[j] == ';') k++;
			else way[k].push_back(temp[j]);
		}
		for (size_t k = 0; k < 2; k++)
		{
			if(Node.find(way[k])==-1) Node.push_back(way[k]);
			//cout << way[k + 2] << endl ;
			if (way[k + 2][0] == 'N')
				tmp[i][k + 2] = inf;
			else tmp[i][k + 2] = stoi(way[k + 2]);
		}
		tmp[i][0] = Node.find(way[0]);
		tmp[i][1] = Node.find(way[1]);
	}
	size = Node.get_size();
	matrix = new int* [size];
	for (size_t i = 0; i < size; i++)
	{
		matrix[i] = new int[size];
		for (size_t j = 0; j < Node.get_size(); j++)
			matrix[i][j] = inf;
	}
	for (size_t i = 0; i < iter; i++)
	{
		matrix[tmp[i][0]][tmp[i][1]] = tmp[i][2];
		matrix[tmp[i][1]][tmp[i][0]] = tmp[i][3];
		delete[] tmp[i];
	}
	delete[] tmp;
}
