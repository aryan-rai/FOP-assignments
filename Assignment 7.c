#include <stdio.h>

struct student {
    int roll;
    char name[50];
    float m1, m2, m3, total, per;
};

int main() {
    struct student s[50];
    int n, i;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nEnter details of student %d\n", i+1);

        printf("Roll no: ");
        scanf("%d", &s[i].roll);

        printf("Name: ");
        scanf("%s", s[i].name);

        printf("Marks of 3 subjects: ");
        scanf("%f %f %f", &s[i].m1, &s[i].m2, &s[i].m3);

        s[i].total = s[i].m1 + s[i].m2 + s[i].m3;
        s[i].per = s[i].total / 3;
    }

    printf("\n--- Student Result ---\n");

    for(i = 0; i < n; i++) {
        printf("\nRoll: %d", s[i].roll);
        printf("\nName: %s", s[i].name);
        printf("\nTotal: %.2f", s[i].total);
        printf("\nPercentage: %.2f", s[i].per);

        if(s[i].per >= 40)
            printf("\nResult: PASS\n");
        else
            printf("\nResult: FAIL\n");
    }

    return 0;
}