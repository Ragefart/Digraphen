#pragma once

#include <string>
#include <iostream>

using namespace std;

class Node
{
public:
	Node();
	~Node();
	void setname(string a) {
		name = a;
	}
	void setduration(int a) {
		duration = a;
	}
	void setvisited(bool b) {
		visited = b;
	}
	void setnumber(int a) {
		number = a;
	}
	string getname() {
		return name;
	}
	int getduration() {
		return duration;
	}
	bool getvisited() {
		return visited;
	}
	int getnumber() {
		return number;
	}
	void increaseIN() {
		indegree += 1;
	}
	void increaseOUT() {
		outdegree += 1;
	}
	void decreaseIN() {
		indegree -= 1;
	}
	void decreaseOUT() {
		outdegree -= 1;
	}
	int getindegree() {
		return indegree;
	}
	int getoutdegree() {
		return outdegree;
	}
private:
	string name;
	int duration;
	bool visited;
	int number;
	int indegree;
	int outdegree;
};

