#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

const int N = 64;
const int TEST_TIMES = 100;

void reset_arrays(vector<vector<vector<int>>>& a,
    vector<vector<vector<int>>>& b,
    vector<vector<vector<int>>>& c,
    int a_value = 1,
    int b_value = 2,
    int c_value = 0)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                a[i][j][k] = a_value;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				b[i][j][k] = b_value;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				c[i][j][k] = c_value;
}

int main()
{

    vector<vector<vector<int>>> a(N, vector<vector<int>>(N, vector<int>(N, 1)));
    vector<vector<vector<int>>> b(N, vector<std::vector<int>>(N, vector<int>(N, 2)));
    vector<vector<vector<int>>> c(N, vector<std::vector<int>>(N, vector<int>(N, 0)));

	// i-j-k
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                c[i][j][k] = a[i][j][k] + b[i][j][k];
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "N: " << N << "  ";
    cout << "i-j-k: " << elapsed.count() << " seconds" << endl;
    
	reset_arrays(a, b, c);

	// i-k-j
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i++)
        for (int k = 0; k < N; k++)
            for (int j = 0; j < N; j++)
                c[i][j][k] = a[i][j][k] + b[i][j][k];
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    cout << "N: " << N << "  ";
    cout << "i-k-j: " << elapsed.count() << " seconds" << endl;

	reset_arrays(a, b, c);

	// j-i-k
	start = chrono::high_resolution_clock::now();
	for (int j = 0; j < N; j++)
		for (int i = 0; i < N; i++)
			for (int k = 0; k < N; k++)
				c[i][j][k] = a[i][j][k] + b[i][j][k];
	end = chrono::high_resolution_clock::now();
	elapsed = end - start;
	cout << "N: " << N << "  ";
	cout << "j-i-k: " << elapsed.count() << " seconds" << endl;

	reset_arrays(a, b, c);

	// j-k-i
	start = chrono::high_resolution_clock::now();
	for (int j = 0; j < N; j++)
		for (int k = 0; k < N; k++)
			for (int i = 0; i < N; i++)
				c[i][j][k] = a[i][j][k] + b[i][j][k];
	end = chrono::high_resolution_clock::now();
	elapsed = end - start;
	cout << "N: " << N << "  ";
	cout << "j-k-i: " << elapsed.count() << " seconds" << endl;

	reset_arrays(a, b, c);

	// k-i-j
	start = chrono::high_resolution_clock::now();
	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				c[i][j][k] = a[i][j][k] + b[i][j][k];
	end = chrono::high_resolution_clock::now();
	elapsed = end - start;
	cout << "N: " << N << "  ";
	cout << "k-i-j: " << elapsed.count() << " seconds" << endl;

	reset_arrays(a, b, c);

	// k-j-i
	start = chrono::high_resolution_clock::now();
	for (int k = 0; k < N; k++)
		for (int j = 0; j < N; j++)
			for (int i = 0; i < N; i++)
				c[i][j][k] = a[i][j][k] + b[i][j][k];
	end = chrono::high_resolution_clock::now();
	elapsed = end - start;
	cout << "N: " << N << "  ";
	cout << "k-j-i: " << elapsed.count() << " seconds" << endl;

    return 0;
}