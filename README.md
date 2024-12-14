# RealTime Signals Demo
A simple test to demonstrate how to send and receive data sent along with realtime signals. It consists of 2 programs, a sender and a receiver. The receiver remains in an infinite loop until it receives 0, terminate, or 1, abort, from the sender using `SIGRTMIN`.

### Compilation
```
gcc -o rtRec rtRec.c
gcc -o rtSend rtSend.c
```
### Usage
Run the receiver first:
```
./rtRec
```
Then from another terminal run the sender using this format:
```
./rtSend pid val
```

## Example
Terminal 1:
```
~$ ./rtRec 
Waiting for signal...
Aborting Process...
Aborted (core dumped)
~$
```
Terminal 2:
```
~$ ./rtSend 24488 1
```
