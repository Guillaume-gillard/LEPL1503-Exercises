int factorial(int n){
    int result = 1;
    for (int i = 1; i <= n; i++) result *= i;
    return result;
}

// Alternative version : Recursive 

int factorial(int n){
    return (n >= 1) ? n*factorial(n-1) : 1;
}