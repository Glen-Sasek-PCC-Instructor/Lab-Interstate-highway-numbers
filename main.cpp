


// Primary U.S. interstate highways are numbered 1-99. 
// Odd numbers (like the 5 or 95) go north/south, and 
// evens (like the 10 or 90) go east/west. 
//
// Auxiliary highways are numbered 100-999, 
// and service the primary highway indicated by the rightmost two digits. 
// I-405 services I-5
// I-290 services I-90 
// Note: 200 is not a valid auxiliary highway because 00 is not a valid primary highway number.


// Given a highway number, 

  
#include <iostream>

using namespace std;

int main() {
    // Given a highway number, 
    int n = 0;
    cin >> n;

    bool primary = true;
    bool valid = true;
    int auxiliaryIsServing = 0;
    bool even = true;

    valid = valid && n > 0;
    valid = valid && n < 1000;
    valid = valid && (n < 100 || n % 100 != 0);

    // indicate whether it is a primary or auxiliary highway.
    // If auxiliary, indicate what primary highway it serves.
    // Also indicate if the (primary) highway runs north/south or east/west.

    if(valid) {
        primary = n < 100;
        if(!primary) {
            auxiliaryIsServing = n % 100;
        }
        even = n % 2 == 0; 
    } 

    if(valid) {
        if(primary) {
            cout << "I-" << n << " is primary";
        } else {
            cout << "I-" << n << " is auxiliary, serving I-" << auxiliaryIsServing;
        }
        cout << ", going " << (even ? "east/west." : "north/south.") << endl;
    } else {
        cout << n << " is not a valid interstate highway number." << endl;
    }

    return 0;
}