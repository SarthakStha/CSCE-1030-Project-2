#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

//global variable declaration
enum options {DisplayLeft = 1, DisplayRight = 2, Guess = 3, Change = 4, Exit = 5};

void header();

string getName();

void genShowMatrix(int matrix[5][5], int rows , int column);

void genHideMatrix(int hiddenMatrix[5][5], int lowerBound, int upperBound,  int rows, int column);

void initialize(int hiddenMatrix[5][5], int matrix[5][5], int &lowerBound, int &upperBound, int displayedLowerBound, int displayedUpperBound);

void guess(int hiddenMatrix[5][5], int matrix[5][5], int pointGain, int pointLoss, int &userScore ,int rows, int column);

void eliminate(int matrix[5][5], int eliminateRow, int eliminateColumn, int rows, int column);

bool allZeros(int matrix[5][5], int rows, int column);

void showMatrix(int matirix[][5], int rows, int column);

int main(){

    //options menu
    int userChoice;
    options choices;

    //user's name and score variable
    string userName;
    int userScore = 100;

    // score gain or loss
    int pointGain = 5;
    int pointLoss = 5;  

    // randon no generation range variable
    srand(time(0));
    int displayedLowerBound = -1;
    int lowerBound = 0;
    int displayedUpperBound = -1;
    int upperBound = 0;

    // displayed and hidden array specification
    const int rows = 5;
    const int column = 5;
    int matrix[rows][column];
    int hiddenMatrix[rows][column];

    // condition to quit
    char playAgain = 'Y';

    header();

    initialize(hiddenMatrix, matrix, lowerBound, upperBound, displayedLowerBound, displayedUpperBound);

    userName = getName(); 

    cout << "Welcome to the game " << userName << "." << endl;

    do{
        //upperbound and lower bound display for testing only
        cout << displayedLowerBound << "\t\t" << displayedUpperBound << endl;

        //user choice prompt
        cout << "1. Display Left Number" << endl;
        cout << "2. Display Right Number" << endl;
        cout << "3. Guess a number in between" << endl;
        cout << "4. Change Numbers" << endl;
        cout << "5. Exit" << endl;

        cout << "What would you like to do? ";
        cin  >> userChoice;

        // changing options datatype to use switch case
        choices = static_cast<options>(userChoice);

        switch (choices){
            case DisplayLeft:

                if(displayedUpperBound == -1){                   
                        
                    displayedLowerBound = lowerBound;
                    pointGain = 1;
                    pointLoss = 10;                           
                    //cout << displayedLowerBound << endl;                          
                    cout << "Now, you will gain " << pointGain << "  points for guessing correctly and lose " << pointLoss << " for guessing incorrectly" << endl;
                        
                } else{
                    cout << "You have already displayed the right boundary, you cannot display both." << endl;
                };

        break;

        case DisplayRight:

            if(displayedLowerBound == -1){                   
                        
                    displayedUpperBound = upperBound;
                    pointGain = 1;
                    pointLoss = 10; 
                    //cout << displayedUpperBound << endl;                          
                    cout << "Now, you will gain " << pointGain << "  points for guessing correctly and lose " << pointLoss << " for guessing incorrectly" << endl;
                        
                } else{
                    cout << "You have already displayed the left boundary, you cannot display both." << endl;
                };
        break;

        case Guess:
            guess(hiddenMatrix, matrix, pointGain, pointLoss, userScore,  rows, column);

            // grid all zero check
            if (allZeros(matrix, rows, column) == true){
                cout << "Do you want to play another gamne?Y/N:";
                cin  >> playAgain;
                playAgain = toupper(playAgain);
            }else if(userScore < 0){ //2nd condition for game over( userScore < 0 ) check
                    cout << "your are out of points." << endl;
                    playAgain = 'N';
            }
            
        break;

        case Change:

            initialize(hiddenMatrix, matrix, lowerBound, upperBound, displayedLowerBound, displayedUpperBound);
            userScore -= 1;
            cout << "You lose 1 point for chosing to reset the board.\nYour remaining points = " << userScore << endl;
        
        break;

        case Exit:// condition to quit
            playAgain = 'N'; 
        break;
    
        // incase user inputs an invalid case
        default :
            cout <<"The choice you have selected in invalid try again.\n";
        break;
    }

    } while (playAgain == 'Y');
    
    cout << "Bye " << userName << "!!!" << endl;
    cout << "Your final score = " << userScore;


    return 0;

}

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

//generates the shown matrix in a blank stae of 5x5 matrix -1 values 
void genShowMatrix(int matrix[5][5], int rows =5, int column =5){

    for (int i = 0; i < rows; i++){
        for(int j = 0; j < column; j++){
            matrix[i][j] = -1;
        }
    }
}

//generates a 5x5 matrix with random value from within passed lowerbound and upperbound
void genHideMatrix(int hiddenMatrix[5][5],int lowerBound, int upperBound, int rows = 5, int column = 5){
    
    srand((time(0)));
    // const int rows = 5;
    // const int column = 5;

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < column; j++){
            hiddenMatrix[i][j] = (rand()%(1 + upperBound - lowerBound)) + lowerBound;
            cout << hiddenMatrix[i][j] << "\t";
        }
        cout << endl;    
    }
}

//creates a new lowerbound and upper bound & passes it to genHideMatrix and call genShowMatrix
void initialize(int hiddenMatrix[5][5], int matrix[5][5], int &lowerBound, int &upperBound, int displayedLowerBound = -1, int displayedUpperBound = -1){

    //generating upper bound and lower bound for guess number generation range
    lowerBound = (rand()%(100) + 100);
    upperBound = (rand()%(100) + 200);

    //cout << displayedLowerBound << "\t\t" << displayedUpperBound << endl;
    
    cout << lowerBound << "\t\t" << upperBound << endl;

    genShowMatrix(matrix);
    genHideMatrix(hiddenMatrix, lowerBound, upperBound);

}
 
 // takes the user guess and checks if the guess mataches with a value of the hidden matrix, call eliminate() if values match
void guess(int hiddenMatrix[5][5], int matrix[5][5], int pointGain, int pointLoss, int &userScore ,int rows = 5, int column = 5){
    
    int userGuess;

    showMatrix(matrix, rows, column);

    cout << "Enter your guess: ";
    cin  >> userGuess;
    bool found = false;

    for(int i = 0; i < rows; i++){
        for (int j = 0; j < column; j++)
        {
            if (userGuess == hiddenMatrix[i][j]){
                found = true;
                userScore += pointGain;
                cout << "You guessed correctly. You gain " << pointGain << " points" << endl;
                cout << "Your remaining points = " << userScore << endl;
                eliminate(matrix, i, j, rows, column);
                break;
            }
        }
    }
    if ( found == false){
        userScore -= pointLoss;
        cout << "You guessed incorrectly. You lose " << pointLoss << " points" << endl;
        cout << "Your remaining points = " << userScore << endl;
    }


};

//takes the position where the values match and replace all the values in the row & column fo the value with 0
void eliminate(int matrix[5][5], int eliminateRow, int eliminateColumn, int rows, int column){

    for (int i = 0; i < rows; i++){
       matrix[i][eliminateColumn] = 0; 
    }
    for (int j = 0; j < column; j++){
        matrix[eliminateRow][j] = 0;    
    }

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < column; j++){
            cout << matrix[i][j] << "\t";
        }
        cout << endl;    
    }
}

// check for the condition to prompt the user to end the game. check weather all the values of the shown grid is 0
//returns true if all values are 0 else returns false
bool allZeros(int matrix[][5], int rows, int column){

    bool valid = true;

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < column; j++){
            if (matrix[i][j] != 0){
                valid = false;
            }
            
        }
         
    }
    return valid;
}

//return all the value of a matrix that is passed as its parameter
void showMatrix(int matirix[][5], int rows, int column){

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < column; j++){
        
            cout << matirix[i][j] << "\t";
            
        }
        cout << endl;
    }

}