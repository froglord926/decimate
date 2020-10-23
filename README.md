# decimate


			 ____ _____  ____ _ __  __  ___
			|  _ \___ / / ___/ |  \/  |( _ )
			| | | ||_ \| |   | | |\/| |/ _ \
			| |_| |__) | |___| | |  | | (_) |
			|____/____/ \____|_|_|  |_|\___/
						DECIMATE
				a language of numbers
		
		Contents:
			-Basics
			-Operators
			-Loops
			-Examples
		
 _               _
| |__   __ _ ___(_) ___ ___
| '_ \ / _` / __| |/ __/ __|
| |_) | (_| \__ \ | (__\__ \
|_.__/ \__,_|___/_|\___|___/
	
	All numbers are variables. You select a number to make that the "working number" which operators will operate on.
	Numbers can be set to other number and then get their value.
	Syntax go like <selector><operator><sometimes number-blocks>
	Selectors select a number
	Some operators require a number to be selected, such as the + operator.
	Operators require a number-blocks afterwards.
	number-blocks are a set of digits 0-9 ending with |
		Each digit will be raised to the power 10 one more time than the one before
		With a number-set of
		0	1	2	3	4	5	6	7	8	9
		the number-block 465| would output the numeric value of 465 (4*100+6*10+5)
		With a number-set of
		5	15	3	8	35	4	1	100	69	9
		the number-block 465| would output the numeric value of 3514 (35*100+1*10+4)
	The system will ignore all chars that are not operators, loop initators, or numbers
	Run it through command line, either using the provided windows bin or compile youself with the given source code.
		./decimate.exe <filename>
	
							_
  ___  _ __   ___ _ __ __ _| |_ ___  _ __ ___
 / _ \| '_ \ / _ \ '__/ _` | __/ _ \| '__/ __|
| (_) | |_) |  __/ | | (_| | || (_) | |  \__ \
 \___/| .__/ \___|_|  \__,_|\__\___/|_|  |___/
      |_|
	
	There are 8 operators
		+
			Must be followed by a number-block
			Adds the following number-block to the selected number
		-
			Same as + but subtracts rather than adds.
		=
			Sets the selected number to the following number-block
		n
			Outputs the following number-block as a number
		a 
			Outputs the following number-block as an ascii char
		b
			Does not reqire a number block to follow
			Outputs the current number set 
		i
			Does not reqire a number block to follow
			Sets the current selected number to the next given integer
			Must be 1 digit integer.
		/
			Starts comment
			End comment with / aswell

 _
| | ___   ___  _ __  ___
| |/ _ \ / _ \| '_ \/ __|
| | (_) | (_) | |_) \__ \
|_|\___/ \___/| .__/|___/
              |_|
			  
	Loops are simple enough
	Start a section to be looped over with : and end it with another :
	It will loop for the ammount of the selected number a the time of initiation subtracting 1 each loop until the number is equal to 0.
	
                                _
  _____  ____ _ _ __ ___  _ __ | | ___  ___
 / _ \ \/ / _` | '_ ` _ \| '_ \| |/ _ \/ __|
|  __/>  < (_| | | | | | | |_) | |  __/\__ \
 \___/_/\_\__,_|_| |_| |_| .__/|_|\___||___/
                         |_|
						 	
/operator demonstartion/    9=13|n19|a100|+1|n9|-5|b|a10|
/lame hello world/          a104|a101|a108|a108|a111|a32|a119|a111|a114|a108|a100|a10|
/cooler hello world/        1=104|-3|2=1|1+3|+4|3=1|1-4|4=3|9-8|5=92|6=5|+8|7=5|8=6|-3|+1|-9|0=900|9=4|b|
                            a1|a2|a3|a4|a5|a6|a7|a8|a9|a0|0=5|-2|a0|
							
/inputs!/                   1i|n1|
/repitition/                a10|6:n3|:n6|n3|

