# 🚗 Vehicle Rental Management System

A console-based **Object-Oriented C++ application** that simulates a real-world vehicle rental business. Built using core OOP principles including inheritance, polymorphism, operator overloading, and custom generic data structures.

---

## 📌 Features

- Add and manage **Cars** and **Trucks**
- Register **Customers** with CNIC and contact details
- Create **Rental agreements** with date-based cost calculation
- View all vehicles, customers, and active rentals
- Search **rental history** by customer CNIC
- Search **vehicles** by model name
- View only **available vehicles**

---

## 🧠 OOP Concepts Used

| Concept | Where Applied |
|---|---|
| **Abstraction** | `vehicles` base class with pure virtual `calculaterent()` |
| **Inheritance** | `car` and `trucks` inherit from `vehicles` |
| **Polymorphism** | `calculaterent()` overridden differently for Car vs Truck |
| **Operator Overloading** | `<<` and `>>` for all major classes |
| **Templates** | Custom generic `List<T>` container class |
| **Dynamic Memory** | Heap-allocated objects managed with `new`/`delete` |
| **Encapsulation** | Private data members with public getters across all classes |

---

## 📁 Project Structure

```
VehicleRentalSystem/
│
├── renting.h        # All class declarations + template List<T>
├── renting.cpp      # Implementation of all classes and utility functions
└── main.cpp         # Entry point with interactive menu
```

---

## 🏗️ Class Design

### `vehicles` (Abstract Base Class)
- Attributes: `model`, `manufacturingYear`, `rentalPricePerDay`, `availabilityStatus`
- Pure virtual method: `calculaterent(int days)`

### `car` : `vehicles`
- Rental cost = `pricePerDay × days`

### `trucks` : `vehicles`
- Rental cost = `pricePerDay × days` + **5% surcharge**

### `customer`
- Attributes: `name`, `cnic`, `mobileNum`

### `rent`
- Links a `customer*` and a `vehicles*`
- Stores `startDate`, `endDate`, and computed `rentalCost`

### `List<T>` (Custom Template Container)
- Fixed-capacity generic array-based list
- Methods: `add()`, `get()`, `size()`

---

## ▶️ How to Run

### Prerequisites
- A C++ compiler (g++ / MSVC)
- C++11 or later

### Compile & Run (g++)
```bash
g++ main.cpp renting.cpp -o rental_system
./rental_system
```

### Compile & Run (Windows)
```bash
g++ main.cpp renting.cpp -o rental_system.exe
rental_system.exe
```

---

## 🖥️ Menu Options

```
Vehicle Rental System Menu
1. Add Vehicle
2. Add Customer
3. Create Rental
4. View All Vehicles
5. View All Customers
6. View All Rentals
7. Search Customer Rental History
8. Search Vehicle by Model
9. View Available Vehicles
0. Exit
```

---

## 💡 Sample Workflow

1. **Add a Car** → Enter model, year, price per day
2. **Add a Customer** → Enter name, CNIC, mobile number
3. **Create a Rental** → Select customer and vehicle, enter start/end dates
4. **View Rentals** → See all rentals with calculated costs
5. **Search History** → Enter a CNIC to see that customer's rental history

---

## 📊 Rental Cost Formula

| Vehicle Type | Formula |
|---|---|
| Car | `days × pricePerDay` |
| Truck | `days × pricePerDay × 1.05` |

---

## 🏆 Achievements

- Dean's List – FAST NUCES
- Demonstrates proficiency in core C++ and OOP design patterns

---

## 👤 Author

**Haad Ahmad Qureshi**  
BS Electrical Engineering – FAST NUCES, Lahore (4th Semester)  
📧 haadahmadqureshi@gmail.com  
🔗 [LinkedIn](https://www.linkedin.com/in/haad-ahmad-qureshi-09072b356)
