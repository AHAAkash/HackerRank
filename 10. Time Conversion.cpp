#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    string hour = s.substr(0, 2);   
    string minutes = s.substr(3, 2); 
    string seconds = s.substr(6, 2); 
    string period = s.substr(8, 2); 
    
    int hourInt = stoi(hour);  
    
   
    if (period == "AM") {
        if (hourInt == 12) {
            hourInt = 0;  
        }
    } else if (period == "PM") {
        if (hourInt != 12) {
            hourInt += 12;  // Add 12 for PM times (except noon)
        }
    }
    
    // Format the hour back to two digits
    string militaryHour = (hourInt < 10) ? "0" + to_string(hourInt) : to_string(hourInt);
    
    // Concatenate to form the military time string
    return militaryHour + ":" + minutes + ":" + seconds;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
