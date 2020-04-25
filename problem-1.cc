#include <iostream>
#include <vector>
#include <unordered_set>

// date: 1.1.2019

// Problem:
// Given a list of numbers and a number k, return whether any 
// two numbers from the list add up to k.
//
// Bonus: Can you do this in one pass?

// Solution:
// The first thing I thought of is that the solution has 
// to be in at least O(n) time since we have to check every 
// element to be sure that no two elements add up to k.
//
// A simple brute-force solution would be to compare every
// element to every other element. This would take O(n^2) time.

bool adds_up_to_k(std::vector<int> list, int k);
{
	for(int i=0;i<list.size();++i)
	{
		for(int j=0;j<list.size();++j)
		{
			if(i==j) continue; // Don't compare the same index.

			if(list[i]+list[j] == k) return true;
		}
	}

	return false;
}

// After a little bit of thinking I did indeed come up with 
// a linear time solution (assuming constant time lookup for hash tables). 
// In other words it is possible to do it in one pass. 
//
// We have a loop that goes through all the elements in the list. 
// While we're looping we insert each element in a hash table 
// (in this case a std::unordered_list) and do a constant time lookup 
// in the table for the current element.
// If the number is in the table, we've found our two numbers that add
// up to k and can immediately terminate our search and return true. 
// If no mathches are found, we only have to go through the list once to be sure. 

bool adds_up_to_k(std::vector<int> list, int k)
{
	std::unordered_set<int> needed_value;

	for(int i=0;i<list.size();++i)
	{
		needed_value.insert(k - list[i]);

		if(i == 0) continue; // We can't compare just one value.

		auto got = needed_value.find(list[i]);
		if(got != needed_value.end()) return true;
	}

	return false;
}
