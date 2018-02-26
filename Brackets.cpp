#include<string>
#include<iostream>
#include<stack>

using namespace std;

// True or False check of whether or not the Braces are balanced
bool Balance(string exp){
    stack<char> s;
    char a, b, c;

    // Fail is to prevent a bug in which the Index was exceeded
    int fail = 0;
    for(int i = 0; i < exp.length(); i++){
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
            s.push(exp[i]);
        }
        // If the Brace is not open, move to check and see if the most recent is balanced.
        else {

            // If the stack is not empty and the fail trigger was not met continue 
            if(!s.empty() && fail == 0){

                switch (exp[i]){
                    case ')':
                        
                        // Save top of stack the pop it in preperation for the next check since this top will no longer be checked
                        // after this loop
                        a = s.top();
                        s.pop();
                        if(a == '{' || a == '['){
                            
                            fail = 1;
                            break; 
                            
                        };
                        break;

                    case '}':

                        b = s.top();
                        s.pop();
                        if(b == '(' || b == '['){
                            
                            fail = 1;
                            break;
                        };
                        break;

                    case ']':

                        c = s.top();
                        s.pop();
                        if(c == '(' || c == '{'){
                            
                            fail = 1;
                            break;
                        };
                        break;
                };
            }
            // Fail the program in the event none of this works and stop checking
            else{
                fail = 1;
                i = exp.length();
            };
            
        };
    };
    // If it never failed and the bracket is empty 
    if(s.empty() && fail == 0)
        return true;
    else   
        fail = 0;
        return false;
};

int main(){
    
    string brackets;
    cout << "Enter an expression of brackets: ";
    getline(cin, brackets);

    // if the balance is true than print balanced, otherwise run else and print Not balanced
    if(Balance(brackets)){
        cout << "Balanced" << endl;
    }
    else{

        cout << "Not Balanced" << endl;
    };

    return 0;


};