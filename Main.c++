#include <iostream>
#include <chrono>
#include "Calcs.h++"
#include "FileHandler.h++"

int main(){
    char parentPath[255];
    char offspringPath[255];

    std::cout << "Enter the parent filepath" << std::endl;
    std::cin >> parentPath;
    std::cout << "Enter the offspring filepath" << std::endl;
    std::cin >> offspringPath;

    unsigned int pend = BufferSize(parentPath);
    unsigned int oend = BufferSize(offspringPath);

    if(!(pend && oend)){
        std::cout << "shit ain work dog";
        return 0;
    }
    
    char* const parent = new char[pend];
    char* const offspring = new char[oend];

    ReadFile(parentPath, parent, pend);
    ReadFile(offspringPath, offspring, oend);
    
    GenomeComparison* compared = new GenomeComparison((pend > oend) ? pend:oend);

    compared->CompareGenome(offspring, parent);

    std::cout << *compared->GetData('d') << std::endl;

    delete[] offspring;
    delete[] parent;
    
    delete compared;

    return 0;
}