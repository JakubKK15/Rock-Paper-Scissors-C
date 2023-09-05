#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * The game function determines the winner of a game of rock-paper-scissors.
 *
 * @param player The choice of the player ('r' for rock, 'p' for paper, 's' for
 * scissors).
 * @param computer The choice of the computer ('r' for rock, 'p' for paper, 's'
 * for scissors).
 * @return -1 if it's a tie, 0 if the player loses, and 1 if the player wins.
 */
int game(char player, char computer) {

  // Both the player and computer have the same choice
  if (player == computer) {
    return -1; // Tie
  }

  // Player chooses rock
  if (player == 'r') {
    if (computer == 's') {
      return 1; // Player wins
    } else if (computer == 'p') {
      return 0; // Player loses
    }
  }

  // Player chooses paper
  if (player == 'p') {
    if (computer == 'r') {
      return 1; // Player wins
    } else if (computer == 's') {
      return 0; // Player loses
    }
  }

  // Player chooses scissors
  if (player == 's') {
    if (computer == 'p') {
      return 1; // Player wins
    } else if (computer == 'r') {
      return 0; // Player loses
    }
  }

  // Invalid choices
  return -2;
}

int main() {
  int n;
  char player, computer, result;
  srand(time(NULL)); // Seed the random number generator
  n = rand() % 100; // Generate a random number between 0 and 99
  if (n < 33) {
    computer = 's'; // Set computer's choice as scissors if n is less than 33
  } else if (n < 66) {
    computer = 'p'; // Set computer's choice as paper if n is less than 66
  } else {
    computer = 'r'; // Set computer's choice as rock if n is greater than or equal to 66
  }

  printf("Enter your choice (r for rock, p for paper, s for scissors): ");
  scanf(" %c", &player); // Read the player's choice from the user

  // Input validation
  while (player != 'r' && player != 'p' && player != 's') {
    printf("Invalid choice. Please enter a valid choice (r for rock, p for "
           "paper, s for scissors): ");
    scanf(" %c", &player); // Read the player's choice from the user
  }

  result = game(player, computer); // Determine the result of the game

  if (result == -1) {
    printf("It's a tie!\n"); // Print message if it's a tie
  } else if (result == 0) {
    printf("You lose!\n"); // Print message if the player loses
  } else {
    printf("You win!\n"); // Print message if the player wins
  }

  printf("Your choice: %c\n", player); // Print the player's choice
  printf("Computer choice: %c\n", computer); // Print the computer's choice

  return 0;
}
