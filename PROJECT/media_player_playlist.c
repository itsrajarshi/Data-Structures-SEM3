#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct songs {
    char *nameOfSong;
    int duration;
    struct songs *prev;
    struct songs *next;
};

struct songs *sg = NULL;

struct songs *insertSong(struct songs* sgStart, struct songs* node) {
    struct songs *inserTemp = sgStart;

    if (inserTemp != NULL) {
        while (inserTemp->next != sgStart) {
            inserTemp = inserTemp->next;
        }
        inserTemp->next = node;
        node->prev = inserTemp;
        node->next = sgStart;
        sgStart->prev = node;
    } else {
        sgStart = node;
        node->next = sgStart;
        node->prev = sgStart;
    }
    return sgStart;
}

struct songs *addNewSong(struct songs *sgStart) {
    struct songs *newSong = malloc(sizeof(struct songs));
    newSong->duration = 5;
    newSong->prev = NULL;
    newSong->next = NULL;
    newSong->nameOfSong = malloc(25 * sizeof(char));

    printf("Enter the name of the song under 25 characters:\n");
    scanf(" %[^\n]", newSong->nameOfSong);

    sgStart = insertSong(sgStart, newSong);
    printf("Added a new Song: %s\n", newSong->nameOfSong);
    return sgStart;
}

void deleteSong(struct songs **sgStart, struct songs *node) {
    if (node != NULL) {
        if (node->next == node && node->prev == node) {
            // Only one node
            free(node->nameOfSong);
            free(node);
            *sgStart = NULL;
            printf("Deleted the last song.\n");
            return;
        }

        node->prev->next = node->next;
        node->next->prev = node->prev;

        if (node == *sgStart) {
            *sgStart = node->next;
        }

        free(node->nameOfSong);
        free(node);
        printf("Deleted the song.\n");
    }
}

void songBrowse(struct songs **songStart) {
    int choice = -1;

    if (*songStart != NULL) {
        struct songs *songsTemp = *songStart;

        while (true) {
            printf("\nNow Playing: %s\n", songsTemp->nameOfSong);
            printf("1. Next song\n2. Previous song\n3. Delete this song\n4. Go back to playlist\n");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    songsTemp = songsTemp->next;
                    break;
                case 2:
                    songsTemp = songsTemp->prev;
                    break;
                case 3: {
                    struct songs *nextSong = songsTemp->next;
                    deleteSong(songStart, songsTemp);
                    if (*songStart == NULL) return;
                    songsTemp = nextSong;
                    break;
                }
                case 4:
                    return;
                default:
                    printf("Wrong input, exiting program.\n");
                    exit(0);
            }
        }
    } else {
        printf("You have no songs in this playlist.\n");
    }
}

struct songs* songsMenu(struct songs *sg) {
    int MenuOpt = -1;
    printf("\n1. Browse through songs\n2. Add a Song\n");
    scanf("%d", &MenuOpt);

    switch (MenuOpt) {
        case 1:
            songBrowse(&sg);
            break;
        case 2:
            sg = addNewSong(sg);
            break;
        default:
            printf("Wrong input, exiting program.\n");
            exit(0);
    }
    return sg;
}

int main() {
    int jk = 0;
    while (jk < 5) {
        printf("\n==== MEDIA PLAYER ====\n");
        printf("-1 to close.\n");

        if (sg != NULL) {
            sg = songsMenu(sg);
        } else {
            printf("You got no songs currently, add one.\n");
            sg = addNewSong(sg);
        }

        jk++;
    }
    return 0;
}
