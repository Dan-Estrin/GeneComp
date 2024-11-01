#ifndef CALCSCOPY_H
#define CALCSCOPY_H
class GenomeComparison{
    unsigned int maxDistance;
    unsigned int hDistance;
    unsigned int* mismatches;

    public:
    GenomeComparison(unsigned int &maxFile);
    ~GenomeComparison();
    unsigned int* GetData(const char &req);
    void CompareGenome(const char* const child, const char* const parent);
    float SimilarityRating();
};
#endif