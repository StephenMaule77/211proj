#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include "Sort.h"

// Stephen Maule
// 0005782489

int main(){
    std::vector<int> VectorToSort = {10, 6, 4, 7, 8, 2, 3, 9, 1, 5};
    std::string input;
    std::cout << "Initial Array : ";
    for(auto cur : VectorToSort){
        std::cout << cur;
    }
    std::cout << "\n";
    printCurrentState(VectorToSort);
    DisplayHelp();
    std::cin >> input;
    while(input != "exit"){
        if(input == "bubble"){
                std::cout << "The Bubble Sort" <<"\n";
                Sleep(2000);
                Algorithms::BubbleSort(VectorToSort);
                DisplayHelp();
                std::cin >> input;
            }
            else if(input == "quick"){
                std::cout << "The Quick Sort" <<"\n";
                Sleep(2000);
                auto copy = VectorToSort;
                Algorithms::Quick::QuickSort(copy, 0, copy.size()-1);
                DisplayHelp();
                std::cin >> input;
            }
            else if(input == "insertion"){
                std::cout << "The Insertion Sort" <<"\n";
                Sleep(2000);
                Algorithms::InsertionSort(VectorToSort);
                DisplayHelp();
                std::cin >> input;
            }
            else if(input == "merge"){
                std::cout << "The Merge Sort" <<"\n";
                Sleep(2000);
                Algorithms::merge_sort(VectorToSort);
                DisplayHelp();
                std::cin >> input;
            }
            else if(input == "heap"){
                std::cout << "The Heap Sort" <<"\n";
                Sleep(2000);
                Algorithms::Heap::HeapSort(VectorToSort);
                DisplayHelp();
                std::cin >> input;
            }
            else{
                DisplayHelp();
                std::cin >> input;
            }
    }
    return 0;
}