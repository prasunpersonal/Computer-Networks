#include<stdio.h>
#include<string.h>

int main(){
    int n, count = 0;

    printf("Enter length of data: ");
    scanf("%d", &n);

    char transmitted[n+1], received[n+1];

    printf("Enter transmitted data: ");
    scanf("%s", transmitted);
    
    for(int i=0; i<strlen(transmitted); i++) 
        if(transmitted[i] =='1') count++;
    
    if(count % 2 == 0) strcat(transmitted, "0");
    else strcat(transmitted, "1");

    printf("Transmitted data with parity bit: %s\n", transmitted);

    count = 0;
    printf("Enter received data: ");
    scanf("%s", received);
    
    for(int i=0; i<strlen(received); i++) 
        if(received[i] =='1') count++;
    
    if(count % 2 == 0) printf("No Error Detected!");
    else printf("Error Detected!");

    return 0;
}