#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void XOR(char *d1, char *d2) {
    for(int i=0; i<strlen(d2); i++) d1[i] = d1[i] == d2[i] ? '0' : '1';
}

void crc(char *data, char *gen, char *check) {
    int i, m = strlen(gen), n = strlen(data);
    for(i=0; i<m; i++) check[i] = data[i];
    
    do {
        if(check[0] == '1') XOR(check, gen);
        for(int j=1; j<m; j++) check[j-1] = check[j];
        check[m-1] = data[i++];
    } while(i <= n);
}

void checkError(char *data, char* gen) {
    char check[strlen(gen)];
    int flag = 0;
    crc(data, gen, check);
    for(int i=0; i<strlen(check); i++) {
        if(check[i] == '1') {
            flag = 1;
            break;
        }
    }
    if(flag) printf("Error detected!");
    else printf("Error not detected!");
}

int main(){
    int m, n;
    printf("Enter size of data and size of generating polynomial: ");
    scanf("%d %d", &n, &m);

    char transmittedData[m+n-1], receivedData[m+n-1], gen[m], check[m];
    printf("Enter data to be transmitted: ");
    scanf("%s", transmittedData);
    printf("Enter generating polynomial: ");
    scanf("%s", gen);

    for(int i=0; i<m-1; i++) strcat(transmittedData, "0");
    printf("Data with padded zero: %s\n", transmittedData);
    
    crc(transmittedData, gen, check);
    printf("The CRC value is: %s\n", check);

    for(int i=0; i<strlen(check); i++) transmittedData[n+i] = check[i];
    printf("Final data to be transmit is: %s\n", transmittedData);

    printf("Enter received data: ");
    scanf("%s", receivedData);

    checkError(receivedData, gen);
    
    return 0;
}