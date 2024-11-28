string kangaroo(int x1, int v1, int x2, int v2) {
    
    // CHECK IF OBVIOUSLY CANNOT REACH
    if ((x1 > x2 && v1 >= v2) || (x1 < x2 && v1 <= v2))
        return "NO";
    
    // IF IT MAY BE POSSIBLE, BUT THE ANIMALS DO NOT CROSS
    int initialDistance = abs(x1 - x2);
    int coveredDistancePerStep = v1 - v2;
    if (initialDistance % coveredDistancePerStep != 0)
        return "NO";
        
    return "YES";

}

int main() {
    
}