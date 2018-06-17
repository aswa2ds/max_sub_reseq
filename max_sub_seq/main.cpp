#include <iostream>
#include <sstream>
#include <string.h>
#include <vector>
#include <string>

using namespace std;

class deal {
private:
	vector<char> list;
	short num;
	vector<short> *dp_matrix;
public:
	deal(int n) {
		num = (n - 1)/2 + 1;
		dp_matrix = new vector<short>[num];
		for (int j = 0; j < num; ++j) {
			dp_matrix[j].resize(j + 1);
			//for (int i = 0; i <= num - 1; ++i) {
			//		cout << "0 ";
			//	dp_matrix[j].push_back(0);
			//}
			//cout << endl;
		}
	}
	int read_in(string);
	void finish_matrix();
	short longest() { return dp_matrix[num-1][0]; }
};

int main() {
	string line;
	while (getline(cin, line, '\n')) {
		deal dp(line.size());
		//cout << "read_in: " << dp.read_in(line) << " characters!" << endl;
		dp.read_in(line);
		cout << "I have read the rules about plagiarism punishment" << endl;
		cout << dp.longest() << endl;
	}
	return 0;
}

int deal::read_in(string line) {
	istringstream ss(line);
	int count = 0;
	char ch;
	while (ss >> ch) {
		count++;
		list.push_back(ch);
	}
	finish_matrix();
	return count;
}

void deal::finish_matrix() {
	for (int j = 0; j < num; ++j) {
		dp_matrix[j][j] = 1;
		for (int i = j - 1; i >= 0; --i) {
			if (list[i] == list[j]) {
				if (i + 1 == j)
					dp_matrix[j][i] = 2;
				else
					dp_matrix[j][i] = dp_matrix[j - 1][i + 1] + 2;
			}
			else
				dp_matrix[j][i] = (dp_matrix[j][i + 1] > dp_matrix[j - 1][i]) ? dp_matrix[j][i + 1] : dp_matrix[j - 1][i];
		}
	}
	/*for (int i = 0; i < num; ++i) {
		for (int j = 0; j <= i; ++j)
			cout << dp_matrix[i][j] << " ";
		cout << endl;
	}*/
}