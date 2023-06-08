#include <stdio.h>
#include <string.h>

void onesComplement(char *data) {
    for(int i=0; i<strlen(data); i++) data[i] = data[i] == '0' ? '1' : '0';
}

void sumAll(int r, int c, char data[r][c+1], char sum[c+1]) {
    strcpy(sum, data[0]);
    for(int i=1; i<r; i++) {
        char carry = '0';
        for(int j=c-1; j>=0; j--) {
            if(sum[j] == '1' && data[i][j] == '1' && carry == '1') {
                sum[j] = '1';
                carry = '1';
            } else if((sum[j] == '1' && data[i][j] == '1' && carry == '0') || (sum[j] == '1' && data[i][j] == '0' && carry == '1') || (sum[j] == '0' && data[i][j] == '1' && carry == '1')) {
                sum[j] = '0';
                carry = '1';
            }  else if((sum[j] == '1' && data[i][j] == '0' && carry == '0') || (sum[j] == '0' && data[i][j] == '1' && carry == '0') || (sum[j] == '0' && data[i][j] == '0' && carry == '1')) {
                sum[j] = '1';
                carry = '0';
            } else {
                sum[j] = '0';
                carry = '0';
            }
        }

        int j=c-1;
        while(carry != '0') {
            if(sum[j] == '1') {
                sum[j] = '0';
                carry = '1';
            } else {
                sum[j] = '1';
                carry = '0';
            }
            if(j == 0) j = c-1;
            else j--;
        }
    }
}

int isError(char *data) {
    for(int i=0; i<strlen(data); i++)
        if(data[i] == '0') return 1;
    return 0;
}

int main() {
    int r, c;

    printf("Enter no of data and size of data: ");
    scanf("%d %d", &r, &c);

    char transmittedData[r][c+1], transmittedSum[c+1], receivedData[r+1][c+1], receivedSum[c+1];

    printf("Enter transmitted data one by one: ");
    for (int i=0; i<r; i++) scanf("%s", transmittedData[i]);

    sumAll(r, c, transmittedData, transmittedSum);

    printf("The sum of transmitted data is: %s\n", transmittedSum);
    onesComplement(transmittedSum);
    printf("The check-sum of transmitted data is: %s\n", transmittedSum);

    printf("Final data to transmit: ");
    for(int i=0; i<r; i++) printf("%s ", transmittedData[i]);
    printf("%s\n", transmittedSum);

    printf("Enter received data one by one: ");
    for (int i=0; i<=r; i++) scanf("%s", receivedData[i]);

    sumAll(r+1, c, receivedData, receivedSum);

    printf("Sum of the received data is: %s\n", receivedSum);

    if(isError(receivedSum)) printf("Error detected!");
    else printf("No error detected!");

    return 0;
}