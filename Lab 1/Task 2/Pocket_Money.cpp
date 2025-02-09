#include <iostream>
#include <string>
#include <iomanip>
#include "Pocket_Money.hpp"

using namespace std;

// Define static member
int PocketMoney::total_amount = 0;

PocketMoney::PocketMoney(string source, int amount_received) {
    this->source = source;
    this->amount_received = amount_received;
    total_amount += amount_received;
}

// Getter functions
string PocketMoney::get_source() const {
    return source;
}

int PocketMoney::get_amount_received() const {
    return amount_received;
}

int PocketMoney::get_total_amount() {
    return total_amount;
}

// Display total amount
void PocketMoney::display_total() const {
    cout << "Received: " << this->get_amount_received() << setw(10) << "Total: " << this->get_total_amount() << endl;
}