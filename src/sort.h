//function definitions
void sort(int* sortedArray, int size);
void parseArgs(int argc, char* argv[], int* from, int* to);
int parseInput(int* arr);
void printArray(int* arr, int size);
void copyArray(int* toArray, int* fromArray, int size);
int reducedArraySize(int* arr, int from, int to, int size);
void reduceArray(int* arr, int* newArr, int from, int to, int size);
int arraycmp(int* arr1, int* arr2, int size);