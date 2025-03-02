#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_HISTORY 10

// Stack structure for browser history
typedef struct {
    char* history[MAX_HISTORY];  // Array to store URLs
    int top;  // Index of the top element
} BrowserHistory;

// Initialize the browser history stack
void initHistory(BrowserHistory* history) {
    history->top = -1;
}

// Push a URL to the stack
void visitPage(BrowserHistory* history, const char* url) {
    if (history->top < MAX_HISTORY - 1) {
        history->history[++history->top] = strdup(url); // Save the URL
        printf("Visiting: %s\n", url);
    } else {
        printf("History is full! Cannot visit new page.\n");
    }
}

// Go back to the previous page
void goBack(BrowserHistory* history) {
    if (history->top > 0) {
        printf("Going back to: %s\n", history->history[--history->top]);
    } else {
        printf("No previous page to go back to.\n");
    }
}

// Go forward to the next page
void goForward(BrowserHistory* history) {
    if (history->top < MAX_HISTORY - 1 && history->history[history->top + 1] != NULL) {
        printf("Going forward to: %s\n", history->history[++history->top]);
    } else {
        printf("No forward page to go to.\n");
    }
}

// Display current page
void displayCurrentPage(BrowserHistory* history) {
    if (history->top == -1) {
        printf("No pages visited yet.\n");
    } else {
        printf("Current page: %s\n", history->history[history->top]);
    }
}

// Display entire browsing history
void displayHistory(BrowserHistory* history) {
    if (history->top == -1) {
        printf("No browsing history available.\n");
    } else {
        printf("Browsing History:\n");
        for (int i = 0; i <= history->top; i++) {
            printf("%s\n", history->history[i]);
        }
    }
}

// Clear browsing history
void clearHistory(BrowserHistory* history) {
    for (int i = 0; i <= history->top; i++) {
        free(history->history[i]);  // Free the allocated memory for URLs
    }
    history->top = -1;
    printf("History cleared.\n");
}

// Main function to test the program
int main() {
    BrowserHistory history;
    initHistory(&history);

    int choice;
    char url[100];

    while (1) {
        printf("\nBrowser History Navigation\n");
        printf("1. Visit Page\n");
        printf("2. Go Back\n");
        printf("3. Go Forward\n");
        printf("4. Display Current Page\n");
        printf("5. Display History\n");
        printf("6. Clear History\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // To consume the newline character left by scanf

        switch (choice) {
            case 1:
                printf("Enter the URL to visit: ");
                fgets(url, sizeof(url), stdin);
                url[strcspn(url, "\n")] = 0; // Remove trailing newline
                visitPage(&history, url);
                break;
            case 2:
                goBack(&history);
                break;
            case 3:
                goForward(&history);
                break;
            case 4:
                displayCurrentPage(&history);
                break;
            case 5:
                displayHistory(&history);
                break;
            case 6:
                clearHistory(&history);
                break;
            case 7:
                clearHistory(&history); // Clear history before exiting
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
