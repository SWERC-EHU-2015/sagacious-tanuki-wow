/* 
 * File:   main.cpp
 * Author: epinzolas001
 *
 * Created on 6 de noviembre de 2015, 16:34
 */

#include <cstdlib>
#include <iostream>
#include <stdio.h>

// 5388 - Up and Down Sequences

using namespace std;

/*
 * 
 */




int main(int argc, char** argv) {
    
    int k;
    
    cin >> k;
    
    while(k){
        int cont = 1;
        int up = 0, down =0, egoera = 0;
        int cup = 0,cdown = 0;
        int past = k;
        cin >> k;
        while(k){
            switch(egoera) {
                case 0:
                    if(k==past){
                        up++; down++;
                    }
                    else if(k>past){
                        down = 0; cup = 1;
                        up++; egoera = 1;
                    }
                    else {
                        up = 0; cdown = 1;
                        down++; egoera = -1;
                    }
                    break;
                    
                case 1:
                    if(k<past){
                        cdown++; down++; egoera = -egoera;
                    } else {
                        up++;
                    }
                    break;
                    
                case -1:
                    if(k>past){
                        cup++; up++; egoera = -egoera;
                    } else {
                        down++;
                    }
                    break;         
            }
            cont++;
            past = k;
            cin >> k;
            
        }
        cout << "Nr values = " << cont << ":  ";
        
        //como coño se imprime la precision
        
        if(cup){
            float temp = ((float)up) / ((float) cup);
            printf("%.6f", temp);
        } else cout << "0.000000";
        cout << " ";
        if(cdown){
            float temp = ((float)down) / ((float) cdown);
            printf("%.6f", temp);
        } else cout << "0.000000";
        cout << endl;
        cin >> k;
    }
    
    
    return 0;
}

