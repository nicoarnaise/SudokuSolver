#include "Utilities.h"

using namespace std;

/* This function splits a string in a vector<string> */
vector<string> split(string input, char delim) {
	int pos(0);
	vector<string> output;
	while (pos != string::npos) {
		pos = input.find(delim);
		output.push_back(input.substr(0, pos));
		input.erase(0, pos + 1);
	}
	return output;
}

/* This function reads the input.csv and return the sudoku to solve */
vector<vector<string>> readFile()
{
	vector<vector<string>> output;
	string line;
	ifstream myfile("input.csv");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			output.push_back(split(line, ';'));
		}
		myfile.close();
	}
	return output;
}

/* This function writes the solved sudoku in the file output.csv */
bool writeFile(queue<Node*> input) {
	ofstream myfile("output.csv",ios::trunc);
	if (myfile.is_open())
	{
		//int i(1);
		while (!input.empty())
		{
			myfile << input.front()->toString();
			input.pop();
			//i++;
			if (input.size() % 9 != 0) {
				myfile << ";";
			}
			else
			{
				myfile << endl;
			}
		}
		myfile.close();
	}
	else return false;
	return true;
}

/* This function makes an hard copy of a csp */
queue<Node*> copyCsp(queue<Node*> csp)
{
	queue<Node*> copied;
	vector<Node*> toFix;
	map<Node*, Node*> carte;
	while (!csp.empty())
	{
		Node* tmp = new Node(csp.front());
		carte.emplace(csp.front(), tmp);
		copied.push(tmp);
		toFix.push_back(tmp);
		csp.pop();
	}
	for each (Node* node in toFix)
	{
		set<Node*> neighbors;
		for each (Node* neighbor in node->getNeighbors())
		{
			neighbors.insert(carte.at(neighbor));
		}
		node->setNeighbors(neighbors);
	}
	return copied;
}
