#include <iostream>
#include "Calcs.h++"
#include "FileHandler.h++"

int main(){
    std::cout << "Enter the parent filepath" << std::endl;
    char parentPath[100] = {};
    std::cin >> parentPath;
    std::cout << "Enter the parent filepath" << std::endl;
    char offspringPath[100] = {};
    std::cin >> offspringPath;

    unsigned int pend = BufferSize(parentPath);
    unsigned int oend = BufferSize(offspringPath);
    
    char* parent1 = new char[pend];
    const char* parentAddress = parent1;
    char* offspring = new char[oend];
    const char* offspringAddress = offspring;

    ReadFile(parentPath, parent1, pend);
    ReadFile(offspringPath, offspring, oend);

    GenomeComparison compared;
    InitializeComparison(compared, (pend > oend) ? pend:oend);
    CompareGenome(compared, offspringAddress, parentAddress);
    std::cout << *GetData(compared, 'd');

    delete[] offspringAddress;
    delete[] parentAddress;

    FreeComparison(compared);

    return 0;
}
