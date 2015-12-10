/*
    A Program that simulates a maths game.
    The game provides a menu for the user to interact with.
    
    The game will use Arrays to generate random numbers and 
    mathmatical symbols for the problems the user must answer.
    
    Compiled with Borland Compiler

    Ronan Connolly DT228
    09/11/2015
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//Functions used to clean up code and make it easier to read
//Checks if users guess is correct answer and displays  the question with correct answer.
void calculate(int num1, int num2, int correct_answer, int user_guess, char math_operator)
{
    if(user_guess == correct_answer)
    {
        printf("Correct answer!!! %d %c %d = %d\n\n", num1, math_operator, num2, correct_answer);
        
    }
    else
    {
        printf("Incorrect answer!!! %d %c %d = %d\n\n", num1, math_operator, num2, correct_answer);
        
    }//End else

}//End calculate


//Main quiz function. Takes num_questions_per_round as argument to set up how long the game will last
//Returns number of correct answers so we can display Menu#3
int quiz(int num_questions_per_round)
{   
    //set up random number off current time for the two numbers of the equation
    srand(time(NULL));
    
    //user guess
    int user_guess = 0;
    int num_correct = 0;
    
    
    //Array that stores maths symbols. Program will randomly pick one of these
    char maths_symbols[] ={'+','-','*','/'};
    
    //Will use this to store a symbol for the above array
    char math_operator;
    
    
    //numbers for random maths problem
    int num1 = 0;
    int num2 = 0;
    
    //Store correct answer
    int correct_answer = 0;
    
    //counter to break out of game loop
    int counter = 1;
    
    //game loop
    while(counter <= num_questions_per_round)
    {
        
        //picks a random index between 0 and 3 for a symbol for maths_symbols[] array
        int rand_maths_symbol = rand() % 3;
        math_operator = maths_symbols[rand_maths_symbol];
        
        //pick random numbers for equation 
        num1 = rand() & 10;
        num2 = rand() % 10;
        
        //Calculates the answer based off of what numbers and symbol have been picked randomly
        switch(math_operator)
        {
            case '+':
                //sets correct answer with appropriate symbol
                correct_answer = num1 + num2;
                printf("Question %d: %d + %d = ?? \n", counter, num1, num2);
            
                //gets users input
                scanf("%d", &user_guess);
                
                //updates amount of questions user has gotten right
                if(user_guess == correct_answer)
                {
                    num_correct++;
                }
                
                //Calculate functions saves duplicate code
                calculate(num1, num2, correct_answer, user_guess, math_operator);
                break;
            case '-':
                //sets correct answer with appropriate symbol
                correct_answer = num1 - num2;
                printf("Question %d: %d - %d = ?? \n", counter, num1, num2);
            
                //gets users input
                scanf("%d", &user_guess);
            
                //updates amount of questions user has gotten right
                if(user_guess == correct_answer)
                {
                    num_correct++;
                }
            
                //Calculate functions saves duplicate code
                calculate(num1, num2, correct_answer, user_guess,  math_operator);
                break;
            case '*':
                //sets correct answer with appropriate symbol
                correct_answer = num1 * num2;
                printf("Question %d: %d * %d = ?? \n", counter, num1, num2);
            
                //gets users input
                scanf("%d", &user_guess);
            
                //updates amount of questions user has gotten right
                if(user_guess == correct_answer)
                {
                    num_correct++;
                }
            
                //Calculate functions saves duplicate code
                calculate(num1, num2, correct_answer, user_guess,  math_operator);
                break;
            case '/':
                //sets correct answer with appropriate symbol
                correct_answer = num1 / num2;
                printf("Question %d: %d / %d = ?? \n", counter, num1, num2);
            
                //gets user input
                scanf("%d", &user_guess);
            
                //updates amount of questions user has gotten right
                if(user_guess == correct_answer)
                {
                    num_correct++;
                }
            
                //Calculate functions saves duplicate code
                calculate(num1, num2, correct_answer, user_guess,math_operator);
                break;
            
        }//End switch
        
        counter++;
        
    }//End While
    
    return num_correct;
}//End Quiz



main()
{
    
    //max amount of questions allowed
    const int MAX_NUM = 5;
    
    //set up variables
    int user_menu_input = 0;
    int num_questions_per_round = 1;
    
    //intialise score to -1 so we can check if quiz has been played yet before displaying Menu #3
    //if it the quiz has been played  the score will either be 0 or a positive number.
    int score = -1;
    bool menu_running = true;
    
    
    while(menu_running)
    {
        //display menu
        printf("\t\t\t***********************************\n");
        printf("\t\t\t*Welcome to DT228 Mathematics Game*\n");
        printf("\t\t\t***********************************\n");
        printf("\n");
        printf("1. Enter the number of questions for this round. \n");
        printf("2. Start Quiz. \n");
        printf("3. Display score. \n");
        printf("4. Exit. \n\n");
    
        //get user input
        printf("Enter a choice: \n");
        scanf("%d", &user_menu_input);
        
        //process user menu choice
        switch(user_menu_input)
        {
            case 1:
                printf("Enter number of rounds you wish to play( MAX 5 ):\n");
                scanf("%d", &num_questions_per_round);
            
                //error check user number of round choice
                if(num_questions_per_round > MAX_NUM || num_questions_per_round < 1)
                {
                    printf("Error: Enter a number between 1 - 5\n");
                    num_questions_per_round = 0;
                }
                
                break;
            case 2:
                //function to start quiz. Quiz returns num_correct(0 or positive number) so menu #3 can print out score(number of correct answers)
                score = quiz(num_questions_per_round);
                break;
            case 3:
                //if score is -1. The quiz has not been run yet so dont display any score. PART 3 on Assignment
                if(score == -1)
                {
                    printf("You must select 1.Enter Rounds and 2.Start Quiz: before a score can be given!\n");
                    break;
                }//End if
                
                //prints how many player has gotten right 
                printf("Questions answered correctly previous round: %d out of %d\n\n", score, num_questions_per_round );
                break;
            case 4:
                //Exit program
                printf("Thanks for playing!! Goodbye\n");
                menu_running = false;
                break;
            default:
                printf("Error: invalid Input\n");
                break;
        }//End Switch
        
        
    }//End While
    
    
    
    getchar();
    getchar();
}//End Main