#include <iostream>
#include <vector>
#include <string>
#include <numeric> 
using namespace std;

class Expense {
private:
    string category;
    double amount;
    bool isIncome;

public:
    Expense(string cat, double amt, bool income)
        : category(cat), amount(amt), isIncome(income) {
    }

    string getCategory() const { return category; }
    double getAmount() const { return amount; }
    bool getIsIncome() const { return isIncome; }
};

class KakeiboManager {
private:
    vector<Expense> records;

public:
    void addExpense(const string& category, double amount, bool isIncome) {
        records.push_back(Expense(category, amount, isIncome));
    }

    void showRecords() const {
        cout << "- â∆åvïÎàÍóó -" << endl;
        for (auto it = records.begin(); it != records.end(); ++it) {
            cout << (it->getIsIncome() ? "[é˚ì¸] " : "[éxèo] ")
                << it->getCategory() << ": " << it->getAmount() << "â~" << endl;
        }
    }

    void showSummary() const {
        double incomeTotal = 0, expenseTotal = 0;
        for (auto it = records.begin(); it != records.end(); ++it) {
            if (it->getIsIncome())
                incomeTotal += it->getAmount();
            else
                expenseTotal += it->getAmount();
        }
        cout << "- é˚éxÇÃçáåv -" << endl;
        cout << "é˚ì¸çáåv: " << incomeTotal << "â~" << endl;
        cout << "éxèoçáåv: " << expenseTotal << "â~" << endl;
        cout << "écçÇ: " << (incomeTotal - expenseTotal) << "â~" << endl;
    }
};

int main() {
    KakeiboManager manager;
    int choice;
    string category;
    double amount;
    int incomeFlag;

    while (true) {
        cout << "\n1. é˚ì¸ÅEéxèoÇí«â¡\n2. àÍóóï\é¶\n3. é˚éxÇÃçáåv\n4. èIóπ\nëIë: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "ÉJÉeÉSÉä: ";
            getline(cin, category);
            cout << "ã‡äz: ";
            cin >> amount;
            cout << "é˚ì¸Ç»ÇÁ1ÅAéxèoÇ»ÇÁ0: ";
            cin >> incomeFlag;
            manager.addExpense(category, amount, incomeFlag == 1);
            break;
        case 2:
            manager.showRecords();
            break;
        case 3:
            manager.showSummary();
            break;
        case 4:
            cout << "èIóπÇµÇ‹Ç∑ÅB" << endl;
            return 0;
        default:
            cout << "ñ≥å¯Ç»ëIëÇ≈Ç∑ÅB" << endl;
        }
    }
}