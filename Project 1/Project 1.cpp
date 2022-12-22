#include "Clock.h"
#include "Validator.h"
#include <iostream>
#include <string>
#include <Windows.h>


using namespace std;

//Outputs a message if the value is not within the range of min - max.
//@param validator - requires a validator object to be created. 
void handleInvalidInput(Validator validator) {

        cout << "Entered value is not valid. Valid range is [" << validator.getMinValue() << " - " << validator.getMaxValue() << "]" << endl;
    }

//Displays the main menu.
void displayMainMenu() {
    cout << "Main Menu" << endl;
    cout << "1 - Display Clock" << endl;
    cout << "2 - Update Clock" << endl;
    cout << "3 - Exit Program" << endl;
    cout << endl;
}

//Displays the update clock menu.
void displayUpdateClockMenu() {
    cout << endl;
    cout << "Update Clock" << endl;
    cout << "1 - Add One Hour" << endl;
    cout << "2 - Add One Minute" << endl;
    cout << "3 - Add One Second" << endl; 
    cout << endl;
}

//Displays a clock in both 12 and 24 hour formats.
//@param clock - requires a clock object to be created.
void displayClock(Clock clock) {
    cout << endl;
    cout << "12-HOUR CLOCK  " << clock.get12HourFormat() << endl;
    cout << "24-HOUR CLOCK  " << clock.get24HourFormat() << endl;
    cout << endl;
}

int main() {
    Clock clock(0, 0, 0);

    enum MainMenuOptions {DISPLAY_CLOCK = 1, UPDATE_CLOCK = 2, EXIT_PROGRAM = 3};
    enum UpdatMenuOptions {ADD_ONE_HOUR = 1, ADD_ONE_MINUTE = 2, ADD_ONE_SECOND = 3};

    int userMenuChoice;
    const int MIN_MAIN_MENU_OPTION = 1;
    const int MAX_MAIN_MENU_OPTION = 3;
    const int MIN_UPDATE_MENU_OPTION = 1;
    const int MAX_UPDATE_MENU_OPTION = 3;
    
    Validator mainMenuChoiceValidator(MIN_MAIN_MENU_OPTION, MAX_MAIN_MENU_OPTION);
    Validator updateMenuChoiceValidator(MIN_UPDATE_MENU_OPTION, MAX_UPDATE_MENU_OPTION);
    
    do {
        system("cls");
        displayClock(clock);
        displayMainMenu();

        cout << "Enter Selection: " << endl;
        cin >> userMenuChoice;

        // Validating userMenuChoice
        while (!mainMenuChoiceValidator.isValid(userMenuChoice)) {
            handleInvalidInput(mainMenuChoiceValidator);
            cout << "Enter Selection: " << endl;
            cin >> userMenuChoice;
        }

        if (userMenuChoice == DISPLAY_CLOCK) {
            clock.addSecond();
        }
        else if (userMenuChoice == UPDATE_CLOCK) {
            displayUpdateClockMenu();

            cout << "Enter Selection: " << endl;
            cin >> userMenuChoice;

            // Validating userMenuChoice
            while (!updateMenuChoiceValidator.isValid(userMenuChoice)) {
                handleInvalidInput(updateMenuChoiceValidator);
                cout << "Enter Selection: " << endl;
                cin >> userMenuChoice;
            }

            if (userMenuChoice == ADD_ONE_HOUR) {
                clock.addHour();
            }
            else if (userMenuChoice == ADD_ONE_MINUTE) {
                clock.addMinute();
            }
            else if (userMenuChoice == ADD_ONE_SECOND) {
                clock.addSecond();
            }

           userMenuChoice = -1; // Setting input to -1. If user selects add one second in update clock menu it will close the program. 
        }

    } while (userMenuChoice != EXIT_PROGRAM);

    return 0;
}