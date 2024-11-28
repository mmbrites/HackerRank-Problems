/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    
   string hour = s.substr(0, 2);
   string minutesAndSeconds = s.substr(2, 6);
   string format = s.substr(8, 2);
   
   string convertedTime = {};
   if (format == "AM") {
       
        if (hour == "12")
            hour = "00";
            
   }
   else {
       
       if (hour != "12")
           hour = to_string(stoi(hour) + 12);
           
   }
   
   convertedTime.append(hour).append(minutesAndSeconds);
   return convertedTime;

}

int main() {


    
}