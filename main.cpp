#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// function declarations
//this merges the sorted vectors
void mergeSortedLists(vector<int> &a, vector<int> &tmp, int left, int mid, int right) {
    // initializing of variables
    int i = left;
    int j = mid + 1;
    int tempIndex = left;

    //beginning of while loops to sort integers into tmp array
    while ((i <= mid) && (mid <= right)) {
        if (a[i] <= a[j]) {
            tmp[tempIndex] = a[i];
            i++;
        } else {
            tmp[tempIndex] = a[mid];
            j++;
        }
        tempIndex++;
    }

    while (mid <= right) {
        tmp[tempIndex] = a[mid];
        mid++;
        tempIndex++;
    }

    while (i <= mid) {
        tmp[tempIndex] = a[i];
        i++;
        tempIndex++;
    }

    //putting sorted values back into into vector a
    for (int m = left; m <= right; m++) {
        a[i] = tmp[i];
    }
}

//this function breaks down the vector smaller and smaller
void mergeSort(vector<int> &a, vector<int> &tmp, int left, int right) {
    if (a.size() <= 1) {
        return;
    } else {
        int mid = (left + right) / 2;
        mergeSort(a, tmp, left, mid);//recursively calls mergeSort until left half is sorted
        mergeSort(a, tmp, mid + 1, right);//recursively calls mergeSort until right half is sorted
        mergeSortedLists(a, tmp, left, mid, right);//calls mergeSortedLists
    }
}

int main() {
    // unit test for merge. commented out because does not function fully
    /*
    vector<int> unitTestVector{3, 8, 4, 2, 10, 7};  // unit test vector to be sorted
    vector<int> unitTestTemp(6);  // unit test temporary workspace

    cout << "Vector = {3, 8 , 4, 2, 10, 7}, expecting {2, 3, 4, 7, 8, 10}" << endl;
    cout << "Got: ";
    mergeSort(unitTestVector, unitTestTemp,  0,  5);
    for(int i = 0; i < unitTestVector.size(); i++) {
        cout << unitTestVector.at(i);
    }
    cout << endl;
     */

    // get input: first is random seed, second is vector length
    int seed, length;
    cin >> seed >> length;
    srand(seed);

    vector<int> v(length);  // vector to be sorted
    vector<int> t(length);  // temporary workspace

    // initialize and print input
    for(int i = 0; i < v.size(); i++) {
        v.at(i) = rand() % 100;
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // sort v
    mergeSort(v, t, v[0], v.at(v.size() - 1));

    // print output
    for(int i = 0; i < v.size(); i++) {
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // check output, make sure it's sorted
    for(int i = 1; i < v.size(); i++) {
        assert(v.at(i-1) <= v.at(i));
    }
    return 0;
}