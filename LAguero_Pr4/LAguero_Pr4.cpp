#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

void displayMessage();
ifstream openInputFile();
ofstream openOutputFile(string& outputFile);

void readStudent(ifstream&, ofstream&);

char computeLetterGrade(double);
string computeStanding(char);

void writeSummaryConsole(int, int, double, double, double);
void writeSummaryFile(ofstream&, int, int, double, double, double);

int main()
{
	char again;

	do
	{
		displayMessage();

		ifstream inputFile = openInputFile();

		string outputFile;
		ofstream report = openOutputFile(outputFile);

		readStudent(inputFile, report);

		inputFile.close();
		report.close();

		cout << "\nReport also written to: " << outputFile << endl;
		
		cout << "\nRun again? (Y/N): ";
		cin >> again;
		cout << endl;
		
	} while (again == 'Y' || again == 'y');

	cout << "Thank you for using the MC File-Based Student Report Generator\n";
	cout << "Summary : Average grade of valid students, max / min grade.\n";
	return 0;
}

//Display program title
void displayMessage()
{
	cout << "============================================\n\n";
	cout << "MC File-Based Student Report Generator\n\n";
	cout << "============================================\n\n";
}

//Opens input file
ifstream openInputFile()
{
	string inputFile;
	
	while (true)
	{
		ifstream inputCredits;

		cout << "Enter input file name: ";
		cin >> inputFile;
		cout << endl;

		inputCredits.open(inputFile);

		if (inputCredits)
			return inputCredits;

		cout << "Error Opening Input File. Try again.\n";
	}
}

//Opens output file
ofstream openOutputFile(string& outputFile)
{
	while(true)
	{
		ofstream report;

		cout << "Enter output file name: ";
		cin >> outputFile;
		cout << endl;

		report.open(outputFile);

		if (report)
			return report;
		
		cout << "Error Opening Output File. Try again.\n";
	}
}

//Computes letter grade
char computeLetterGrade(double grade)
{
	if (grade >= 90)
		return 'A';
	else if (grade >= 80)
		return 'B';
	else if (grade >= 70)
		return 'C';
	else if (grade >= 60)
		return 'D';
	else
		return 'F';
}

//Computes academic standing
string computeStanding(char gradeLetter)
{
	if (gradeLetter == 'A' || gradeLetter == 'B')
		return "Good Standing";
	else if (gradeLetter == 'C')
		return "Academic Warning";
	else
		return "See Advisor";
}

//Reads student records and creates reports
void readStudent(ifstream& inputCredits, ofstream& report)
{
	string names;
	int credit;
	double cost;
	double grade;
	char gradeLetter;
	string standing;

	double totalDue;

	int validStudents = 0;
	int invalidStudents = 0;

	double totalGrades = 0;
	double minGrade = 101;
	double maxGrade = -1;

	while (inputCredits >> names >> credit >> cost >> grade)
	{
		//Validate data
		if (credit < 0 || cost < 0 || grade < 0 || grade >100)
		{
			invalidStudents++;
		
		}
		else

		{
			gradeLetter = computeLetterGrade(grade);

			standing = computeStanding(gradeLetter);

			totalDue = credit * cost;

			//Console output
			cout << fixed << setprecision(2);

			cout << "Student Name: " << names << endl;
			cout << "Credits: " << credit << endl;
			cout << "Cost/Credit: $" << cost << endl;
			cout << "Grade: " << grade << " (" << gradeLetter << ")" << endl;
			cout << "Standing: " << standing << endl;
			cout << "Total Due: $" << totalDue << endl;
			cout << "------------------------------------\n";

			//File output
			report << fixed << setprecision(2);

			report << "Student Name: " << names << endl;
			report << "Credits: " << credit << endl;
			report << "Cost/Credit: $" << cost << endl;
			report << "Grade: " << grade << " (" << gradeLetter << ")" << endl;
			report << "Standing: " << standing << endl;
			report << "Total Due: $" << totalDue << endl;
			report << "------------------------------------\n";

			//Update statistics
			validStudents++;

			totalGrades += grade;

			if (grade < minGrade)
				minGrade = grade;

			if (grade > maxGrade)
				maxGrade = grade;
		}
	}

	double averageGrade = 0;

	if (validStudents > 0)
	{
		averageGrade = totalGrades / validStudents;
	}
	else
	{
		minGrade = 0;
		maxGrade = 0;
	}

	writeSummaryConsole(validStudents, invalidStudents, averageGrade, minGrade, maxGrade);

	writeSummaryFile(report, validStudents, invalidStudents, averageGrade, minGrade, maxGrade);

}

//Writes summary report
void writeSummaryConsole(int validStudents, int invalidStudents, double averageGrade, double minGrade, double maxGrade)

{
	cout << fixed << setprecision(2);

	cout << "\n======== Summary Report ========\n";
	cout << "Valid Students: " << validStudents << endl;
	cout << "Invalid Records: " << invalidStudents << endl;
	cout << "Average Grade: " << averageGrade << endl;
	cout << "Min Grade: " << minGrade << endl;
	cout << "Max Grade: " << maxGrade << endl;
	cout << "================================\n";
}

// Writes summary to the output file
void writeSummaryFile(ofstream& report, int validStudents, int invalidStudents, double averageGrade, double minGrade, double maxGrade)

{
	report << fixed << setprecision(2);

	report << "\n======== Summary Report ========\n";
	report << "Valid Students: " << validStudents << endl;
	report << "Invalid Records: " << invalidStudents << endl;
	report << "Average Grade: " << averageGrade << endl;
	report << "Min Grade: " << minGrade << endl;
	report << "Max Grade: " << maxGrade << endl;
	report << "================================\n";
}
