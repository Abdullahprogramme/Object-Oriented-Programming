#include <iostream>
#include <vector>
using namespace std;

class DatabaseRecord {
    public:
        virtual void process() {
            cout << "Processing a general database record" << endl;
        }

        virtual ~DatabaseRecord() = default;
};


class CustomerRecord : public DatabaseRecord {
    public:
        void process() override {
            cout << "Processing customer record" << endl;
        }
    
        void specificCustomerAction() {
            cout << "Performing customer-specific action" << endl;
        }   
};

class EmployeeRecord : public DatabaseRecord {
    public:
        void process() override {
            cout << "Processing employee record" << endl;
        }
    
        void specificEmployeeAction() {
            cout << "Performing employee-specific action" << endl;
        }   
};

class InvoiceRecord : public DatabaseRecord {
    public:
        void process() override {
            cout << "Processing invoice record" << endl;
        }
};

void ProcessRecords(vector<DatabaseRecord*> records) {
    for (auto record : records) {
        record->process();

        // Using dynamic_cast to determine the type of the record, this is called downcasting
        if (CustomerRecord* cr = dynamic_cast<CustomerRecord*>(record)) {
            cr->specificCustomerAction();
        } else if (EmployeeRecord* er = dynamic_cast<EmployeeRecord*>(record)) {
            er->specificEmployeeAction();
        }

        cout << endl;
    }
}

int main() {
    vector<DatabaseRecord*> records;
    records.push_back(new CustomerRecord());
    records.push_back(new EmployeeRecord());
    records.push_back(new InvoiceRecord());

    ProcessRecords(records);

    for (auto record : records) {
        delete record;
    }

    return 0;
}