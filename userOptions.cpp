#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main (){

    enum options {displayLeft = 1, displayRight = 2, guess = 3, change = 4, exit = 5};
    int userChoice;
    options choices;

    int displayedLowerBound = -1;
    int displayedUpperBound = -1;
    int lowerBound = 0;
    int displayedUpper = 0;


    //upperbound and lower bound display
    cout << displayedLowerBound << "     " << displayedUpperBound << endl;
    //user choice prompt
    cout << "1. Display Left Number" << endl;
    cout << "2. Display Right Number" << endl;
    cout << "3. Guess a number in between" << endl;
    cout << "4. Change Numbers" << endl;
    cout << "5. Exit" << endl;

    cin >> userChoice;
    choices = static_cast<options>(userChoice);

    switch(choices){
        case displayLeft:
            if(displayedLowerBound != -1){
                cout << "You have already displayed the right boundary, you cannot display both." << endl;
            } else{
                displayedLowerBound = lowerBound;
            }
        break;

        case displayRight:
        /* code */
        break;

        case guess:
        /* code */
        break;

        case change:
        /* code */
        break;

        case exit:
        /* code */
        break;
    
        default :

        break;
    }

        return 0;

}