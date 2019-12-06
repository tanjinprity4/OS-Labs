Processes and pipes
The C program in (pipes_processes.c) creates two processes P1(parent process) and P2(child process). A 2-way communication is created using pipe. P1 takes a string from the prompt and passes it to P2 via a 1-way pipe. P2 concatenates the received string with another string (“howard.edu”) without using string function and prints to the stdout. Then, P2 sends concatenated string back to P1 using second pipe and P1 concatenates “gobison.org” to the string before printing it to stdout.

Output:
Input : www.geeks
Output from child process: www.geekshoward.edu
Output from parent process: www.geekshoward.edugobison.org
