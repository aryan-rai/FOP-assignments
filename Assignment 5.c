#include <stdio.h>

int main() {
    int A[10][10], B[10][10], C[10][10];
    int i, j, k, r, c;

    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter matrix A:\n");
    for(i=0;i<r;i++) {
        for(j=0;j<c;j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter matrix B:\n");
    for(i=0;i<r;i++) {
        for(j=0;j<c;j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Addition
    printf("\nAddition:\n");
    for(i=0;i<r;i++) {
        for(j=0;j<c;j++) {
            C[i][j] = A[i][j] + B[i][j];
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    // Saddle Point
    int found = 0;
    for(i=0;i<r;i++) {
        int min = A[i][0], col = 0;

        for(j=1;j<c;j++) {
            if(A[i][j] < min) {
                min = A[i][j];
                col = j;
            }
        }

        for(k=0;k<r;k++) {
            if(A[k][col] > min)
                break;
        }

        if(k == r) {
            printf("\nSaddle Point = %d\n", min);
            found = 1;
            break;
        }
    }

    if(found == 0)
        printf("\nNo Saddle Point\n");

    // Inverse (only 2x2)
    if(r==2 && c==2) {
        int det;
        det = A[0][0]*A[1][1] - A[0][1]*A[1][0];

        if(det == 0) {
            printf("\nInverse not possible\n");
        } else {
            printf("\nInverse matrix:\n");
            printf("%.2f %.2f\n", (float)A[1][1]/det, -(float)A[0][1]/det);
            printf("%.2f %.2f\n", -(float)A[1][0]/det, (float)A[0][0]/det);
        }
    } else {
        printf("\nInverse only for 2x2 matrix\n");
    }

    // Magic Square
    if(r == c) {
        int sum = 0, flag = 1;

        for(j=0;j<c;j++)
            sum += A[0][j];

        for(i=0;i<r;i++) {
            int rsum = 0;
            for(j=0;j<c;j++)
                rsum += A[i][j];
            if(rsum != sum)
                flag = 0;
        }

        for(j=0;j<c;j++) {
            int csum = 0;
            for(i=0;i<r;i++)
                csum += A[i][j];
            if(csum != sum)
                flag = 0;
        }

        int d1=0, d2=0;
        for(i=0;i<r;i++) {
            d1 += A[i][i];
            d2 += A[i][r-i-1];
        }

        if(d1 != sum || d2 != sum)
            flag = 0;

        if(flag == 1)
            printf("\nMagic Square\n");
        else
            printf("\nNot Magic Square\n");

    } else {
        printf("\nNot a square matrix\n");
    }

    return 0;
}