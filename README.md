# Primer Portfolio

## Section 1 - Primer Challenges
### Primer 1 - Fahrenheit / Centigrade Conversion
This challenge requires us to allow a user to enter a value before selecting whether to convert it from Fahrenheit to Centigrade or Centigrade to Fahrenheit.  As part of the initial design the conversion algorithms were needed for both calculations. 

To help complete this challenge I needed to break the overall problem down into the following main tasks: 
* Get data from the user
* Verify the data is in a suitable format
* Create a method to convert F->C
* Create a method to convert C->F
 
#### Reflection (as well as issues, challenges & resolutions)
The biggest issue was related to testing the areas my solution failed, originally, I tested to see if it worked - however, it wasn’t until I tried to break it that I found some of the more serious issues with my design and implementation.  For example, in my first prototype there was very little error handling therefore my program broke if I entered a letter. My program lacked robustness so I refactored the code and added a try catch block to stop the program from breaking and wrapped that in a do while block. Though this worked, I recognise that this was not the most efficient way to solve this problem. However, it worked fine and was a simple implementation so I decided not to refactor further.

### Primer 2 - Self-service Checkout
This challenge asked the user to input the quantity of an item and the price until the user entered 0. A subtotal would be calculated and displayed to the user before sales tax was adding and the final total was also displayed.
 
To break down the challenge:
* Create a function to add an item
* Create function that converts subtotal to total after tax
* Create a loop for the user to keep entering items
* Check the correct values where being entered


#### Reflection 
The biggest issue again with this task was validating the user input. The user had to input 3 different data types so each data type needed to be tested to make sure it was correct in order for the program to work. I had to use a more efficient function for number validating which checked the characters in a string to see if they matched any numbers in an already existing string that contained only numbers. This function was used to check user inputs before converting from string to int or float.


### Primer 3 - Password complexity checker
The task was to take a user input and check the complexity of the password against different rules. The password could either be weak, moderate, strong or very strong. The program should return an int that represents the complexity of the password and the display the complexity.

To break down the challenge:
* Create a function to check for numbers
* Create a function to check for special characters
* Calculate the complexity of the password
* Return an int that represents a complexity

#### Challenges
The biggest problem I had when coding this was the order of each if statement when executing. In my first prototype the order of my if statements were incorrect so it was returning the wrong int. I had to refactor the code to return the correct int so the if statements had to be reversed in order.

### Primer 4 - Employees removal 
The task for this was to display a list of names to the user and prompt then to remove a name from the list. The user will enter a name and if it matches then is will be removed from the list of names.

To break down the challenge: 
* Create a function to output the names
* Crate a function to remove the name from the list 

#### Challenges
The biggest challenge for this primer was deciding which data type to use for storing the names. Firstly, I tried to use a array but as they were not dynamic I thought it wasnt efficient enough due to the extensive lines of code just to resize the array. Instead, I decided to use a list as it was in fact dynamic so a simple .remove() made the code more efficient as I didnt need a function to resize the array.

### Primer 5 - Data file parser
The task was to take a csv a file that was formatted in any way. The program should then take the file and output it to the user in a formatted way.

To break down the challenge:
* Pass the file to a function
* Create a function that saves the file to a vector
* Create a function that outputs the vector
* Create a function to see if the file exists

#### Challenges 
The biggest challenge I faced in this primer was formatting the output of that data. In my first prototype, I tried to seperate the data from the files after every common. I had a problem with that implementation so I had to change the way I formatted the file to remove all commas. I did this by just placing each piece of data on a seperate line which made it easier to add to the vector.
..  
..  

---
## Section 2 - Programming Paradigms
### Programming Paradigms
Simply put, a programming paradigm, for example, procedural, object-oriented, functional, structured, declarative, imperative and event driven can be described as a specific approach used when trying to solve a problem.  Although many programming languages can (and do) support multiple paradigms this discussion will focus more specifically on the possible benefits with examples of the potential differences and similarities of five from the above list. These are ...

---
## Section 3 - Continued Professional Development
### Benefits of becoming a Polyglot Programmer
Vestibulum vitae semper sem. Duis leo leo, suscipit at felis non, pellentesque varius massa. Sed sit amet orci nibh. Morbi scelerisque faucibus elit, vitae mollis turpis finibus eget. In convallis euismod nunc non imperdiet. Duis ultricies pulvinar lorem, sed molestie nunc porta at. Aenean arcu ante, efficitur nec felis sed, feugiat iaculis turpis. Vestibulum eu elementum diam. Quisque nec tortor auctor, scelerisque ante vitae, fringilla tellus.

Quisque ligula lectus, efficitur quis malesuada sit amet, malesuada sed nibh. In lorem erat, elementum quis tempus nec, rhoncus ac ante. Mauris suscipit massa tempor, pulvinar neque vel, gravida nulla. Donec massa diam, molestie in diam nec, vulputate faucibus ligula. Aliquam erat volutpat. Aliquam sit amet dui ligula. Nullam euismod eros ultrices magna convallis lobortis. Proin convallis placerat tincidunt. Quisque interdum, nisi id egestas luctus, augue libero lacinia urna, sit amet tempus nisl sem nec quam. Vestibulum interdum urna mauris, vel dignissim nisi dignissim egestas. Donec volutpat dictum dui, at egestas sem tristique nec.
