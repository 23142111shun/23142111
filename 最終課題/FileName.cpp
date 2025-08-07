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
        cout << "- �ƌv��ꗗ -" << endl;
        for (auto it = records.begin(); it != records.end(); ++it) {
            cout << (it->getIsIncome() ? "[����] " : "[�x�o] ")
                << it->getCategory() << ": " << it->getAmount() << "�~" << endl;
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
        cout << "- ���x�̍��v -" << endl;
        cout << "�������v: " << incomeTotal << "�~" << endl;
        cout << "�x�o���v: " << expenseTotal << "�~" << endl;
        cout << "�c��: " << (incomeTotal - expenseTotal) << "�~" << endl;
    }
};

int main() {
    KakeiboManager manager;
    int choice;
    string category;
    double amount;
    int incomeFlag;

    while (true) {
        cout << "\n1. �����E�x�o��ǉ�\n2. �ꗗ�\��\n3. ���x�̍��v\n4. �I��\n�I��: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "�J�e�S��: ";
            getline(cin, category);
            cout << "���z: ";
            cin >> amount;
            cout << "�����Ȃ�1�A�x�o�Ȃ�0: ";
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
            cout << "�I�����܂��B" << endl;
            return 0;
        default:
            cout << "�����ȑI���ł��B" << endl;
        }
    }
}