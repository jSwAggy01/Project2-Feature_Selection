/*
Sources:
   Reading columns of txt file: https://cplusplus.com/forum/beginner/269288/ 
   Convert string to double: https://www.geeksforgeeks.org/cpp-program-for-string-to-double-conversion/#:~:text=1.-,Using%20stod(),%3A%3Asize_t*%20pos%20%3D%200)%3B
   Struct in vector: https://stackoverflow.com/questions/8067338/vector-of-structs-initialization
   Selection sort algorithm: https://www.geeksforgeeks.org/selection-sort/
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

/* Object to store our class and feature data */
struct data {
    int classification = 0; // Either class 1 or 2
    int feature = 0;        // Feature's data
};

/* Function declarations: */
void nearestNeighbor(double);
void forwardSelection();
void backwardElimination();
void openFile(string);
void swap(int,int);
void selectionSortByFeature(vector<data>,int);
void printVector(vector<data>, int);
vector<data> metaData;

/* Main driver program: */

int main() {
    string fileName = "";
    int algorithmNumber = 0;

    cout << "Please type in the file name you would like to test: ";
    cin >> fileName;
    openFile(fileName);
    cout << '\n';

    cout << "Please type the number of the algorithm you would like to run: \n\n 1) Forward selection \n 2) Backward elimination \n\n";

    while (cin >> algorithmNumber) {
        if (algorithmNumber == 1) {
            cout << "\nYou have chosen forward selection.\n\n";
            forwardSelection();
            break;
        }
        else if (algorithmNumber == 2) {
            cout << "\nYou have chosen backward elimination.\n\n";
            backwardElimination();
            break;
        }
        else {
            cout << "\nPlease choose a valid number: ";
        }  
    }
   return 0;
}

// Compile with: g++ main.cpp -o main

/* Function definitions: */

void nearestNeighbor(double unkownClass_Instance) {
    // Push back unkown instance's feature
    metaData.push_back(data());
    metaData.back().feature = unkownClass_Instance;

    // Organize to find nearest instances
    selectionSortByFeature(metaData, metaData.size());
    double closestClass1_Instance;
    double closestClass2_Instance;
    /* TODO */
    

    // Nearest neighbor algorithm
    if ((unkownClass_Instance - closestClass1_Instance) < (unkownClass_Instance - closestClass2_Instance)) {
        metaData.back().classification = 1;
    }
    else {
        metaData.back().classification = 2;
    }
}

void forwardSelection() {/*
    for i <- 1 to n
        nearestNeighbor(i)
        calc accuracy
        for j <- i + 1 to n
            nearestNeighbor(i,j)
            calc accuracy
            for k <- j + 1 to n
                nearestNeighbor(i,j,k)
                calc accuracy
    *All the way until 64 loops
    *Note: Not all loops will be used depending on the data set
*/}

void backwardElimination() {/*
    vector<int> features

    for i <- 1 to n
        features.pushback(i)
    
    nearestNeighbor(*all features)

    for i <- 1 to n
        nearestNeighbor(*all features excluding ith-feature)
        calc accuracy
    choose subset with highest accuracy
    *Repeat this process until you get to one feature
    *Choose the best subset of features out of all of them
*/}

void openFile(string fileName) {
    vector<string> classes;
    vector<string> features;
    double c1;
    double c2;

    // Open the file
    ifstream inFile(fileName);
   
    // Error if opened incorrectly
    if (!inFile) {
        cout << "Cannot open file\n";
        exit(1);
    }

    // Get the 1st two columns into a string
    string line, col1, col2;
    while (getline(inFile, line)) {
        stringstream(line) >> col1 >> col2;
        classes.push_back(col1);
        features.push_back(col2);
    }

    // Output the columns and convert to double
    cout << "***CLASSES***\n";
    for (string cl : classes) {
        c1 = stod(cl);
        // cout << c1 << '\n';
    }
    cout << "***FEATURES***:\n";
    for (string fts : features) {
        c2 = stod(fts);
        // cout << c2 << '\n';
    }
}

void swap(int xp, int yp) {
    int temp = xp;
    xp = yp;
    yp = temp;
}

void selectionSortByFeature(vector<data> vec, int size) {
    int i, j, min_idx;
 
    // One by one move boundary of
    // unsorted subarray
    for (i = 0; i < size-1; i++) {
       
        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i+1; j < size; j++)
        if (vec.at(j).feature < vec.at(min_idx).feature)
            min_idx = j;
 
        // Swap the found minimum element
        // with the first element
        if(min_idx!=i)
            swap(vec.at(min_idx), vec.at(i));
    }
}

void printVector(vector<data> vec, int size) {
    int i;
    for (i=0; i < size; i++)
        cout << vec.at(i).feature << " ";
    cout << endl;
}