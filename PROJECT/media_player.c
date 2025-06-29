#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for each song
struct Song {
    char title[50];
    struct Song* next;
    struct Song* prev;
};

// Create a new song node
struct Song* createSong(char* title) {
    struct Song* newSong = (struct Song*)malloc(sizeof(struct Song));
    if (newSong == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(newSong->title, title);
    newSong->next = newSong->prev = NULL;
    return newSong;
}

// Add a new song at the end of the playlist
void addSong(struct Song** head, char* title) {
    struct Song* newSong = createSong(title);

    if (*head == NULL) {
        *head = newSong;
        newSong->next = newSong->prev = newSong;  // Circular link
    } else {
        struct Song* last = (*head)->prev;
        last->next = newSong;
        newSong->prev = last;
        newSong->next = *head;
        (*head)->prev = newSong;
    }
    printf("Song '%s' added to the playlist.\n", title);
}

// Remove a song by title
void removeSong(struct Song** head, char* title) {
    if (*head == NULL) {
        printf("The playlist is empty.\n");
        return;
    }

    struct Song* current = *head;
    do {
        if (strcmp(current->title, title) == 0) {
            if (current->next == current) {
                *head = NULL;
            } else {
                if (current == *head) {
                    *head = current->next;
                }
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            free(current);
            printf("Song '%s' removed from the playlist.\n", title);
            return;
        }
        current = current->next;
    } while (current != *head);

    printf("Song '%s' not found in the playlist.\n", title);
}

// Browse playlist forward
void browseForward(struct Song* head) {
    if (head == NULL) {
        printf("The playlist is empty.\n");
        return;
    }

    struct Song* current = head;
    do {
        printf("Playing song: %s\n", current->title);
        current = current->next;
    } while (current != head);

    printf("End of playlist reached. Looping back to the start...\n");
    printf("Playing song: %s\n", head->title);
}

// Browse playlist backward
void browseBackward(struct Song* head) {
    if (head == NULL) {
        printf("The playlist is empty.\n");
        return;
    }

    struct Song* current = head->prev;
    do {
        printf("Playing song: %s\n", current->title);
        current = current->prev;
    } while (current->next != head);

    printf("Start of playlist reached. Looping back to the end...\n");
    printf("Playing song: %s\n", head->prev->title);
}

// Free all songs before exiting
void freePlaylist(struct Song* head) {
    if (head == NULL) return;

    struct Song* current = head->next;
    while (current != head) {
        struct Song* temp = current;
        current = current->next;
        free(temp);
    }
    free(head);
}

int main() {
    struct Song* playlist = NULL;
    int choice;
    char title[50];

    while (1) {
        printf("\n--- Media Player Playlist Management ---\n");
        printf("1. Add Song\n");
        printf("2. Remove Song\n");
        printf("3. Browse Playlist Forward\n");
        printf("4. Browse Playlist Backward\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Clear input buffer newline after scanf
        getchar();

        switch (choice) {
            case 1:
                printf("Enter the title of the song to add: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0;  // Remove trailing newline
                addSong(&playlist, title);
                break;

            case 2:
                printf("Enter the title of the song to remove: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0;
                removeSong(&playlist, title);
                break;

            case 3:
                printf("\nBrowsing playlist forward:\n");
                browseForward(playlist);
                break;

            case 4:
                printf("\nBrowsing playlist backward:\n");
                browseBackward(playlist);
                break;

            case 5:
                freePlaylist(playlist);
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
