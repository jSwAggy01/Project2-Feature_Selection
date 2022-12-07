#include <iostream>
using namespace std;

void nearestNeighbor(double);
void forwardSelection();
void backwardElimination();

struct data {/*
    classification <- either x or y
    id = <number>
*/};

int main() {

    /* User interface will be here */

    return 0;
}

void nearestNeighbor(double z) {/*
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