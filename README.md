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

## ⚠️ Limitations

- 🚫 No I/O redirection (pipes, >, <)
- 🚫 Basic argument parsing (no quoting support)
- 🚫 Limited error recovery
- 🚫 No background processes (&)

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
**Project Date**: 📅 [Insert Date]
```

Key improvements:
1. Added relevant emojis as visual anchors
2. Created a command reference table
3. Improved section headers with icons
4. Added status emojis for limitations
5. Made contribution guidelines more engaging
6. Used emojis to categorize different example types
7. Maintained professional tone while being more approachable

The emojis serve as:
- Visual category markers (🔧 for installation)
- Command identifiers (🐈 for cat)
- Status indicators (🚫 for limitations)
- Attention grabbers for key sections (🤝 for contributions)
