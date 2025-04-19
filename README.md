# 🐚 Simple C Shell v2.0

A lightweight Unix-like shell implementation in C, supporting built-in commands and execution of external programs. Perfect for learning shell fundamentals! 🧠

---

## 🚀 Features

### 🛠️ Built-in Commands
| Command  | Emoji | Description                  |
|----------|-------|------------------------------|
| `echo`   | 📢   | Display arguments            |
| `cd`     | 📂   | Change directory             |
| `pwd`    | 🗺️   | Print working directory      |
| `type`   | 🔍   | Identify command type        |
| `exit`   | 🚪   | Quit shell                   |
| `cat`    | 🐈   | Display file contents        |
| `clear`  | 🧹   | Clear terminal screen        |
| `sort`   | 🔢   | Sort file contents           |
| `head`   | 👆   | Show file head               |
| `grep`   | 🔎   | Pattern search               |
| `rm`     | 🗑️   | Remove files or directories  |
| `mv`     | 🔀   | Move or rename files         |
| `cp`     | 📄   | Copy files or directories    |
| `mkdir`  | 📁   | Create directories           |
| `help`   | ❓   | Show help documentation      |
| `ps`     | 📊   | Show process status          |
| `df`     | 💽   | Show disk usage              |
| `top`    | 📈   | Show real-time system stats  |

- 🌐 **External Command Execution**: Searches `PATH` for valid executables  
- 🛡️ **Error Handling**: Clear error messages for common issues  
- 💻 **Interactive Interface**: Familiar shell prompt experience

---

## 📦 Installation & Usage

### Compile the Shell 🔧
```bash
gcc main.c -o shell
```

### Run the Executable 🚀
```bash
./shell
```

### Start Exploring 🔭
```bash
$ pwd
/home/user
$ help grep
```

---

## 📚 Examples

### 📂 File Operations
```bash
cat document.txt          # 🐈 Display file
sort lines.txt            # 🔢 Sort content
head -n 5 log.txt         # 👆 Show first 5 lines
rm file.txt               # 🗑️ Remove a file
rm -r folder              # 🗑️ Remove a directory
mv file1 file2            # 🔀 Rename or move a file
cp source.txt dest.txt    # 📄 Copy a file
mkdir new_folder          # 📁 Create a new directory
```

### 🔍 Searching
```bash
grep -i "error" system.log   # 🔎 Case-insensitive search
grep -nv "debug" app.log     # 🔍 Inverted match with line numbers
```

### 🧭 Navigation
```bash
cd ~/projects  # 📂 Change directory
pwd            # 🗺️ Show current path
```

### ℹ️ Information
```bash
type ls    # 🔍 Shows executable path
help cd    # ❓ Displays documentation
```

### 📊 System Monitoring
```bash
ps               # 📊 Show current shell processes
ps -e            # 📊 Show all processes
ps -u root       # 📊 Show processes by user
ps aux           # 📊 BSD-style output of all processes

df               # 💽 Show filesystem usage
df -h            # 💽 Human-readable sizes
df -T            # 💽 Show filesystem types

top              # 📈 Real-time CPU/memory usage
top -u username  # 📈 Filter by user
top -n 1         # 📈 Run for 1 iteration
```

---

## 🤝 Contribution

Contributions welcome! 🎉 Please:

1. 🐛 Open an issue to discuss changes  
2. 🌱 Fork the repository  
3. ✨ Create a feature branch  
4. 📝 Submit a PR with a detailed description  

---

## 📜 License

MIT License © 2023 Mohamed Selim Mahjoub

---

### Author
👨💻 **Mohamed Selim Mahjoub**
