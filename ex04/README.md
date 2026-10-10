# PROGRAM 4 : PROCESS CREATION AND MANAGEMENT USING LINUX SYSTEM CALLS

## AIM :
To study process creation, execution, and synchronization using Linux process system calls:
• fork()
• exec()
• wait()
• getpid()
• getppid()
and to understand parent-child process relationships.

## CONTEXT :
A process is a program that is currently being executed. Linux allows a process to create another process (called a child process) and manage its execution.

## LINUX SYSTEM CALLS USED :

| System Call | Function |
|---|---|
| `fork()` | Creates a new child process by duplicating the current (parent) process. |
| `getpid()` | Returns the Process ID (PID) of the currently executing process. |
| `getppid()` | Returns the Process ID (PID) of the parent process. |
| `wait()` | Suspends the parent process until the child process terminates. |
| `sleep()` | Suspends the execution of the current process for the specified number of seconds. *(Library function that internally uses kernel timing services; often included in OS labs.)* |

## SOURCE CODE (Process Creation) :
**File:** [forkDemo.c](https://github.com/Balakrishna0907/osLab/blob/e8972d1e2c1c5162f3e1aace93b050e4c35a48ce/ex04/ProcessCreation/forkDemo.c)

## COMPILATION :

```bash
gcc forkDemo.c -o forkDemo
```

## EXECUTION :

```bash
./forkDemo
```
## OUTPUT :
![Output for Experiment 4_1](https://github.com/Balakrishna0907/osLab/blob/bbd57840d65e577ebc3f1ccb8af1c27f3ae0d7f9/ex04/ProcessCreation/output.png)

## SOURCE CODE (Process Management) :
**File:** [waitDemo.c](https://github.com/Balakrishna0907/osLab/blob/a9928e50c1662a83b886dab3a6e66849dd5a23b8/ex04/ProcessManagement/waitDemo.c)

## COMPILATION :

```bash
gcc waitDemo.c -o waitDemo
```

## EXECUTION :

```bash
./waitDemo
```

## OUTPUT :
![Output for Experiment 4_2](https://github.com/Balakrishna-0907/osLab/blob/e8a9597fae7039c2f34e5a07f86a4869e41d1b11/ex04/ProcessManagement/output.png)
