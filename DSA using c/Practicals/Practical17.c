// #include <stdio.h>

// int multiply(int a, int b)
// {
//     if (b == 0)
//     {
//         return 0;
//     }
//     return a + multiply(a, b - 1);
// }
// int main()
// {
//     int result = multiply(5, 3);
//     printf("The result of multiplying 5 by 3 is: %d\n", result);
//     return 0;
// }

#include <stdio.h>

int mul(int a, int b){
   return b==0 ? 0 : a + mul(a, b-1);
}
int main(){
    int res = mul(5,3);
    printf("Result:- %d\n", res);
    return 0; 
}