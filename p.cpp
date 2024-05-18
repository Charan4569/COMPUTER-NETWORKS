#include <iostream>
#include <string>
using namespace std;

int parity_check(string data) {
    int parity = 0;
    for (char bit : data) {
        if (bit == '1') {
            parity ^= 1;
        }
    }
    return parity;
}

string correct_data(string data, int error_index) {
    data[error_index] = (data[error_index] == '0') ? '1' : '0';
    return data;
}

int main() {
    string data = "1000001";
    int error_index = 2;

    int error_detected = parity_check(data);
    if (error_detected) {
        cout << "Error Detected at index " << error_index << endl;
        cout << "Corrected Data: " << correct_data(data, error_index) << endl;
    } else {
        cout << "No Error Detected" << endl;
    }

    return 0;
}
