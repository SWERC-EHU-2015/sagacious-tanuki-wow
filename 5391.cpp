/* 
 * File:   main.cpp
 * Author: epinzolas001
 *
 * Created on 6 de noviembre de 2015, 16:34
 */
// 5391 - LED Test

 WA

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * 
 */

int toI(string s){
    int pow = 1;
    int res = 0;
    for (int i = s.size() -1; i>=0; i--){
        if (s[i] == 'Y') res += pow;
        pow*=2;
    }
    return res;
}


int main(int argc, char** argv) {
    int base[10] ={126,48,109,121,51,91,95,112,127,123};
    int k;
    cin >> k;
    while(k != 0){
        string s;
        cin >> s;
        vector<int> v;
        vector<int> br;
        int t = toI(s);
        for(int i = k; i < 10 ;i++ ){
            if((base[i]|t) == base[i]) {
                v.push_back(i-1);
                br.push_back(base[i] -t);
            }
        }
        int a = t;
        while(--k){
            cin >> s;
            int t = toI(s);
            for (int i = 0; i<v.size();i++){
                if(((base[v[i]]|t) != base[v[i]]) ||
                  ( br[i] & t )){
                    v.erase(v.begin() + i);
                    br.erase(br.begin() +i);
                    i--;
                } else {
                    br[i] |= base[v[i]] - t;
                    v[i]--;
                }
            }
            
        }
        if(v.size()) {
            cout << "MATCH" << endl;
        } else cout << "MISMATCH" << endl;
        
        cin >> k;
    }

    
    return 0;
}

