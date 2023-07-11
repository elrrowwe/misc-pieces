#include <iostream>
#include <string.h>
#include "funcalgo.h"

using namespace std;

/*
 * This is the last algorithms and data structures laboratory I did.
 * Thought it would be a nice idea to do something in a lower-level language, like C++.
 */

//exercise 1

//task 1 -- Levenshtein distance
int Levenshtein(char string1[], char string2[]){
    int m = strlen(string1);
    int n = strlen(string2);
    int intermat[m + 1][n + 1];
    int i=0, j=0;

    //initializing first row, column to zero, since that is the number of operations,
    //required to turn an empty string into string1 or string2
    while(j<=n){
        intermat[0][j] = j;
        j++;
    }
    while(i<=m){
        intermat[i][0] = i;
        i++;
    }
    i = 1, j = 1;

    //the distance computing loop itself
    while(i<=m){
        while(j<=n){
            if(string1[i-1] == string2[j-1]){ //checking, if any operations are required
                intermat[i][j] = intermat[i-1][j-1];
            }
            else{
                //finding the minimum costing operation, to advance
                //in turning one string into another
                int insertion = intermat[i-1][j] + 1;
                int deletion = intermat[i][j-1] + 1;
                int substitution = intermat[i-1][j-1] + 1;

                int min_operation = minimum(insertion, deletion, substitution);
                intermat[i][j] = min_operation;
            }
            j++;
        }
        i++;
        j = 1;
    }

    int distance = intermat[m][n];

    return distance;
}

//task 2 -- Hamming distance
int Hamming(char string1[], char string2[]){
    int counter=0;
    int len = strlen(string1);

    for(int i=0; i<=len;++i){
        if(string1[i] != string2[i]){
            counter++;
        }
    }

    return counter;
}

//task 3 -- Indel distance (essentially Levenshtein distance without substitutions)
int Indel(char string1[], char string2[]){
    int m = strlen(string1);
    int n = strlen(string2);
    int mattemp[m + 1][n + 1];
    int i=0, j=0;

    //initializing first row, column to zero, since that is the number of operations,
    //required to turn an empty string into string1 or string2
    while(j<=n){
        mattemp[0][j] = j;
        j++;
    }
    while(i<=m){
        mattemp[i][0] = i;
        i++;
    }
    i = 1, j = 1;

    //the distance computing loop itself
    while(i<=m){
        while(j<=n){
            if(string1[i-1] == string2[j-1]){ //checking, if any operations are required
                mattemp[i][j] = mattemp[i - 1][j - 1];
            }
            else{
                //finding the minimum costing operation, to advance
                //in turning one string into another
                int insertion = mattemp[i - 1][j] + 1;
                int deletion = mattemp[i][j - 1] + 1;

                int min_operation = minimum(insertion, deletion);
                mattemp[i][j] = min_operation;
            }
            j++;
        }
        i++;
        j = 1;
    }

    int distance = mattemp[m][n];

    return distance;
}


//exercise 2
//task 1, binary heap from an array of characters is in funcalgo.h

//driver code for demostrating the completed tasks
int main() {
    //exercise 1
    char str1[] = "edamame";
    char str2[] = "edamame";
    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2     << endl;

    int distLevenshtein = Levenshtein(str1, str2);
    cout << "Levenshtein distance between str1 and str2: " << distLevenshtein << endl;
    int distHamming = Hamming(str1, str2);
    cout << "The Hamming distance between str1 and str2: " <<distHamming << endl;
    int distIndel = Indel(str1, str2);
    cout << "The Indel distance between str1 and str2: " << distIndel << endl;

    //exercise 2
    int test_array[] = {1,2,3,4,5,6};
    int size = sizeof(test_array)/sizeof(test_array[0]);

    Heap arr = Heap(test_array, size);
    cout << "\nThe array for heap: " << endl;
    print_arr(arr.heap, size);

    arr.build_minheap(size);

    cout << "\nMax heap:" << endl;
    print_arr(arr.heap, size);

    arr.build_minheap(size);

    cout << "\nMin heap:" << endl;
    print_arr(arr.heap, size);

    arr.insert(20);
    cout << "\nThe heap upon inserting an element:" << endl;
    print_arr(arr.heap, size);

    return 0;
}

