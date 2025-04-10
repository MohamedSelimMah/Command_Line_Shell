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
gcc -std=c99 -Wall -Wextra -pedantic -o mushell main.c
