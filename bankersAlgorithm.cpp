#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

void fillAlloc();
void fillMax();
void fillAvail();
void calcNeeded();
bool isSafe();
void printRes();
void parseFile(std::string fileName);

struct resources {
    int all[10][10];
    int max[10][10];
    int available[10];
    int need[10][10];
};

int processes, numberResources;
resources data;
std::vector<int> safeSeq, allNums; // allNums is filled in calcNeeded();

int main(int argc, char* argv[]) {

    if (argc > 1) {
        parseFile(argv[1]);
        processes = 5;
        numberResources = 3;
        // printRes();
        calcNeeded();
    } else {
        std::cout << "File not provided, enter values manually." << std::endl;
        fillAlloc();
        fillMax();
        fillAvail();
        // all values are entered
        calcNeeded();
    }
    

    if (isSafe()) {
    std::cout << "Safe sequence: ";
    for(int i = 0; i < safeSeq.size(); ++i ) {
        std::cout << "P" << safeSeq[i] << ",";
    }
        std::cout << std::endl;
    } else {
        std::cout << "No safe sequence." << std::endl;
    }
    
    
    

    return 0;
}


bool isSafe() {
    bool break_ = false;
    while (allNums.size() > 0) {
        for (int i = 0; i < allNums.size(); ++i ) {
            break_ = false;
            for (int j = 0; j < numberResources; ++j ) {
                if (data.need[allNums[i]][j] > data.available[j]) {
                    break_ = true;
                }
            }
            if (!break_) {
                for (int z = 0; z < numberResources; ++z ) {
                    data.available[z] = data.available[z] + data.all[allNums[i]][z];
                }
                safeSeq.push_back(allNums[i]);
                allNums.erase(allNums.begin()+i);
            }
        }
    }
    return true;
}

void calcNeeded() {
    for (int i = 0; i < processes; ++i ) {
        for (int j = 0; j < numberResources; ++j ) {
            data.need[i][j] = data.max[i][j]-data.all[i][j];
        }
        allNums.push_back(i);
    }
}


void fillAvail() {
    for (int i = 0; i < numberResources; ++i ) {
        std::cout << "Enter available resources, index: " << i << ": "; std::cin >> data.available[i];
    }
}

void fillMax() {
    for (int i = 0; i < processes; ++i ) {
        for (int j = 0; j < numberResources; ++j) {
            std::cout << "Max for process " << i << ", resource " << j << ": "; std::cin >> data.max[i][j];
        }
    }
}

void fillAlloc() {
    std::cout << "How many processes: "; std::cin >> processes;
    std::cout << "Number of resources: "; std::cin >> numberResources;
    for (int i = 0; i < processes; ++i) {
        for (int j = 0; j < numberResources; ++j ) {
            std::cout << "Allocation for Process " << i << ", resource " << j << ": "; std::cin >> data.all[i][j];
        }
    }
}

void parseFile(std::string fileName) {
    std::string fullData = "";
    std::ifstream file(fileName);
    if (!file) {
        std::cout << "File cannot open." << std::endl;
        exit(1);
    }
    char ch = file.get();
    int nums = 0;
    int row = 0, col = 0;
    while (!file.eof()) {
        if (ch != '\n' && ch != ' ') {
            col = nums % 3;
            if (nums % 3 == 0) ++row;
            if (row == 6) row = 0;
            if (nums < 15) {
                data.all[row-1][col] = int(ch)-int('0');
            } else if (nums < 30) {
                data.max[row][col] = int(ch)-int('0');
            } else {
                data.available[col] = int(ch)-int('0');
            }
            ++nums;
        }
        
        file.get(ch);
    }
}

void printRes() {
    for (int i = 0; i < processes; ++i) {
        std::cout << "\nMAX FOR P" << i << ": ";
        for (int j = 0; j < numberResources; ++j) {
            std::cout << data.max[i][j];
        }
        std::cout << std::endl;
    }
}