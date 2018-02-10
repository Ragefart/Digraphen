#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "Graph.h"

using namespace std;


class Menu
{
public:
	Menu();
	~Menu();
	void main(int a);
	void addgraph();
	vector<Graph> graphs;
	void bearbeiten(int a);
	void choosegraph(int a);
	void newgraph();
	void addknoten(int a);
	void addkante(int a);
	void deletekante(int a);
	void deleteknoten(int a);
	void copy(int a);
private:

};

