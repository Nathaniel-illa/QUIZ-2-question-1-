#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

const int N = 3; // Number of rows in the input file
const int M = 5; // Number of columns in the input file

// Function to implement bubble sort
void bubbleSort(vector<int>& vec) {
    int n = vec.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (vec[j] > vec[j + 1]) {
                swap(vec[j], vec[j + 1]);
            }
        }
    }
}

void reform(string filename) {
    // Open the input file
    ifstream infile(filename);
    if (!infile) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    // Initialize a 2D array to hold the data
    int data[N][M];

    // Read the data from the file into the 2D array
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            infile >> data[i][j];
        }
    }
    infile.close();

    // Create a 2D vector to hold the transposed data
    vector<vector<int>> transposed(M, vector<int>(N));

    // Transpose the data
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            transposed[j][i] = data[i][j];
        }
    }

    // Open the output file
    ofstream outfile("trans.data");
    if (!outfile) {
        cerr << "Error creating file: trans.data" << endl;
        return;
    }

    // Write the transposed data to the file
    for (const auto& row : transposed) {
        for (size_t i = 0; i < row.size(); ++i) {
            outfile << row[i];
            if (i < row.size() - 1) {
                outfile << " "; // Separate values with a space
            }
        }
        outfile << endl;
    }
    outfile.close();
}

#endif // MAIN_HPP