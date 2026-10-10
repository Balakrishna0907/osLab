# PROGRAM 3 : LINUX FILE AND DIRECTORY OPERATIONS USING C SYSTEM CALLS

## AIM :
 To implement basic file and directory operations using Linux system calls such as `open()`, `read()`, `write()`, `close()`, `stat()`, `mkdir()`, `opendir()`, and `readdir()`. 

## CONTEXT :
This C program demonstrates the use of Linux system calls for performing file and directory operations.

## LINUX SYSTEM CALLS USED :

| System Call | Function |
|---|---|
| `open()` | Opens an existing file or creates a new file and returns a file descriptor. |
| `write()` | Writes data from memory to a file. |
| `read()` | Reads data from a file into a buffer. |
| `close()` | Closes an opened file descriptor and releases resources. |
| `stat()` | Retrieves information about a file, such as size, permissions, and number of links. |
| `mkdir()` | Creates a new directory with the specified permissions. |
| `opendir()` | Opens a directory stream for reading its contents. |
| `readdir()` | Reads one directory entry at a time from the opened directory. |
| `closedir()` | Closes the opened directory stream. |


## SOURCE CODE :
**File :** [fileOperation.c](https://github.com/Balakrishna0907/osLab/blob/2f321c83044d726bc83bb6073285cff000b15f05/ex03/fileOperation.c)

## COMPILATION :

```bash
gcc fileOperation.c -o fileOperation
```

## EXECUTION :

```bash
./fileOperation
```

## OUTPUT :
![Output for Experiment 3](https://github.com/Balakrishna0907/osLab/blob/3f1a8bc30b394d151354f5fb26518b4f1eda0cf5/ex03/output.png)
