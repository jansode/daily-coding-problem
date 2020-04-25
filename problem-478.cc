#include <iostream>
#include <unordered_map>
#include <vector>

int main(int argc, char **argv)
{
    // This is guaranteed to have a duplicate value.
    std::vector<int> numbers = {1,2,3,4,5,6,3};

    // Linear space
    std::unordered_map<int, int> occurance_count;

    // Linear time
    for(auto n : numbers)
    {
        occurance_count[n]++;
        if(occurance_count[n] == 2)
        {
            std::cout<<"Duplicate is: "<<n<<"\n";
            return 0;
        }
    }
    std::cout<<"No duplicate!\n";

    return 0;
}
