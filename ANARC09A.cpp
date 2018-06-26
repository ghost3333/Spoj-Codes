#include <iostream>
#include <vector>
#include <stack>
#include <string>
 
using namespace std;
 
int main(){
    string s;
    cin >> s;
    int k = 1;
    
    while (s[0] != '-'){
        stack <char> st;
        for (char ele : s){
            if (ele == '{') st.push('{');
            else{
                if (!st.empty() && st.top() == '{') st.pop();
                else st.push('}');
            }
        }
        
        int copen = 0;
        int cclose = 0;
        while (!st.empty()){
            char ele = st.top();
            st.pop();
            if (ele == '{') copen++;
            else cclose++;
        }        
        int c = 0;
        if (copen%2 == 0) c += copen/2;
        else c += copen/2 + 1;
        
        if (cclose%2 == 0) c += cclose/2;
        else c+= cclose/2 + 1; 
        
        cout << k << ". " << c << endl;
        k++;
        
        cin >> s;
    }  
    return 0;
}