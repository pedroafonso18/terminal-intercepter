# Terminal Intercepter

This is a simple C project for experimenting with process output interception and basic terminal monitoring on Windows.

## What does it do?
- Contains a test program (`test.c`) that prints numbers from 0 to 99.
- Includes a tool (`main.c`) that runs a process, monitors its output for a keyword, and sends CTRL+C (SIGINT) to the process if the keyword is found in its output.

## How to build

You need a C compiler (like GCC/MinGW or MSVC) installed.

### Using GCC (MinGW):
```
gcc -o test.exe test.c

gcc -o monitor.exe main.c
```

### Using MSVC (Developer Command Prompt):
```
cl test.c

cl main.c
```

## How to run

### Run the test program:
```
./test.exe
```
It will print numbers from 0 to 99, each on a new line.

### Run the monitor tool:
```
./monitor.exe
```
You will be prompted to enter:
- The keyword you want to find in the process output.
- The command to run the process you want to monitor.

The tool will launch the process, monitor its output, and if the keyword is found, it will send CTRL+C to stop the process.

---

This project is for educational and experimental purposes. 