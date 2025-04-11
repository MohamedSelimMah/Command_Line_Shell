# 🐚 Simple C Shell 
A lightweight Unix-like shell implementation in C, supporting built-in commands and execution of external programs. Perfect for learning shell fundamentals! 🧠 
## 🚀 Features

### 🛠️ Built-in Commands
| Command   | Emoji | Description                      |
|-----------|-------|----------------------------------|
| `echo`    | 📢    | Display arguments                |
| `cd`      | 📂    | Change directory                 |
| `pwd`     | 🗺️    | Print working directory          |
| `type`    | 🔍    | Identify command type            |
| `exit`    | 🚪    | Quit shell                       |
| `cat`     | 🐈    | Display file contents            |
| `clear`   | 🧹    | Clear terminal screen            |
| `sort`    | 🔢    | Sort file contents               |
| `head`    | 👆    | Show file head                   |
| `grep`    | 🔎    | Pattern search                   |
| `help`    | ❓    | Show help documentation          |

- **🌐 External Command Execution**: Searches PATH for valid executables
- **🛡️ Error Handling**: Clear error messages for common issues
- **💻 Interactive Interface**: Familiar shell prompt experience

## 📦 Installation & Usage

1. **Compile the shell** 🔧
   ```bash
   gcc main.c -o shell
   ```

2. **Run the executable** 🚀
   ```bash
   ./shell
   ```

3. **Start exploring** 🔭
   ```bash
   $ pwd
   /home/user
   $ help grep
   ```

## 📚 Examples

### 📂 File Operations
```bash
cat document.txt  # 🐈 Display file
sort lines.txt    # 🔢 Sort content
head -n 5 log.txt # 👆 Show first 5 lines
```

### 🔍 Searching
```bash
grep -i "error" system.log  # 🔎 Case-insensitive search
grep -nv "debug" app.log    # 🔍 Inverted match with line numbers
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

## 🤝 Contribution

**Contributions welcome!** 🎉 Please:
1. 🐛 Open an issue to discuss changes
2. 🌱 Fork the repository
3. ✨ Create a feature branch
4. 📝 Submit a PR with detailed description

## 📜 License

[MIT License](LICENSE) © 2023 Mohamed Selim Mahjoub

---

**Author**: 👨💻 Mohamed Selim Mahjoub  
