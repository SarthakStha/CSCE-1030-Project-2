#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// enum choices {displayLeft = 1, displayRight = 2, guess = 3, reset = 4, exit = 5};

// prints the student information header
void header(){

    cout << "+----------------------------------------------------+" << endl;
    cout << "| Computer Science and Engineering                   |" << endl;
    cout << "| CSCE 1030 - Computer Science I                     |" << endl;
    cout << "| Milan Chaulagain mc1623 MilanChaulagain@my.unt.edu |" << endl;
    cout << "| Prasuna Khadka pk0777 prasunakhadka@my.unt.edu     |" << endl;
    cout << "| Tarang Shiwakoti ts1366 TarangShiwakoti@my.unt.edu |" << endl;
    cout << "| Sarthak Shrestha ss3926 sarthakshrestha@my.unt.edu |" << endl;
    cout << "+----------------------------------------------------+" << endl;

}

//asks for a string userName checks if it is valid, returns the userName with their initials capitalized and everthing else in lower case
string getName(){

    bool valid = true;
    string userName;
    string capitalizedString;
    string temp;
    
    // valid check: checks if the userName consists of anything except alphabets and spaces
    do{

        cout << "Please enter your name (must include only alpahbets): ";
        getline(cin, userName );

        for(int i = 0; i < userName.size(); i++){
            if((isalpha(userName.at(i)) == false) && (userName.at(i) != ' ')){
                valid = false;
                cout << "Your name can only include alphabets and spaces. Try again." << endl;
                break;
            }
        }

    }while(valid == false);

    // capitalizes the initials and changes everthing else to lowercase.
    for(int i = 0; i < userName.size(); i++){

        if ((i == 0))
        {
            temp = toupper(userName.at(0));
            capitalizedString += temp;
        }else if((userName.at(i-1) == ' ')){
            temp = toupper(userName.at(i));
            capitalizedString += temp;
        }else{
            temp = tolower(userName.at(i));
            capitalizedString += temp;
        }
        
    }

    return capitalizedString;

}

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
void genHideMatrix(int lowerBound, int upperBound){

    srand((time(0)));
    const int rows = 5;
    const int column = 5;

    int hiddenMatrix[rows][column]; 

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < column; j++){
            hiddenMatrix[i][j] = (rand()%(1 + upperBound - lowerBound)) + lowerBound;
            cout << hiddenMatrix[i][j] << "\t";
        }
        cout << endl;
        
    }
    

}

//
void initialize(int displayedLowerBound = -1, int displayedUpperBound = -1){

    //generating upper bound and lower bound for guess number generation range
    int lowerBound = (rand()%(100) + 100);
    int upperBound = (rand()%(100) + 200);

    cout << displayedLowerBound << "\t\t" << displayedUpperBound << endl;
    
    cout << lowerBound << "\t\t" << upperBound << endl;

    genHideMatrix(lowerBound, upperBound);


}

int main(){

    srand(time(0));
    int userScore = 100;
    int displayedLowerBound;
    int displayedUpperBound;

    string userName;

    const int rows = 5;
    const int column = 5;
    int matrix[rows][column];

    genShowMatrix(matrix, rows, column);

    initialize();




    //header();
    //getName();
    //cout << "Welcome to the game " + username + ".";

    //genShowMatrix();

    //genHideMatrix(100,200);

    return 0;

}

