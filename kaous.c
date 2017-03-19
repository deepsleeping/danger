// 가우스 소거법
#include <math.h>
#include <stdio.h>

int main() {
    double matrix[3][3];
    double b[3],x[3];
    int n,i,count,j;
    double ratio,temp;

    // 행렬과 b 읽어들이기
    n=3;
    printf("The matrix is %d by %d\n",n,n);
    printf("Matrix:\n");
    for(i=0;i<n;i+=1) {
        for(j=0;j<n;j+=1) {
            scanf("%lf",&matrix[i][j]);
        }
        scanf("%lf",&b[i]);
    }
    printf("\n");
    for(i=0;i<n;i+=1) {
        for(j=0;j<n;j+=1) {
            printf("%g ",matrix[i][j]);
        }
        printf("\n");
    }
    printf("\nRight Hand Side:\n");
    for(i=0;i<n;i+=1) {
        printf("%g ",b[i]);
    }
    printf("\n\n");
    // 가우스 소거법
    for(i=0;i<n-1;i+=1) {
        for(j=i+1;j<n;j+=1){
            ratio = matrix[j][i] / matrix[i][i];
            for(count=i;count<n;count+=1) {
                matrix[j][count] -= (ratio * matrix[i][count]);
            }
            b[j] -= (ratio * b[i]);
        }
    }
    for (i=0;i<n;i+=1) {
        for(j=0;j<n;j+=1) {
            printf("%g ",matrix[i][j]);
        }
        printf("\n");
    }
    /* Back substitution */
    x[n-1] = b[n-1] / matrix[n-1][n-1];
    for(i=n-2;i>=0;i-=1) {
        temp = b[i];
        for(j=i+1;j<n;j+=1){
            temp -= (matrix[i][j] * x[j]);
        }
        x[i] = temp / matrix[i][i];
    }
    printf("\nAnswer:\n");
    for(i=0;i<n;i+=1){
        printf("x%d = %g\n",i,x[i]);
    }

    return 0;
}