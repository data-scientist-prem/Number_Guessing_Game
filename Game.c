#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    srand(time(0));

    int play_again = 1;

    while (play_again)
    {
        int randomnumber = rand() % 101; //This generates a random number.
        int guessednumber, no_of_guesses = 0;
        int limit, gameover = 0;
        int valid_leval_input=0;
        int leval;

        // This asks for difficulty leval before games start.
        printf("Choose difficulty from:\n1.Easy(15 chances)\n2.Normal(10 chances)\n3.Hard(5 chances)\nEnter: ");
        while (!valid_leval_input)
        {
            if (scanf("%d", &leval) == 0)
            {
                printf("Invalid Input! please choose a valid option.\n");
                int c;
                while ((c = getchar()) != '\n' && c != EOF)
                    ;
            }
            else if(leval==1)
            {
                limit=15;
                valid_leval_input =1;
                printf("\t\t\t<====New Game Started====>\n");
            }
            else if(leval==2)
            {
                limit=10;
                valid_leval_input =1;
                printf("\t\t\t<====New Game Started====>\n");
            }
            else if(leval==3)
            {
                limit=5;
                valid_leval_input =1;
                printf("\t\t\t<====New Game Started====>\n");
            }
            else
            {
                printf("Please choose from given options.\n");
            }
        }

        // This starts the our game.
        while ((!gameover))
        {
            printf("Guess the number(0 to 100): ");
            if (scanf("%d", &guessednumber) == 0)  //Verify for given input if it is not a number.
            {
                printf("Invalid Input! please enter a valid number.\n");
                int c;
                while ((c = getchar()) != '\n' && c != EOF)
                    ;
                continue;
            }
            else if (guessednumber < 0 || guessednumber > 100) //Verify for given input if it is not in given range.
            {
                printf("Invalid Input! Please enter integer from between 0 to 100.\n");
                continue;
            }
            else if (guessednumber < randomnumber)
            {
                no_of_guesses++;
                printf("(Remaining chance: %d) Higher the number please!\n", limit - no_of_guesses);
            }
            else if (guessednumber > randomnumber)
            {
                no_of_guesses++;
                printf("(Remaining chance: %d) Lower the number please!\n", limit - no_of_guesses);
            }
            else
            {
                no_of_guesses++;
                printf("Congrats! Right answer.\n");
                printf("You guessed number in %d guesses.\n", no_of_guesses);
                gameover = 1;
            }

            if (no_of_guesses == limit && guessednumber != randomnumber) //Check the remaining chances along with game and overs game after all chances used without correct answer.
            {
                printf("Maximum limit reached!\n");
                printf("Correct answer was: %d\n", randomnumber);
                printf("Better luck next time!\n");
                gameover = 1;
            }
        }

        int valid_replay_input = 0;

        //Asks player to replay game or not after game over.
        while (!valid_replay_input)
        {
            char replay;
            printf("Do you want to continue(y/n): ");
            if (scanf(" %c", &replay) == 0) //verify the replay input if not from given options.
            {
                printf("Invalid Input! please choose a valid option.\n");
                int c;
                while ((c = getchar()) != '\n' && c != EOF)
                    ;
                continue;
            }
            else if (replay == 'y' || replay == 'Y')
            {
                valid_replay_input = 1;
                play_again = 1;
                printf("\t\t\t<====New Game Started====>\n");
            }
            else if (replay == 'n' || replay == 'N')
            {
                valid_replay_input = 1;
                play_again = 0;
                printf("Goodbye!\n");
            }
            else
            {
                printf("Please choose from 'y' or 'n'.\n");
            }
        }
    }

    return 0;
}