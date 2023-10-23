#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

//
void genShowMatrix(int matrix[5][5], int rows , int column){

    // const int rows = 5;
    // const int column = 5;
    // int matrix[rows][column];

    for (int i = 0; i < rows; i++){
        for(int j = 0; j < column; j++){
            matrix[i][j] = -1;
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

//
void genHideMatrix(int hiddenMatrix[5][5],int lowerBound = 5, int upperBound =5){

    
    srand((time(0)));
    const int rows = 5;
    const int column = 5;
/*
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < column; j++){
            hiddenMatrix[i][j] = (rand()%(1 + upperBound - lowerBound)) + lowerBound;
            cout << hiddenMatrix[i][j] << "\t";
        }
        cout << endl;
        
    }
    
*/

}

//
void initialize(int hiddenMatrix[5][5],int displayedLowerBound = -1, int displayedUpperBound = -1){

    //generating upper bound and lower bound for guess number generation range
    int lowerBound = (rand()%(100) + 100);
    //int lowerBound = (rand()%(100) + 100);
    int upperBound = (rand()%(100) + 200);
    //int upperBound = (rand()%(100) + 200);

    cout << displayedLowerBound << "\t\t" << displayedUpperBound << endl;
    
    cout << lowerBound << "\t\t" << upperBound << endl;

    genHideMatrix(hiddenMatrix ,lowerBound, upperBound);


}

int main(){

    srand(time(0));
    int displayedLowerBound = -1;
    int lowerBound = 0;
    int displayedUpperBound = -1;
    int upperBound = 0;

    const int rows = 5;
    const int column = 5;
    int matrix[rows][column];
    int hiddenMatrix[rows][column];
    
    initialize(hiddenMatrix);

/*
    cout << endl;

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < column; j++){
            cout << hiddenMatrix[i][j] << "\t";
        }
        cout << endl;
        
    }
*/    

    displayedLowerBound = lowerBound;
    cout << displayedLowerBound << endl; 

    return 0;

}
