#include <thread>
#include <iostream>
#include <random>
#include <fstream>
#include <chrono>
using namespace std ;
using namespace chrono;
constexpr int MAX_SIZE = 1000;
/*
This is the function called by the thread
*/
void hello_world(vector<int> numbers)
{
}


int main(int argc, char **argv)
{
    auto start = system_clock::now();
    auto matrix = new int[MAX_SIZE][MAX_SIZE];
    int vector[MAX_SIZE];
    int result[MAX_SIZE];

    // init matrix
    for (int row = 0; row < MAX_SIZE; row++)
    {
        for (int col = 0; col < MAX_SIZE; col++)
        {
            matrix[row][col] = 1;
        }
    }

    for (int i = 0; i < MAX_SIZE; i++)
    {
        vector[i] = 1;
    }

    for (int i = 0; i < MAX_SIZE; i++)
    {
        result[i] = 0;
    }


    
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            result[i] += (matrix[i][j] * vector[j]);
        }
    }

    auto end = system_clock::now();
    auto total = end - start;
    auto total_ms = duration_cast<milliseconds>(total).count();
    
    cout << total_ms << endl;
    delete[] matrix;
    return 0;
}