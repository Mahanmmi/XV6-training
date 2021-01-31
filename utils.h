int
reverseInt(int number){
    int rev = 0;
    while(!number){
        rev *= 10;
        rev += number % 10;
        number /= 10;
    }
    return rev;
}