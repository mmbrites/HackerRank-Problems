string catAndMouse(int x, int y, int z) {

    int catADistance = abs(x - z);
    int catBDistance = abs(y - z);
    
    if (catADistance < catBDistance)
        return "Cat A";
    else if (catADistance > catBDistance)
        return "Cat B";
    else
        return "Mouse C";

}

int main() {


    
}