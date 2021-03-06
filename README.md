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

#### Reflection
The biggest problem I had when coding this was the order of each if statement when executing. In my first prototype the order of my if statements were incorrect so it was returning the wrong int. I had to refactor the code to return the correct int so the if statements had to be reversed in order.

### Primer 4 - Employees removal 
The task for this was to display a list of names to the user and prompt then to remove a name from the list. The user will enter a name and if it matches then is will be removed from the list of names.

To break down the challenge: 
* Create a function to output the names
* Crate a function to remove the name from the list 

#### Reflection
The biggest challenge for this primer was deciding which data type to use for storing the names. Firstly, I tried to use a array but as they were not dynamic I thought it wasnt efficient enough due to the extensive lines of code just to resize the array. Instead, I decided to use a list as it was in fact dynamic so a simple .remove() made the code more efficient as I didnt need a function to resize the array.

### Primer 5 - Phone directory
The task was to take a csv a file that was formatted in any way. The program should then take the file and output it to the user in a formatted way.

To break down the challenge:
* Pass the file to a function
* Create a function that saves the file to a vector
* Create a function that outputs the vector
* Create a function to see if the file exists

#### Reflection 
The biggest challenge I faced in this primer was formatting the output of that data. In my first prototype, I tried to seperate the data from the files after every common. I had a problem with that implementation so I had to change the way I formatted the file to remove all commas. I did this by just placing each piece of data on a seperate line which made it easier to add to the vector.

### Primer 6 - Data file parser
The task was again to take data from a csv file and output it to the user. Instead the main task for this primer was to format the output so it matches the number of characters plus 1 extra. Also the names should all  start at the same point and same with the salaries. The formatting should be dynamic and change according to the length of the surname.

To break down the problem:
* Pass the file to a function
* Create a function that assigns the contents of the file to an array
* Create a function calculates the width and outputs the formatted data

#### Reflection 
The biggest challenge for this primer was calculating the dynamic width for the data output. I could not get the surnames to line up with the start of the characters and they would not output fully inline. All the data outputs to the screen just not in the formatted way the challenge described.

### Primer 7 - Sleep timer 
This task was to create a function that makes a thread sleep during execution. It should take an int argument for the number of seconds the thread is to sleep. 

To break down the task:
* Pass an int argument for number of seconds
* Check if the int value is greater than 0 - if not default to 10 seconds

#### Reflection
This task was not particularly technical. It was important to meet certain conditions like a default number of seconds which had to be set to 10. It was also important to have the correct calculations for convert milliseconds into seconds for the correct sleep time.

### Primer 8 - Joining and detaching threads
PartA: 
This task was to create two seperate threads and hardcode timers with 5 and 10 seconds as arguments. The function will display when the thread starts, will call the timer and then display when the thread ends. It will then join the threads after the time has been called.

PartB:
Similarly to part A, two seperate threads will be made with the hardcoded timers for 5 and 10 seconds. However, this time the threads will be detached. The main thread start and end should still be displayed.

To break down the problem:
*  Create two threads to be detached
*  Have the threads sleep for 5 or 10 seconds
*  Either detach or join the thread
*  Display the start and end of 2 threads plus the main thread

#### Reflection
For part A the goal was to display the start and end times off each thread. The approach was to call a function and display the main thread start time and then call the a function to make two more threads, then joining them and displaying the end time of all the threads.

For part B again very similar, I had to call the same functions but instead of joining the two threads the program would detach them instead, then displaying the end time of each threads.

### Primer 9 - Car class
The task of this primer was to create a class for a car including both private and public properties with methods like getters and setters along with other methods to change the properties of the car. The car would have a set of default values and the user was displayed with a menu where they can choose options e.g. turn engine on. This would be continued until the user entered 0.

To break down the problem: 
* Create a car class - including all properties
* Create methods to get or set the properties
* Create methods to alter the status of the car
* Create instance of the car and allow the user to prompt a method

#### Reflection
One problem I had was not making the menu part of the class. It made coding the solution a little harder as I couldnt directly access the private properties. However, I understand that this is the best practice as it stops the user from changing variables they should not have access to. It was difficult deciding what should be in the private and public sections of the class as the car instantiation would be in the constructor, default values had to be set.


### Primer 10 - Area of
This primer focused on having just one class for calculating 3 different areas based on the arguments passed to the constructor. It should be just a single class and a method named size that calculates the area of the shape. For this challenge the shapes I chose were square, rectangle and trapezoid.

To break down the problem:
* Create the area class
* Create a method that calculates the area of 3 different shapes(depending on the arguments passed)


#### Reflection 
When approaching this task I decided to choose 3 shapes that would require 3 different arguments to calculate the area. This was the easiest way to differentiate between the shapes. When initialising the area class, you could pass the constructor up to 3 arguments, any arguments not passed had a default value of 0. This is how I would know which area to calculate, using a variety of if statements, if a argument was 0 then it couldnt be that shape.

..  
..  

---
## Section 2 - Programming Paradigms
### Programming Paradigms
Simply put, a programming paradigm, for example, procedural, object-oriented, functional, structured, declarative, imperative and event driven can be described as a specific approach used when trying to solve a problem.  Although many programming languages can (and do) support multiple paradigms this discussion will focus more specifically on the possible benefits with examples of the potential differences and similarities of five from the above list.
 
First of all, object-oriented programming has many benefits. This approach utilises the use of classes and objects where code is written and instances of the class are made. Also one of the main benefits of OOP is the use of inheritance, which allows different classes to inherit properties and methods of the parent class which can dramatically reduce the size of the code. It aims mainly to stop the reuse of excessive amounts of code, allowing it to be used in other parts of the program without being rewritten which reduces data redundancy. It also makes debugging easier as a problem can be located in a single class, also allowing for easier maintenance as it only needs to be changed in one place rather than in multiple places. So new people who are getting to grips with the code can pick things up faster due to the structured approach.
 
Very similarly to OOP, structured programming is done by using modules and functions to create the program. Its aim is to improve clarity, quality and reduce developing time by the use of a structured control flow. This, like OOP, makes the program much easier to read and understand and also makes finding errors much easier due to code being in modules.
 
The programming paradigm is the functional paradigm. This is the process of building software by using pure functions and avoiding mutable data. A pure function is a function with a return value type that is identical to the ones passed by the arguments with no other side effects to local static variables or public variables. Functional programming is also considered to be declarative rather than imperative. Some benefits of this may be the program is easier to test as it only adopts pure functions which in turn would mean it's easier to locate the problem as functions only return specific type values. It can make understanding the code easier as again the functions return one type and are generally move concise because of this. This would be slightly different to something like OOP as the methods usually affect the properties of the class which can include more than one data type so would not likely return anything making it impure.
 
A declarative approach would be described as always having the end results in my rather than all the intermediate working steps to achieve the problem. The idea of this means the solution path would be determined automatically. As a result the programmer is usually shielded from lower level code that materialises the desired end state. Some benefits of this would mean code is usually short and efficient due to the brunt of the work being done behind the scenes and optimisation is easy due to implementation being controlled by an algorithm. This also allows methods to be implemented that are not yet known at the time of development allowing for greater freedom when coding.
 
However, when looking at the imperative paradigm and its approach it is nearly the opposite to declarative programming. Imperative is the idea that the program describes stop by step how to accomplish the task at hand unlike declarative where just the end goal is considered. There are some advantages to imperative programming, it is considered much easier to learn and understand as the step by step approach breaks down the problem unlike the declarative approach where the solution is hidden and the programmer can't understand what is going on beneath the surface. Another main advantage is that you can control the complexity of the program due to the full control of the implementation. This means that there is a potential to increase a program's performance over declarative programming.




---
## Section 3 - Continued Professional Development
### Benefits of becoming a Polyglot Programmer
First of all, a polyglot programmer is someone who can write code in multiple languages to utilise functionality and/or efficiency that would not be available in just a single language. To be a polyglot programmer you would have to consider yourself to be someone who is proficient in multiple languages, understanding the syntax and nuances of each language so you could efficiently solve the problem.
 
Being a polyglot programmer aims to improve the concept of not just coding but instead solving the problem. If you can code confidently in more than one language it opens the doors to solving the problem in more than one way. A programmer is not limited by any language specific and has the opportunity to think outside of the box, creating more efficient code. It makes you a more effective programmer if you can solve a problem with multiple languages. If you are a programmer who can just write code in one language, if that problem can not be solved in that language then that becomes a blocker for your work and you are no longer effectively doing your job.
 
Another benefit is that you are training your brain to think without a language in mind. Similar to the first point, programmers art is to solve a problem. However, knowing multiple languages can open your eyes to the possible problems and solutions when solving a task. One problem may not be so clear in one language but in another much clearer. It may show a programmer how to solve that problem in a specific way that would usually be the standard in one specific language. The aim is to broaden the knowledge and experience of the programmer so they don't think so narrow mindedly.
 
Finally, when looking to achieve a business goal the final product is generally the most important part to a customer or consumer. Being able to string multiple languages together to make an application that meets every need of the client makes you a much more valuable programmer. It's the idea of giving the customer the product they asked for without any limitations or constraints due to the specific language that is being used. For example, someone who can only code in java may struggle to make a full stack application. A polyglot programmer could create a js stack to interact with the java backend and there would be no limitations of the application because the programmer could solve the problem using more than one language.

