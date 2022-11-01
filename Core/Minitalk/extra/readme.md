Minitalk methodolgy: 

1) set up server to write its PID onto the terminal when started. (done)

2) set up client to take both the server PID and the string to be sent. 

3) split up each character of the string to be sent to server by character, convert character to binary based on the corresponding int value. 

4) send the sets of int values to server using SIGUSR1 (0) and SIGUSR2 (1), as binary values. 
(find way to actually do this so that it is clear when the end of each character is achieved) (maybe have entirely 8 bits characters)

5) write character to stdout, until the sent signal is \0 (0 or 128, figure it out)