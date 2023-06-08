#include<stdio.h>
#include<math.h>

int main(){
    int n, m=0;
    printf("Enter length of data: ");
    scanf("%d", &n);

    char data[n];
    printf("Enter data: ");
    scanf("%s", data);

    for(int power = 1; power <= (m+n); power *= 2) m++;
    
    char tMsg[m+n+1], rMsg[m+n+1];
    tMsg[m+n] = '\0';

    for(int i=0, j=0, k=0; i<(m+n); i++) {
        if(i == pow(2, k) - 1) {
            tMsg[i] = '0';
            k++;
        } else tMsg[i] = data[j++];
    }

    for(int i=1; i<(m+n); i*=2) {
        int flag = 1,  count = 0;
        for(int j=i-1, k=0; j<(m+n); j++, k++) {
            if(flag && tMsg[j] == '1') count++;
            if(k != 0 && k % i == 0) flag ^= 1;
        }
        tMsg[i-1] = (count % 2 == 0) ? '0' : '1';
    }

    printf("Final data to transmit is: %s\n", tMsg);

    printf("Enter received data: ");
    scanf("%s", rMsg);

    int wrongCode = 0, power = 1;
    for(int i=1; i<(m+n); i*=2) {
        int flag = 1,  count = 0;
        for(int j=i-1, k=0; j<(m+n); j++, k++) {
            if(flag && rMsg[j] == '1') count++;
            if(k != 0 && k % i == 0) flag ^= 1;
        }
        if(count % 2 != 0) wrongCode += power;
        power *= 2;
    }

    if(wrongCode == 0) printf("No error detected!");
    else printf("Error detected at %d no. bit!", wrongCode);

    return 0;
}