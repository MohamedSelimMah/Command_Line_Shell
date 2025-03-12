#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

// Function to check if a file exists and is executable
int is_executable(const char *path) {
    return access(path, X_OK) == 0; // `access` checks if the file at `path` is executable
}

// Function to search for a command in the PATH
char *find_in_path(const char *command) {
    char *path_env = getenv("PATH"); // Get the PATH environment variable
    if (path_env == NULL) {
        return NULL; // If PATH is not set, return NULL
    }

    char *path_copy = strdup(path_env); // Create a modifiable copy of PATH
    if (path_copy == NULL) {
        return NULL; // Return NULL if memory allocation fails
    }

    char *save_ptr;
    char *dir = strtok_r(path_copy, ":", &save_ptr); // Split PATH into directories using ":"
    static char full_path[1024]; // Buffer to store the full path of the command

    while (dir != NULL) {
        // Construct the full path of the command
        snprintf(full_path, sizeof(full_path), "%s/%s", dir, command);
        if (is_executable(full_path)) { // Check if the file is executable
            free(path_copy); // Free the allocated memory
            return full_path; // Return the full path of the command
        }
        dir = strtok_r(NULL, ":", &save_ptr); // Move to the next directory
    }

    free(path_copy); // Free the allocated memory
    return NULL; // Command not found in PATH
}

// Function to handle the 'type' command
void handle_type(char *args) {
    const char *builtins[] = {"echo", "exit", "type", NULL}; // List of built-in commands

    // Check if the argument matches any built-in command
    for (int i = 0; builtins[i] != NULL; i++) {
        if (strcmp(args, builtins[i]) == 0) {
            printf("%s is a shell builtin\n", args); // Output that it is a built-in command
            return;
        }
    }

    char *path = find_in_path(args); // Search for the command in PATH
    if (path) {
        printf("%s is %s\n", args, path); // Output the full path if found
    } else {
        printf("%s: not found\n", args); // Output not found message
    }
}

// Main function
int main() {
    setbuf(stdout, NULL); // Disable buffering for stdout to ensure immediate output
    char input[1024]; // Buffer for user input

    while (1) {
        printf("$ "); // Display the shell prompt
        if (fgets(input, sizeof(input), stdin) == NULL) { // Read input from the user
            continue; // Continue to the next iteration if input is NULL
        }

        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0'; // Remove the newline character from the input
        }

        if (strlen(input) == 0) { // Skip if the input is empty
            continue;
        }

        // Split input into arguments
        char *args[100]; // Array to store arguments
        int arg_count = 0;
        char *token = strtok(input, " "); // Split the input by spaces
        while (token != NULL && arg_count < 99) {
            args[arg_count++] = token; // Store each token in the arguments array
            token = strtok(NULL, " "); // Get the next token
        }
        args[arg_count] = NULL; // Null-terminate the arguments array

        if (arg_count == 0) { // Skip if no arguments were provided
            continue;
        }

        // Handle built-in commands
        if (strcmp(args[0], "echo") == 0) { // If the command is 'echo'
            for (int i = 1; i < arg_count; i++) {
                printf("%s", args[i]); // Print each argument
                if (i != arg_count - 1) {
                    printf(" "); // Add a space between arguments
                }
            }
            printf("\n"); // End with a newline
        } else if (strcmp(args[0], "type") == 0) { // If the command is 'type'
            if (arg_count < 2) { // Ensure the command has an argument
                printf("type: missing argument\n");
            } else {
                handle_type(args[1]); // Check the type of the given argument
            }
        } else if (strcmp(args[0], "exit") == 0) { // If the command is 'exit'
            if (arg_count >= 2 && strcmp(args[1], "0") == 0) { // Validate the exit argument
                exit(0); // Exit the shell
            } else {
                fprintf(stderr, "exit: invalid argument\n"); // Output an error message
            }
        } else {
            // Handle external commands
            char *path = find_in_path(args[0]); // Search for the command in PATH
            if (path) {
                pid_t pid = fork(); // Create a child process
                if (pid == -1) { // Check for fork errors
                    perror("fork");
                } else if (pid == 0) { // In the child process
                    execv(path, args); // Execute the command
                    perror("execv"); // Output an error if execv fails
                    exit(1); // Exit with an error code
                } else { // In the parent process
                    int status;
                    waitpid(pid, &status, 0); // Wait for the child process to complete
                }
            } else {
                printf("%s: command not found\n", args[0]); // Output if the command is not found
            }
        }
    }

    return 0;
}
