#include <iostream>
#include <string>
using namespace std;

string ronaldo(string &x) {
	string tmp = "";
	for (int i = 0; i < x.length(); i++) {
		tmp += x.substr(i,1) + "\n";
	}
	x = tmp;
	return x;
}
int main() {
	string aa;
	cout << "type: ";
	cin >> aa;
	ronaldo(aa);
	cout << aa;
	return 0;
}