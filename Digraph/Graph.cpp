#include "stdafx.h"
#include "Graph.h"


Graph::Graph()
{
}


Graph::~Graph()
{
}

//Fügt eine neue gerichtete Kante in den Graphen ein
void Graph::InsertArc(int a, int b) {
	arcs[a][b] = true;
	nodes[a].increaseOUT();
	nodes[b].increaseIN();
}


//Fügt einen neuen Knoten in den Graphen ein
//erweitert die Kantenmatrix und setzt alle Verbindungen
//die diesen Knoten betreffen auf false
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


//Gibt die Knoten des Graphen aus
void Graph::print() {
	cout << "Der Graph besteht aus folgenden Knoten: " << endl;
	for (int i = 0; i < nodes.size(); i++) {
		cout << nodes[i].getnumber() << " " << nodes[i].getname() << " " << nodes[i].getduration() << endl;
	}
}
//löscht den Graphen
void Graph::destroy() {
	nodes.clear();
	if (arcs.size() > 0) {
		for (int i = 0; i < arcs.size(); i++) {
			arcs[i].clear();
		}
	}
	arcs.clear();
}


//Löscht eine Kante und aktualisiert die Ein und Ausgangsgrade
void Graph::deleteArc(int a, int b) {
	arcs[a][b] = false;
	nodes[a].decreaseOUT();
	nodes[b].decreaseIN();
}


//Löscht einen Knoten und aktualisiert alle
//Ein und Ausgangsgrade von anderen Knoten
void Graph::deleteNode(int a) {
	nodes.erase(nodes.begin() + a);
	for (int i = 0; i < arcs.size(); i++) {
		if (arcs[i][a]) {
			nodes[i].decreaseOUT();
		}
		if (arcs[a][i]) {
			nodes[i].decreaseIN();
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


//Topologische sortierung des Graphen
//Durchläuft den Graphen von einem Startknoten und geht von 
//dort aus den ganzen Knoten 
void Graph::topsort() {
	queue<int> q;
	int duration = 0;
	for (int i = 0; i < nodes.size(); i++) {
		if (nodes[i].getindegree() == 0) {
			q.push(i);
			duration = duration + nodes[i].getduration();
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
			duration = 0;
		}
		cout << nodes[v].getnumber() << " " << nodes[v].getname() << " " << nodes[v].getduration() << endl;
		nodes[v].setvisited(true);
		duration = duration + nodes[v].getduration();
		for (int i = 0; i < nodes.size(); i++) {
			if (ready(i)) {
				q.push(i);
			}
		}
		if (allvisited()) {
			break;
		}
	}
	cout << endl << endl;
	cout << "Dauer des Vorgangs: " << duration << endl;
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