#include <iostream>
#include <algorithm>
#include "Sort.h"
#include <Windows.h>

// Stephen Maule
// 0005782489

void printCurrentState(std::vector<int> CurrentVector){//inefficient because it has to find the largest and smallest every time
    Sleep(100);
    int Largest = CurrentVector.at(0), Smallest = CurrentVector.at(0);
        for(int i = 0; i < CurrentVector.size(); i++){
            if(CurrentVector.at(i) > Largest){
                Largest = CurrentVector.at(i);
            }
            if(CurrentVector.at(i) < Smallest){
                Smallest = CurrentVector.at(i);
            }
        }
        for(int i = Largest; i > 0; i--){
            for(int j = 0; j < CurrentVector.size(); j++){
                if(CurrentVector.at(j) == i){
                    std::cout << "#";
                    CurrentVector.at(j) = CurrentVector.at(j) - 1;
                }
                else{std::cout << " ";}
            }
            std::cout << "\n";
        }
}

void DisplayHelp(){
    std::cout << "Please Enter (Case Sensitive): \n" << 
    "<bubble> To View The Bubble Sort\n" <<
    "<quick> To View The Quick Sort\n" <<
    "<insertion> To View The Insertion Sort\n" <<
    "<merge> To View The Merge Sort\n" <<
    "<heap> To View The Merge Sort \n" << 
    "<exit> To exit \n-";
};

void Algorithms::BubbleSort(std::vector<int> VectorToSort){ //working
printCurrentState(VectorToSort);
    for(int i = 0; i < VectorToSort.size() - 1; i++){
        for(int j = 0; j < VectorToSort.size() - i - 1; j++){
            if(VectorToSort.at(j) > VectorToSort.at(j+1)){ 
                std::swap(VectorToSort.at(j), VectorToSort.at(j+1));
                printCurrentState(VectorToSort);
            }
        }
    }
    std::cout << "\n";
    printCurrentState(VectorToSort);
}

void Algorithms::Quick::QuickSort(std::vector<int>& VectorToSort, int Lowest, int Highest){
    int pivot = 0;

    if(Lowest < Highest){
        pivot = Partition(VectorToSort, Lowest, Highest);
        QuickSort(VectorToSort, Lowest, pivot);
        QuickSort(VectorToSort, pivot + 1, Highest);
    }
    printCurrentState(VectorToSort);
}

int Algorithms::Quick::Partition(std::vector<int>& VectorToSort, int Lowest, int Highest){
    bool Complete = false;
    int right = Highest, left = Lowest + 1;
    int Pivot = VectorToSort.at(Lowest);

    while(Complete == false){
        while(left <= right && VectorToSort.at(left) <= Pivot){
            left++;
        }
        while(right >= left && VectorToSort.at(right) >= Pivot){
            right--;
        }
        if(right < left){
            Complete = true;
        }else{
            std::swap(VectorToSort.at(left), VectorToSort.at(right));
            printCurrentState(VectorToSort);
        }
    }
    std::swap(VectorToSort.at(right), VectorToSort.at(Lowest));
    printCurrentState(VectorToSort);
    return right;
}

void Algorithms::InsertionSort(std::vector<int> VectorToSort){ // Works
    int CurElement = 0, j = 0;
    for(int i = 1; i < VectorToSort.size(); i++){
        CurElement = VectorToSort.at(i);
        j = i - 1;
        while(j >= 0 && VectorToSort.at(j) > CurElement){
            VectorToSort.at(j+1) = VectorToSort.at(j);
            printCurrentState(VectorToSort);
            j = j - 1;
        }
        VectorToSort.at(j+1) = CurElement;
        printCurrentState(VectorToSort);
    }
    printCurrentState(VectorToSort);
}

std::vector<int> Algorithms::merge_sort(std::vector<int> VectorToSort){
    if(VectorToSort.size() > 1){
        int mid = VectorToSort.size() / 2;
        std::vector<int> left(VectorToSort.begin(), VectorToSort.begin()+mid);
        std::vector<int> right(VectorToSort.begin()+mid, VectorToSort.end());
        left = merge_sort(left);
        right = merge_sort(right);
        int i = 0, j = 0, x = 0; 
        while(i < left.size() && j < right.size()){
            if(left.at(i) < right.at(j)){
                VectorToSort.at(x) = left.at(i);
                printCurrentState(VectorToSort);
                ++i;
            }else{
                VectorToSort.at(x) = right.at(j);
                printCurrentState(VectorToSort);
                ++j;
            }
            ++x;
        }
        while(i < left.size()){
            VectorToSort.at(x) = left.at(i);
            printCurrentState(VectorToSort);
            ++i;
            ++x;
        }
        while(j < right.size()){
            VectorToSort.at(x) = right.at(j);
            printCurrentState(VectorToSort);
            ++j;
            ++x;
        }
    }
    return VectorToSort;
    printCurrentState(VectorToSort);
}

void Algorithms::Heap::makeHeap(std::vector<int>& VectorToSort, int n, int i){
    int biggestValue = i, left = 2 * i + 1, right = 2 * i + 2;
    if(left < n && VectorToSort.at(left) > VectorToSort.at(biggestValue)){
        biggestValue = left;
    }
    if(right  < n && VectorToSort.at(right) > VectorToSort.at(biggestValue)){
        biggestValue = right;
    }
    if(biggestValue != i){
        std::swap(VectorToSort.at(i), VectorToSort.at(biggestValue));
        printCurrentState(VectorToSort);
        std::cout <<"in makeHeap\n";
        makeHeap(VectorToSort, n, biggestValue);
    }
}

void Algorithms::Heap::HeapSort(std::vector<int> VectorToSort){
    int n = VectorToSort.size();
    for(int i = n / 2 - 1; i >= 0; i--){
        makeHeap(VectorToSort, n, i);
    }
    for(int j = n - 1; j >= 0; j--){
        std::swap(VectorToSort.at(0), VectorToSort.at(j));
        printCurrentState(VectorToSort);
        std::cout <<"in heapSort\n";
        makeHeap(VectorToSort, j, 0);
    }
    for(auto cur : VectorToSort){
        std::cout << cur;
    }
    std::cout << "\n";
}