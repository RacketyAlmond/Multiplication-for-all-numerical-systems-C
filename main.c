#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define SYSTEM 10 //(2/8/10/16)

int validateNumber(int c) {
    if (SYSTEM == 2) {
        if ((c != '0' && c != '1') && !isspace(c)) {
            return 0;
        } else {
            return 1;
        }
    } else if (SYSTEM == 10 || SYSTEM == 8) {
        if (!(c >= '0' && c <= '9') && !isspace(c)) {
            return 0;
        } else {
            return 1;
        }
    } else if (SYSTEM == 16) {
        if (!isxdigit(c) && !isspace(c)) {
            return 0;
        } else {
            return 1;
        }
    }
}

char *getLiner(FILE *infile, char** lines, int numLines) {
    char *line;
    int size = 0;
    int capacity = 1;
    int c;
    char *temporary;
    if ((temporary = malloc(sizeof (char) * capacity)) == NULL) {
        fprintf(stderr, "Memory allocation error");
        fclose(infile);
        exit(1);
    }
    line = temporary;//malloc check na line
    int wrongCount = 0;

    while ((c = fgetc(infile)) != '\n' && c != EOF) {
        if (size == 0 && c == '0') {
            continue;
        }
        if (validateNumber(c) == 0) {
            wrongCount++;
            goto labeler;
        }
        if (!isspace(c)) {
            line[size++] = c;
        } else if (size > 0) {
            break;
        }
        labeler:
        if (size >= capacity) {
            if (capacity == 1) {
                capacity = 10;
            } else if (capacity < INT_MAX / 2) {
                capacity *= 2;
            } else if (capacity < INT_MAX - 100) {
                capacity += 100;
            } else {
                fprintf(stderr, "Stack overflow");
                return NULL;
            }
            char *temp;
            if ((temp = realloc(line, sizeof(char) * capacity)) == NULL) {
                fprintf(stderr, "Memory allocation error");
                free(line);//!!!!
                fclose(infile);
                exit(1);
            }

            line = temp;
        }
    }
    if (size == 0 && c == EOF) {
        free(line);
        return NULL;
    }
    line[size] = '\0';
    if (wrongCount != 0) {
        fprintf(stderr, "Wrong input number");
        for(int i = 0; i < numLines; i++){
            free(lines[i]);
        }
        free(lines);
        free(line);
        fclose(infile);
        exit(1);
    } else {
        return line;
    }
}

int ToDecimal(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else if (c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    } else if (c >= 'a' && c <= 'f') {
        return c - 'a' + 10;
    }
    return 0;
}

void multiplyNumbers(FILE *infile, char *num_0, char *num_1, char **lines, int numLines) {
    char *result = NULL;
    char *resulting = NULL;

    long int length_0 = strlen(num_0);
    long int length_1 = strlen(num_1);
    long int max_length = length_0 + length_1;

    char *temporary;
    if ((temporary = (char *) realloc(result, sizeof(char) * max_length)) == NULL) {
        fprintf(stderr, "Memory allocation error");
        for (int h = 2; h < numLines; h++) {
            free(lines[h]);
        }
        free(lines);
        free(num_0);
        free(num_1);
        free(result);
        fclose(infile);
        exit(1);
    }
    result = temporary;

    long int k = max_length - 1;
    long int p = length_1;
    long int g = length_0;
    long int carry = 0;

    for (int i = 0; i < max_length; i++) {
        result[i] = 0;
    }

    while (g > 0) {
        long int bit1 = ToDecimal(num_0[g - 1]);
        while (p > 0) {
            long int bit2 = ToDecimal(num_1[p - 1]);
            long int sum;

            sum = bit1 * bit2 + carry;
            carry = sum / SYSTEM;
            result[k] += sum % SYSTEM;
            if (result[k] >= SYSTEM) {
                carry += result[k] / SYSTEM;
                result[k] = result[k] % SYSTEM;
            }
            if (p > 0) {
                p--;
            }
            k--;
        }

        if (carry > 0) {
            result[k] = carry;
            carry = 0;
        }
        k = max_length - 1 - (length_0 - g);
        if (g > 0) {
            g--;
        }
        p = length_1;
        k--;
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////

    for (int j = 2; j < numLines; j++) {
        char *num = lines[j];
        if (num == NULL) {
            fprintf(stderr, "Error reading number from the file\n");
            for (int h = 2; h < numLines; h++) {
                free(lines[h]);
            }
            free(lines);
            free(num_0);
            free(num_1);
            free(result);
            fclose(infile);
            exit(1);
        }

        long int lengthNum = strlen(num);
        long int lengthResult = max_length;
        max_length = lengthNum + lengthResult;

        char *tmp;
        if ((tmp = (char *) realloc(result, sizeof(char) * (max_length + 1))) == NULL) {
            fprintf(stderr, "Memory allocation error");
            for (int h = 2; h < numLines; h++) {
                free(lines[h]);
            }
            free(lines);
            free(num_0);
            free(num_1);
            free(result);
            fclose(infile);
            exit(1);
        }
        result = tmp;

        k = max_length - 1;
        p = lengthResult;
        g = lengthNum;
        carry = 0;

        char *temp;
        if ((temp = (char *) realloc(resulting, sizeof(char) * (max_length + 1))) == NULL) {
            fprintf(stderr, "Memory allocation error");
            for (int h = 2; h < numLines; h++) {
                free(lines[h]);
            }
            free(lines);
            free(num_0);
            free(num_1);
            free(result);
            fclose(infile);
            exit(1);
        }
        resulting = temp;

        for (long int i = 0; i < p; i++) {
            resulting[i] = result[i];
            result[i] = 0;
        }
        for (long int i = p; i < k + 1; i++) {
            result[i] = 0;
        }
        while (g > 0) {
            long int bit1 = ToDecimal(num[g - 1]);
            while (p > 0) {
                unsigned char resulter = resulting[p - 1];
                long int bit2 = resulter;
                long int sum;
                sum = bit1 * bit2 + carry;
                carry = sum / SYSTEM;
                result[k] += sum % SYSTEM;
                if (result[k] >= SYSTEM) {
                    carry += result[k] / SYSTEM;
                    result[k] = result[k] % SYSTEM;
                }
                if (p > 0) {
                    p--;
                }
                k--;
            }
            if (carry > 0) {
                result[k] = carry;
                carry = 0;
            }
            k = max_length - 2 - (lengthNum - g);

            if (g > 0) {
                g--;
            }

            p = lengthResult;
        }
        free(num);
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////

    int zeroCount = 0;
    for (int i = 0; i < max_length; i++) {
        if (result[i] == 0) {
            zeroCount++;
        } else {
            break;
        }
    }
    printf("The result: ");
    for (int i = zeroCount; i < max_length; i++) {
        printf("%X", result[i]);
    }
    free(result);
    free(resulting);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Bad input.");
        return EXIT_FAILURE;
    }
    FILE *infile = fopen(argv[1], "r");
    if (infile == NULL) {
        printf("Bad allocation.");
        return EXIT_FAILURE;
    }
    char *line;
    int numLines = 0;
    char **lines = NULL;
    while ((line = getLiner(infile, lines, numLines)) != NULL) {
        char **temp;
        if ((temp = realloc(lines, (numLines + 1) * sizeof(*lines))) == NULL) {
            printf("lines allocation error");
            for (int i = 0; i < numLines; i++) {
                free(lines[i]);
            }
            free(lines);
            if (fclose(infile) != 0) {
                printf("Error closing the file");
                return EXIT_FAILURE;
            }
            return EXIT_FAILURE;
        }
        lines = temp;
        lines[numLines] = line;
        numLines++;
    }
    if (numLines < 2) {
        fprintf(stderr, "\nIncorrect input error\n");
        for (int h = 0; h < numLines; h++) {
            free(lines[h]);
        }
        free(lines);
        if (fclose(infile) != 0) {
            printf("Error closing the file");
            return EXIT_FAILURE;
        }
        return EXIT_FAILURE;
    }
    char *num_0 = lines[0];
    if (num_0 == NULL) {
        fprintf(stderr, "Error reading the first number from the file\n");
        for (int h = 0; h < numLines; h++) {
            free(lines[h]);
        }
        free(lines);
        if (fclose(infile) != 0) {
            printf("Error closing the file");
            return EXIT_FAILURE;
        }
        return EXIT_FAILURE;
    }
    char *num_1 = lines[1];
    if (num_1 == NULL) {
        fprintf(stderr, "Error reading the second number from the file\n");
        for (int h = 0; h < numLines; h++) {
            free(lines[h]);
        }
        free(lines);
        free(num_0);
        if (fclose(infile) != 0) {
            printf("Error closing the file");
            return EXIT_FAILURE;
        }
        return EXIT_FAILURE;
    }

    multiplyNumbers(infile, num_0, num_1, lines, numLines);

    free(lines);
    free(num_0);
    free(num_1);
    fclose(infile);
    return 0;
}