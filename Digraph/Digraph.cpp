// Digraph.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Graph.h"
#include "Menu.h"

using namespace std;


int main()
{
	Menu M;
	M.addgraph();

	// Graph aufbauen *************************************************
	
	// Name:
	M.graphs[0].setname("Standard");

	// Knoten:
	M.graphs[0].InsertNode(0, "Besprechen", 4);
	M.graphs[0].InsertNode(1, "Zeichnen", 14);
	M.graphs[0].InsertNode(2, "Einmessen", 1);
	M.graphs[0].InsertNode(3, "Genehmigen", 21);
	M.graphs[0].InsertNode(4, "Angebot Fundament", 7);
	M.graphs[0].InsertNode(5, "Angebot Rohbau", 14);
	M.graphs[0].InsertNode(6, "Fundament", 5);
	M.graphs[0].InsertNode(7, "Rohbau", 20);

	// Kanten:
	M.graphs[0].InsertArc(0, 1);

	M.graphs[0].InsertArc(1, 2);
	M.graphs[0].InsertArc(1, 3);
	M.graphs[0].InsertArc(1, 4);
	M.graphs[0].InsertArc(1, 5);

	M.graphs[0].InsertArc(2, 6);
	M.graphs[0].InsertArc(3, 6);
	M.graphs[0].InsertArc(4, 6);
	M.graphs[0].InsertArc(5, 7);

	M.graphs[0].InsertArc(6, 7);

	// Menue: ******************************************
	
	M.main(0);

    return 0;
}

