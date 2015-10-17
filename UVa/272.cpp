#include<bits/stdc++.h>
using namespace std;

string line;
int main(){
    bool left = true;
    while(getline(cin, line)){
        string res = "";
        for(int i = 0; i < line.length(); i++){
            if(line[i] == '"' && !left){
                res += "''";
                left = true;
            }
            else if(line[i] == '"' && left){
                res += "``";
                left = false;
            }
            else{
                res += line[i];
            }
        }
        cout << res << endl;
    }
}
