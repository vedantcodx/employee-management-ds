# 🏢 Employee Management System
### Data Structures Mini Project

A **C++ console-based Employee Management System** that demonstrates various **sorting algorithms** applied to real-world employee salary data.

---

## 📌 Features

| Feature | Description |
|---|---|
| ➕ Add Employee | Add employee with ID, Name, Department, Salary |
| 📋 Display All | View all employees in a formatted table |
| 🔍 Search | Search by Employee ID or Name |
| 🗑️ Delete | Remove an employee by ID |
| 📊 Sort by Salary | Sort using 5 different algorithms |
| ⚡ Compare All | Compare all sorting algorithms side-by-side |
| 🧪 Sample Data | Load 10 pre-built employees for testing |

---

## 🔢 Sorting Algorithms Implemented

| Algorithm | Time Complexity | Space | Stable |
|---|---|---|---|
| Bubble Sort | O(n²) | O(1) | ✅ Yes |
| Selection Sort | O(n²) | O(1) | ❌ No |
| Insertion Sort | O(n²) | O(1) | ✅ Yes |
| Merge Sort | O(n log n) | O(n) | ✅ Yes |
| Quick Sort | O(n log n) avg | O(log n) | ❌ No |

---

## 🚀 How to Run

### Prerequisites
- A C++ compiler (g++ recommended)

### Compile & Run
```bash
g++ -std=c++17 -o employee_management employee_management.cpp
./employee_management
```

---

## 🖥️ Sample Output

```
============================================================
     EMPLOYEE MANAGEMENT SYSTEM - DS Mini Project
     Sorting Employees by Salary using Various Algorithms
============================================================

================ MAIN MENU ================
1. Add Employee
2. Display All Employees
3. Search Employee
4. Delete Employee
5. Sort Employees by Salary
6. Add Sample Data (for testing)
0. Exit
=============================================
```

### Algorithm Comparison Output
```
+--------------------+-------------+----------------+
| Algorithm          | Comparisons | Time (microsec)|
+--------------------+-------------+----------------+
| Bubble Sort        |          45 |              2 |
| Selection Sort     |          45 |              0 |
| Insertion Sort     |          33 |              0 |
| Merge Sort         |          23 |              1 |
| Quick Sort         |          23 |              1 |
+--------------------+-------------+----------------+
```

---

## 📁 File Structure

```
employee_system/
│
└── employee_management.cpp    # Main source file (all-in-one)
```

---

## 👨‍💻 Author

**Vedant Ingle**  
Data Structures Mini Project  
Subject: Data Structures (DS)

---

## 📝 Concepts Covered

- Arrays and Structures in C++
- Linear Search
- Sorting Algorithms (Bubble, Selection, Insertion, Merge, Quick)
- Algorithm Complexity Analysis
- Menu-Driven Console Application
