#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

int main(int argc, char **argv)
{
    std::unordered_set<std::string> words = {"bedbath", "bed", "bath", "and", "beyond"};
    std::string sentence = "bedbath";

    std::vector<std::string> found_words;

    std::string curr_word = "";
    for(auto c : sentence)
    {
       curr_word += c; 
       if(words.find(curr_word) != words.end())
       {
           found_words.push_back(curr_word);
           curr_word.clear();
       }
    }

    if(words.size() != found_words.size())
    {
        std::cout<<"No possible reconstruction.\n";
        return 0;
    }

    std::cout<<"words = [ ";
    for(auto word : found_words)
    {
        std::cout<<word<<" ";
    }
    std::cout<<"]"<<std::endl;

    return 0;
}
