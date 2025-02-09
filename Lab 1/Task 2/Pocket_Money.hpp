#ifndef Pocket_Money_hpp
#define Pocket_Money_hpp

#include <iostream>
#include <string>

using namespace std;

class PocketMoney {
    private:
        string source;
        int amount_received;
        static int total_amount;
    
    public:
        PocketMoney(string source, int amount_received);

        // Getter functions
        string get_source() const;
        int get_amount_received() const;
        static int get_total_amount();

        // Display function
        void display_total() const;
};

#endif /* PocketMoney_hpp */