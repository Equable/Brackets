#include<string>
#include<iostream>
#include<stack>

using namespace std;

bool Balance(string exp){
    stack<char> s;
    char a, b, c;
    int fail = 0;
    for(int i = 0; i < exp.length(); i++){
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
            s.push(exp[i]);
        }
        else {
            if(!s.empty() && fail == 0){

                switch (exp[i]){
                    case ')':
                        
                        a = s.top();
                        s.pop();
                        if(a == '{' || a == '['){
                            cout <<"Not Balanced" << endl;
                            fail = 1;
                            break; 
                            
                        };
                        break;

                    case '}':

                        b = s.top();
                        s.pop();
                        if(b == '(' || b == '['){
                            cout <<"Not Balanced" << endl;
                            fail = 1;
                            break;
                        };
                        break;

                    case ']':

                        c = s.top();
                        s.pop();
                        if(c == '(' || c == '{'){
                            cout << "Not Balanced" << endl;
                            fail = 1;
                            break;
                        };
                        break;
                };
            }
            else{
                fail = 1;
            };
            
        };
    };
    
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

    if(Balance(brackets)){
        cout << "Balanced" << endl;
    }
    else{

        cout << "Not Balanced" << endl;
    };

    return 0;


};