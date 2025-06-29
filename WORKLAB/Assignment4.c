#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// we will define node structure for each song in a playlist
struct song {
  char title[100];
  struct song *next;
  struct song *prev;
};

// we will create a function for creating a new song node
struct song *create_song(char *title) {
  struct song *new_song = (struct song *)malloc(sizeof(struct song));
  strcpy(new_song->title, title);         // copy song title to new song
  new_song->next = new_song->prev = NULL; // set next and prev pointers to null
  return new_song;
}

// we will create a function to add a new song to the playlist at the end in a
// sequence
void add_song(struct song **head, char *title) {
  struct song *new_song = create_song(title);

  // if the playlist is empty, initialize it with the new song
  if (*head == NULL) {
    *head = new_song;
    new_song->next = new_song->prev = new_song; // circular linked list
  } else {
    struct song *last = (*head)->prev; // get the last song to the playlist
    // insert the new song at the end and circular links
    last->next = new_song;
    new_song->prev = last;
    new_song->next = *head;
    (*head)->prev = new_song;
  }
  printf("song '%s' added to the playlist.\n", title);
}

// function to remove a song from the playlist by title
void remove_song(struct song **head, char *title) {
  // check if the playlist is empty
  if (*head == NULL) {
    printf("playlist is empty.\n");
    return;
  }

  struct song *current = *head;
  // traverse the playlist to find the song
  do {
    if (strcmp(current->title, title) == 0) {
      // if the playlist has only one song
      if (current->next == current && current->prev == current) {
        *head = NULL; // set playlist to empty
      } else {
        // update head if the song to be deleted is the first one
        if (current == *head) {
          *head = current->next;
        }
        // remove the current song and fix the circular links
        current->prev->next = current->next;
        current->next->prev = current->prev;
      }

      free(current); // free the memory allocated for the song
      printf("Song '%s' removed from the playlist.\n", title);
      return;
    }

    current = current->next;
  } while (current != *head); // loop until we've checked the entire playlist

  // if the song was not found
  printf("Song '%s' not found in the playlist.\n", title);
}

// function to browse the playlist in forward direction
void browseforward(struct song *head) {
  if (head == NULL) {
    printf("playlist is empty.\n");
    return;
  }
  struct song *current = head;

  // loop through the playlist until we return to the head (starting point)
  do {
    printf("Playing song: %s\n", current->title);
    current = current->next;
  } while (current != head); // when we return to the head, stop loop

  // to show the loop effect
  printf("End of the playlist reached, looping back to the start...\n");
  printf("Playing song: %s\n", head->title); // first song again
}

// function to browse the playlist in backward direction
void browsebackward(struct song *head) {
    if (head == NULL) {
        printf("playlist is empty.\n");
        return;
    }
    struct song *current = head->prev; // start from the last song

    // loop through the playlist until we return to the head->prev (starting point)
    do {
        printf("Playing song: %s\n", current->title);
        current = current->prev;
    } while (current != head->prev); // when we return to the starting point, stop loop

    // to show the loop effect
    printf("End of the playlist reached, looping back to the end...\n");
    printf("Playing song: %s\n", head->prev->title); // first song again
}

// function to print the playlist
void print_playlist(struct song *head) {
  if (head == NULL) {
    printf("Playlist is empty.\n");
    return;
  }
  struct song *current = head;
  printf("Playlist: \n");
  do {
    printf(" - %s\n", current->title);
    current = current->next;
  } while (current != head);
  printf("End of playlist.\n");
}

// function for valid integer input
int is_valid_number(const char *input) {
  for (int i = 0; input[i] != '\0' && input[i] != '\n'; i++) {
    if (!isdigit(input[i])) {
      return 0; // Return false if a non-digit character is found
    }
  }
  return 1; // Return true if the string is all digits
}

// main
int main() {
  struct song *playlist = NULL; // Initialize the playlist as empty
  int choice;
  char title[100];
  char input[100]; // Buffer to store user input

  // Text-Based menu loop
  while (1) {
    // Display menu options
    printf("\n--- Media Player Playlist Management ---\n");
    printf("1. Add a song to the playlist\n");
    printf("2. Remove a song from the playlist\n");
    printf("3. Browse the playlist in forward direction\n");
    printf("4. Browse the playlist in backward direction\n");
    printf("5. Print the playlist\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");

    // Read the input from the user
    if (fgets(input, sizeof(input), stdin) != NULL) {
      // Validate the input to ensure it's a valid number
      if (!is_valid_number(input)) {
        printf("Invalid choice. Please enter a valid number.\n");
        continue; // Prompt the user again if the input is not valid
      }

      // Convert the input to an integer
      choice = atoi(input);
    }

    switch (choice) {
    case 1:
            // Add a song to the playlist
            printf("Enter the song title: ");
            fgets(title, sizeof(title), stdin); // Read the entire line as song title
            title[strcspn(title, "\n")] = 0;    // Remove the newline character
            add_song(&playlist, title);
            break;
    case 2:
            // Remove a song from the playlist
            printf("Enter the song title to remove: ");
            fgets(title, sizeof(title), stdin); // Read the entire line as song title
            title[strcspn(title, "\n")] = 0;    // Remove the newline character
            remove_song(&playlist, title);
            break;

    case 3:
      // Browse the playlist in forward direction
      printf("\nBrowsing the playlist in forward direction:\n");
      browseforward(playlist);
      break;
    case 4:
      // Browse the playlist in backward direction
      printf("\nBrowsing the playlist in backward direction:\n");
      browsebackward(playlist);
      break;
    case 5:
      // Print the playlist
      print_playlist(playlist);
      break;
    case 6:
      // Exit the program
      printf("Exiting the program.\n");
      return 0;
    default:
      // Invalid choice
      printf("Invalid choice. Please try again.\n");
      break;
    }
  }
  return 0;
}