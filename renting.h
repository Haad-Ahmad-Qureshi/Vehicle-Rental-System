#pragma once
#include <iostream>
#include <string>
using namespace std;
template<typename T>
class List {
    T* obj;
    int limit;
    int x = 0;
public:
    List(int cap);
    ~List();
    void add(T v);
    T get(int index);
    int size();
};
template<typename T>
List<T>::List(int cap) : limit(cap) {
    obj = new T[limit];
}

template<typename T>
List<T>::~List() {
    delete[] obj;
}

template<typename T>
void List<T>::add(T v) {
    if (x < limit) {
        obj[x++] = v;
    }
}

template<typename T>
T List<T>::get(int index) {
    if (index >= 0 && index < x) {
        return obj[index];
    }
    return nullptr;
}

template<typename T>
int List<T>::size() {
    return x;
}

class vehicles {
protected:
    string model;
    double manufactringyear;
    double rentalpriceperday;
    int availablitiyStatus;
public:
    vehicles();
    vehicles(string x, double y, double z);
    virtual double calculaterent(int) = 0;

    friend ostream& operator<<(ostream& os, const vehicles& v);
    friend istream& operator>>(istream& is, vehicles& v);

    string getmodel() const;
    double getprice() const;
    int getAvailability() const;
};

class car : public vehicles {
public:
    car();
    car(string x, double y, double z);
    double calculaterent(int days);
};

class trucks : public vehicles {
public:
    trucks();
    trucks(string x, double y, double z);
    double calculaterent(int days);
};

class customer {
    string name;
    int cnic;
    int mobilenum;
public:
    customer();
    customer(string x, int y, int z);

    friend ostream& operator<<(ostream& os, const customer& c);
    friend istream& operator>>(istream& is, customer& c);

    int getCnic() const;
};

class rent {
    customer* a;
    vehicles* g;
    int startdate;
    int enddate;
    double rentalcost;
public:
    rent();
    rent(customer* c, vehicles* v, int start, int end);

    friend ostream& operator<<(ostream& os, const rent& r);
    friend istream& operator>>(istream& is, rent& r);

    customer* getCustomer() const;
    vehicles* getVehicle() const;
};

// Function declarations
void displayCustomerHistory(List<rent*>* rentalslist, int cnic);
void searchVehicleByModel(List<vehicles*>* vehicleslist, string model);
void displayAvailableVehicles(List<vehicles*>* vehicleslist);

