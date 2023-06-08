#include<stdio.h>

int main(){
    int r, c;

    printf("Enter no. of data and data size: ");
    scanf("%d %d", &r, &c);

    char transmittedData[r+1][c+1], receivedData[r+1][c+1];

    printf("Enter transmitted data one by one: ");
    for(int i=0; i<r; i++) scanf("%s", transmittedData[i]);

    for(int i=0; i<c; i++) {
        int count = 0;
        for(int j=0; j<r; j++)
            if(transmittedData[j][i] == '1') count++;
            
        if(count % 2 == 0) transmittedData[r][i] = '0';
        else transmittedData[r][i] = '1';
    }
    
    for(int i=0; i<=r; i++) {
        int count = 0;
        for(int j=0; j<c; j++)
            if(transmittedData[i][j] == '1') count++;
        
        if(count % 2 == 0) transmittedData[i][c] = '0';
        else transmittedData[i][c] = '1';
    }

    printf("Data with parity bits:\n");
    for(int i=0; i<=r; i++) {
        for(int j=0; j<=c; j++) 
            printf("%c ", transmittedData[i][j]);
        printf("\n");
    }

    printf("Enter received data one by one: ");
    for(int i=0; i<=r; i++) scanf("%s", receivedData[i]);

    int errPosRow = -1, errPosCol = -1;
    
    for(int i=0; i<r; i++) {
        int count = 0;
        for(int j=0; j<c; j++)
            if(receivedData[i][j] == '1') count++;
            
        if((count % 2 == 0 && receivedData[i][c] != '0') || (count % 2 == 1 && receivedData[i][c] != '1')) {
            errPosRow = i;
            break;
        }
    }

    for(int i=0; i<c; i++) {
        int count = 0;
        for(int j=0; j<r; j++)
            if(receivedData[j][i] == '1') count++;
            
        if((count % 2 == 0 && receivedData[r][i] != '0') || (count % 2 == 1 && receivedData[r][i] != '1')) {
            errPosCol = i;
            break;
        }
    }

    if(errPosRow == -1 && errPosCol == -1) printf("No error occured!");
    else printf("Error occured at row=%d, col=%d", errPosRow+1, errPosCol+1);
    
    return 0;
}