# Overview 

Once again I had to tackle a bunch of exercises. Even though not as many, I ran into a couple of problems that have taught me some good lessons. 
Let's see the exercises first:

- Exercises 2 - 6: Temperature conversion
- Exercises 8 - 10: Summing values
- Exercise 11: Fibonacci
- Exercise 12 - 13: Bulls and Cows
- Exercise 14: Day-value pairs

The only exercise missing here is exercise number 7, which was an addition to the Quadratic Equation solver from last chapter, which I already solved.
I also skipped the second part, technically exercise 13, since I couldn't make Stroustrup's header file work and therefore couldn't use the random 
function provided. 

Notes on some exercises: 

**Bulls and Cows**
This exercise has challenged me more than I'd like to admit. I went through a bunch of trial and errors
before I finally had found the right path. That path was realising that I would need to change the input.
My first attempts continuously wrote an integer between 0 - 9 into the vector that I'd use for comparison.
This created problems, since the exercise stated I could only end the input loop once the player had found 
all 4 numbers in the correct order (4 bulls). I initially tried to built another game loop around it, but 
didn't manage to make that work. So eventually I decided people should give all 4 numbers as a 4 digit integer
value, that I would then split up into it's digits and add those digits to the vector for comparison. 

Note: Since Stroustrups header-file produces an error during compilation that I couldn't fix yet, I did not 
do the second part of this exercise in which I would have had to use a function within that header file. 
Therefore the initial 4 numbers to be found remain hard-coded at this moment.

**Day-value pairs**
While I am sure this exercise could be solved more elegantly than having such a long chain of conditionals, I decided to go with it eventually. 
This exercise definitely made me miss the ability to easily use switch statements on strings. 