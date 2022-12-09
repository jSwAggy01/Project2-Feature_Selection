#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void nearestNeighbor(double);
void forwardSelection();
void backwardElimination();

struct data {/*
    classification <- either x or y
    id = <number>
*/};

/*
Sources:
   Reading columns: https://cplusplus.com/forum/beginner/269288/ 
   Convert string to double: https://www.geeksforgeeks.org/cpp-program-for-string-to-double-conversion/#:~:text=1.-,Using%20stod(),%3A%3Asize_t*%20pos%20%3D%200)%3B
*/
int main() {
   vector<string> classes;
   vector<string> features;
   double c1;
   double c2;

   // Open the file
   ifstream inFile("Data/CS170_Small_Data__125.txt");
   
   // Error if opened incorrectly
   if (!inFile) {
      cout << "Can't open file\n";
      return 1;
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
      cout << c1 << '\n';
   }
   cout << "***FEATURES***:\n";
   for (string fts : features) {
      c2 = stod(fts);
      cout << c2 << '\n';
   }
   return 0;
}

// Compile with: g++ test.cpp -o test

void nearestNeighbor(double z) {
    /*
    If closest distance to z is x
        z <- x
    else
        z <- y
*/}

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