#include "Utilities.h"

using namespace std;

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
