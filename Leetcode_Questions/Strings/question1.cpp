#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> diffWaysToCompute(std::string expression) {
        // Result vector to store all possible outcomes
        std::vector<int> result;
        
        // Traverse the string to find operators
        for (int i = 0; i < expression.size(); i++) {
            char c = expression[i];
            
            // If the character is an operator, split the expression into two parts
            if (c == '+' || c == '-' || c == '*') {
                // Recursively compute all possible results for the left part
                std::vector<int> leftResults = diffWaysToCompute(expression.substr(0, i));
                // Recursively compute all possible results for the right part
                std::vector<int> rightResults = diffWaysToCompute(expression.substr(i + 1));
                
                // Combine the results from left and right parts based on the current operator
                for (int left : leftResults) {
                    for (int right : rightResults) {
                        if (c == '+') {
                            result.push_back(left + right);
                        } else if (c == '-') {
                            result.push_back(left - right);
                        } else if (c == '*') {
                            result.push_back(left * right);
                        }
                    }
                }
            }
        }
        
        // If there were no operators, the expression must be a number
        if (result.empty()) {
            result.push_back(std::stoi(expression));
        }
        
        return result;
    }
};