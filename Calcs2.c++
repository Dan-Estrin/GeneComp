//created to use learn the use of headers and dynamically linked libraries

/// @brief stores the info of the comparison made between a parent and child
/// @note creating an instance of GenomeComparison allocates free memory automatically
/// calling the destructor takes care for freeing all associated memory(hopefully)
/// @param distance the number of differences calculated between the two squences
/// @param mismatches the indexes (starting at 0) where all differences occur
struct GenomeComparison{
    public:
    unsigned int maxDistance;
    unsigned int hDistance;
    unsigned int* mismatches;
};
/// @brief initializes the properties of GenomeComparison container that holds
/// all relevent data made in the comparisons
/// @param container reference to the struct containing the data to be initialized
/// @param maxFile integer value representing the size of the larger file being compared
void InitializeComparison(GenomeComparison &container, unsigned int &maxFile){
    container.maxDistance = maxFile;
    container.hDistance = 0;
    container.mismatches = new unsigned int[maxFile];
}
/// @brief frees the dynamically allocated memory on free memory that is occupied by the
/// array holding mismatch indexes
/// @param container reference to the struct containing the data to be freed
void FreeComparison(GenomeComparison &container){
    delete container.mismatches;
}
/// @brief single access point for retrieving the data of the container
/// @param container reference to the struct containing the data to be retrieved
/// @param req a reference to a character, either 'd'(0x64/100d) for distance address
/// or 'm'(0x6d/109d) for the address of the mismatch index array
/// @return if a valid param is given the address of the data is returned otherwise
/// nothing is returned
unsigned int* GetData(GenomeComparison &container, const char &req){
    if(req == 0x64){
        return &(container.hDistance);
    }
    if (req == 0x6d){
        return container.mismatches;
    }
    return nullptr;
}

/// @brief CompareGenome opperates under the assumption that 
/// sequence and parent are both the same length in memory
/// @param container reference to the struct that will stored the comparison results
/// @param sequence The sequence to be read from a text file. This is a reference to the pointer
/// @param parent The parent stored in the config file. This is a reference to the pointer
/// @return returns a struct containing the hamming distance and mismatch as unsigned ints
void CompareGenome(GenomeComparison &container, const char* child, const char* parent){
    //GeonomeComaprison instance to store data of the comparison
    //index integer to avoid changing the location of mismatches directly to avoid memory leaks
    unsigned int index = 0;
    //analyzes every character representation of the bases
    for(unsigned int i = 0; *(child + i) != '\0'; i++){
        //if the comparison detects inequality it is stored in memory and the ditance is incremented
        if(*(child + i) != *(parent + i)){
            //comparison is dereferenced here and distance is accessed
            //then intremented to reflect the number of differences
            container.hDistance++;
            //comparison is dereferenced here and mismatch is accessed
            //then incremented by the index to find the next empty memory
            //location, then that is dereferenced again and assigned with
            //the index that the mismatch occurrs at
            *(container.mismatches + index) = i;
            //incementing the index assures that a different point in the array
            //will be accessed: noted because it caused issues in initial tests
            index++;
        }
    }
}
/// @brief calculates the % similarity between the parent and offspring
/// @param container reference to the struct containing the data
/// @param totalDistance greatest length of the geneomes that where compared
/// @return floating point int representing the % similarity between the analized parent and offspring
/// @note attempting to run this without having previously run the CompareGenome function properly will
/// result in a return value of -1, indicating failure
float SimilarityRating(GenomeComparison &container){
    return (100 * (container.maxDistance - container.hDistance) / container.maxDistance);
}
