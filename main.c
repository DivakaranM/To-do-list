#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display(char **al, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d %s\n", i + 1, al[i]);
    }
}

int main() {
    char **al = NULL;
    int size = 0;
    char input[100];

    while (1) {
        printf("Enter the task\n");
        printf("1. add\n");
        printf("2. remove\n");
        printf("3. update\n");
        printf("4. display\n");
        printf("5. exit\n");

        int n;
        scanf("%d", &n);

        switch (n) {
            case 1:
                scanf("%s", input);
                al = realloc(al, (size + 1) * sizeof(char *));
                al[size] = strdup(input);
                size++;
                break;
            case 2:
                int del;
                scanf("%d", &del);
                if (del > 0 && del <= size) {
                    free(al[del - 1]);
                    for (int i = del - 1; i < size - 1; i++) {
                        al[i] = al[i + 1];
                    }
                    size--;
                    al = realloc(al, size * sizeof(char *));
                } else {
                    printf("Invalid index\n");
                }
                break;
            case 3:
                int m;
                scanf("%d", &m);
                if (m > 0 && m <= size) {
                    scanf("%s", input);
                    free(al[m - 1]);
                    al[m - 1] = strdup(input);
                } else {
                    printf("Invalid index\n");
                }
                break;
            case 4:
                display(al, size);
                break;
            case 5:
                for (int i = 0; i < size; i++) {
                    free(al[i]);
                }
                free(al);
                return 0;
        }
    }
}
