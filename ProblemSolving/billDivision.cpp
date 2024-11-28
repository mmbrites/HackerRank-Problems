int annasBill(vector<int> & bill, int k) {
    
    int toPay = 0;
    for (int i = 0; i < bill.size(); i++)
        if (i != k)
            toPay += bill[i];
            
    return toPay / 2; // Divided by 2 because the plates were shared with Brian
    
}

/*
 * Complete the 'bonAppetit' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY bill
 *  2. INTEGER k
 *  3. INTEGER b
 */

void bonAppetit(vector<int> bill, int k, int b) {
    
    int a = annasBill(bill, k);

    if (a != b)
        cout << b - a << "\n";
    else 
        cout << "Bon Appetit\n";

}

// Interesting solution using 'accumulate' - the third parameter corresponds to the starting value and accumulates sums all elements from bill.begin() to bill.end() using the + operator :)
void bonAppetit(vector<int> bill, int k, int b) {
    int s = accumulate(bill.begin(), bill.end(), -1 * bill[k]);
    int c = s / 2;
    if(c == b) cout << "Bon Appetit";
    else cout << b - c;
}

int main() {
    
}