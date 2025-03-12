#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/* Check if we can run this file like a proper program */
int is_executable(const char *path) {
    return access(path, X_OK) == 0;
}

/* Hunt through system folders to find where a command lives */
char *find_in_path(const char *command) {
    char *path_env = getenv("PATH");
    if (!path_env) return NULL;

    char *path_copy = strdup(path_env);
    if (!path_copy) return NULL;

    char *save_ptr;
    char *dir = strtok_r(path_copy, ":", &save_ptr);
    static char full_path[1024];  // Persistent buffer for path construction

    while (dir) {
        snprintf(full_path, sizeof(full_path), "%s/%s", dir, command);
        if (is_executable(full_path)) {
            free(path_copy);
            return full_path;
        }
        dir = strtok_r(NULL, ":", &save_ptr);
    }

    free(path_copy);
    return NULL;  // Search failed
}

/* Tell users if a command is built-in or where it's located */
void handle_type(char *args) {
    const char *builtins[] = {"echo", "exit", "type","pwd", NULL};

    // Check against built-in commands
    for (int i = 0; builtins[i]; i++) {
        if (strcmp(args, builtins[i]) == 0) {  // Fixed: proper comparison
            printf("%s is a shell builtin\n", args);
            return;
        }
    }

    // Search PATH if not built-in
    char *path = find_in_path(args);
    if (path) {
        printf("%s is %s\n", args, path);
    } else {
        printf("%s: not found\n", args);
    }
}

/* Our shell's main loop - keeps things running until exit */
int main() {
    setbuf(stdout, NULL);  // Immediate output for interactive feel
    char input[1024];

    while (1) {
        printf("$ ");
        if (!fgets(input, sizeof(input), stdin)) continue;

        input[strcspn(input, "\n")] = 0;  // Cleaner newline removal
        if (!input[0]) continue;  // Skip empty commands

        // Split command into arguments
        char *args[100];
        int arg_count = 0;
        char *token = strtok(input, " ");

        while (token && arg_count < 99) {
            args[arg_count++] = token;
            token = strtok(NULL, " ");
        }
        args[arg_count] = NULL;

        if (!arg_count) continue;

        // Handle built-in commands
        if (strcmp(args[0], "echo") == 0) {
            for (int i = 1; i < arg_count; i++) {
                printf("%s%s", args[i], (i == arg_count-1) ? "\n" : " ");
            }
            if (arg_count == 1) printf("\n");  // Handle bare 'echo'
        }
        else if (strcmp(args[0], "type") == 0) {
            if (arg_count < 2) {
                printf("type: missing argument\n");
            } else {
                handle_type(args[1]);
            }
        }
        else if (strcmp(args[0], "exit") == 0) {
            if (arg_count >= 2 && strcmp(args[1], "0") == 0) {
                exit(0);  // Valid exit
            } else {
                fprintf(stderr, "exit: invalid argument\n");  // Error message
                exit(1);
            }
        }
        else if (strcmp(args[0], "pwd") == 0) {
            char cwd[1024];
            getcwd(cwd, sizeof(cwd));
            printf("%s\n", cwd);
        }
        else {
            // Handle external programs
            char *path = find_in_path(args[0]);
            if (!path) {
                printf("%s: command not found\n", args[0]);
                continue;
            }

            pid_t pid = fork();
            if (pid == -1) {
                perror("fork");
            } else if (!pid) {
                execv(path, args);
                perror("execv");
                exit(1);
            } else {
                waitpid(pid, NULL, 0);  // Wait for child completion
            }
        }
    }

    return 0;
}