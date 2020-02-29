#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;



class P3 {
 public:
	void solve() {
		read_input();
		print_output(get_result());
	}

 private:
	int n;
	int number;
	vector<int> numbers;
	int total_score;

    vector< pair <int,bool> > clone;  

	void read_input() {
		ifstream fin("p3.in");
		fin >> n;
		for (int i = 0; i < n; i++) {
			fin >> number;
			numbers.push_back(number);
		}
		fin.close();
	}

	long int get_result() {
        // dp[i+1][j+1] = the value of the game [piles[i], ..., piles[j]]
        long int dp[n + 2][n + 2];
        memset(dp, 0, sizeof(dp));

        for (int size = 1; size <= n; ++size)
            for (int i = 0, j = size - 1; j < n; ++i, ++j) {
                int parity = (j + i + n) % 2;
                if (parity == 1) {
                    dp[i+1][j+1] = max(numbers[i] + dp[i+2][j+1], numbers[j] + dp[i+1][j]);
                }
                else {
                    dp[i+1][j+1] = min(-numbers[i] + dp[i+2][j+1], -numbers[j] + dp[i+1][j]);
                }
            }

        return dp[1][n];
	}

	void print_output(long int result) {
		ofstream fout("p3.out");
		fout << result << '\n';
		fout.close();
	}
};

int main() {
	P3 p3;
	p3.solve();
	return 0;
}
