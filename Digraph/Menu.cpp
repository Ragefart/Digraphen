#include "stdafx.h"
#include "Menu.h"


Menu::Menu()
{
}


Menu::~Menu()
{
}

void Menu::main(int a) {
	int c = -1;


	cout << "\nMenue von Graph " << graphs[a].getname() << endl;
	cout << " 1: Aktuelles Projekt ausgeben" << endl;
	cout << " 2: Neues Projekt" << endl;
	cout << " 3: Aktuelles Projekt löschen" << endl;
	cout << " 4: Projekt wechseln" << endl;
	cout << " 5: Reihenfolge planen" << endl;
	cout << " 6: Mindestlaufzeit" << endl;
	cout << " 7: Projekt bearbeiten" << endl;
	cout << " 9: ENDE" << endl;

	cin >> c;

	switch (c) {
	case 1:
		system("cls");
		graphs[a].print();
		main(a);
		break;

	case 2: 
		newgraph();
		break;

	case 3: 
		graphs[a].destroy();
		graphs.erase(graphs.begin() + a);
		cout << "Der Graph wurde gelöscht!" << endl;
		if (graphs.size() == 0) {
			cout << "Es sind keine weiteren Graphen vorhanden!" << endl << endl;
		}
		main(0);
			break;

	case 4: 
		choosegraph(a);
		break;

	case 5:
		system("cls");
		cout << "Topologische Sortierung des Graphen " << graphs[a].getname() << "." << endl;
		graphs[a].topsort();
		main(a);
		break;

	case 6: // Mindestlaufzeit-- Aufgabe 4
			// hier ergänzen
		break;

	case 7:
		bearbeiten(a);
		break;
	case 9: // Ende
			
		break;
	default:
		main(a);
		break;
	}
}


void Menu::addgraph() {
	Graph g;
	graphs.push_back(g);
}

void Menu::choosegraph(int a) {
	int c = -1;
	system("cls");
	cout << "Welchen Graph möchten Sie auswählen?" << endl;
	for (int i = 0; i < graphs.size(); i++) {
		cout << i + 1 << ". " << graphs[i].getname() << endl;
	}
	cin >> c;
	if (c - 1 <= graphs.size()) {
		main(c - 1);
	}
	else {
		cout << "Kein solcher Graph vorhanden." << endl;
		main(a);
	}
}

void Menu::newgraph() {
	system("cls");
	string newname;
	cout << "Bitte geben sie einen Namen für den Graphen ein: ";
	cin >> newname;
	addgraph();
	graphs[graphs.size() - 1].setname(newname);
	cout << endl;
	cout << "Der Graph wurde erfolgreich erstellt." << endl;
	main(graphs.size() - 1);
}

void Menu::topsort(int a) {

	main(a);
}

void Menu::bearbeiten(int a) {
	system("cls");
	cout << "Was möchten sie mit dem Graphen " << graphs[a].getname() << " machen?" << endl;
	int c = -1;
	cout << " 1. Knoten hinzufügen" << endl;
	cout << " 2. Kante hinzufügen" << endl;
	cout << " 3. Knoten löschen" << endl;
	cout << " 4. Kante löschen" << endl;
	cout << " 5. Graph kopieren" << endl;
	cout << " 9. Zurück" << endl;
	cin >> c;
	switch (c) {
	case 1:
		addknoten(a);
		break;
	case 2:
		addkante(a);
		break;
	case 3:
		deleteknoten(a);
		break;
	case 4:
		deletekante(a);
		break;
	case 5:
		copy(a);
		break;
	case 9:
		main(a);
		break;
	default:
		bearbeiten(a);
	}
}

void Menu::addknoten(int a) {
	system("cls");
	string newnode;
	int c;
	cout << "Welchen Knoten möchten sie zum Graph " << graphs[a].getname() << " hinzufügen?" << endl;
	graphs[a].print();
	cout << "Name des Vorgangs: ";
	cin >> newnode;
	cout << "Wie lange dauert dieser Vorgang?";
	cin >> c;
	graphs[a].InsertNode(graphs[a].getsize()+1, newnode, c);
	bearbeiten(a);
}

void Menu::addkante(int a) {
	system("cls");
	int start;
	int end;
	cout << "Zwischen welchen Knoten wollen Sie eine Kante einfügen?" << endl;
	graphs[a].print();
	cout << "Startknoten: ";
	cin >> start;
	cout << endl;
	cout << "Zielknoten: ";
	cin >> end;
	cout << endl;
	graphs[a].InsertArc(start, end);
	bearbeiten(a);

}

void Menu::deletekante(int a) {
	system("cls");
	int start;
	int end;
	cout << "Zwischen welchen Knoten wollen Sie eine Kante löschen?" << endl;
	graphs[a].print();
	cout << "Startknoten: ";
	cin >> start;
	cout << endl;
	cout << "Zielknoten: ";
	cin >> end;
	cout << endl;
	graphs[a].deleteArc(start, end);
	bearbeiten(a);
}

void Menu::deleteknoten(int a) {
	system("cls");
	int c;
	cout << "Welchen Knoten möchten Sie löschen?" << endl;
	graphs[a].print();
	cin >> c;
	if (c <= graphs[a].getsize()) {
		graphs[a].deleteNode(c);
	}
	else {
		bearbeiten(a);
	}
	bearbeiten(a);
}

void Menu::copy(int a) {
	addgraph();
	graphs[graphs.size() - 1] = graphs[a];
	graphs[graphs.size() - 1].setname(graphs[graphs.size() - 1].getname() + " KOPIE");
	main(graphs.size() - 1);
}
