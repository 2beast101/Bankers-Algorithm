# Bankers-Algorithm
Compile:
clang++ -Wall bankersAlgorithm.cpp -o bankersAlg
Execute:
./bankersAlg *filename*
If a filename is not provided, values for processes, and resources will need to be entered manually.

If the processes do not have enough resources to execute without a deadlock, the program will exit, and display a message saying there is a deadlock
If the processes do have enough resources to execute without a deadlock, the program will display a safe sequence that the processes can be executed in order for safe execution.

There is a sample text document that is provided for testing of the algorithm. 
When using a separate file, you must only have 5 processes, with 3 resources each.
Print the allocation of the processes first, separated by a space, and 3 per line.
Next, the max, with the same format as allocation. 
Then, the available on the last line, with the same format as before.


Screenshot of after execution:
![Screenshot 2023-04-28 230033](https://user-images.githubusercontent.com/15059428/235280747-990488a2-d225-4852-9d52-ded02424144c.png)





As you can see, there is a safe sequence for these processes, and it prints a sequence that will run these processes safely.
