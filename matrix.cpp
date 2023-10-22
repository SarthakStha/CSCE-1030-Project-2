#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

void genShowMatrix(){

    const int rows = 5;
    const int column = 5;
    int matrix[rows][column];


    for (int i = 0; i < rows; i++){

        for(int j = 0; j < column; j++){
            matrix[i][j] = 0;
            cout << matrix[i][j] << "\t";
        }
           cout << endl;
    }

}


int main(){

    genShowMatrix();

    return 0;

}
