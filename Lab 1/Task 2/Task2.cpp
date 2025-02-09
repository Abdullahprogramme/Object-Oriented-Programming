#include <iostream>
#include <string>
#include <vector>
#include "Pocket_Money.hpp"

using namespace std;

int main() {

    vector<PocketMoney> pocket_money;

    int n;
    cout << "Enter the number of sources: ";
    cin >> n;

    string source;
    int amount_received;
    for (int i = 0; i < n; i++) {
        cout << "Enter the source of pocket money: ";
        cin >> source;
        cout << "Enter the amount received: ";
        cin >> amount_received;

        pocket_money.push_back(PocketMoney(source, amount_received));
        pocket_money.back().display_total();
    }
}