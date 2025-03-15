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
    const char *builtins[] = {"echo", "exit", "type","pwd","cd","cat","clear","sort",NULL};

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


// function for the cat command
void print_file(char *args){
    FILE* file = fopen(args,"r");
    if(file == NULL){
        printf("unable to open file%s\n",args);
        return;
    }

    int x;

    while((x = fgetc(file)) != EOF){
        putchar(x);
    }
    fclose(file);
}


//function for sorting

//comapre lines
int compare_lines(const void *a, const void *b){
    return strcmp(*(const char**)a,*(const char **)b);
}
//sort the content
void sort_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("sort: cannot open file '%s'\n", filename);
        return;
    }

    char **lines = NULL;
    size_t line_count = 0;
    size_t capacity = 10;  // Initial capacity for storing lines
    lines = malloc(capacity * sizeof(char *));
    if (!lines) {
        printf("sort: memory allocation failed\n");
        fclose(file);
        return;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file)) {
        if (line_count >= capacity) {
            capacity *= 2;
            char **new_lines = realloc(lines, capacity * sizeof(char *));
            if (!new_lines) {
                printf("sort: memory allocation failed\n");
                for (size_t i = 0; i < line_count; i++) {
                    free(lines[i]);
                }
                free(lines);
                fclose(file);
                return;
            }
            lines = new_lines;
        }
        lines[line_count++] = strdup(buffer);
    }
    fclose(file);

    // Sort the lines
    qsort(lines, line_count, sizeof(char *), compare_lines);

    // Print sorted lines
    for (size_t i = 0; i < line_count; i++) {
        printf("%s", lines[i]);
        free(lines[i]);  // Free each line after printing
    }
    free(lines);  // Free the array of pointers
}

//function for the help command
void help_print(char *command){
    if(command == NULL){
        printf("\n");
        printf("Welcome to my shell. This shell was made by mohamed selim mahjoub, coded with  c language\n");
        printf("\n");
        printf("Here are the available built-in commands :\n");
        printf("\n");
        printf("help            - Display this help message\n");
        printf("\n");
        printf("echo            - Print arguments to the terminal\n");
        printf("\n");
        printf("cd              - Change the current directory\n");
        printf("\n");
        printf("clear           - Clear the terminal screen\n");
        printf("\n");
        printf("sort            - Sort lines of text from a file\n");
        printf("\n");
        printf("exit 0          - Exit the shell\n");
        printf("\n");
        printf("pwd             - Print the current working directory\n");
        printf("\n");
        printf("cat             - Display the content of a file\n");
        printf("\n");
        printf("Use 'help <command>' for more information about a specific command.\n");
        printf("\n");
    }
    else{
        if (strcmp(command, "help") == 0) {
            printf("help: Display information about built-in commands.\n");
            printf("Usage: help [command]\n");
        } else if (strcmp(command, "echo") == 0) {
            printf("echo: Print arguments to the terminal.\n");
            printf("Usage: echo [arguments]\n");
        } else if (strcmp(command, "cd") == 0) {
            printf("cd: Change the current directory.\n");
            printf("Usage: cd [directory]\n");
            printf("       cd ~   - Go to the home directory\n");
        } else if (strcmp(command, "clear") == 0) {
            printf("clear: Clear the terminal screen.\n");
            printf("Usage: clear\n");
        } else if (strcmp(command, "exit") == 0) {
            printf("exit: Exit the shell.\n");
            printf("Usage: exit [status]\n");
            printf("       status - Exit with the specified status (default: 0)\n");
    }
       else if (strcmp(command, "type") == 0) {
            printf("type: Display information about a command.\n");
            printf("Usage: type <command>\n");
        } else if (strcmp(command, "pwd") == 0) {
            printf("pwd: Print the current working directory.\n");
            printf("Usage: pwd\n");
        } else if (strcmp(command, "cat") == 0) {
            printf("cat: Display the contents of a file.\n");
            printf("Usage: cat <file>\n");
        }else if (strcmp(command, "sort") == 0) {
            printf("sort: Sort lines of text from a file or input.\n");
            printf("Usage: sort [file]\n");
        }else {
            printf("help: No help available for '%s'.\n", command);
        }
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
        else if (strcmp (args[0], "cd")==0){
            if (chdir(args[1]) == 0 ) {
                chdir(args[1]);
            }
            else if (strcmp(args[1], "~")==0) {
                chdir(getenv("HOME"));
            }
            else {
                printf("cd : %s: No such  file or directory\n",args[1]);
            }

        }
        else if (strcmp(args[0], "cat") == 0){
            if(arg_count < 2 ){
                printf("cat : missing file \n");
            }
            else{
                for(int i=1 ; i< arg_count; i++){
                    print_file(args[i]);
                }
            }
        }
        else if (strcmp(args[0], "clear")==0){
            printf("\033[H\033[J");
            continue;
        }else if(strcmp(args[0],"help")==0){
            if(arg_count <2 ){
                help_print(NULL);
            }
            else{
                help_print(args[1]);
            }
        }
        else if(strcmp(args[0], "sort")==0){
            if(arg_count < 2){
                printf("sort: missing file\n");
            }else{
                sort_file(args[1]);
            }
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