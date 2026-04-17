#include "renting.h"
int main() {
    List<vehicles*>* vehicleslist = new List<vehicles*>(100);
    List<customer*>* clientslist = new List<customer*>(50);
    List<rent*>* rentalslist = new List<rent*>(200);

    int choice;
    do {
        cout << "\nVehicle Rental System Menu" << endl;
        cout << "1. Add Vehicle" << endl;
        cout << "2. Add Customer" << endl;
        cout << "3. Create Rental" << endl;
        cout << "4. View All Vehicles" << endl;
        cout << "5. View All Customers" << endl;
        cout << "6. View All Rentals" << endl;
        cout << "7. Search Customer Rental History" << endl;
        cout << "8. Search Vehicle by Model" << endl;
        cout << "9. View Available Vehicles" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "\nAdding Vehicle (1=Car, 2=Truck): ";
            int type;
            cin >> type;
            if (type == 1) {
                vehicles* v = new car();
                cin >> *v;
                vehicleslist->add(v);
            }
            else if (type == 2) {
                vehicles* v = new trucks();
                cin >> *v;
                vehicleslist->add(v);
            }
            else {
                cout << "Invalid vehicle type!" << endl;
            }
            break;
        }
        case 2: {
            customer* c = new customer();
            cin >> *c;
            clientslist->add(c);
            break;
        }
        case 3: {
            if (clientslist->size() == 0 || vehicleslist->size() == 0) {
                cout << "No customers or vehicles available to create rental!" << endl;
                break;
            }
            cout << "Select Customer (0-" << clientslist->size() - 1 << "):" << endl;
            for (int i = 0; i < clientslist->size(); i++) {
                cout << i << ": " << *clientslist->get(i) << endl;
            }
            int custIndex;
            cin >> custIndex;

            cout << "Select Vehicle (0-" << vehicleslist->size() - 1 << "):" << endl;
            for (int i = 0; i < vehicleslist->size(); i++) {
                cout << i << ": " << *vehicleslist->get(i) << endl;
            }
            int vehIndex;
            cin >> vehIndex;

            rent* r = new rent(clientslist->get(custIndex), vehicleslist->get(vehIndex), 0, 0);
            cin >> *r;
            rentalslist->add(r);
            break;
        }
        case 4: {
            cout << "\nAll Vehicles:" << endl;
            for (int i = 0; i < vehicleslist->size(); i++) {
                cout << *vehicleslist->get(i) << endl;
            }
            break;
        }
        case 5: {
            cout << "\nAll Customers:" << endl;
            for (int i = 0; i < clientslist->size(); i++) {
                cout << *clientslist->get(i) << endl;
            }
            break;
        }
        case 6: {
            cout << "\nAll Rentals:" << endl;
            for (int i = 0; i < rentalslist->size(); i++) {
                cout << *rentalslist->get(i) << endl;
            }
            break;
        }
        case 7: {
            int cnic;
            cout << "Enter customer CNIC to search: ";
            cin >> cnic;
            displayCustomerHistory(rentalslist, cnic);
            break;
        }
        case 8: {
            string model;
            cout << "Enter vehicle model to search: ";
            cin >> model;
            searchVehicleByModel(vehicleslist, model);
            break;
        }
        case 9: {
            displayAvailableVehicles(vehicleslist);
            break;
        }
        case 0: {
            cout << " You Exit the program..." << endl;
            break;
        }
        default: {
            cout << "Invalid choice! Please try again." << endl;
        }
        }
    } while (choice != 0);

    delete vehicleslist;
    delete clientslist;
    delete rentalslist;

    system("pause");
    return 0;
}