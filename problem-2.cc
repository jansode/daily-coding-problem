#include <iostream>
#include <vector>

// date: 2.1.2019

// Problem:
// Given an array of integers, return a new array such that 
// each element at index i of the new array is the product
// of all the number in the original array except the one at i.
//
// For example, if our input was [1,2,3,4,5], the expected output
// would be [120, 60, 40, 30, 24]. If our input was [3,2,1], the 
// expected output would be [2,3,6].
//
// Follow-up: what if you can't use division?

// Solution:
// A brute-force solution to this would be to simply for 
// each element in the new list calculate the product of 
// all the elements in the original list except the current
// index.

std::vector<int> get_new_list(const std::vector<int>& list)
{
	std::vector<int> new_list(list.size()); 	
	for(int i=0;i<list.size();++i)
	{
		int product = 1;
		for(int j=0;j<list.size();++j)
		{
			if(i==j) continue; 

			product *= list[j]; 
		}

		new_list[i] = product;
	}

	return new_list;
}

// This would be O(n^2) and would obviously be a 
// very inefficient way to solve the problem since we're 
// just repeating the same calculation over and over again 
// only leaving out a different element from the product each  
// iteration of the outer loop. 
//
// A better approach would be to just calculate
// the whole product first and then for each of the indices
// divide by that number to leave it out. Like the first problem, 
// this one can also be solved in linear time.
//
// Here we have to be careful to take into account the
// case where we have zeros in our list. If we have two 
// or more zeros then the product will always be zero for 
// all indices. If we have just one zero our product will
// be zero for all other indices than the index with the 
// zero itself. 

std::vector<int> get_new_list(const std::vector<int>& list)
{
	enum {NO_ZEROS,ONE_ZERO,TWO_OR_MORE_ZEROS};
	int zeros = NO_ZEROS;

	int product = 1;
	for(int i=0;i<list.size();++i)
	{
		if(list[i] == 0) 
		{
			switch(zeros)
			{
				case NO_ZEROS: 
					zeros = ONE_ZERO; 
					break;
				case ONE_ZERO: 
					zeros = TWO_OR_MORE_ZEROS;
					goto loop_end; // We can exit the loop, everything is zero anyways.
			}
		}
		else 
			product *= list[i];
	}
loop_end:

	std::vector<int> new_list(list.size());
	switch(zeros)
	{
		case NO_ZEROS:
			for(int i=0;i<list.size();++i) new_list[i] = (product/list[i]);
			break;
		case ONE_ZERO:
			for(int i=0;i<list.size();++i)
			{
				if(list[i] == 0)
					new_list[i] = product;
				else
					new_list[i] = 0;
			}
			break;
		case TWO_OR_MORE_ZEROS:
			for(int i=0;i<list.size();++i) new_list[i] = 0;
			break;
	}

	return new_list;
}

// I haven't come up with an approach, that isn't quadratic, 
// for the case where we aren't allowed to use division.
