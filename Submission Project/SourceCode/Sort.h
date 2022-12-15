#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <algorithm>
#include <vector>

// Stephen Maule
// 0005782489

void printCurrentState(std::vector<int> CurrentVector);
void DisplayHelp();

namespace Algorithms{
    void BubbleSort(std::vector<int> VectorToSort);
    namespace Quick{
        void QuickSort(std::vector<int>& VectorToSort, int Lowest, int Highest);
        int Partition(std::vector<int>& VectorToSort, int Lowest, int Highest);
    }
    void InsertionSort(std::vector<int> VectorToSort);
    std::vector<int> merge_sort(std::vector<int> VectorToSort);
    namespace Heap{
        void makeHeap(std::vector<int>& VectorToSort, int n, int i);
        void HeapSort(std::vector<int> VectorToSort);

    }
}

#endif