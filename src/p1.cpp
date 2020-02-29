#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;



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
	int n;
	int numar;
	vector<int> numere;

	void read_input() {
		ifstream fin("p1.in");
		fin >> n;
		for (int i = 0; i < n; i++) {
			fin >> numar;
			numere.push_back(numar);
		}
		fin.close();
	}

	int get_result() {
		
		int scor_Tuzgu = 0;
		int scor_Ritza = 0;

		sort(numere.begin(), numere.end(), compara_numere);

		for (int i = 0; i < n; i++) {
			
			if (i % 2 == 0) {
				scor_Tuzgu += numere[i];
			} else {
				scor_Ritza += numere[i];
			}
		}

		return scor_Tuzgu - scor_Ritza; 
		
	}

	void print_output(int result) {
		ofstream fout("p1.out");
		fout << result;

		fout.close();
	}
};

int main() {
	P1 p1;
	p1.solve();
	return 0;
}