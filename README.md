# 📜 About `pipex`

The goal of the `pipex` project is to deepen your understanding of Unix process and pipe management by recreating the shell behavior of piping commands together using the `|` (pipe) operator.

This project teaches you how to create and manage multiple processes, how to redirect input/output using file descriptors, and how to connect processes using pipes — fundamental skills for systems and shell programming.

## 🛠️ How to use
- Clone or add the `pipex` repository into the root directory of your project.
- Use the `make` command to build the project.
- Execute the program with the following syntax:
```bash
./pipex infile "cmd1" "cmd2" outfile
```
This emulates the following shell behavior:
```bash
< infile cmd1 | cmd2 > outfile
```
### Example:
```bash
./pipex input.txt "grep a" "wc -l" output.txt
```
This is equivalent to:
```bash
< input.txt grep a | wc -l > output.txt
```
## 🔍 How it works
`pipex` uses Unix system calls such as `fork`, `execve`, `dup2`, and `pipe` to:
- Redirect the input of cmd1 from the infile
- Pipe the output of cmd1 into the input of cmd2
- Redirect the final output into outfile

## Mandatory Features
- Handle exactly two commands.
- Support quoted commands with arguments (e.g., "ls -la").
- Correctly manage input/output redirection.
- Close all unused file descriptors.
- Wait for child processes to finish.

## Bonus Features
- Support multiple commands as in:
```bash
./pipex file1 "cmd1" "cmd2" "cmd3" ... "cmdn" file2
```
- Support here_doc behavior:
```bash
./pipex here_doc LIMITER "cmd1" "cmd2" file
```
which emulates:
```bash
<< LIMITER cmd1 | cmd2 >> file
```
## 📂 Repository Structure
- [`Makefile`](Makefile) - Makefile of the project. Builds the project.
### 📂 Includes
- [`pipex.h`](includes/pipex.h) - Function declarations and includes.
- [`get_next_line.h`](includes/get_next_line.h) - `get_next_line` function declaration.
### 📂 Sources
- [`pipex.c`](srcs/pipex.c) - Main logic: handles argument parsing and setup.
- [`init_pipex.c`](srcs/init_pipex.c) - Initialization: parses arguments, allocates memory.
- [`free_pipex.c`](srcs/free_pipex.c) - Frees all the memory and closes all the fds.
- [`children.c`](srcs/children.c) - Handles child processes and `here_doc` logic.
- [`executes.c`](srcs/executes.c) - Handles cmd and script executions.
- [`get_next_line.c`](srcs/get_next_line.c) - `get_next_line` function implementation.
- [`get_next_line_utils.c`](srcs/get_next_line_utils.c) - Helper for `get_next_line` function.

# 🧱 System Calls Used
- `fork()` - Creates a child process.
- `execve()` - Replaces the current process image with a new one.
- `dup2()` - Duplicates file descriptors for redirection.
- `pipe()` - Creates a unidirectional data channel.
- `wait()` - Waits for child processes to terminate.
- `access()` - Checks if a file exists and is executable.
- `open()` - Opens a file for reading or writing.
- `close()` - Closes file descriptors.

# 🧠 Learning Objectives
- Deepen understanding of processes and file descriptors.
- Learn to chain programs and build Unix-like behavior.
- Get comfortable with system-level programming in C.

# 🤝 Contributing
Bug reports and suggestions are welcome! Open an issue or submit a pull request if you’d like to improve this project.

