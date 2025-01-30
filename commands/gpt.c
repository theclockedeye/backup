#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COMMANDS_FILE_PATH "C:\\commands\\commands.txt"

void run(char buffer[]);
void create_file(char buffer[]);
void remove_file(char buffer[]);
void add();
void remove_alias();
void show();
void execute_command(const char *command);

void run(char buffer[]) {
    if (strcmp(buffer, "add") == 0) {
        add();
    } else if (strcmp(buffer, "remove_alias") == 0) {
        remove_alias();
    } else if (strcmp(buffer, "show") == 0) {
        printf("\n");
        system("type " COMMANDS_FILE_PATH);
        printf("\n");
    } else {
        FILE *file = fopen(COMMANDS_FILE_PATH, "r");
        if (file == NULL) {
            perror("Error opening commands.txt");
            return;
        }

        char line[256];
        int found = 0;
        while (fgets(line, sizeof(line), file)) {
            char *part_one = strtok(line, ":");
            char *part_two = strtok(NULL, "\n");
            if (part_one && part_two) {
                if (strcmp(part_one, buffer) == 0) {
                    execute_command(part_two);
                    found = 1;
                    break;
                }
            }
        }
        fclose(file);
        if (!found) {
            printf("No such command listed!!\n");
        }
    }
}

void create_file(char buffer[]) {
    char *filename = buffer;
    char *extension = strchr(filename, '.');

    char *file_to_create;
    if (extension == NULL) {
        file_to_create = malloc(strlen(filename) + 5);
        sprintf(file_to_create, "%s.txt", filename);
    } else {
        file_to_create = filename;
    }

    FILE *file = fopen(file_to_create, "r");
    if (file != NULL) {
        printf("File '%s' already exists.\n", file_to_create);
        fclose(file);
        return;
    }

    if (extension == NULL) {
        file = fopen(filename, "r");
        if (file != NULL) {
            printf("File '%s' already exists.\n", filename);
            fclose(file);
            return;
        }
    }

    file = fopen(file_to_create, "w");
    if (file == NULL) {
        perror("Error creating file");
        return;
    }
    fclose(file);
    printf("File '%s' created successfully.\n", file_to_create);

    if (extension == NULL) {
        free(file_to_create);
    }
}

void remove_file(char buffer[]) {
    if (remove(buffer) == 0) {
        printf("File '%s' deleted successfully.\n", buffer);
    } else {
        perror("Error deleting file");
    }
}

void add() {
    char name[50];
    char command[256];
    char line[256];

    printf("Enter alias name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    FILE *file = fopen(COMMANDS_FILE_PATH, "r");
    if (file == NULL) {
        file = fopen(COMMANDS_FILE_PATH, "w");
        if (file == NULL) {
            perror("Error creating commands.txt");
            return;
        }
        fclose(file);
        file = fopen(COMMANDS_FILE_PATH, "r");
        if (file == NULL) {
            perror("Error opening commands.txt");
            return;
        }
    }

    while (fgets(line, sizeof(line), file)) {
        char *part_one = strtok(line, ":");
        if (part_one && strcmp(part_one, name) == 0) {
            printf("Alias name already taken, Try another!!\n");
            fclose(file);
            return;
        }
    }
    fclose(file);

    printf("Enter command to be stored: ");
    fgets(command, sizeof(command), stdin);
    command[strcspn(command, "\n")] = 0;

    file = fopen(COMMANDS_FILE_PATH, "a");
    if (file == NULL) {
        perror("Error opening commands.txt");
        return;
    }

    fprintf(file, "%s:%s\n", name, command);
    fclose(file);

    printf("Alias name saved\n\n");
    system("type " COMMANDS_FILE_PATH);
}

void remove_alias() {
    char name[50];
    char line[256];
    char *filename = COMMANDS_FILE_PATH;
    char *tempfile = "commands_temp.txt";

    printf("Enter alias name to be removed: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    FILE *file = fopen(filename, "r");
    FILE *temp = fopen(tempfile, "w");
    if (file == NULL || temp == NULL) {
        perror("Error opening file");
        if (file) fclose(file);
        if (temp) fclose(temp);
        return;
    }

    int found = 0;
    while (fgets(line, sizeof(line), file)) {
        char *part_one = strtok(line, ":");
        char *part_two = strtok(NULL, "\n");
        if (part_one && part_two) {
            if (strcmp(part_one, name) != 0) {
                fprintf(temp, "%s:%s\n", part_one, part_two);
            } else {
                found = 1;
            }
        }
    }

    fclose(file);
    fclose(temp);

    if (found) {
        remove(filename);
        rename(tempfile, filename);
        printf("Alias name removed\n");
    } else {
        remove(tempfile);
        printf("Alias name not found\n");
    }
}

void execute_command(const char *command) {
    system(command);
}

void main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: gpt <anchor_command> <command(s)>");
        exit(0);
    }

    if (strcmp(argv[1], "create") == 0) {
        if (argc >= 3) {
            create_file(argv[2]);
        } else {
            printf("No file name provided for create command.\n");
        }
    } else if (strcmp(argv[1], "remove") == 0) {
        if (argc >= 3) {
            remove_file(argv[2]);
        } else {
            printf("No file name provided for remove command.\n");
        }
    } else {
        run(argv[1]);  // Treat the first argument as a command alias
    }
}
