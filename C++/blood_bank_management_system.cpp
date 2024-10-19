#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Donor {
    string name;
    string bloodType;
    int quantity;
};

class BloodBank {
private:
    vector<Donor> donors;

public:
    void addDonor(const string& name, const string& bloodType, int quantity) {
        for (auto& donor : donors) {
            if (donor.name == name && donor.bloodType == bloodType) {
                donor.quantity += quantity;
                cout << "Updated quantity for existing donor " << name << ".\n";
                return;
            }
        }
        Donor newDonor = {name, bloodType, quantity};
        donors.push_back(newDonor);
        cout << "Donor added successfully!\n";
    }

    void displayAvailableBlood() {
        cout << "\nAvailable Blood Types:\n";
        for (const auto& donor : donors) {
            cout << "Blood Type: " << donor.bloodType 
                 << ", Quantity: " << donor.quantity << " liters, "
                 << "Donor Name: " << donor.name << endl;
        }
    }

    void requestBlood(const string& bloodType, int quantity) {
        for (auto& donor : donors) {
            if (donor.bloodType == bloodType && donor.quantity >= quantity) {
                donor.quantity -= quantity;
                cout << "Requested " << quantity << " liters of " << bloodType 
                     << " from donor " << donor.name << ".\n";
                return;
            }
        }
        cout << "Blood type " << bloodType << " with required quantity is not available.\n";
    }

    void searchDonor(const string& name) {
        bool found = false;
        for (const auto& donor : donors) {
            if (donor.name == name) {
                cout << "Donor Found: " << donor.name << ", Blood Type: " << donor.bloodType 
                     << ", Quantity: " << donor.quantity << " liters\n";
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Donor " << name << " not found.\n";
        }
    }

    void updateDonorQuantity(const string& name, int quantity) {
        for (auto& donor : donors) {
            if (donor.name == name) {
                donor.quantity += quantity;
                cout << "Updated quantity for donor " << name << ". New Quantity: " << donor.quantity << " liters\n";
                return;
            }
        }
        cout << "Donor " << name << " not found.\n";
    }
};

int main() {
    BloodBank bloodBank;
    int choice;

    do {
        cout << "\nBlood Bank Management System\n";
        cout << "1. Add/Update Donor\n";
        cout << "2. View Available Blood\n";
        cout << "3. Request Blood\n";
        cout << "4. Search Donor\n";
        cout << "5. Update Donor Quantity\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name, bloodType;
                int quantity;
                cout << "Enter donor name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter blood type (e.g., A+, B-, O+): ";
                getline(cin, bloodType);
                cout << "Enter quantity in liters: ";
                cin >> quantity;
                bloodBank.addDonor(name, bloodType, quantity);
                break;
            }
            case 2:
                bloodBank.displayAvailableBlood();
                break;
            case 3: {
                string bloodType;
                int quantity;
                cout << "Enter blood type to request: ";
                cin.ignore();
                getline(cin, bloodType);
                cout << "Enter quantity in liters: ";
                cin >> quantity;
                bloodBank.requestBlood(bloodType, quantity);
                break;
            }
            case 4: {
                string name;
                cout << "Enter donor name to search: ";
                cin.ignore();
                getline(cin, name);
                bloodBank.searchDonor(name);
                break;
            }
            case 5: {
                string name;
                int quantity;
                cout << "Enter donor name to update quantity: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter new quantity in liters: ";
                cin >> quantity;
                bloodBank.updateDonorQuantity(name, quantity);
                break;
            }
            case 6:
                cout << "Exiting the system.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
