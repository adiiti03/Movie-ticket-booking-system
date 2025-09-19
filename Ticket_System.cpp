#include<bits/stdc++.h>
#include<unistd.h>
#include<windows.h>
#include<dos.h>
#include<fstream>
// DEVELOPED BY Aditi
// ADMIN CODE: 2106 IS REQUIRED TO CREATE A NEW ADMIN ACCOUNT
using namespace std;

void qformatup();
void qformatdown();
void printline();

int movie_id;
int choice;
int ret;
int i = 5;
char movie_name[10][50];
int timing[10];
int bill_id = 1;
int bill_movie[10];
char bill_timing[10][6];
int seat_num[10][10];
char date[10][15];
char seat[10][6];

class entrypoint {
public:
    entrypoint() {
        strcpy(movie_name[1], "Yeh Jawaani Hai Deewani");
        timing[1] = 1;
        strcpy(movie_name[2], "Jaane Tu Ya Jaane Na");
        timing[2] = 2;
        strcpy(movie_name[3], "Rockstar");
        timing[3] = 2;
        strcpy(movie_name[4], "Jab We Met");
        timing[4] = 3;
    }

    int admin_menu();
    int user_menu();
    int add_show();
    int delete_show();
    int booking();
    void showmovielist();
    int cancellation();
    int generate_bill();
    string username, password, check;
    void mainmenu();
    void welcome();

    // Login
    void login();
    void regis();
};

void printline() {
    cout << "\n====================================================================================================================\n";
}

// Welcome Page
void entrypoint::welcome() {
    cout << "\n==============================================================\n";
    cout << "    Movie Ticket Management System \n";
    cout << "==============================================================\n";
    cout << "--------------------------- DEVELOPED BY Aditi ---------------------------\n";
    sleep(2);
    cout << "\n\n\t\tPlease wait while loading...\n\n";
    char a=177, b=219;
    cout << "\t\t\t\t";
    for (int i=0;i<=15;i++) cout<<a;
    cout<<"\r";
    cout << "\t\t\t\t";
    for (int i=0;i<=15;i++) {
        cout<<b;
        for (int j=0;j<=1e8;j++);
    }
    mainmenu();
}

// Formatting
void qformatup() {
    cout << "\n\t:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::";
    cout << "\n\t::::::::::::::::::::: ";
}
void qformatdown() {
    cout << "\n\t:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::";
}

// Main Menu
void entrypoint::mainmenu() {
    system("CLS");
    qformatup();
    cout << "\tLogin/Signup to proceed";
    qformatdown();
    int chi;
    cout << "\n[1]. Login";
    cout << "\n[2]. Sign Up";
    cout << "\n[3]. Continue as Guest";
    cout << "\n Enter your choice: ";
    cin >> chi;
    switch (chi) {
        case 1: login(); break;
        case 2: regis(); break;
        case 3: user_menu(); break;
        default: mainmenu(); break;
    }
}

// Add Show
int entrypoint::add_show() {
    string ans;
abc:
    system("CLS");
    qformatup();
    cout << "ADMIN MENU - Add Show";
    qformatdown();
    cout << "\n\tEnter movie name: ";
    cin >> movie_name[i];                
    cout << "\t\tTIMINGS ";
    cout << "\n1. 9:00 13:00 17:00 \n2. 10:00 14:00 18:00\n3. 11:00 15:00 19:00\nChoose Timing ID [1/2/3]: ";
    int x;
    cin >> x;
    timing[i] = x;
    cout << "Movie ID: " << i;
    cout << "\nMovie name: " << movie_name[i];
    cout << "\nShow timing ID: " << timing[i];
    i++;
    cout << "\nDo you want to add more movies? [y/n]: ";
    cin >> ans;
    if(ans=="y"||ans=="Y") goto abc;
    else admin_menu();  
    return 0;
}

// Delete Show
int entrypoint::delete_show() {
    system("CLS");
    qformatup();
    cout << "ADMIN MENU - Delete Show";
    qformatdown();
    cout << "Enter the movie ID to delete: ";
    cin >> i;
    cout << "Movie: " << movie_name[i];
    cout << "\nAre you sure? [y/n]: ";
    char c; cin >> c;
    if(c=='y'|| c=='Y') {
        strcpy(movie_name[i]," ");
    }
    admin_menu();
    return 0;
}

// Admin Menu
int entrypoint::admin_menu() {
    system("CLS");
    qformatup();
    cout << "ADMIN MENU";
    qformatdown();
    cout << "\n\n\t1. Add Show & Select Timing";
    cout << "\n\t2. Delete Show";
    cout << "\n\t3. Book Show";
    cout << "\n\t4. Back to Main";
    cout << "\n\nEnter your choice: ";
    cin >> choice;
    switch(choice) {
        case 1: add_show(); break;
        case 2: delete_show(); break;
        case 3: booking(); break;
        default: mainmenu(); break;
    }
    return 0;
}

// User Menu
int entrypoint::user_menu() {
    system("CLS");
    qformatup();
    cout << "USER MENU";
    qformatdown();
    cout << "\n\n\t1. Booking";
    cout << "\n\t2. Cancellation";
    cout << "\n\t3. Generate Bill";
    cout << "\n\t4. Back to Main Menu";
    cout << "\nEnter your choice: ";
    cin >> choice;
    switch(choice) {
        case 1: booking(); break;
        case 2: cancellation(); break;
        case 3: generate_bill(); break;
        default: mainmenu(); break;
    }
    return 0;
}

// Booking
int entrypoint::booking() {
    system("CLS");
    qformatup();
    cout << "BOOK YOUR TICKET";
    qformatdown();
    showmovielist();
    cout << "\nMovie Serial No [1/2/3..]: ";
    cin >> bill_movie[bill_id];
    cout << "Movie Timing ID [1/2/3]: ";
    cin >> timing[bill_id];
    cout << "Enter Date [DD/MM/YYYY]: ";
    cin >> date[bill_id];
    for(int j=1;j<=5;j++) {
        cout<<endl;
        for(int k=1;k<=6;k++) { 
            cout<<"\t|["<<j<<","<<k<<"]";
        }
    }
    cout << "\nSelect your Seat: ";
    cin >> seat[bill_id];
    cout << "\n\n\tProcessing";
    for(i=0;i<3;i++) { cout<<" ."; sleep(1);}
    cout << "\n\nâœ… Your ticket is booked!";
    cout << "\nYour Bill ID is: " << bill_id;
    bill_id++;
    sleep(2);
    user_menu();
    return 0;
}

// Show Movie List
void entrypoint::showmovielist() {
    cout << "\n-------------------------------------------------------------";
    cout << "\n| SR NO | TIMINGS                | MOVIE NAME              |";
    cout << "\n-------------------------------------------------------------";
    for(int j=1;j<i;j++) {
        string timings;
        switch (timing[j]) {
            case 1: timings="9:00 13:00 17:00"; break;
            case 2: timings="10:00 14:00 18:00"; break;
            default: timings="11:00 15:00 19:00"; break;
        }
        cout << "\n" << j << ".\t" << timings << "\t\t" << movie_name[j];
    }
}

// Cancellation
int entrypoint::cancellation() {
    system("CLS");
    qformatup();
    cout << "CANCEL TICKET";
    qformatdown();
    cout << "Enter your Bill ID: ";
    int k; cin >> k;

    if (k <= 0 || k >= bill_id) {
        cout << "\nâŒ Invalid Bill ID!";
        sleep(2);
        user_menu();
        return 0;
    }

    cout << "\nCancelling ticket for: " << movie_name[bill_movie[k]];
    cout << "\nDate: " << date[k];
    cout << "\nSeat: " << seat[k];

    cout << "\n\n\tProcessing";
    for(i=0;i<3;i++) { cout<<" ."; sleep(1);}
    cout << "\n\nâœ… Ticket Cancelled!";
    bill_movie[k] = 0;
    strcpy(date[k], "CANCELLED");
    strcpy(seat[k], "--");
    sleep(2);
    user_menu();
    return 0;
}

// Generate Bill
int entrypoint::generate_bill() {
    system("CLS");
    qformatup();
    cout << "GENERATE BILL";
    qformatdown();
    cout << "Enter your Bill ID: ";
    int k; cin >> k;

    if (k <= 0 || k >= bill_id) {
        cout << "\n Invalid Bill ID!";
        sleep(2);
        user_menu();
        return 0;
    }

    cout << "\n===================== BILL =====================";
    cout << "\n Bill ID      : " << k;
    cout << "\n Movie        : " << movie_name[bill_movie[k]];
    cout << "\n Timing ID    : " << timing[k];
    cout << "\n Date         : " << date[k];
    cout << "\n Seat Number  : " << seat[k];
    if(strcmp(date[k],"CANCELLED")==0)
        cout << "\n Status       : CANCELLED";
    else
        cout << "\n Status       : BOOKED";
    cout << "\n================================================";
    sleep(4);
    user_menu();
    return 0;
}

// Login
void entrypoint::login() {
    qformatup();
    cout << "WELCOME TO LOGIN PAGE";
    qformatdown();
    sleep(1);
    cout << "\n\tUSERNAME: ";
    cin >> username;
    cout << "\n\tPASSWORD: ";
    cin >> password;
    system("CLS");
    cout << "\tPlease wait while checking";
    for(int i = 0; i < 5; i++) {
        cout << ".";
        sleep(1);
    }
    ifstream take("login.txt");
    while(!take.eof()) {
        take >> check;
        if(check == username) {
            take >> check;
            if(check == password) {
                cout << "\n\n Login Successful!";
                sleep(2);
                take >> check;
                if(check == "admin") {
                    cout << "\n\tWelcome ADMIN!";
                    sleep(2);
                    admin_menu();
                    break;
                } else {
                    cout << "\n\tWelcome USER!";
                    sleep(2);
                    user_menu();
                }
            } else {
                cout << "\n Incorrect Password!";
                sleep(2);
                system("CLS");
                mainmenu();
            }
        }
    }
}

// Registration
void entrypoint::regis() {
    string admin, temp;
    system("CLS");
    qformatup();
    cout << "Registration Form";
    qformatdown();
    cout << "\n\nFULL NAME: ";
    cin >> temp;
    cout << "\nCONTACT NUMBER: ";
    cin >> temp;
    cout << "\nEMAIL ADDRESS: ";
    cin >> temp;
    cout << "\nUSERNAME: ";
    cin >> username;
    cout << "\nPASSWORD: ";
    cin >> password;
xy:
    cout << "\nCONFIRM PASSWORD: ";
    cin >> temp;
    if(temp != password) {
        cout << "\n PASSWORD MISMATCHED!";
        sleep(1);
        goto xy;
    }
yz:
    cout << "\nADMIN ACCOUNT? [Y/N]: ";
    char ch;
    cin >> ch;
    if(ch == 'y' || ch == 'Y') {
        cout << "Admin code: ";
        cin >> admin;
        if(admin != "2106") {
            cout << "âŒ Wrong Admin Code!";
            goto yz;
        }
    }
    ofstream fill("login.txt", ios::app);
    if(admin == "2106")
        fill << "\n" << username << ' ' << password << ' ' << "admin";
    else
        fill << "\n" << username << ' ' << password << ' ' << "user";
    mainmenu();
}

// Main
int main() {
    entrypoint e;
    e.welcome();
}