#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

char toup(char c) {
    if ((c >= 'a') and (c <= 'z')) {
        return c - ('a' - 'A');
    }
}

// Функция для ввода одной матрицы
void inputMatrix(vector<vector<int>>& matrix, int m, int n) {
    matrix.resize(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
}

// Функция для записи матриц в файл
void writeMatricesToFile(const string& filename, const vector<vector<vector<int>>>& matrices) {
    ofstream out(filename);
    for (const auto& matrix : matrices) {
        for (const auto& row : matrix) {
            for (int val : row) {
                out << val << " ";
            }
            out << "\n";
        }
        out << "\n";
    }
}

// Функция для чтения матриц из файла
void readMatricesFromFile(const string& filename, vector<vector<vector<int>>>& matrices) {
    ifstream in(filename);
    matrices.clear();
    vector<vector<int>> currentMatrix;
    string line;

    while (getline(in, line)) {
        if (line.empty()) {
            if (!currentMatrix.empty()) {
                matrices.push_back(currentMatrix);
                currentMatrix.clear();
            }
            continue;
        }

        vector<int> row;
        int val;
        istringstream iss(line);
        while (iss >> val) {
            row.push_back(val);
        }
        currentMatrix.push_back(row);
    }

    if (!currentMatrix.empty()) {
        matrices.push_back(currentMatrix);
    }
}

// Функция для вывода матриц на экран
void printMatrices(const vector<vector<vector<int>>>& matrices) {
    for (size_t i = 0; i < matrices.size(); ++i) {
        std::cout << "Матрица " << i + 1 << ":\n";
        for (const auto& row : matrices[i]) {
            for (int val : row) {
                std::cout << val << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
}


