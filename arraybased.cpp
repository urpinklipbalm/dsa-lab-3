#include <iostream>
using namespace std;

const int matrixrows = 3;
const int matrixcols = 3;

int main(){
    int matrix[matrixrows][matrixcols] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    int vector[matrixcols] = {1,2,3};
    int result[matrixrows] = {};

    for (int i = 0; i< matrixrows; i++){
        for (int j = 0; j< matrixcols; j++){
            result[i] += matrix[i][j] * vector[j];

        }
    }

    cout<< "-- resultant vector after array based vector \nmultiplication using static memory allocation:\n";
    for (int i = 0; i< matrixrows; i++){
        cout << result[i] <<" ";
    }
    cout<< endl;
    cout<< endl;
    return 0;
}