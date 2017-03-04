#include "Utilities.h"
using namespace std;

vector<string> split(string input, char delim) {
	int pos(0);
	vector<string> output;
	while (pos != string::npos) {
		pos = input.find(delim);
		output.push_back(input.substr(0, pos));
		input.erase(0, pos+1);
	}
	return output;
}