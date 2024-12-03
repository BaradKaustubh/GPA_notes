#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_S 40
#define MAX_N 50

#define COLOR_RESET "\033[0m"
#define COLOR_RED "\033[31m"
#define COLOR_GREEN "\033[32m"
#define COLOR_CYAN "\033[36m"
#define COLOR_MAGENTA "\033[35m"
#define COLOR_WHITE "\033[37m"
#define COLOR_PURPLE "\033[34m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_BOLD "\033[1m"
#define COLOR_UNDERLINE "\033[4m"

typedef struct Seat {
    int num;
    char name[MAX_N];
} Seat;

typedef struct Queue {
    Seat data[MAX_S];
    int front;
    int rear;
    int size;
} Queue;

Queue q;

void initQueue() {
    q.front = q.rear = q.size = 0;
}

void enqueue(Seat s) {
    if (q.size == MAX_S) {
        printf(COLOR_RED "Oops! The bus is fully booked! No more reservations can be made.\n" COLOR_RESET);
        return;
    }
    q.data[q.rear] = s;
    q.rear = (q.rear + 1) % MAX_S;
    q.size++;
}

Seat dequeue() {
    if (q.size == 0) {
        printf(COLOR_RED "There are no reservations to cancel! The bus is empty.\n" COLOR_RESET);
        Seat s = {-1, ""};
        return s;
    }
    Seat s = q.data[q.front];
    q.front = (q.front + 1) % MAX_S;
    q.size--;
    return s;
}

void displayQueue() {
    printf(COLOR_CYAN "\n-------------------------------------------------\n" COLOR_RESET);
    printf(COLOR_BOLD COLOR_PURPLE "    Current Bus Reservations\n" COLOR_RESET);
    printf(COLOR_CYAN "-------------------------------------------------\n" COLOR_RESET);
    if (q.size == 0) {
        printf(COLOR_YELLOW "No reservations yet. The bus is empty.\n" COLOR_RESET);
    } else {
        for (int i = 0; i < q.size; i++) {
            Seat s = q.data[(q.front + i) % MAX_S];
            printf(COLOR_GREEN "Seat %d reserved for %s.\n" COLOR_RESET, s.num, s.name);
        }
    }
    printf(COLOR_CYAN "-------------------------------------------------\n" COLOR_RESET);
}

void findReservation(const char *cName) {
    printf(COLOR_CYAN "\n-------------------------------------------------\n" COLOR_RESET);
    printf(COLOR_BOLD COLOR_PURPLE "   Searching for reservation\n" COLOR_RESET);
    printf(COLOR_CYAN "-------------------------------------------------\n" COLOR_RESET);
    for (int i = 0; i < q.size; i++) {
        Seat s = q.data[(q.front + i) % MAX_S];
        if (strcmp(s.name, cName) == 0) {
            printf(COLOR_GREEN "Seat %d reserved for %s.\n" COLOR_RESET, s.num, cName);
            return;
        }
    }
    printf(COLOR_RED "No reservation found under the name '%s'.\n" COLOR_RESET, cName);
    printf(COLOR_CYAN "-------------------------------------------------\n" COLOR_RESET);
}

void displayAvailableSeats() {
    printf(COLOR_CYAN "\n-------------------------------------------------\n" COLOR_RESET);
    printf(COLOR_BOLD COLOR_PURPLE "      Available Bus Seats\n" COLOR_RESET);
    printf(COLOR_CYAN "-------------------------------------------------\n" COLOR_RESET);
    for (int i = 1; i <= MAX_S; i++) {
        int found = 0;
        for (int j = 0; j < q.size; j++) {
            Seat s = q.data[(q.front + j) % MAX_S];
            if (s.num == i) {
                found = 1;
                break;
            }
        }
        if (!found) {
            printf(COLOR_GREEN "Seat %d is available.\n" COLOR_RESET, i);
        } else {
            printf(COLOR_RED "Seat %d is reserved.\n" COLOR_RESET, i);
        }
    }
    printf(COLOR_CYAN "-------------------------------------------------\n" COLOR_RESET);
}

void showBusStatus() {
    printf(COLOR_CYAN "\n-------------------------------------------------\n" COLOR_RESET);
    printf(COLOR_BOLD COLOR_PURPLE "   Bus Reservation Status\n" COLOR_RESET);
    printf(COLOR_CYAN "-------------------------------------------------\n" COLOR_RESET);
    printf(COLOR_GREEN "Total Reservations: %d\n" COLOR_RESET, q.size);
    printf(COLOR_YELLOW "Available Seats: %d\n" COLOR_RESET, MAX_S - q.size);
    printf(COLOR_CYAN "-------------------------------------------------\n" COLOR_RESET);
}

void cancelAllReservations() {
    if (q.size == 0) {
        printf(COLOR_RED "No reservations to cancel! The bus is empty.\n" COLOR_RESET);
    } else {
        while (q.size > 0) {
            dequeue();
        }
        printf(COLOR_GREEN "All reservations have been canceled.\n" COLOR_RESET);
    }
}

void reservationSummary() {
    printf(COLOR_CYAN "\n-------------------------------------------------\n" COLOR_RESET);
    printf(COLOR_BOLD COLOR_PURPLE "   Reservation Summary\n" COLOR_RESET);
    printf(COLOR_CYAN "-------------------------------------------------\n" COLOR_RESET);
    if (q.size == 0) {
        printf(COLOR_YELLOW "No reservations to show.\n" COLOR_RESET);
    } else {
        for (int i = 0; i < q.size; i++) {
            Seat s = q.data[(q.front + i) % MAX_S];
            printf(COLOR_GREEN "Seat %d reserved for %s.\n" COLOR_RESET, s.num, s.name);
        }
    }
    printf(COLOR_CYAN "-------------------------------------------------\n" COLOR_RESET);
}

int main() {
    initQueue();
    char name[MAX_N];
    int sNum, choice;
    char contChoice;

    do {
        printf(COLOR_CYAN "\n-------------------------------------------------\n" COLOR_RESET);
        printf(COLOR_BOLD COLOR_PURPLE "    Bus Reservation System\n" COLOR_RESET);
        printf(COLOR_CYAN "-------------------------------------------------\n" COLOR_RESET);
        printf(COLOR_WHITE "1. Make a reservation\n");
        printf("2. Cancel a reservation\n");
        printf("3. View reservations\n");
        printf("4. View available seats\n");
        printf("5. Find reservation by name\n");
        printf("6. View bus status\n");
        printf("7. Cancel all reservations\n");
        printf("8. Reservation summary\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf(COLOR_CYAN "\nEnter seat number (1-%d): " COLOR_RESET, MAX_S);
                scanf("%d", &sNum);
                if (sNum < 1 || sNum > MAX_S) {
                    printf(COLOR_RED "Invalid seat number.\n" COLOR_RESET);
                    break;
                }
                printf("Enter your name: ");
                scanf("%s", name);
                Seat s = {sNum, ""};
                strcpy(s.name, name);
                enqueue(s);
                printf(COLOR_GREEN "Seat %d reserved for %s.\n" COLOR_RESET, sNum, name);
                break;

            case 2:
                printf(COLOR_CYAN "\nEnter seat number to cancel (1-%d): " COLOR_RESET, MAX_S);
                scanf("%d", &sNum);
                if (sNum < 1 || sNum > MAX_S) {
                    printf(COLOR_RED "Invalid seat number.\n" COLOR_RESET);
                    break;
                }
                int canceled = 0;
                for (int i = 0; i < q.size; i++) {
                    Seat s = q.data[(q.front + i) % MAX_S];
                    if (s.num == sNum) {
                        dequeue();
                        printf(COLOR_RED "Reservation for seat %d canceled.\n" COLOR_RESET, sNum);
                        canceled = 1;
                        break;
                    }
                }
                if (!canceled) printf(COLOR_RED "No reservation for seat %d.\n" COLOR_RESET, sNum);
                break;

            case 3:
                displayQueue();
                break;

            case 4:
                displayAvailableSeats();
                break;

            case 5:
                printf(COLOR_CYAN "\nEnter name to search: " COLOR_RESET);
                scanf("%s", name);
                findReservation(name);
                break;

            case 6:
                showBusStatus();
                break;

            case 7:
                cancelAllReservations();
                break;

            case 8:
                reservationSummary();
                break;

            case 9:
                printf(COLOR_RED "\nExiting the Bus Reservation System. Goodbye!\n" COLOR_RESET);
                break;

            default:
                printf(COLOR_RED "Invalid choice! Please try again.\n" COLOR_RESET);
                break;
        }

        if (choice != 9) {
            printf("Do you want to continue? (y/n): ");
            scanf(" %c", &contChoice);
            if (contChoice == 'n' || contChoice == 'N') choice = 9;
        }

    } while (choice != 9);

    return 0;
}
