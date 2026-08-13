C++ File-Based Student Report Generator

A C++ file-based student report generator that reads student records from an input file, validates the data, calculates letter grades and academic standing, and generates detailed reports both in the console and in an output file.

Features

- Reads student records from an input file
- Writes formatted reports to an output file
- Validates student records
- Calculates letter grades from A to F
- Determines academic standing based on letter grade
- Calculates the total amount due based on credits and cost per credit
- Tracks valid and invalid student records
- Calculates:
  - Average grade
  - Minimum grade
  - Maximum grade
- Displays summary statistics in the console
- Saves the summary statistics to the output file
- Allows the user to run the program again with different files

Technologies Used

- C++
- File Input/Output (ifstream and ofstream)
- iostream
- iomanip
- string

How It Works

The program first asks the user for the name of an input file containing student records and the name of an output file where the report will be saved.

Each student record contains:

Name Credits Cost Grade

For example:

John 15 250.00 92
Jane 12 250.00 78
Mike 9 250.00 65

The program validates each record and ignores records containing invalid credit, cost, or grade values.

For valid records, the program calculates:

- Letter grade
- Academic standing
- Total amount due

The results are displayed in the console and written to the specified output file.

Grading System
Grade	        Score
A	            90–100
B	            80–89
C	            70–79
D	            60–69
F	            0–59

Academic Standing

Letter Grade	      Academic Standing
A	                  Good Standing
B	                  Good Standing
C	                  Academic Warning
D	                  See Advisor
F	                  See Advisor

Data Validation

The program checks that:

- Credits are not negative
- Cost per credit is not negative
- Grades are between 0 and 100
- Input files can be successfully opened
- Output files can be successfully created

Invalid student records are counted separately and are not included in the grade statistics.

Example Output

Student Name: John
Credits: 15
Cost/Credit: $250.00
Grade: 92.00 (A)
Standing: Good Standing
Total Due: $3750.00
------------------------------------

======== Summary Report ========
Valid Students: 3
Invalid Records: 1
Average Grade: 81.67
Min Grade: 65.00
Max Grade: 92.00
================================

Project Structure

File-Based-Student-Report/
│
├── main.cpp
├── input.txt
├── report.txt
└── README.md

Concepts Demonstrated

This project demonstrates several fundamental C++ programming concepts:

- Functions and function prototypes
- File input and output
- Loops
- Conditional statements
- Input validation
- Mathematical calculations
- String handling
- Formatted output
- Passing variables by reference
- Basic statistics
  
Project Information

Language: C++
Project Type: Console Application
Topic: File-Based Student Report Generation

Author

Luis Aguero
