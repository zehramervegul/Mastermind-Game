# Mastermind Game


## Description

The idea of the game is, one side holds a secret number and the other side(user) proposes numbers and gets useful hints at each turn. The aim of the user is to guess the secret number. 

## Game Rules

1)A digit is an integer in the range[0,9] 
2)A valid number is defined to be an N digit number (N≤9) where the high-most (leftmost) digit cannot be0andany digit appears only once in the number.
3)Your program chooses a valid number (secret number). 
	–First option is to generate a random number (it must be a valid number)
	–Second option is to use a given number (a number will be provided as a command-line argument)
4)(At each turn) the code breaker (user) proposes a valid number. Turns are counted (Starting with 1).
5)As response to the proposal, the code maker(program) provides two counts:
	– First count(Cexact): The count of digits of the proposed number that match in place of the secretnumber.
	– Second count(Cmisplaced): The count of digits of the proposed number which do exist in the secretnumber but are not in place.
6)A C exactvalue of N stops the game and the turn-count is recorded; otherwise the game continues with accepting user proposals. 


### Executing program

* Type below in your terminal
```
gcc -c mastermind.cpp -o mastermind
```
* And then type to run
	if random number
```
./mastermind -r
```
* 	if user given number
```
./mastermind -u USERNUMBER
```



## Authors

Zehra Merve Gül


## Version History

* 0.1
    * Initial Release
