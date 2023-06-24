#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void copyFile(FILE *sourceFile, FILE *destinationFile, int option) {
    char ch;
    while ((ch = fgetc(sourceFile)) != EOF) {
        switch (option) {
            case 1: // -u: Convert to Upper Case
                fputc(toupper(ch), destinationFile);
                break;
            case 2: // -l: Convert to Lower Case
                fputc(tolower(ch), destinationFile);
                break;
            case 3: // -s: Convert to Purely Upper Case
                if (islower(ch))
                    fputc(toupper(ch), destinationFile);
                else
                    fputc(ch, destinationFile);
                break;
            default: // No option: Normal Copy
                fputc(ch, destinationFile);
                break;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: ./cp [-u | -l | -s] source_file destination_file\n");
        return 1;
    }

    FILE *sourceFile, *destinationFile;
    int option = 0;

    // Check if an option is provided
    if (argc > 3) {
        if (argv[1][0] == '-') {
            switch (argv[1][1]) {
                case 'u':
                    option = 1;
                    break;
                case 'l':
                    option = 2;
                    break;
                case 's':
                    option = 3;
                    break;
                default:
                    printf("Invalid option: %s\n", argv[1]);
                    return 1;
            }
        } else {
            printf("Invalid option: %s\n", argv[1]);
            return 1;
        }
    }

    // Open the source file in text mode
    sourceFile = fopen(argv[argc - 2], "r");
    if (sourceFile == NULL) {
        printf("Unable to open the source file.\n");
        return 1;
    }

    // Open the destination file in text mode
    destinationFile = fopen(argv[argc - 1], "w");
    if (destinationFile == NULL) {
        printf("Unable to create the destination file.\n");
        fclose(sourceFile);
        return 1;
    }

    // Copy the contents of the source file to the destination file
    copyFile(sourceFile, destinationFile, option);

    printf("File copied successfully.\n");

    // Close the files
    fclose(sourceFile);
    fclose(destinationFile);

    return 0;
}
