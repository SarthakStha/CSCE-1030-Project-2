#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

enum options {DisplayLeft = 1, DisplayRight = 2, Guess = 3, Change = 4, Exit = 5};

void header();

string getName();

void genShowMatrix(int matrix[5][5], int rows , int column);

void genHideMatrix(int hiddenMatrix[5][5], int lowerBound, int upperBound,  int rows, int column);

void initialize(int hiddenMatrix[5][5], int matrix[5][5], int &lowerBound, int &upperBound, int displayedLowerBound, int displayedUpperBound);

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

    header();

    initialize(hiddenMatrix, matrix, lowerBound, upperBound, displayedLowerBound, displayedUpperBound);

    userName = getName(); 

    cout << "Welcome to the game " << userName << "." << endl;

//    do{
        //upperbound and lower bound display
        cout << displayedLowerBound << "\t\t" << displayedUpperBound << endl;

        //user choice prompt
        cout << "1. Display Left Number" << endl;
        cout << "2. Display Right Number" << endl;
        cout << "3. Guess a number in between" << endl;
        cout << "4. Change Numbers" << endl;
        cout << "5. Exit" << endl;

        cout << "What would you like to do? ";
        cin  >> userChoice;

        choices = static_cast<options>(userChoice);


        switch (choices)
        {
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
        /* code */
        break;

        case Change:
            //initialize(hiddenMatrix, matrix);
            userScore -= 1;
        break;

        case Exit:
            /* code */
        break;
    
        default :

        break;
    }

//    } while ();
    
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
            //cout << hiddenMatrix[i][j] << "\t";
        }
        //cout << endl;    
    }
}

//
void initialize(int hiddenMatrix[5][5], int matrix[5][5], int &lowerBound, int &upperBound, int displayedLowerBound = -1, int displayedUpperBound = -1){

    //generating upper bound and lower bound for guess number generation range
    lowerBound = (rand()%(100) + 100);
    upperBound = (rand()%(100) + 200);

    //cout << displayedLowerBound << "\t\t" << displayedUpperBound << endl;
    
    cout << lowerBound << "\t\t" << upperBound << endl;

    genShowMatrix(matrix);
    genHideMatrix(hiddenMatrix, lowerBound, upperBound);

}
 
 //
void guess(int hiddenMatrix[5][5], int pointGain, int pointLoss, int rows = 5, int column = 5){
    
    int userGuess;

    cout << "Enter your guess: ";
    cin  >> userGuess;

    for(int i = 0; i < rows; i++){
        for (int j = 0; j < column; j++)
        {
            if (userGuess == hiddenMatrix[i][j]){
                
            }else{
                
                cout << "You guessed incorrectly. You lose ";
            }
            
        }
        


    }

};

