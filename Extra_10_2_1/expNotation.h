using namespace std;

class expNotation {
  public:
    bool isOperator(char);
    int priority(char);
    void infixToPostfix(string);
    void postfixToInfix(string);
    void evalPostfix(string);
};