int
reverseInt(int number){
    int rev = 0;
    while(number > 0){
        rev *= 10;
        rev += number % 10;
        number /= 10;
    }
    return rev;
}

int 
strtol(char *s){
  int ans = 0;
  for(int i = 0; s[i] != 0; i++){
    ans *= 10;
    ans += s[i] - '0';
  }
  return ans;
}