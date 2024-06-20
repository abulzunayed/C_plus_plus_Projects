/* 
Project : A simple Bank System that lets users create an account with a basic registration system, 
not to mention deposit and withdraw money.
Details of code:
--> Class Name: BankAccount; Object_name: account and private member variables: account name and balance.
-->We provided public methods (deposit, withdraw, display) for account operations.
-->he main function allows the user to create a bank account with an initial deposit, 
before letting them deposit, withdraw, or display account information via a do-while loop.
-->The switch statement in the main function handles user choices for banking operations.

 */

/* #include <iostream>
#include <string>
 using namespace std;

class BankAccount
{
    private:
     string name;
     double balance;
    public:
     BankAccount( string accountName, double initialBalance) : name(accountName), balance(initialBalance) {}

    void deposit(double amount)
    {
        if (amount > 0)
        { balance += amount; }
    }

    void withdraw(double amount)
    {
        if (amount <= balance)
        {  balance -= amount; }
        else
        {   cout << "Insufficient funds." << endl; }
    }

    void display()
    {  cout << "Account: " << name << "\nBalance: $" << balance << endl;   }

};
int main()
{   string name;
     double initial_deposit;
     cout<< " Enter your name :";
     getline( cin, name);
     cout<< " Enter intitial deposit :";
     cin>>initial_deposit;
     BankAccount account(name, initial_deposit);  // class name: BankAccount and object_name: account

     int choice;
     double amount;

     do
     {
        cout << "\n1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Display Account" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

         switch (choice)
         {
         case 1:
            cout << "Enter deposit amount: ";
            cin >> amount;
           account.deposit(amount);
          break;
        case 2:
          cout << "Enter withdrawal amount: ";
          cin >> amount;
          account.withdraw(amount);
          break;
        case 3:
          account.display();
          break;
        case 4:
          break;

        default:  cout << "Invalid choice." << endl;
        }

     } while (choice!=4);
     
    return 0;
}
 */

