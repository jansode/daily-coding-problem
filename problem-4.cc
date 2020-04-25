// Problem:
// Given an array of integers, find the first missing 
// positive integer in linear time and constant space. 
// In other words, find the lowest positive integer that 
// does not exist in the array. The array can contain duplicates 
// and negative numbers as well.
//
// For example, the input [3, 4, -1, 1] should give 2. 
// The input [1, 2, 0] should give 3.
//
// You can modify the input array in-place.
//
// Solution:
//

#include <iostream>
#include <vector>

int find_lowest_positive(std::vector<int> list)
{
	int missing_index = 0;
	for(int i=0;i<list.size();++i)
	{
		if(list[i] != i+1)
		{
			bool found = false;
			missing_index = i;
			for(int j=i+1;j<list.size();++j)
			{
				if(list[missing_index] == list[j])
				{
					int tmp = list[j];
					list[j] = list[missing_index];
					list[missing_index] = tmp;
					found = true;
					break;
				}
			}
			if(!found) return i+1;
		}
	}

	return list.size()+1;
}

int main()
{
	std::cout<<find_lowest_positive(std::vector<int>{1,3,4,5,2});
	return 0;
}
