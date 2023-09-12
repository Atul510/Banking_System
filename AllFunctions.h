#include <bits/stdc++.h>
using namespace std;

long generateAccountNumber() {
    srand(static_cast<unsigned>(time(nullptr)));

    // Generate a random 12-digit account number
    long accountNumber = 0;
    for (int i = 0; i < 12; ++i) {
        accountNumber = accountNumber * 10 + (rand() % 10);
    }
    if(accountNumber<0) return -1*accountNumber;
    return accountNumber;
}

bool isValidPAN(const string& pan) {
    if (pan.length() != 10)     return false;
    
    for (int i = 0; i < 5; ++i) 
        if (!isalpha(pan[i]))   return false; 
        
    for (int i = 5; i < 9; ++i) 
        if (!isdigit(pan[i]))   return false; 

    if (!isalpha(pan[9]))   return false; 

    return true;
}
bool isValidIFSC(string ifsc){
    
    if (ifsc.length() != 11)    return false;
    
    for (int i = 0; i < 4; ++i) 
        if (!isalpha(ifsc[i]))   return false; 
        
    if (ifsc[4]!='0')    return false; 
    
    for(int i=5; i<11; i++)
        if (!isdigit(ifsc[i]))   return false; 
    
    return true;
}