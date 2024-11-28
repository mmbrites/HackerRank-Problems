int recursiveSuperDigit(string n) {
    
    // Base case: n only has 1 digit -> return that digit
    if (n.size() == 1)
        return n[0] - '0';
    
    // Recursive case
    int sum = 0;
    for (int i = 0; i < n.size(); i++)
        sum += n[i] - '0';
    
    return recursiveSuperDigit(to_string(sum));
    
}

/*
 * Complete the 'superDigit' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING n
 *  2. INTEGER k
 */

int superDigit(string n, int k) {
    
    int originalNumber = recursiveSuperDigit(n);
    return recursiveSuperDigit(to_string(originalNumber * k));

}

int main() {


    
}