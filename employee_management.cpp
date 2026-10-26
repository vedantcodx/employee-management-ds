/*
 * ============================================================
 *  MINI PROJECT: Employee Management System
 *  Subject: Data Structures
 *  
 *  Features:
 *    - Add, Display, Search employee records
 *    - Sort employees by salary using:
 *        1. Bubble Sort
 *        2. Selection Sort
 *        3. Insertion Sort
 *        4. Merge Sort
 *        5. Quick Sort
 *    - Compare sorting algorithm performance
 * ============================================================
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <chrono>
#include <cstdlib>

using namespace std;

// ==================== EMPLOYEE STRUCTURE ====================
struct Employee {
    int id;
    string name;
    string department;
    float salary;
};

// Maximum number of employees
const int MAX_EMP = 100;

// Global array and count
Employee emp[MAX_EMP];
int empCount = 0;

// Temporary array for merge sort
Employee temp[MAX_EMP];

// ==================== UTILITY FUNCTIONS ====================

// Display a single employee record
void displayEmployee(const Employee& e) {
    cout << "| " << setw(5) << e.id
         << " | " << setw(20) << left << e.name
         << " | " << setw(15) << e.department
         << " | " << right << setw(10) << fixed << setprecision(2) << e.salary
         << " |" << endl;
}

// Display table header
void displayHeader() {
    cout << endl;
    cout << "+-------+----------------------+-----------------+------------+" << endl;
    cout << "|  ID   | Name                 | Department      |   Salary   |" << endl;
    cout << "+-------+----------------------+-----------------+------------+" << endl;
}

// Display table footer
void displayFooter() {
    cout << "+-------+----------------------+-----------------+------------+" << endl;
}

// Copy array (used to preserve original before sorting)
void copyArray(Employee source[], Employee dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

// Swap two employees
void swapEmployees(Employee& a, Employee& b) {
    Employee temp = a;
    a = b;
    b = temp;
}

// ==================== ADD EMPLOYEE ====================
void addEmployee() {
    if (empCount >= MAX_EMP) {
        cout << "\n[!] Maximum capacity reached. Cannot add more employees.\n";
        return;
    }

    Employee e;
    cout << "\n--- Add New Employee ---\n";
    cout << "Enter Employee ID: ";
    cin >> e.id;

    // Check for duplicate ID
    for (int i = 0; i < empCount; i++) {
        if (emp[i].id == e.id) {
            cout << "[!] Employee with ID " << e.id << " already exists!\n";
            return;
        }
    }

    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, e.name);

    cout << "Enter Department: ";
    getline(cin, e.department);

    cout << "Enter Salary: ";
    cin >> e.salary;

    emp[empCount] = e;
    empCount++;

    cout << "[+] Employee added successfully! Total employees: " << empCount << endl;
}

// ==================== DISPLAY ALL ====================
void displayAll() {
    if (empCount == 0) {
        cout << "\n[!] No employee records found.\n";
        return;
    }

    displayHeader();
    for (int i = 0; i < empCount; i++) {
        displayEmployee(emp[i]);
    }
    displayFooter();
    cout << "Total employees: " << empCount << endl;
}

// ==================== SEARCH EMPLOYEE ====================
void searchEmployee() {
    if (empCount == 0) {
        cout << "\n[!] No employee records to search.\n";
        return;
    }

    int choice;
    cout << "\n--- Search Employee ---\n";
    cout << "1. Search by ID\n";
    cout << "2. Search by Name\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1) {
        int searchId;
        cout << "Enter Employee ID: ";
        cin >> searchId;

        // Linear search
        bool found = false;
        for (int i = 0; i < empCount; i++) {
            if (emp[i].id == searchId) {
                cout << "\n[+] Employee Found!\n";
                displayHeader();
                displayEmployee(emp[i]);
                displayFooter();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "\n[-] Employee with ID " << searchId << " not found.\n";
        }
    } else if (choice == 2) {
        string searchName;
        cin.ignore();
        cout << "Enter Employee Name: ";
        getline(cin, searchName);

        bool found = false;
        displayHeader();
        for (int i = 0; i < empCount; i++) {
            if (emp[i].name.find(searchName) != string::npos) {
                displayEmployee(emp[i]);
                found = true;
            }
        }
        displayFooter();
        if (!found) {
            cout << "[-] No employee found with name containing \"" << searchName << "\"\n";
        }
    }
}

// ==================== DELETE EMPLOYEE ====================
void deleteEmployee() {
    if (empCount == 0) {
        cout << "\n[!] No employee records to delete.\n";
        return;
    }

    int delId;
    cout << "\nEnter Employee ID to delete: ";
    cin >> delId;

    for (int i = 0; i < empCount; i++) {
        if (emp[i].id == delId) {
            cout << "Deleting: " << emp[i].name << " (ID: " << delId << ")\n";
            // Shift elements left
            for (int j = i; j < empCount - 1; j++) {
                emp[j] = emp[j + 1];
            }
            empCount--;
            cout << "[+] Employee deleted successfully!\n";
            return;
        }
    }
    cout << "[-] Employee with ID " << delId << " not found.\n";
}

// ============================================================
//                    SORTING ALGORITHMS
// ============================================================

// -------------------- 1. BUBBLE SORT --------------------
// Time: O(n^2) | Space: O(1) | Stable: Yes
int bubbleSort(Employee arr[], int n) {
    int comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; j++) {
            comparisons++;
            if (arr[j].salary > arr[j + 1].salary) {
                swapEmployees(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // Optimization: if no swaps in a pass, array is sorted
        if (!swapped) break;
    }
    return comparisons;
}

// -------------------- 2. SELECTION SORT --------------------
// Time: O(n^2) | Space: O(1) | Stable: No
int selectionSort(Employee arr[], int n) {
    int comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j].salary < arr[minIdx].salary) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            swapEmployees(arr[i], arr[minIdx]);
        }
    }
    return comparisons;
}

// -------------------- 3. INSERTION SORT --------------------
// Time: O(n^2) | Space: O(1) | Stable: Yes
int insertionSort(Employee arr[], int n) {
    int comparisons = 0;
    for (int i = 1; i < n; i++) {
        Employee key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            comparisons++;
            if (arr[j].salary > key.salary) {
                arr[j + 1] = arr[j];
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
    return comparisons;
}

// -------------------- 4. MERGE SORT --------------------
// Time: O(n log n) | Space: O(n) | Stable: Yes
int mergeComparisons = 0;

void merge(Employee arr[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {
        mergeComparisons++;
        if (arr[i].salary <= arr[j].salary) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    for (int i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

void mergeSortHelper(Employee arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortHelper(arr, left, mid);
        mergeSortHelper(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int mergeSort(Employee arr[], int n) {
    mergeComparisons = 0;
    mergeSortHelper(arr, 0, n - 1);
    return mergeComparisons;
}

// -------------------- 5. QUICK SORT --------------------
// Time: O(n log n) avg, O(n^2) worst | Space: O(log n) | Stable: No
int quickComparisons = 0;

int partition(Employee arr[], int low, int high) {
    float pivot = arr[high].salary;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        quickComparisons++;
        if (arr[j].salary <= pivot) {
            i++;
            swapEmployees(arr[i], arr[j]);
        }
    }
    swapEmployees(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortHelper(Employee arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}

int quickSort(Employee arr[], int n) {
    quickComparisons = 0;
    quickSortHelper(arr, 0, n - 1);
    return quickComparisons;
}

// ============================================================
//              SORT MENU & COMPARISON
// ============================================================

void sortBySalary() {
    if (empCount == 0) {
        cout << "\n[!] No employees to sort.\n";
        return;
    }

    int choice;
    cout << "\n========== Sort Employees by Salary ==========\n";
    cout << "1. Bubble Sort      (O(n^2), Stable)\n";
    cout << "2. Selection Sort   (O(n^2), Unstable)\n";
    cout << "3. Insertion Sort   (O(n^2), Stable)\n";
    cout << "4. Merge Sort       (O(n log n), Stable)\n";
    cout << "5. Quick Sort       (O(n log n) avg, Unstable)\n";
    cout << "6. Compare ALL algorithms\n";
    cout << "================================================\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice >= 1 && choice <= 5) {
        // Sort the actual array
        int comparisons = 0;
        string algoName;

        auto start = chrono::high_resolution_clock::now();

        switch (choice) {
            case 1:
                algoName = "Bubble Sort";
                comparisons = bubbleSort(emp, empCount);
                break;
            case 2:
                algoName = "Selection Sort";
                comparisons = selectionSort(emp, empCount);
                break;
            case 3:
                algoName = "Insertion Sort";
                comparisons = insertionSort(emp, empCount);
                break;
            case 4:
                algoName = "Merge Sort";
                comparisons = mergeSort(emp, empCount);
                break;
            case 5:
                algoName = "Quick Sort";
                comparisons = quickSort(emp, empCount);
                break;
        }

        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

        cout << "\n[+] Sorted using " << algoName << "!\n";
        cout << "    Comparisons: " << comparisons << endl;
        cout << "    Time taken:  " << duration.count() << " microseconds\n";

        displayAll();

    } else if (choice == 6) {
        // Compare all algorithms on copies of the array
        cout << "\n============ ALGORITHM COMPARISON ============\n";
        cout << "Number of employees: " << empCount << "\n\n";

        Employee copyArr[MAX_EMP];
        string names[] = {"Bubble Sort", "Selection Sort", "Insertion Sort", "Merge Sort", "Quick Sort"};

        cout << "+--------------------+-------------+----------------+" << endl;
        cout << "| Algorithm          | Comparisons | Time (microsec)|" << endl;
        cout << "+--------------------+-------------+----------------+" << endl;

        for (int algo = 0; algo < 5; algo++) {
            // Make a fresh copy each time
            copyArray(emp, copyArr, empCount);

            int comps = 0;
            auto start = chrono::high_resolution_clock::now();

            switch (algo) {
                case 0: comps = bubbleSort(copyArr, empCount); break;
                case 1: comps = selectionSort(copyArr, empCount); break;
                case 2: comps = insertionSort(copyArr, empCount); break;
                case 3: comps = mergeSort(copyArr, empCount); break;
                case 4: comps = quickSort(copyArr, empCount); break;
            }

            auto end = chrono::high_resolution_clock::now();
            auto dur = chrono::duration_cast<chrono::microseconds>(end - start);

            cout << "| " << setw(18) << left << names[algo]
                 << " | " << setw(11) << right << comps
                 << " | " << setw(14) << dur.count()
                 << " |" << endl;
        }

        cout << "+--------------------+-------------+----------------+" << endl;
        cout << "\nNote: Original data is NOT modified in comparison mode.\n";
    }
}

// ==================== ADD SAMPLE DATA ====================
void addSampleData() {
    struct { int id; const char* name; const char* dept; float salary; } samples[] = {
        {101, "Rahul Sharma",     "Engineering",  75000.00},
        {102, "Priya Patel",      "Marketing",    62000.00},
        {103, "Amit Kumar",       "Engineering",  88000.00},
        {104, "Sneha Gupta",      "HR",           55000.00},
        {105, "Vikram Singh",     "Finance",      92000.00},
        {106, "Anjali Verma",     "Engineering",  71000.00},
        {107, "Rohit Joshi",      "Marketing",    58000.00},
        {108, "Kavita Reddy",     "Finance",      84000.00},
        {109, "Deepak Mehta",     "HR",           49000.00},
        {110, "Neha Agarwal",     "Engineering",  67000.00}
    };

    int count = sizeof(samples) / sizeof(samples[0]);
    for (int i = 0; i < count && empCount < MAX_EMP; i++) {
        emp[empCount].id = samples[i].id;
        emp[empCount].name = samples[i].name;
        emp[empCount].department = samples[i].dept;
        emp[empCount].salary = samples[i].salary;
        empCount++;
    }

    cout << "\n[+] Added " << count << " sample employees for testing!\n";
}

// ==================== MAIN MENU ====================
int main() {
    int choice;

    cout << "============================================================\n";
    cout << "     EMPLOYEE MANAGEMENT SYSTEM - DS Mini Project\n";
    cout << "     Sorting Employees by Salary using Various Algorithms\n";
    cout << "============================================================\n";

    do {
        cout << "\n================ MAIN MENU ================\n";
        cout << "1. Add Employee\n";
        cout << "2. Display All Employees\n";
        cout << "3. Search Employee\n";
        cout << "4. Delete Employee\n";
        cout << "5. Sort Employees by Salary\n";
        cout << "6. Add Sample Data (for testing)\n";
        cout << "0. Exit\n";
        cout << "=============================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayAll(); break;
            case 3: searchEmployee(); break;
            case 4: deleteEmployee(); break;
            case 5: sortBySalary(); break;
            case 6: addSampleData(); break;
            case 0:
                cout << "\n[*] Exiting Employee Management System. Goodbye!\n";
                break;
            default:
                cout << "\n[!] Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
