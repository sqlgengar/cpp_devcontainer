#include <stdio.h>
#include <string.h>

int main()
{
    int Nx = 0, Ny = 0;
    double T = 0;
    int has_Nx = 0, has_Ny = 0, has_T = 0;
    char buf[80];
    FILE *file;

    if ((file = fopen("test.txt", "r")) == NULL) {
        fprintf(stderr, "cannot open test.txt\n");
        return 1;
    }

    while (fgets(buf, sizeof buf, file)) {
        if (buf[strspn(buf, " ")] == '\n')  /* accept blank lines */
            continue;

        if (sscanf(buf, " Nx = %d", &Nx) == 1)
            has_Nx = 1;
        else
        if (sscanf(buf, " Ny = %d", &Ny) == 1)
            has_Ny = 1;
        else
        if (sscanf(buf, " T = %lf", &T) == 1)
            has_T = 1;
        else
            fprintf(stderr, "invalid line: %s", buf);
    }
    fclose(file);

    // Print values to check
    if (has_Nx)
        printf("Value of Nx is %d\n", Nx);
    if (has_Ny)
        printf("Value of Ny is %d\n", Ny);
    if (has_T)
        printf("Value of T is %g\n", T);
    return 0;
}