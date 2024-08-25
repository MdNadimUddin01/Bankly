#include <iostream>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;
class Bank {
    
  string name;
  char type;
  long long balance;
  int lastdepositmoney;
  int lastwithdrawmoney;
  long long aadharNumber;
  long long mobileNo;

public:
  string accountno;


  void create() {
      
    cin.ignore();
    cout << "Enter the account the account holder name : ";
    getline(cin, name);
    
    cout << "\nEnter the account number : ";
    getline(cin, name);
    
    cout << "\nEnter the account type for saving account press S and for "
            "current "
            "account press C : ";
    cin >> type;
    
    if(type != 's' && type != 'c'){
        
        char temp;
        cout<<"You have eneterd wrong account type please enter again with correct type"<<endl;
        cin >> temp;
        
        type = temp;
        
        
    }
    
    if(type == 'c'){
        
        cout << "\nEnter the deposited account for current type account greater than or equal to 1000 :";
        cin >> balance;
        
    }else if(type == 's'){
        
        cout << "\nEnter the deposited account for saving type account greater than or equal to 500 :";
        cin >> balance;
        
    }
    
    while (type == 'c' && balance < 1000) {
        
      cout << "\nplease enter the deposited account for current >= 1000 :";
      cin >> balance;
      
    }
    
    while (type == 's' && balance < 500) {
        
      cout << "\nplease enter the deposited account for saving >= 500 :";
      cin >> balance;
      
    }
    
    lastdepositmoney = balance;
    lastwithdrawmoney = 0;
    
    cout << "\nYour Account is Succesfully created (: " << endl;
    
  }

  void deposit() {
      
    int money;
    cout << "\nenter the money you have to deposit : ";
    cin >> money;
    balance = balance + money;
    lastdepositmoney = money;
    cout << "\n\nYour money is deposited succesfully (: " << endl;
    cout << "\n\nyour last money deposit is : " << lastdepositmoney;
    cout << "\n\nAfter deposited money total amount is : " << balance;
    
  }

  void withraw() {
      
    int money;
    
    cout << "\nenter the money you have to withraw : ";
    cin >> money;
    
    while (balance - money < 500 && type == 's') {
        
      cout << "\nyou can't witharw the money because your account is less than "
              "500 after withrawing money";
              
      cout << "\nenter the other amount : ";
      cin >> money;
      
    }
    
    
    balance = balance - money;
    lastwithdrawmoney = money;
    
    cout << "\n\nYour money is withrawn succesfully (: " << endl;
    cout << "\n\nyour last money withrawed is : " << lastwithdrawmoney;
    cout << "\n\nAfter withrawing money total amount is : " << balance;
    
  }

  void info() {
      
    cout << "\n\nAccount holder name : " << name;
    cout << "\n\nAccount number : " << accountno;
    cout << "\n\nAccount type : " << type;
    cout << "\n\nTotal Balance : " << balance;
    cout << "\n\nlastwithdrawmoney : " << lastwithdrawmoney;
    cout << "\n\nlastdepositmoney : " << lastdepositmoney;
    
  }

  static int search(Bank a[], int size) {
      
    string ac;
    cout << "\nEnter the acoount No : ";
    getline(cin , ac);
    for (int i = 0; i < size; i++) {
        
      if (ac == a[i].accountno) {
        return i;
      }
      
    }
    // cout << "\nEnter account not found " << endl;
    return -1;
  }
  
  static int searchByAadhar(Bank a[], int size) {
      
    string ac;
    cout << "\nEnter the acoount No : ";
    getline(cin , ac);
    
    for (int i = 0; i < size; i++) {
        
      if (ac == a[i].accountno) {
        return i;
      }
      
    }
    
    // cout << "\nEnter account not found " << endl;
    return -1;
  }
  
};

int main() {
    
  Bank *a = new Bank[1000];
  
  int choice;
  int size = 0;
  
  while (1) {
      
    cout << "enter your choice " << endl;
    cout << "1.create    2.deposit    3.withraw    4.search & info    5.delete "
            "account    6.exit : "
         << endl;
         
    cin >> choice;
    
    switch (choice) {
        
        case 1: {
            
          size++;
          a[size - 1].create();
          break;
          
        }
    
        case 2: {
            
          int j = Bank::search(a, size);

          if(j==-1){
              
              cout<<"Invalid Account Number"<<endl;
              
          }
          else{
              
              a[j].deposit();
              
          }
          
          break;
          
        }
    
        case 3: {
            
          int j = Bank::search(a, size);
          
           if(j==-1){
               
              cout<<"Invalid Account Number"<<endl;
              
            }
            else{
                
              a[j].withraw();
              
            }
          
          break;
        }
        
        case 4:
    
            {
                  int j = Bank::search(a, size);
                  if (j != -1) {
                    a[j].info();
                  } 
                  else {
                    cout << "please enter the valid account no" << endl;
                  }
                  break;
                  
            }
        case 5: 
            {
              int j = Bank::search(a, size);
              
              if (j != -1) {
                  
                if (j != -1) {
                    
                      for (int i = j; i < size - 1; i++) {
                          
                        a[i] = a[i + 1];
                        
                      }
                      
                      size--;
                      cout << "Account deleted successfully." << endl;
                      
                }
                
              } else {
                  
                cout << "Account not found " << endl;
              }
              
              break;
              
            }
            
        case 6:
        
          exit(0);
    }
    
  }

  return 0;
}