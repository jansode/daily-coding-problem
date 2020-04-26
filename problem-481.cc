#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

int main()
{

    // The input expression assumed to be in reverse polish notation.
    std::vector<char> expression = {'5','5','3','+','*'}; 

    const std::unordered_set<char> operations = {'+','-','*','/'};

    // Use a stack to push the numbers on.
    std::vector<int> stack;

    int tmp_value = 0;
    for(auto c : expression)
    {
        auto found = operations.find(c);
        if(found != operations.end())     
        {
            // Performe found operand on the 
            // two last operands on the stack.

            int op1 = stack.back();
            stack.pop_back();
            int op2 = stack.back();
            stack.pop_back();

            switch(c)
            {
                case '+': stack.push_back(op1+op2); break;
                case '-': stack.push_back(op1-op2); break;
                case '*': stack.push_back(op1*op2); break;
                case '/': stack.push_back(op1/op2); break;
            }
        }
        else
        {
            stack.push_back(c - '0');
        }
    }

    // The answer should be the last remaining element on the stack. 
    std::cout<<"Answer: "<<stack[0]<<"\n";

    return 0;
}
