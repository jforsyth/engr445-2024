#include <iostream>
#include "App.h"
using namespace std;

int main() {
    cout << "Booting up your Program...Calling init() function" << endl;

    bool init_success = app_init();

    if (!init_success) {
        cout << "Initialization failed. Program will not proceed. Exiting." << endl;
        return -1;
    }

    cout << "Initialization success. Will now proceed to called your process_action() function repeatedly.." << endl;
    int LOOP_ACTION_LIMIT = 1000000;
    for (int i = 0; i < LOOP_ACTION_LIMIT; i++) {
        bool success = app_process_action();

        if (!success) {
            cout << "App action exiting..." << endl;
            return -1;
        }
    }

    cout << "This should never happen. main() has called your code " << LOOP_ACTION_LIMIT << " times." << endl;

    return -1;
}