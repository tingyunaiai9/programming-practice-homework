#include <iostream>
#include <chrono>
#include <fstream>

using namespace std;

const int N = 64;
const int TEST_TIMES = 100;

int a[N][N][N];
int b[N][N][N];
int c[N][N][N];

int main()
{
	// record
	ofstream fout("time_record.txt", ios::app);
	fout << "N=" << N << endl;
	fout << "TEST_TIMES=" << TEST_TIMES << endl;
	fout.close();

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				a[i][j][k] = 1;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				b[i][j][k] = 2;

	auto start = chrono::high_resolution_clock::now();
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed = end - start;

	// i-j-k
	double total_time = 0.0;
	for (int t = 0; t < TEST_TIMES; t++)
	{
		start = chrono::high_resolution_clock::now();
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				for (int k = 0; k < N; k++)
					c[i][j][k] = a[i][j][k] + b[i][j][k];
		end = chrono::high_resolution_clock::now();
		elapsed = end - start;
		total_time += elapsed.count();
	}
	fout.open("time_record.txt", ios::app);
	fout << "i-j-k=" << total_time / TEST_TIMES << endl;
	fout.close();
	cout << "i-j-k=" << total_time / TEST_TIMES << endl;

    // i-k-j
    total_time = 0.0;
    for (int t = 0; t < TEST_TIMES; t++)
    {
        start = chrono::high_resolution_clock::now();
        for (int i = 0; i < N; i++)
            for (int k = 0; k < N; k++)
                for (int j = 0; j < N; j++)
                    c[i][j][k] = a[i][j][k] + b[i][j][k];
        end = chrono::high_resolution_clock::now();
        elapsed = end - start;
        total_time += elapsed.count();
    }
    fout.open("time_record.txt", ios::app);
    fout << "i-k-j=" << total_time / TEST_TIMES << endl;
    fout.close();
    cout << "i-k-j=" << total_time / TEST_TIMES << endl;

    // j-i-k
    total_time = 0.0;
    for (int t = 0; t < TEST_TIMES; t++)
    {
        start = chrono::high_resolution_clock::now();
        for (int j = 0; j < N; j++)
            for (int i = 0; i < N; i++)
                for (int k = 0; k < N; k++)
                    c[i][j][k] = a[i][j][k] + b[i][j][k];
        end = chrono::high_resolution_clock::now();
        elapsed = end - start;
        total_time += elapsed.count();
    }
    fout.open("time_record.txt", ios::app);
    fout << "j-i-k=" << total_time / TEST_TIMES << endl;
    fout.close();
    cout << "j-i-k=" << total_time / TEST_TIMES << endl;

    // j-k-i
    total_time = 0.0;
    for (int t = 0; t < TEST_TIMES; t++)
    {
        start = chrono::high_resolution_clock::now();
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                for (int i = 0; i < N; i++)
                    c[i][j][k] = a[i][j][k] + b[i][j][k];
        end = chrono::high_resolution_clock::now();
        elapsed = end - start;
        total_time += elapsed.count();
    }
    fout.open("time_record.txt", ios::app);
    fout << "j-k-i=" << total_time / TEST_TIMES << endl;
    fout.close();
	cout << "j-k-i=" << total_time / TEST_TIMES << endl;

	// k-i-j
	total_time = 0.0;
	for (int t = 0; t < TEST_TIMES; t++)
	{
		start = chrono::high_resolution_clock::now();
		for (int k = 0; k < N; k++)
			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
					c[i][j][k] = a[i][j][k] + b[i][j][k];
		end = chrono::high_resolution_clock::now();
		elapsed = end - start;
		total_time += elapsed.count();
	}
	fout.open("time_record.txt", ios::app);
	fout << "k-i-j=" << total_time / TEST_TIMES << endl;
	fout.close();
	cout << "k-i-j=" << total_time / TEST_TIMES << endl;

	// k-j-i
	total_time = 0.0;
	for (int t = 0; t < TEST_TIMES; t++)
	{
		start = chrono::high_resolution_clock::now();
		for (int k = 0; k < N; k++)
			for (int j = 0; j < N; j++)
				for (int i = 0; i < N; i++)
					c[i][j][k] = a[i][j][k] + b[i][j][k];
		end = chrono::high_resolution_clock::now();
		elapsed = end - start;
		total_time += elapsed.count();
	}
	fout.open("time_record.txt", ios::app);
	fout << "k-j-i=" << total_time / TEST_TIMES << endl;
	fout.close();
	cout << "k-j-i=" << total_time / TEST_TIMES << endl;

    return 0;
}