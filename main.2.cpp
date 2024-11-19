#include <iostream>
#include <string>
using namespace std;

// Struct to group birthday details
struct Birthday {
    int month;
    int day;
    int year;
};

// Function to get the meaning of the month
string getMonthMeaning(int month) {
    switch (month) {
        case 1: return "The month of January means Janus";
        case 2: return "The month of February means purification";
        case 3: return "The month of March means Mars";
        case 4: return "The month of April means Aphrodite";
        case 5: return "The month of May means Maia";
        case 6: return "The month of June means Juno";
        case 7: return "The month of July means Julius Caesar";
        case 8: return "The month of August means Augustus";
        case 9: return "The month of September means seven";
        case 10: return "The month of October means eight";
        case 11: return "The month of November means nine";
        case 12: return "The month of December means ten";
        default: return "Unknown month";
    }
}

// Function to get the meaning of the day
string getDayMeaning(int day) {
    switch (day) {
        case 1: return "The 1st means Self-Starter";
        case 2: return "The 2nd means Partnership";
        case 3: return "The 3rd means Creativity";
        case 4: return "The 4th means Stability";
        case 5: return "The 5th means Freedom";
        case 6: return "The 6th means Responsibility";
        case 7: return "The 7th means Spirituality";
        case 8: return "The 8th means Power";
        case 9: return "The 9th means Compassion";
        default: return "Unknown day";
    }
}

// Function to get the meaning of the year
string getYearMeaning(int year) {
    switch (year) {
        case 2000: return "The year 2000 means you are a millennial";
        case 2001: return "The year 2001 means beginnings";
        case 2002: return "The year 2002 means duality";
        case 2003: return "The year 2003 means growth";
        case 2004: return "The year 2004 means foundation";
        case 2005: return "The year 2005 means change";
        case 2006: return "The year 2006 means responsibility";
        case 2007: return "The year 2007 means spirituality";
        case 2008: return "The year 2008 means abundance";
        case 2009: return "The year 2009 means completion";
        case 2010: return "The year 2010 means new beginnings";
        case 2011: return "The year 2011 means progress";
        case 2012: return "The year 2012 means transformation";
        case 2013: return "The year 2013 means innovation";
        case 2014: return "The year 2014 means stability";
        case 2015: return "The year 2015 means discovery";
        case 2016: return "The year 2016 means adaptation";
        case 2017: return "The year 2017 means growth";
        case 2018: return "The year 2018 means reflection";
        case 2019: return "The year 2019 means transition";
        case 2020: return "The year 2020 means resilience";
        case 2021: return "The year 2021 means renewal";
        case 2022: return "The year 2022 means collaboration";
        case 2023: return "The year 2023 means determination";
        default: return "Unknown year";
    }
}

int main() {
    Birthday bday;
    char repeat;

    cout << "Welcome to Birthday Date Meaning Generator!" << endl;

    do {
        // Input month, day, and year
        cout << "Please enter the month of your birthday (1-12): ";
        cin >> bday.month;

        cout << "Please enter the day of your birthday (1-31): ";
        cin >> bday.day;

        cout << "Please enter the year of your birthday (2000-2023): ";
        cin >> bday.year;

        // Display meanings
        cout << getMonthMeaning(bday.month) << endl;
        cout << getDayMeaning(bday.day) << endl;
        cout << getYearMeaning(bday.year) << endl;

        // Ask user if they want to try another date
        cout << "Would you like to try another one? (Y/N): ";
        cin >> repeat;
        cin.ignore(); // Ignore leftover newline
    } while (repeat == 'Y' || repeat == 'y');

    cout << "Thanks for playing!" << endl;
    return 0;
}
