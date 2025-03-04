// you are given an unsorted list of numbers 
// you must go through the list and return the smallest number in the list
// you are not allowed to sort the list
// I will be checking

#include <algorithm>  
#include <iostream>

int smallestDigit(int testList[]) {
    return 0;
}































































































































int myanswer(int testlist[]) {
    int ans = testlist[0];
    int length = sizeof(testlist) / sizeof(testlist[0]);
    for (int i = 0; length > i; i++) {
       ans = std::min(testlist[i],ans);
    }
    return ans;
}

int check() {
    int testcases[][10] {
        {0, -1, -2, -3},
        {1000000, 999999, 1000001, 500000},
        {5, 5, 5, 5, 5},
        {7},
        {4, 8, 8, 2, 8, 5},
        {12, -5, 0, -10, 25, 3},
        {-10, -3, -5, -1, -7},
        {3, 1, 7, 5, 9, 2}
    };
    int length = sizeof(testcases) / sizeof(testcases[0]);
    for (int i = 0; length > i; i++) {
        if (smallestDigit(testcases[i]) != myanswer(testcases[i])) {
            std::cout << "You FAILED" << std::endl;
            return 0;
        }
    }
    std::cout << "you PASSED" << std::endl;
    return 1;
}



int main(int argc, char const *argv[])
{
    check();
    return 0;
}
