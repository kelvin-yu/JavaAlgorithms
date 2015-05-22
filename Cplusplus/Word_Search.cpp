/* Word Search Algorithm */
void findWord(string word, int l, char grid[][MAX]){
    for(int a = 0; a < m; a++){
        for(int b = 0; b < n - l + 1; b++){
            temp = "";
            for(int i = 0; i < l; i++){
                temp += grid[a][b + i];
            }

            if(temp == word){
                cout << (a + 1) << " " << (b + 1) << endl;
                return;
            }
            reverse(temp.begin(), temp.end());
            if(temp == word){
                cout << (a + 1) << " " << (b + l) << endl;
                return;
            }
        }
    }

    for(int a = 0; a < m - word.length() + 1; a++){
        for(int b = 0; b < n; b++){
            temp = "";
            for(int i = 0; i < l; i++){
                temp += grid[a + i][b];
            }
            if(temp == word){
                cout << (a + 1) << " " << (b + 1) << endl;
                return;
            }
            reverse(temp.begin(), temp.end());
            if(temp == word){
                cout << (a + l) << " " << (b + 1) << endl;
                return;
            }
        }
    }


    for(int a = 0; a < m; a++){
        for(int b = 0; b < n; b++){
            temp ="";
            for(int i = 0; i < l; i++){
                if(a + i < m && b + i < n)
                    temp += grid[a + i][b + i];
            }
            if(temp == word){
                cout << (a + 1) << " " << (b + 1) << endl;
                return;
            }
            reverse(temp.begin(), temp.end());
            if(temp == word){
                cout << (a + l) << " " << (b + l) << endl;
                return;
            }
        }
    }

    for(int a = 0; a < m; a++){
        for(int b = 0; b < n; b++){
            temp = "";
            for(int i = 0; i < l; i++){
                if(a + i < m && b - i >= 0)
                    temp += grid[a + i][b - i];
            }
            if(temp == word){
                cout << (a + 1) << " " << (b + 1) << endl;
                return;
            }
            reverse(temp.begin(), temp.end());
            if(temp == word){
                cout << (a + l) << " " << (b - l + 2) << endl;
                return;
            }
        }
    }
}
