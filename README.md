CPU Scheduling SImulator
Devin Lucas
Python

This program simulates three CPU scheduling algorithms — First Come First Serve, Shortest Job First, and Round Robin using data from a CSV file. Each algo computes metrics including waiting time, turnaround time, and throughput.

Components:
process.py Defines the Process class and computes timing statistics.
fcfs.py Implements First Come First Serve scheduling
sjf_p.py Implements Shortest Job First (Preemptive)
rr.py Implements Round Robin scheduling
output.py Formats and prints results for each algorithm, including process tables, Gantt charts, and performance metrics
scheduler.py main driver
