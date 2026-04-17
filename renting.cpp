#include "renting.h"

vehicles::vehicles() : model(""), manufactringyear(0), rentalpriceperday(0), availablitiyStatus(1) {}
vehicles::vehicles(string x, double y, double z) : model(x), manufactringyear(y), rentalpriceperday(z), availablitiyStatus(1) {}

string vehicles::getmodel() const { return model; }
double vehicles::getprice() const { return rentalpriceperday; }
int vehicles::getAvailability() const { return availablitiyStatus; }

ostream &operator<<(ostream& os, const vehicles& v) {
    os << "Model: " << v.model << "  Year: " << v.manufactringyear
        << "  Priceperday: " << v.rentalpriceperday << "  Availablity status: " << v.availablitiyStatus;
    return os;
}

istream& operator>>(istream& is, vehicles& v) {
    cout << "Enter model: ";
    is >> v.model;
    cout << "Enter manufacturing year: ";
    is >> v.manufactringyear;
    cout << "Enter rental price per day: ";
    is >> v.rentalpriceperday;
    return is;
}

// Car implementation

car::car() : vehicles() {}
car::car(string x, double y, double z) : vehicles(x, y, z) {}
double car::calculaterent(int days) {
    double x = rentalpriceperday * days;
    return x;
}

// Truck implementation
trucks::trucks() : vehicles() {}
trucks::trucks(string x, double y, double z) : vehicles(x, y, z) {}
double trucks::calculaterent(int days) {
    double x = rentalpriceperday * days;
    x = x + (x * 0.05);
    return x;
}

// Customer implementation
customer::customer() : name(""), cnic(0), mobilenum(0) {}
customer::customer(string x, int y, int z) : name(x), cnic(y), mobilenum(z) {}

int customer::getCnic() const { return cnic; }

ostream& operator<<(ostream& os, const customer& c) {
    os << "Name: " << c.name << ", CNIC: " << c.cnic << ", Mobile: " << c.mobilenum;
    return os;
}

istream& operator>>(istream& is, customer& c) {
    cout << "Enter name: ";
    is >> c.name;
    cout << "Enter CNIC: ";
    is >> c.cnic;
    cout << "Enter mobile number: ";
    is >> c.mobilenum;
    return is;
}

// Rent implementation
rent::rent() : startdate(0), enddate(0), rentalcost(0), a(nullptr), g(nullptr) {}
rent::rent(customer* c, vehicles* v, int start, int end) : a(c), g(v), startdate(start), enddate(end) {
    rentalcost = g->calculaterent(end - start);
}

customer* rent::getCustomer() const { return a; }
vehicles* rent::getVehicle() const { return g; }

ostream& operator<<(ostream& os, const rent& r) {
    os << "Customer: " << *r.a << "\nVehicle: " << *r.g
        << "\nRental Period: " << r.startdate << " to " << r.enddate
        << "\nTotal Cost: " << r.rentalcost;
    return os;
}

istream& operator>>(istream& is, rent& r) {
    cout << "Enter start date (YYYYMMDD): ";
    is >> r.startdate;
    cout << "Enter end date (YYYYMMDD): ";
    is >> r.enddate;
    return is;
}

// Utility functions
void displayCustomerHistory(List<rent*>* rentalslist, int cnic) {
    bool found = false;
    cout << "\nRental History for CNIC: " << cnic << endl;
    for (int i = 0; i < rentalslist->size(); i++) {
        rent* r = rentalslist->get(i);
        if (r->getCustomer()->getCnic() == cnic) {
            cout << *r << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No rental history found for this customer." << endl;
    }
}

void searchVehicleByModel(List<vehicles*>* vehicleslist, string model) {
    bool found = false;
    cout << "\nSearch Results for Model: " << model << endl;
    for (int i = 0; i < vehicleslist->size(); i++) {
        vehicles* v = vehicleslist->get(i);
        if (v->getmodel() == model) {
            cout << *v << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "No vehicles found with this model." << endl;
    }
}

void displayAvailableVehicles(List<vehicles*>* vehicleslist) {
    cout << "\nAvailable Vehicles:" << endl;
    for (int i = 0; i < vehicleslist->size(); i++) {
        vehicles* v = vehicleslist->get(i);
        if (v->getAvailability()) {
            cout << *v << endl;
        }
    }
}