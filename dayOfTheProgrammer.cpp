bool leapYear(int year) {
    
    if (year < 1918) // JULIAN CALENDAR
        return year % 4 == 0;
    else
        return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)); // GREGORIAN CALENDAR
    
}

/*
 * Complete the 'dayOfProgrammer' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER year as parameter.
 */

string dayOfProgrammer(int year) {
    
    string stringYear = to_string(year);
    
    if (year == 1918) {
        
        string date = "26.09.";
        date.append(stringYear);
        return date;
        
    }
    
    if (leapYear(year)) {
        string date = "12.09.";
        date.append(stringYear);
        return date;
    }
    else {
        string date = "13.09.";
        date.append(stringYear);
        return date;
    }

}

int main() {



}