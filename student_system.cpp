#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX = 50;

struct Student {
    int id;
    string name;
    int rollNumber;
    float math;
    float physics;
    float english;
    float average;
};

Student students[MAX];
int count = 0;

float calcAverage(Student s) {
    return (s.math + s.physics + s.english) / 3.0;
}

char getGrade(float avg) {
    if (avg >= 90) return 'A';
    if (avg >= 75) return 'B';
    if (avg >= 60) return 'C';
    if (avg >= 50) return 'D';
    return 'F';
}

void addStudent() {
    if (count >= MAX) {
        cout << "Maximum students reached!" << endl;
        return;
    }

    Student s;
    s.id = count + 1;

    cout << "\n--- ADD STUDENT ---" << endl;
    cout << "Name: ";
    cin.ignore();
    getline(cin, s.name);

    cout << "Roll Number: ";
    cin >> s.rollNumber;

    cout << "Math marks (0-100): ";
    cin >> s.math;
    while (s.math < 0 || s.math > 100) {
        cout << "Must be 0-100: ";
        cin >> s.math;
    }

    cout << "Physics marks (0-100): ";
    cin >> s.physics;
    while (s.physics < 0 || s.physics > 100) {
        cout << "Must be 0-100: ";
        cin >> s.physics;
    }

    cout << "English marks (0-100): ";
    cin >> s.english;
    while (s.english < 0 || s.english > 100) {
        cout << "Must be 0-100: ";
        cin >> s.english;
    }

    s.average = calcAverage(s);
    students[count] = s;
    count++;

    cout << "Student added! Average: "
         << fixed << setprecision(1)
         << s.average << " (Grade " << getGrade(s.average) << ")" << endl;
}

void displayAll() {
    if (count == 0) {
        cout << "No students yet!" << endl;
        return;
    }

    cout << "\n" << string(70, '=') << endl;
    cout << left << setw(5) << "ID"
         << setw(20) << "Name"
         << setw(10) << "Roll"
         << setw(8) << "Math"
         << setw(9) << "Physics"
         << setw(9) << "English"
         << setw(8) << "Avg"
         << setw(6) << "Grade"
         << endl;
    cout << string(70, '-') << endl;

    for (int i = 0; i < count; i++) {
        Student s = students[i];
        cout << left
             << setw(5) << s.id
             << setw(20) << s.name
             << setw(10) << s.rollNumber
             << setw(8) << fixed << setprecision(1) << s.math
             << setw(9) << s.physics
             << setw(9) << s.english
             << setw(8) << s.average
             << setw(6) << getGrade(s.average)
             << endl;
    }

    cout << string(70, '=') << endl;
    cout << "Total students: " << count << endl;
}

void showStats() {
    if (count == 0) {
        cout << "No students!" << endl;
        return;
    }

    int topIndex = 0, bottomIndex = 0;
    float classTotal = 0;

    for (int i = 0; i < count; i++) {
        classTotal += students[i].average;
        if (students[i].average > students[topIndex].average)
            topIndex = i;
        if (students[i].average < students[bottomIndex].average)
            bottomIndex = i;
    }

    float classAvg = classTotal / count;

    int passed = 0;
    for (int i = 0; i < count; i++)
        if (students[i].average >= 50) passed++;

    float mathTotal = 0, physicsTotal = 0, englishTotal = 0;
    for (int i = 0; i < count; i++) {
        mathTotal += students[i].math;
        physicsTotal += students[i].physics;
        englishTotal += students[i].english;
    }

    cout << "\n=== CLASS STATISTICS ===" << endl;
    cout << fixed << setprecision(1);
    cout << "Total Students   : " << count << endl;
    cout << "Class Average    : " << classAvg << endl;
    cout << "Passed           : " << passed << endl;
    cout << "Failed           : " << count - passed << endl;
    cout << "Math Average     : " << mathTotal / count << endl;
    cout << "Physics Average  : " << physicsTotal / count << endl;
    cout << "English Average  : " << englishTotal / count << endl;
    cout << "\nCLASS TOPPER: " << students[topIndex].name
         << " (" << students[topIndex].average << ")" << endl;
    cout << "LOWEST SCORER: " << students[bottomIndex].name
         << " (" << students[bottomIndex].average << ")" << endl;
}

void sortByAverage() {
    if (count == 0) {
        cout << "No students to sort!" << endl;
        return;
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].average > students[j + 1].average) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    cout << "Students sorted by average (ascending)!" << endl;
}

void sortByName() {
    if (count == 0) {
        cout << "No students to sort!" << endl;
        return;
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].name > students[j + 1].name) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    cout << "Students sorted by name (A-Z)!" << endl;
}

void searchByRoll() {
    if (count == 0) {
        cout << "No students yet!" << endl;
        return;
    }

    int roll;
    cout << "Enter roll number to search: ";
    cin >> roll;

    for (int i = 0; i < count; i++) {
        if (students[i].rollNumber == roll) {
            Student s = students[i];
            cout << "\n--- STUDENT FOUND ---" << endl;
            cout << "ID       : " << s.id << endl;
            cout << "Name     : " << s.name << endl;
            cout << "Roll     : " << s.rollNumber << endl;
            cout << fixed << setprecision(1);
            cout << "Math     : " << s.math << endl;
            cout << "Physics  : " << s.physics << endl;
            cout << "English  : " << s.english << endl;
            cout << "Average  : " << s.average << endl;
            cout << "Grade    : " << getGrade(s.average) << endl;
            return;
        }
    }

    cout << "No student found with roll number " << roll << endl;
}

void deleteById() {
    if (count == 0) {
        cout << "No students yet!" << endl;
        return;
    }

    int id;
    cout << "Enter student ID to delete: ";
    cin >> id;

    int foundIndex = -1;
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        cout << "No student found with ID " << id << endl;
        return;
    }

    for (int i = foundIndex; i < count - 1; i++) {
        students[i] = students[i + 1];
    }
    count--;

    cout << "Student with ID " << id << " deleted!" << endl;
}

void saveToFile() {
    ofstream file("students.txt");
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    file << count << endl;
    for (int i = 0; i < count; i++) {
        Student s = students[i];
        file << s.id << "\n"
             << s.name << "\n"
             << s.rollNumber << "\n"
             << s.math << "\n"
             << s.physics << "\n"
             << s.english << "\n";
    }

    file.close();
    cout << "Saved " << count << " students!" << endl;
}

void loadFromFile() {
    ifstream file("students.txt");
    if (!file.is_open()) return;

    file >> count;
    file.ignore();

    for (int i = 0; i < count; i++) {
        Student s;
        file >> s.id;
        file.ignore();
        getline(file, s.name);
        file >> s.rollNumber
             >> s.math
             >> s.physics
             >> s.english;
        file.ignore();
        s.average = calcAverage(s);
        students[i] = s;
    }

    file.close();
    cout << "Loaded " << count << " students." << endl;
}

void showMenu() {
    cout << "\n========== STUDENT RECORD SYSTEM ==========" << endl;
    cout << "1. Add Student" << endl;
    cout << "2. View All Students" << endl;
    cout << "3. Show Class Statistics" << endl;
    cout << "4. Sort by Average" << endl;
    cout << "5. Sort by Name" << endl;
    cout << "6. Search Student by Roll Number" << endl;
    cout << "7. Delete Student by ID" << endl;
    cout << "8. Save to File" << endl;
    cout << "9. Load from File" << endl;
    cout << "10. Exit" << endl;
    cout << "=============================================" << endl;
    cout << "Enter your choice: ";
}

int main() {
    loadFromFile();

    int choice;
    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayAll();
                break;
            case 3:
                showStats();
                break;
            case 4:
                sortByAverage();
                break;
            case 5:
                sortByName();
                break;
            case 6:
                searchByRoll();
                break;
            case 7:
                deleteById();
                break;
            case 8:
                saveToFile();
                break;
            case 9:
                loadFromFile();
                break;
            case 10:
                cout << "Saving before exit..." << endl;
                saveToFile();
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 10);

    return 0;
}
