#include "stdafx.h"
#include "Graph.h"


Graph::Graph()
{
}


Graph::~Graph()
{
}


void Graph::InsertArc(int a, int b) {
	arcs[a][b] = true;
	nodes[a].increaseOUT();
	nodes[b].increaseIN();
}

void Graph::InsertNode(int a, string b, int c) {
	Node n;
	n.setnumber(a);
	n.setname(b);
	n.setduration(c);
	nodes.push_back(n);
	vector<bool> vec;
	arcs.push_back(vec);
	for (int i = 0; i < nodes.size() - 1; i++) {
		arcs[arcs.size()-1].push_back(false);
	}
	for (int i = 0; i < arcs.size(); i++) {
		arcs[i].push_back(false);
	}
}

void Graph::print() {
	cout << "Der Graph besteht aus folgenden Knoten: " << endl;
	for (int i = 0; i < nodes.size(); i++) {
		cout << nodes[i].getnumber() << " " << nodes[i].getname() << " " << nodes[i].getduration() << endl;
	}
}

void Graph::destroy() {
	nodes.clear();
	if (arcs.size() > 0) {
		for (int i = 0; i < arcs.size(); i++) {
			arcs[i].clear();
		}
	}
	arcs.clear();
}

void Graph::deleteArc(int a, int b) {
	arcs[a][b] = false;
	nodes[a].decreaseOUT();
	nodes[b].decreaseIN();
}

void Graph::deleteNode(int a) {
	nodes.erase(nodes.begin() + a);
	for (int i = 0; i < arcs.size(); i++) {
		if (arcs[i][a]) {
			nodes[i].decreaseOUT();
		}
	}
	for (int i = 0; i < arcs.size(); i++) {
		arcs[i].erase(arcs[i].begin() + a);
	}
	arcs.erase(arcs.begin() + a);
}


//Prüft ob die Vorknoten von i besucht wurden
bool Graph::ready(int a) {
	for (int i = 0; i < arcs.size(); i++) {
		if (arcs[i][a]) {
			if (!nodes[i].getvisited()) {
				return false;
			}
		}
	}
	return true;
}

void Graph::topsort() {
	queue<int> q;
	for (int i = 0; i < nodes.size(); i++) {
		if (nodes[i].getindegree() == 0) {
			q.push(i);
			break;
		}
	}
	int dummy = q.front();
	while (q.size() != 0) {
		int v = q.front();
		q.pop();
		//hässliche Lösung, aber ohne das kann man dem Programm beim Arbeiten zusehen
		if (v == dummy) {
			system("cls");
		}
		cout << nodes[v].getnumber() << " " << nodes[v].getname() << " " << nodes[v].getduration() << endl;
		nodes[v].setvisited(true);
		for (int i = 0; i < nodes.size(); i++) {
			if (ready(i)) {
				q.push(i);
			}
		}
		if (allvisited()) {
			break;
		}
	}


	//ENDE
	for (int i = 0; i < nodes.size(); i++) {
		nodes[i].setvisited(false);
	}
}


//prüft ob alle Knoten besucht worden
bool Graph::allvisited() {
	for (int i = 0; i < nodes.size(); i++) {
		if (!nodes[i].getvisited()) {
			return false;
		}
	}
	return true;
}