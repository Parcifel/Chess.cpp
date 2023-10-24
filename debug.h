#ifndef DEBUG_H
#define DEBUG_H

#include "constants.h"

#include <iostream>

using namespace std;

void dout(auto& message) {
    if (DEBUG) {
        cout << message << endl;
    }
}

void derr(auto& message) {
    if (DEBUG) {
        cerr << message << endl;
    }
}


#endif