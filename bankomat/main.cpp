#include <iostream>

using namespace std;

class Bankomat 
{
private:
    int id;
    int totalMoney;
    int minWithdraw;
    int maxWithdraw;
    int hundreds;
    int twoHundreds;
    int fiveHundreds;
    int thousands;

public:
    
    Bankomat() : id(0), totalMoney(0), minWithdraw(100), maxWithdraw(1000), hundreds(0), twoHundreds(0), fiveHundreds(0), thousands(0) {}

    Bankomat(int atmID, int minW, int maxW) : id(atmID), totalMoney(0), minWithdraw(minW), maxWithdraw(maxW), hundreds(0), twoHundreds(0), fiveHundreds(0), thousands(0) {}

    void InitATM(int atmID, int minW, int maxW) 
    {
        id = atmID;
        minWithdraw = minW;
        maxWithdraw = maxW;
    }

    void LoadCash(int h, int th, int fh, int ths) 
    {
        hundreds = h;
        twoHundreds = th;
        fiveHundreds = fh;
        thousands = ths;
        totalMoney = (hundreds * 100) + (twoHundreds * 200) + (fiveHundreds * 500) + (thousands * 1000);
    }

    void Withdraw(int amount) 
    {
        if (amount < minWithdraw || amount > maxWithdraw)
        {
            cout << "Invalid amount. Must be between " << minWithdraw << " and " << maxWithdraw << endl;
            return;
        }

        if (amount > totalMoney) 
        {
            cout << "Not enough money in the ATM." << endl;
            return;
        }

        totalMoney -= amount;
        cout << "Withdrawn: " << amount << endl;
        cout << "Remaining total: " << totalMoney << endl;
    }

    void DisplayMoneyLeft() const 
    {
        cout << "Total money left in ATM: " << totalMoney << endl;
        cout << "Hundreds: " << hundreds << ", TwoHundreds: " << twoHundreds;
        cout << ", FiveHundreds: " << fiveHundreds << ", Thousands: " << thousands << endl;
    }
};

int main()
{
    Bankomat atm(1, 100, 1000);
    atm.LoadCash(10, 5, 2, 1);
    atm.DisplayMoneyLeft();
    atm.Withdraw(500);
    atm.DisplayMoneyLeft();

    return 0;
}

