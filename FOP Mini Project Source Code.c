#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define ROWS 10
#define COLS 10
#define DAYS 4
#define MAX_SHOWS 10
#define MAX_BOOKINGS 500
#define MAX_SEATS_PER_BOOKING 10
#define DATA_FILE "bookingData.dat"
#define ADMIN_PASS "1234"

typedef struct {
    char title[50];
    char time[20];
    float price;
} Movie;

typedef struct {
    int bookingID;
    char name[50];
    int day;
    int show;
    int seatCount;
    int rows[MAX_SEATS_PER_BOOKING];
    int cols[MAX_SEATS_PER_BOOKING];
    float amount;
    int active;
} Booking;

int seats[DAYS][MAX_SHOWS][ROWS][COLS] = {0};
Movie movies[MAX_SHOWS];
Booking bookings[MAX_BOOKINGS];

int bookingCount = 0;
int SHOWS = 0;

/* ================= DATE ================= */

void showLiveDates() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    printf("\nSelect Date:\n");

    for (int i = 0; i < DAYS; i++) {
        struct tm temp = tm;
        temp.tm_mday += i;
        mktime(&temp);

        printf("%d. %02d/%02d/%d\n",
               i + 1,
               temp.tm_mday,
               temp.tm_mon + 1,
               temp.tm_year + 1900);
    }
}

/* ================= FILE ================= */

void saveData() {
    FILE *fp = fopen(DATA_FILE, "wb");
    if (!fp) return;

    fwrite(&SHOWS, sizeof(int), 1, fp);
    fwrite(seats, sizeof(seats), 1, fp);
    fwrite(&bookingCount, sizeof(int), 1, fp);
    fwrite(bookings, sizeof(Booking), bookingCount, fp);
    fwrite(movies, sizeof(Movie), SHOWS, fp);

    fclose(fp);
}

void loadData() {
    FILE *fp = fopen(DATA_FILE, "rb");
    if (!fp) return;

    fread(&SHOWS, sizeof(int), 1, fp);
    fread(seats, sizeof(seats), 1, fp);
    fread(&bookingCount, sizeof(int), 1, fp);
    fread(bookings, sizeof(Booking), bookingCount, fp);
    fread(movies, sizeof(Movie), SHOWS, fp);

    fclose(fp);
}

/* ================= UTIL ================= */

int generateID() {
    return rand() % 90000 + 10000;
}

int findBooking(int id) {
    for (int i = 0; i < bookingCount; i++)
        if (bookings[i].bookingID == id && bookings[i].active)
            return i;
    return -1;
}

/* ================= DISPLAY ================= */

void displaySeats(int day, int show) {
    int booked = 0;

    printf("\n      ");
    for (int j = 0; j < COLS; j++)
        printf("%2d  ", j + 1);
    printf("\n");

    for (int i = 0; i < ROWS; i++) {
        printf(" %c    ", 'A' + i);
        for (int j = 0; j < COLS; j++) {
            if (seats[day][show][i][j] == 0)
                printf("[ ] ");
            else {
                printf("[X] ");
                booked++;
            }
        }
        printf("\n");
    }

    printf("\n=====================================\n");
    printf("            SCREEN THIS WAY\n");
    printf("=====================================\n");

    printf("\nBooked: %d | Available: %d\n",
           booked, ROWS * COLS - booked);
}

/* ================= VALID ROW ================= */

int getValidRow() {
    char rowChar;
    while (1) {
        printf("Row (A-J): ");
        scanf(" %c", &rowChar);
        rowChar = toupper(rowChar);

        if (rowChar >= 'A' && rowChar <= 'J')
            return rowChar - 'A';

        printf("Invalid Row! Enter A-J only.\n");
    }
}

/* ================= RECEIPT ================= */

void printReceipt(Booking b) {
    printf("\n=========== RECEIPT ===========\n");
    printf("Booking ID : %d\n", b.bookingID);
    printf("Name       : %s\n", b.name);
    printf("Movie      : %s\n", movies[b.show].title);
    printf("Time       : %s\n", movies[b.show].time);

    printf("Seats      : ");
    for (int i = 0; i < b.seatCount; i++)
        printf("(%c,%d) ", 'A' + b.rows[i], b.cols[i] + 1);

    printf("\nTotal      : ₹%.0f\n", b.amount);
    printf("Status     : %s\n", b.active ? "Active" : "Cancelled");
    printf("================================\n");
}

/* ================= USER ================= */

void bookTicket() {

    if (SHOWS == 0) {
        printf("No movies available. Contact Admin.\n");
        return;
    }

    int day, show, count;

    getchar();
    printf("Enter your name: ");
    char name[50];
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    showLiveDates();
    printf("Choose Date: ");
    scanf("%d", &day);
    day--;

    printf("\nShows:\n");
    for (int i = 0; i < SHOWS; i++)
        printf("%d. %s (%s) - ₹%.0f\n",
               i + 1,
               movies[i].title,
               movies[i].time,
               movies[i].price);

    printf("Choose show: ");
    scanf("%d", &show);
    show--;

    displaySeats(day, show);

    printf("How many seats? (Max 10): ");
    scanf("%d", &count);
    if (count > 10) count = 10;

    Booking b;
    b.bookingID = generateID();
    strcpy(b.name, name);
    b.day = day;
    b.show = show;
    b.seatCount = 0;
    b.amount = 0;
    b.active = 1;

    for (int i = 0; i < count; i++) {

        int r = getValidRow();

        int c;
        printf("Col (1-10): ");
        scanf("%d", &c);
        c--;

        if (c < 0 || c >= COLS || seats[day][show][r][c] == 1) {
            printf("Invalid or Already Booked Seat!\n");
            i--;
            continue;
        }

        seats[day][show][r][c] = 1;
        b.rows[i] = r;
        b.cols[i] = c;
        b.seatCount++;
        b.amount += movies[show].price;
    }

    bookings[bookingCount++] = b;
    printReceipt(b);
}

void cancelTicket() {
    int id;
    printf("Enter Booking ID: ");
    scanf("%d", &id);

    int idx = findBooking(id);
    if (idx == -1) {
        printf("Booking not found.\n");
        return;
    }

    Booking *b = &bookings[idx];

    for (int i = 0; i < b->seatCount; i++)
        seats[b->day][b->show][b->rows[i]][b->cols[i]] = 0;

    b->active = 0;
    printf("Ticket Cancelled Successfully.\n");
}

void modifyTicket() {
    int id;
    printf("Enter Booking ID: ");
    scanf("%d", &id);

    int idx = findBooking(id);
    if (idx == -1) {
        printf("Booking not found.\n");
        return;
    }

    Booking *b = &bookings[idx];

    for (int i = 0; i < b->seatCount; i++)
        seats[b->day][b->show][b->rows[i]][b->cols[i]] = 0;

    displaySeats(b->day, b->show);

    for (int i = 0; i < b->seatCount; i++) {

        int r = getValidRow();

        int c;
        printf("Col (1-10): ");
        scanf("%d", &c);
        c--;

        if (c < 0 || c >= COLS) {
            printf("Invalid Column!\n");
            i--;
            continue;
        }

        seats[b->day][b->show][r][c] = 1;
        b->rows[i] = r;
        b->cols[i] = c;
    }

    printReceipt(*b);
}

/* ================= ADMIN ================= */

void viewAllBookings() {
    printf("\n=========== ALL BOOKINGS ===========\n");
    for (int i = 0; i < bookingCount; i++) {
        printf("ID: %d | Name: %s | Movie: %s | Status: %s\n",
               bookings[i].bookingID,
               bookings[i].name,
               movies[bookings[i].show].title,
               bookings[i].active ? "Active" : "Cancelled");
    }
    printf("====================================\n");
}

void clearAllBookings() {
    for (int d = 0; d < DAYS; d++)
        for (int s = 0; s < MAX_SHOWS; s++)
            for (int r = 0; r < ROWS; r++)
                for (int c = 0; c < COLS; c++)
                    seats[d][s][r][c] = 0;

    bookingCount = 0;
    printf("All bookings cleared successfully.\n");
}

void adminPanel() {
    int choice;

    while (1) {

        printf("\n===== CINEPLEX =====\n");
        printf("1. Set Movies\n");
        printf("2. View All Bookings\n");
        printf("3. Cancel All Bookings\n");
        printf("4. Back\nChoice: ");
        scanf("%d", &choice);

        if (choice == 1) {

            printf("How many movies? (Max 10): ");
            scanf("%d", &SHOWS);
            if (SHOWS > 10) SHOWS = 10;

            for (int i = 0; i < SHOWS; i++) {
                getchar();
                printf("Movie %d Title: ", i + 1);
                fgets(movies[i].title, 50, stdin);
                movies[i].title[strcspn(movies[i].title, "\n")] = 0;

                printf("Time: ");
                fgets(movies[i].time, 20, stdin);
                movies[i].time[strcspn(movies[i].time, "\n")] = 0;

                printf("Price: ");
                scanf("%f", &movies[i].price);
            }

            saveData();
        }

        else if (choice == 2)
            viewAllBookings();

        else if (choice == 3) {
            clearAllBookings();
            saveData();
        }

        else break;
    }
}

/* ================= MAIN ================= */

int main() {

    srand(time(NULL));
    loadData();

    int role;

    while (1) {

        printf("\n===== CINEPLEX =====\n");
        printf("1. User\n2. Admin\n3. Exit\nChoice: ");
        scanf("%d", &role);

        if (role == 1) {

            int ch;
            while (1) {

                printf("\n===== CINEPLEX =====\n");
                printf("1. Book Ticket\n2. Modify Ticket\n3. Cancel Ticket\n4. Back\nChoice: ");
                scanf("%d", &ch);

                if (ch == 1) { bookTicket(); saveData(); }
                else if (ch == 2) { modifyTicket(); saveData(); }
                else if (ch == 3) { cancelTicket(); saveData(); }
                else break;
            }
        }

        else if (role == 2) {

            char pass[20];
            printf("Enter Admin Password: ");
            scanf("%s", pass);

            if (strcmp(pass, ADMIN_PASS) == 0)
                adminPanel();
            else
                printf("Wrong Password.\n");
        }

        else {
            saveData();
            exit(0);
        }
    }
}