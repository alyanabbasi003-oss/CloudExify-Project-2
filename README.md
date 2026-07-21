# Student Record System (C++)

Name: Muhammad Alyan Abbasi

Registration No: CX-INT-2026-CPP-0017

Project 2 for Month 1 of the CloudExify C++ internship. This is a simple console app to manage student records using structs, arrays, and file handling.

## About

Each student's data (name, roll number, marks, average) is grouped together using a struct, and all students are stored in an array. From the menu you can add students, view them, check class stats, sort them, search, delete, and save/load everything to a file so the data isn't lost when you close the program.

## Features

- Add a student (name, roll number, Math/Physics/English marks) with input validation so marks can't go below 0 or above 100
- View all students in a formatted table
- Class statistics — class average, how many passed/failed, subject-wise averages, topper and lowest scorer
- Sort by average marks using bubble sort
- Sort by name alphabetically
- Search a student by roll number
- Delete a student by ID
- Save records to a file and load them back automatically when the program starts
- Letter grade (A/B/C/D/F) shown for every student
