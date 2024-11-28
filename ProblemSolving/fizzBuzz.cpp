void fizzBuzz(int n) {
    
    for (unsigned int i = 1; i <= n; i++) {
        
        if (i % 3 == 0) {
            
            if (i % 5 == 0)
                cout << "FizzBuzz\n";
            else
                cout << "Fizz\n";
        
        }
        else if (i % 5 == 0)
            cout << "Buzz\n";
        else 
            cout << i << "\n";
        
    }

}

int main {

    

}