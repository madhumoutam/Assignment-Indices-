#include <iostream>
#include <vector>
using namespace std;

int main() {
    int target;
    vector<int> numbers;

    cout << "Enter numbers or \"N\" to end entering: ";
    while (1) {
        int num;
        if (!(cin >> num))
            break;
        numbers.push_back(num);
    }
    
    cout << "Enter target: ";
    cin.clear();
    cin.ignore(10000, '\n');
    cin >> target;

    int index = 0, firstIndex = -1, secondIndex = -1;
    bool found = false;

    for (; index < numbers.size() - 1; index++) {
        if (numbers[index] == target) {
            firstIndex = index;
            found = true;
            break;
        }
        if ((numbers[index] + numbers[index + 1]) == target) {
            firstIndex = index;
            secondIndex = index + 1;
            found = true;
            break;
        }
    }

    if (numbers[index] == target) {
        firstIndex = index;
        found = true;
    }

    if (found) {
        if (firstIndex >= 0 && secondIndex == -1)
            cout << "[" << firstIndex << "]" << endl;
        else
            cout << "[" << firstIndex << "," << secondIndex << "]" << endl;
    } else {
        cout << "none" << endl;
    }

    return 0;
}

