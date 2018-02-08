#pragma once

#include "Node.h"
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;


class Graph
{
public:
	Graph();
	virtual ~Graph();
	void InsertNode(int a, string b, int c);
	void InsertArc(int a, int b);
	void deleteArc(int a, int b);
	void print();
	void destroy();
	void deleteNode(int a);
	void topsort();
	bool allvisited();
	void setname(string a) {
		name = a;
	}
	string getname() {
		return name;
	}
	int getsize() {
		return nodes.size();
	}
	Node getstart() {
		return nodes[0];
	}
	void setvisited(int a) {
		nodes[a].setvisited(true);
	}
	bool getvisited(int a) {
		return nodes[a].getvisited();
	}
	Node getnext() {
		for (int i = 0; i < nodes.size(); i++) {
			if (!nodes[i].getvisited()) {
				if (ready(i)) {
					setvisited(i);
					return nodes[i];
				}
			}
		}
	}
	bool ready(int a);
private:
	vector<Node> nodes;
	vector< vector<bool> > arcs;
	string name;
};

