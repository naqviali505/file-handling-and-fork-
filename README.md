# file-handling-and-fork-

Write a C++ program which performs following tasks:
Create a student class with the following data member’s roll number (string), marks (int) and grade (char) and member functions including constructor, getter and setters. For this task you will create a separate header file and source files. 
Now create a child process which will:
•	Read data from a student file in an array of student objects. The name of the file is asked from the user.
•	Update student grades from previous I (incomplete) grade using the following grade scheme.


80-100 A

70-79 B

60-69 C

50-59 D

< 50 F




•	
•	write the updated data of each student (with grades assigned) to a file named output.txt








After the child has done its job, the parent process will read the new file created by the child (output.txt) and print the data on the screen. The parent will have to wait until the child has finished execution, so you will need to use the wait() system call in the parent so that the parent stops its execution until the child terminates.
