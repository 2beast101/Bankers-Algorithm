#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

void fillAlloc();
void fillMax();
void fillAvail();
void calcNeeded();
bool isSafe();
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
    parseFile("data.txt");
    
    fillAlloc();
    fillMax();
    fillAvail();
    // all values are entered
    calcNeeded();
    isSafe();
    std::cout << "Safe sequence: ";
    for(int i = 0; i < safeSeq.size(); ++i ) {
        std::cout << safeSeq[i] << std::endl;
    }
    

    return 0;
}


bool isSafe() {
    bool break_;
    std::cout << allNums.size() << std::endl;
    while (allNums.size() > 0) {
        for (std::vector<int>::iterator i = allNums.begin(); i != allNums.end(); ++i ) {
            for (int j = 0; j < numberResources; ++j ) {
                if (data.need[*i][j] > data.available[j]) {
                    break_ = true;
                }
            }
            if (!break_) {
                for (int z = 0; z < numberResources; ++z ) {
                    data.available[z] = data.available[z] + data.all[*i][z];
                    std::cout << data.available[z];
                }
                safeSeq.push_back(*i);
                allNums.erase(i);
                std::cout << std::endl;
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
        std::cout << "Enter resources for " << i << ": "; std::cin >> data.available[i];
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
    int numCommas = 0; 
    int numBreaks = 0;
    while (!file.eof()) {
        if (ch != ',') {

        }
        file.get(ch);
    }
}