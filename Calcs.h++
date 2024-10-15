#ifndef CALCS_H
#define CALCS_H
struct GenomeComparison{};
void InitializeComparison(GenomeComparison &container, unsigned int &maxFile);
void FreeComparison(GenomeComparison &container);
unsigned int* GetData(GenomeComparison &container, const char &req);
void CompareGenome(GenomeComparison &container, const char* child, const char* parent);
float SimilarityRating(GenomeComparison &container);
#endif
