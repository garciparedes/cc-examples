#include <cmath>


int main()
{
    const int size = 256;
    double sinTable[size];

    #pragma omp target teams distribute parallel for map(from:sinTable[0:256])
    for(int n=0; n<size; ++n)
        sinTable[n] = std::sin(2 * M_PI * n / size);

    // the table is now initialized
}
