#include <iostream>
using namespace std;

int main(){
    int matrixrows = 3; 
    int matrixcolumns = 3;

    int *matrix = new int[matrixrows *matrixcolumns]; //1d array
    int *vector = new int[matrixcolumns];
    int *result = new int[matrixrows];

    // temp matrix to store the data
    int testmatrix[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    //copying values into the dynamic array

    for (int i = 0; i< matrixrows; i++){
        for (int j = 0; j< matrixcolumns; j++){
            matrix[i * matrixcolumns + j] = testmatrix[i][j]; //accessing 2d via 1d
        }
    }

    //init the vector to be multiplied, copying the values from tempvector to vector- dynamic
    int tempvector[3] = {1,2,3};
    for (int i = 0; i < matrixcolumns; i++){
        vector[i] = tempvector[i];
    }

    //matrix vector multiplication
    for (int i = 0; i < matrixrows; i++){
        for (int j = 0; j< matrixcolumns; j++){
            result[i] += matrix[i * matrixcolumns + j] * vector[j];
        }
    }

    // printing the result vector
    cout << "resultant vector: \n";
    for (int i = 0; i < matrixrows; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    cout << endl;

    //freeing allocated memory
    delete[] matrix;
    delete[] vector;
    delete[] result;

    return 0;
}