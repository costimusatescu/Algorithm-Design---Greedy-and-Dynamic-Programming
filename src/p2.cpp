#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// functie de comparare a doua numere;
bool compara_numere(int a, int b) {
	return a > b;
}

class P1 {
 public:
	void solve() {
		read_input();
		print_output(get_result());
	}

 private:
	int n, k;
	int numar;
	vector<int> numere;

	// citire input
	void read_input() {
		ifstream fin("p2.in");
		fin >> n >> k;
		for (int i = 0; i < n; i++) {
			fin >> numar;
			numere.push_back(numar);
		}
		fin.close();
	}

	// intoarce difernta de scor
	long get_result() {
		
		int scor_Tuzgu;
		int scor_Ritza;
		int size = n;

		// ordoneaza numerele descrescator
		sort(numere.begin(), numere.end(), compara_numere);

		// scoate cele k numere din vector
		while (k) {
			vector<int> dif;
			int max = -1;
			int index;

			for (int i = 0; i < size - 1; i++) {
				dif.push_back(numere[i] - numere[i + 1]);
			}

			for (int i = 0; i < size - 1; i++) {
				if ((i % 2 == 1) && (dif[i] > max)) {
					max = dif[i];
					index = i;
				}
			}

			numere.erase(numere.begin() + index);

			k--;
			size--;
		}

		// calculare scoruri
		for (int i = 0; i < size; i++) {
			if (i % 2 == 0) {
				scor_Tuzgu += numere[i];
			} else {
				scor_Ritza += numere[i];
			}
		}

		return scor_Tuzgu - scor_Ritza; 
		
	}

	// scrie in fieser rezultatul
	void print_output(long result) {
		ofstream fout("p2.out");
		fout << result;

		fout.close();
	}
};

int main() {
	P1 p1;
	p1.solve();
	return 0;
}