# µShell v1.0 - Minimal Unix-like Shell Implementation

[![C Standard](https://img.shields.io/badge/C-ISO%20C99-blue)](https://iso.org/standard/29237.html)
[![License: MIT](https://img.shields.io/badge/License-MIT-green)](LICENSE)
[![Platform: POSIX](https://img.shields.io/badge/Platform-POSIX-lightgrey)](https://pubs.opengroup.org/onlinepubs/9699919799/)

**A lightweight shell demonstrating core operating system concepts**  
*"Learn by building the tools you use every day"*

---

## 🚀 Key Features

### 🛠️ Built-in Commands
| Command    | Description                          | Implementation Example          |
|------------|--------------------------------------|----------------------------------|
| `cd`       | Directory navigation                 | `chdir()` system call            |
| `echo`     | Argument expansion                   | String processing with `va_args` |
| `type`     | Command type detection               | `stat()` path resolution         |
| `pwd`      | Current working directory            | `getcwd()` system call           |
| `exit`     | Shell termination                    | Clean process tree management    |

### 🌟 Core Functionality
- **External Command Execution**
  - PATH environment variable resolution
  - `fork()`/`execv()` process management
  - Background process detection (`&` suffix)
- **Input Handling**
  - Tokenization with configurable delimiters
  - Basic signal handling (SIGINT for Ctrl+C)
  - Command history buffer (Up/Down arrow support)
- **Error Handling**
  - Comprehensive error messages
  - Graceful failure recovery
  - Zombie process prevention

---

## 📦 Installation & Usage

### Compilation
   ```bash
   gcc main.c -o simple_shell
   ```
### Run
   ```bash
   ./simple_shell
   ```
### Example Commands:
   ```bash
   $ echo Hello, World!
   $ type ls
   $ ls
   $ exit 0
   ```

📚 Learning Resources
Core Concepts Demonstrated

    Process creation/management (fork, exec, waitpid)

    Environment variable manipulation

    File descriptor management

    Signal handling fundamentals

    Memory management best practices

Recommended Reading

    Advanced Programming in the UNIX Environment

    Linux System Programming

    POSIX.1-2017 Specification

🛠️ Development Roadmap
v1.1 Planned Features

    I/O Redirection (>, <, >>)

    Pipeline support (|)

    Background job control (jobs, fg, bg)

    Tab-completion

    Configuration file support

⚠️ Safety Notice

This is an educational tool - not a production-grade shell!

    No permission management

    Limited error recovery

    Basic security features

    Always test in contained environments

🤝 Contribution Guidelines

    Fork the repository

    Create feature branch (git checkout -b feature/amazing-feature)

    Commit changes (git commit -m 'Add amazing feature')

    Push branch (git push origin feature/amazing-feature)

    Open Pull Request

µShell v1.0 - Created for developers curious about systems programming
"The best way to understand a system is to build it from scratch" 🔧
