/// @brief stores the info of the comparison made between a parent and child
/// @note creating an instance of GenomeComparison allocates free memory automatically
/// calling the destructor takes care for freeing all associated memory(hopefully)
/// @param distance the number of differences calculated between the two squences
/// @param mismatches the indexes (starting at 0) where all differences occur
class GenomeComparison{
    private:
    unsigned int distance;
    unsigned int* mismatches;

    public:
    /// @param maxFile integer value representing the size of the larger file being compared
    GenomeComparison(unsigned int maxFile){
        distance = 0;
        mismatches = new unsigned int[maxFile];
    }

    ~GenomeComparison(){
        delete[] mismatches; 
    }

    /// @brief single access point for retrieving the data of the instance
    /// @param req a reference to a character, either 'd'(0x64/100d) for distance address
    /// or 'm'(0x6d/109d) for the address of the mismatch index array
    /// @return if a valid param is given the address of the data is returned otherwise
    /// nothing is returned
    unsigned int* GetData(const char &req){
        if(req == 0x64){
            return &distance;
        }
        if (req == 0x6d){
            return mismatches;
        }
        return nullptr;
    }

    /// @brief CompareGenome opperates under the assumption that 
    /// sequence and parent are both the same length in memory
    /// @param sequence The sequence to be read from a text file. This is a reference to the pointer
    /// @param parent The parent stored in the config file. This is a reference to the pointer
    /// @return returns a struct containing the hamming distance and mismatch as unsigned ints
    void CompareGenome(const char* child, const char* parent){
        //GeonomeComaprison instance to store data of the comparison
        //index integer to avoid changing the location of mismatches directly to avoid memory leaks
        unsigned int index = 0;
        //analyzes every character representation of the bases
        for(unsigned int i = 0; *(child + i) != '\0'; i++){
            //if the comparison detects inequality it is stored in memory and the ditance is incremented
            if(*(child + i) != *(parent + i)){
                //comparison is dereferenced here and distance is accessed
                //then intremented to reflect the number of differences
                distance++;
                //comparison is dereferenced here and mismatch is accessed
                //then incremented by the index to find the next empty memory
                //location, then that is dereferenced again and assigned with
                //the index that the mismatch occurrs at
                *(mismatches + index) = i;
                //incementing the index assures that a different point in the array
                //will be accessed: noted because it caused issues in initial tests
                index++;
            }
        }
    }
};