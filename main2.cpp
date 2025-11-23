#include <iostream>
#include <cstring>
using namespace std;

#include "stack.h"

int main(int argc, char **argv){
    Stack s;

    printf("Checking the parentheses in argv arguments\n");

    
    for (int i = 1; i < argc; i++) {

        cout << "Checking: " << argv[i] << endl;

        bool balanced = true;      

        for (int j = 0; j < strlen(argv[i]); j++) {
            char c = argv[i][j];

            
            if (c == '(' || c == '[' || c == '{') {
                s.push(c);
            }

            
            else if (c == ')' || c == ']' || c == '}') {

                if (s.isEmpty()) {
                    cout << "Unbalanced: extra closing " << c << endl;
                    balanced = false;
                    break;
                }

                char top = s.pop();    

                
                if ((c == ')' && top != '(') ||
                    (c == ']' && top != '[') ||
                    (c == '}' && top != '{')) {

                    cout << "Unbalanced: mismatched " << top << " with " << c << endl;
                    balanced = false;
                    break;
                }
            }
        }

        
        if (balanced) {
            if (s.isEmpty()) {
                cout << "Balanced!" << endl;
            } else {
                cout << "Unbalanced: missing closing bracket(s)" << endl;
            }
        }

        
        while (!s.isEmpty()) s.pop();
    }

    return 0;
}