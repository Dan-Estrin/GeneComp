#include <iostream>
#include "Calcs.h++"
#include "FileHandler.h++"

int main(){
    int pend = BufferSize("parent.txt");
    int oend = BufferSize("offspring.txt");
    
    char* parent1 = new char[pend];
    const char* parentAddress = parent1;
    char* offspring = new char[oend];
    const char* offspringAddress = offspring;

    read_file("parent.txt", parent1, pend);
    read_file("offspring.txt", offspring, oend);

    GenomeComparison compared = GenomeComparison((pend > oend) ? pend:oend);
    compared.CompareGenome(offspringAddress, parentAddress);

    return 0;
}