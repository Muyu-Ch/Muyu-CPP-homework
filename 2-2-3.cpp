#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isInArray(char arr[], int size, char c) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == c) {
            return true;
        }
    }
    return false;
}

void removeFromArray(char arr[], int& size, char c) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] == c) {
            break;
        }
    }

    for (; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--; 
}

void addToArray(char arr[], int& size, char c) {
    arr[size++] = c;
}

int calculateWalkedAway(int beds, const string& sequence) {
    const int MAX_CUSTOMERS = 100;
    char current[MAX_CUSTOMERS];  
    char waiting[MAX_CUSTOMERS];  
    int currentSize = 0;          
    int waitingSize = 0;          
    int walkedAway = 0;           

    for (char c : sequence) {
        if (isInArray(current, currentSize, c)) {
            removeFromArray(current, currentSize, c);

            if (waitingSize > 0) {
                char next = waiting[0];
                removeFromArray(waiting, waitingSize, next);
                addToArray(current, currentSize, next);
            }
        }
        else if (isInArray(waiting, waitingSize, c)) {
            removeFromArray(waiting, waitingSize, c);
            walkedAway++;
        }
        else {
            if (currentSize < beds) {
                addToArray(current, currentSize, c);
            }
            else {
                addToArray(waiting, waitingSize, c);
            }
        }
    }

    return walkedAway;
}

int main() {
    int beds;
    string sequence;
    ifstream inFile("in.txt");

    inFile >> beds >> sequence;
    inFile.close();

    int result = calculateWalkedAway(beds, sequence);

    if (result == 0) {
        cout << "All customers tanned successfully." << endl;
    }
    else {
        cout << result << " customer(s) walked away." << endl;
    }

    return 0;
}
