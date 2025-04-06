#include <clocale>
#include <iostream>
#include <regex>
#include <string>
using namespace std;

int VERTEX_COUNT = 1;

struct Tree {
	int data;
	Tree* left;
	Tree* right;
} *tree;

Tree* createNode(Tree* current, int n) {
	Tree* temp;
	int leftVertexCount = 0, rightVertexCount = 0;
	if (n == 0) return NULL;
	else {
		leftVertexCount = n / 2;
		rightVertexCount = n - leftVertexCount - 1;

		temp = new Tree;

		temp->data = rand() % 100;

		temp->left = createNode(temp -> left, leftVertexCount);
		temp->right = createNode(temp->right, rightVertexCount);

		current = temp;
		return temp;
	}
}

static void printForwardTree(Tree* current, int level) {
	if (current != NULL) {
		string str;

		for (int i = 0; i < level; i++) str += "     ";
		cout << " " << str << current->data << endl;

		printForwardTree(current->left, level + 1);
		printForwardTree(current->right, level + 1);
	}
}

static void printBackwardTree(Tree* current, int level) {
	if (current != NULL) {
		string str;
		for (int i = 0; i < level; i++) str += "     ";
		cout << " " << str << current->data << endl;
		printBackwardTree(current->right, level + 1);
		printBackwardTree(current->left, level + 1);
	}
}

static void printSymetricTree(Tree* current, int level) {
	if (current != NULL) {
		printSymetricTree(current->left, level + 1);

		string str;
		for (int i = 0; i < level; i++) str += "     ";
		cout << " " << str << current->data << endl;
		
		printSymetricTree(current->right, level + 1);
	}
}

static void printBackSymetricTree(Tree* current, int level) {
	if (current != NULL) {
		printSymetricTree(current->right, level + 1);

		string str;
		for (int i = 0; i < level; i++) str += "     ";
		cout << " " << str << current->data << endl;

		printSymetricTree(current->left, level + 1);
	}
}

static void deleteTree(Tree* current) {
	if (current != NULL) {
		deleteTree(current->left);
		deleteTree(current->right);
		delete current;
	}
}



static int validIntegerInput(string message) {
	string input;
	regex valid("-?[1-9][0-9]*");
	do {
		cout << message;
		getline(cin,input);
	} while (!regex_match(input, valid));
	return stoi(input);
}


using namespace std;




int main() {
	setlocale(LC_ALL, "Russian");
	
	srand(time(0));

	VERTEX_COUNT = validIntegerInput("Введите количество вершин дерева: ");
	while (VERTEX_COUNT > 0){
		cout << endl << "---------------------------------------------------------------" << endl;
		
		tree = createNode(tree, VERTEX_COUNT);
		cout << "Дерево создано" << endl;

		cout << endl << "Дерево в прямом порядке:" << endl;
		printForwardTree(tree, 0);

		cout << endl << "Дерево в обратном порядке:" << endl;
		printBackwardTree(tree, 0);

		cout << endl << "Дерево в симметричном порядке:" << endl;
		printSymetricTree(tree, 0);

		cout << endl << "Дерево в обратном симметричном порядке:" << endl;
		printBackSymetricTree(tree, 0);

		cout << endl << "Удаление дерева" << endl;
		deleteTree(tree);
		VERTEX_COUNT = validIntegerInput("Введите количество вершин дерева: ");

	}

	cout << "Exit";
	return 0;
}