# Terminal Intercepter

This is a simple C project for experimenting with process output interception and basic terminal monitoring on Windows.

## What does it do?
- Contains a test program (`test.c`) that prints numbers from 0 to 99.
- (Planned) Will include a tool to run a process, monitor its output, and send CTRL+C if a keyword is found.

## How to build

You need a C compiler (like GCC/MinGW or MSVC) installed.

### Using GCC (MinGW):
```
gcc -o test.exe test.c
```

### Using MSVC (Developer Command Prompt):
```
cl test.c
```

## How to run

After building, run the test program:
```
./test.exe
```

It will print numbers from 0 to 99, each on a new line.

---

This project is for educational and experimental purposes. 