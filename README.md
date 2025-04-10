# Simple C Shell

A lightweight Unix-like shell implementation in C, supporting built-in commands and execution of external programs.

## Features

- **Built-in Commands**:
  - `echo`: Display arguments
  - `cd`: Change directory
  - `pwd`: Print working directory
  - `type`: Identify command type (built-in or system)
  - `exit`: Quit shell
  - `cat`: Display file contents
  - `clear`: Clear terminal screen
  - `sort`: Sort file contents
  - `head`: Show file head (with `-n` option)
  - `grep`: Pattern search (supports `-i`, `-n`, `-v` options)
  - `help`: Show help documentation

- **External Command Execution**: Searches PATH for valid executables
- **Basic Error Handling**: Clear error messages for common issues
- **Interactive Interface**: Familiar shell prompt experience

## Installation & Usage

1. Compile the shell:
   ```bash
   gcc main.c -o shell

    Run the executable:
    bash
    Copy

    ./shell

    Enter commands at the prompt:
    Copy

    $ pwd
    /home/user
    $ help grep

Built-in Command Examples

    File Operations:
    bash
    Copy

    cat document.txt
    sort lines.txt
    head -n 5 largefile.log

    Searching:
    bash
    Copy

    grep -i "error" system.log
    grep -nv "debug" app.log

    System Navigation:
    bash
    Copy

    cd ~/projects
    pwd

    Information:
    bash
    Copy

    type ls          # Shows ls executable path
    help cd          # Displays cd documentation

Limitations

    No I/O redirection (pipes, >, <)

    Limited error recovery

    No background processes (&)

    Basic argument parsing (no quoting support)

Contribution

Contributions welcome! Please open an issue to discuss proposed changes before submitting PRs.
License

MIT License (include appropriate license file)   
