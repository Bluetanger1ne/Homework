#include <stdio.h>

int students();
int student(int z);
int grades(int x);

int main() {
    int running = 1;
    int studentamt = students();
    int studentgrade[studentamt];
    for (int i= 0; i < studentamt;i++) {
        studentgrade[i] = -1;
    }
    while (running != 0) {
        int num = student(studentamt);
        if (num == 0) {
            running = 0;
        }
        else if (num >= 1 && num <= studentamt) {
            int valid = 0;
            while (!valid) {
                int grade = grades(num);
                if (grade == -1) {
                    studentgrade[num -1 ] = -1;
                    valid = 1;
                }
                else if ( grade >= 0 && grade <= 5) {
                    studentgrade[num-1] = grade;
                    valid = 1;
                }
                else {
                    printf("Invalid grade! \n");
                }
            }
        }
        else {
            printf("Invalid student number! \n");
        }

        }
    printf("%5s","Student");
    printf("%10s","Grade");
    for (int i = 0; i<studentamt;i++) {
        if (studentgrade[i] == -1) {
            printf("\n %5d %10s",i+1,"N/A");
        } else {
            printf("\n %5d %10d",i+1,studentgrade[i]);
        }
    }
    }

int students () {
    int array_length;
    printf("Please enter the amount of students: ");
    scanf("%d", &array_length);
    return array_length;
}


int student(int z) {
    int number;
    printf("Please enter student number (1-%d) or 0 to stop: ",z);
    scanf("%d", &number);
    return number;
}
int grades (int x) {
    int grade;
    printf("Please enter the grade (0-5) for student %d or -1 to cancel: ",x);
    scanf("%d",&grade);
    return grade;
}

