#include <iostream>
using namespace std;

// --- Starter Code ---
const int CAPACITY = 20;

struct ArrayList {
    int data[CAPACITY];
    int size = 0;
};

// Global variables
ArrayList list;
int *ptr = list.data; 

int minimum, maximum, median, closestValue, closestPosition, sum = 0;
double generalAverage, specialAverage, averageDifference, finalScore;


// 1. Insert at End
bool insertEnd(ArrayList &list, int value) {
    if (list.size >= CAPACITY) return false;
    list.data[list.size] = value;
    list.size++;
    return true;
}

// 2. Insert at Beginning (Shifts elements to the right)
bool insertAtBeginning(ArrayList &list, int value) {
    if (list.size >= CAPACITY) return false;
    // Start from the end and move everything one step right
    for (int i = list.size; i > 0; i--) {
        list.data[i] = list.data[i - 1];
    }
    list.data[0] = value;
    list.size++;
    return true;
}

// 3. Delete at Position (Shifts elements to the left)
bool deleteAtPosition(ArrayList &list, int position) {
    if (position < 0 || position >= list.size) return false;
    // Start from the position and move everything one step left
    for (int i = position; i < list.size - 1; i++) {
        list.data[i] = list.data[i + 1];
    }
    list.size--;
    return true;
}

// 4. Display List
void displayList(const ArrayList &list) {
    for (int i = 0; i < list.size; i++) {
        cout << list.data[i] << " ";
    }
    cout << endl;
}


int main() {
    

    
    cout << "--- Part A ---" << endl;

 

    insertEnd(list, 18);
    insertEnd(list, 7);
    insertEnd(list, 45);
    insertEnd(list, 11);
    insertEnd(list, 36);
    insertEnd(list, 47);
    insertEnd(list, 21);
    insertEnd(list, 13);
    insertEnd(list, 29);

    cout << "Initial ArrayList:" << endl;
    displayList(list);
    cout << endl;

    
    
    cout << "--- Part B ---" << endl;
    
    ptr = list.data; // Reset pointer to start
    
    
    minimum = *ptr;
    maximum = *ptr;
    sum = 0;
    
    int *minPtr = list.data; 
    int *maxPtr = list.data; 

    for (int i = 0; i < list.size; i++) {
        int currentValue = *ptr; // Get value from pointer
        
        sum = sum + currentValue;
        
        if (currentValue < minimum) {
            minimum = currentValue;
            minPtr = ptr; // Save address of new minimum
        }
        
        if (currentValue > maximum) {
            maximum = currentValue;
            maxPtr = ptr; // Save address of new maximum
        }
        
        ptr++; // Move pointer to next element
    }

    cout << "Minimum Value: " << minimum << endl;
    cout << "Maximum Value: " << maximum << endl;
    cout << "Sum: " << sum << endl;

    
    cout << "--- Part C ---" << endl;
    
    // Copy to temporary array
    int tempArr[CAPACITY];
    for (int i = 0; i < list.size; i++) {
        tempArr[i] = list.data[i];
    }

    // Simple Bubble Sort
    for (int i = 0; i < list.size - 1; i++) {
        for (int j = 0; j < list.size - i - 1; j++) {
            if (tempArr[j] > tempArr[j + 1]) {
                int temp = tempArr[j];
                tempArr[j] = tempArr[j + 1];
                tempArr[j + 1] = temp;
            }
        }
    }

    // The middle element of 9 items is at index 4
    median = tempArr[list.size / 2];
    
    // Find where this median value is in the original list and save its pointer
    int *medianPtr = list.data;
    for (int i = 0; i < list.size; i++) {
        if (list.data[i] == median) {
            medianPtr = &list.data[i];
            break;
        }
    }
    
    cout << "Median Value: " << median << endl;

    
    cout << "--- Part D ---" << endl;
    
    // 1. General Average
    generalAverage = (double)sum / list.size;
    cout << "General Average: " << generalAverage << endl;

    // 2. Special Average (using saved pointers)
    specialAverage = (double)(*minPtr + *medianPtr + *maxPtr) / 3.0;
    cout << "Special Average: " << specialAverage << endl;

    // 3. Find Closest Value
    ptr = list.data; // Reset pointer to start
    int *closestPtr = list.data;
    double smallestDistance = 1000000.0; // Start with a very large number

    for (int i = 0; i < list.size; i++) {
        double distance;
        
        // Manual absolute value calculation (no cmath library needed)
        if (*ptr > specialAverage) {
            distance = *ptr - specialAverage;
        } else {
            distance = specialAverage - *ptr;
        }

        // If this distance is smaller than the previous smallest, update it
        if (distance < smallestDistance) {
            smallestDistance = distance;
            closestPtr = ptr;
        }
        
        ptr++; // Move pointer
    }

    closestValue = *closestPtr;
    // Pointer math to find the position (address difference)
    closestPosition = closestPtr - list.data; 

    cout << "Closest Value: " << closestValue << endl;
    cout << "Position of Closest Value: " << closestPosition << endl;
    cout << "--- Part E ---" << endl;
    
    // 1. Calculations
    if (generalAverage > specialAverage) {
        averageDifference = generalAverage - specialAverage;
    } else {
        averageDifference = specialAverage - generalAverage;
    }
    
    // Final Score formula
    double diff1, diff2;
    if (*closestPtr > generalAverage) diff1 = *closestPtr - generalAverage;
    else diff1 = generalAverage - *closestPtr;
    
    if (*closestPtr > specialAverage) diff2 = *closestPtr - specialAverage;
    else diff2 = specialAverage - *closestPtr;
    
    finalScore = diff1 + diff2 + averageDifference;

    cout << "Difference Between Averages: " << averageDifference << endl;
    cout << "Final Score: " << finalScore << endl;

    // 2. Delete the closest value
    closestPosition = closestPtr - list.data; // Recalculate position just to be safe
    deleteAtPosition(list, closestPosition);
    
    cout << "ArrayList After Deletion:   ";
    displayList(list);

    // 3. Insert rounded Special Average at beginning
    // Adding 0.5 then casting to int does the rounding for positive numbers
    int roundedAvg = (int)(specialAverage + 0.5); 
    insertAtBeginning(list, roundedAvg);

    cout << "Final ArrayList After Insertion:  ";
    displayList(list);

    return 0;
}