// Name: Bhagyashree Aras
// Filename: p1.cpp
// Date: 28 September 2020
// Purpose: The program demonstrates recommendations for books. The program to
//          read file specified by user and use BookList object, ratingList
//          object and memberList object to perform operations and provide
//          insights as per choice of user.
//
// Input:   Two .txt file(books and ratings)
// Process: Takes file to read and upload to respective dynamic arrays.
//          Use BookList object, ratingList object and memberList object.
//
// Output:  Display array and size of array
#include <iostream>
#include "BookList.h"
#include "RatingList.h"
#include "MemberList.h"
#include <fstream>
#include <sstream>

using namespace std;

void welcome();
// This function displays welcome message.
// IN: none
// Modify: none
// OUT: print welcome message

void readFile(BookList &, MemberList &, RatingList &);
// This function reads the file specified by user.
// IN: BookList object, RatingList object, MemberList object
// Modify: none
// OUT: Prints error message if file dont exist and terminates, otherwise
//      program runs

void passToBookArray(BookList &, ifstream &);
// This function is helper function of readFile, which populates data to book
// array
// IN : BookList object, Ifstream object
// MODIFY: None
// OUT: None

void memberAndRatingArray(MemberList &, RatingList &, ifstream &);
// This function is helper function of readFile, which populates data to rating
// array and member array
// IN : BookList object, RatingList object, Ifstream object
// MODIFY: None
// OUT: None

void printSize(BookList &, MemberList &);

// This function displays size of dynamically created array.
// IN: BookList object, MemberList object
// Modify: none
// OUT: print size of BookList and MemberList array

void mainMenu(BookList & , RatingList &, MemberList &);
// This function displays main menu.
// IN: BookList object, RatingList object, MemberList object, 1 >= user's
//                                                              input <= 4
// Modify: none
// OUT: Direct to addBook or addMember or login or goodBye function as per
//      user's input
void printMainMenu();
// This function prints main menu.
// IN: none
// Modify: none
// OUT: prints main menu

void printMenu();
// This function prints another sub menu if user inputs choose 3(login) in menu.
// IN: none
// Modify: none
// OUT: prints sub menu from login function

void addBook(BookList &);
// This function add books to dynamic bookArray on heap using BookList object.
// IN: BookList object
// MODIFY: Adding book to book array
// OUT: Printing which book is added

void addMember(MemberList &);
// This function add members to dynamic array on heap using MemberList object
// IN: MemberList object
// MODIFY: Adding member to member array
// OUT: Printing which member is added

void login(MemberList &, BookList &, RatingList &);
// This function allow the user to login and access sub menu as well as
// perform operation as per user's input
// IN: MemberList object, BookList object, RatingList object
// MODIFY:
// OUT: direct to add member, add book, view ratings, rate book, book
//      recommendation or back to main menu.

void viewRatings(int,MemberList &, BookList &, RatingList &);
// This function allow the logged in user to view ratings
// IN: MemberList object, BookList object, RatingList object
// MODIFY: none
// OUT: Prints ratings of logged in user

void rateBook(int, BookList &, RatingList &);
// This function allow the logged in user to assign new ratings or update
// ratings.
// IN: BookList object, RatingList object, member key
// MODIFY: rating array will be updated
// OUT: Print the updated rating by fetching from array

void bookRecommendation(RatingList &, MemberList &, BookList &, int);
// This function allow the logged in user get book recommendation
// IN: MemberList object, BookList object, RatingList object, member key
// MODIFY: None
// OUT: Prints the member name with whom choice resembles
void printRecommendation(RatingList &, BookList &, int , int, int );
// This function is helper function of bookRecommendation
// IN: MemberList object, BookList object, RatingList object, member key ,
//     really liked rating and liked rating
// MODIFY: None
// OUT: Prints the recommended books for logged in member

void goodBye();
// This function displays goodBye message.
// IN: none
// Modify: none
// OUT: print goodBye message

int main()
{
    const int SIZE = 10;                        // declare constant size
    BookList bookArray(SIZE);                   // object of BookList
    MemberList memberList(SIZE);                // object of memberList
    RatingList ratingList(SIZE);                // object od ratingList

    welcome();
    readFile(bookArray, memberList, ratingList);
    printSize(bookArray, memberList);
    mainMenu(bookArray, ratingList, memberList);
    return 0;
}

void welcome()
{
    cout << "Welcome to the Book Recommendation Program. This program allow"
            "\nyou to add/update member, book, rating. In addition to this,"
            "\nthe program enables you to see ratings after login as well as"
            "\ngive recommendation of books." << endl << endl;
}

void readFile(BookList &bookArray, MemberList &memberList, RatingList
&ratingList)
{
    string fileName, ratingFile;                // filename
    ifstream inFile1, inFile2;                  // object of ifstream

    // get the file
    cout << "Enter books file: ";
    cin >> fileName;

    // get the file
    cout << "Enter ratings file: ";
    cin >> ratingFile;

    // open and read the file
    inFile1.open(fileName);
    if (inFile1)
    {
        passToBookArray(bookArray, inFile1);
    }
    else
    {
        cout << "Error opening file...\n";
        exit(0);
    }
    // close file
    inFile1.close();

    // open and read the file
    inFile2.open(ratingFile);

    if (inFile2)
    {
        memberAndRatingArray(memberList, ratingList, inFile2);

    }
    else
    {
        cout << "Error opening file...\n";
        exit(0);
    }
    // close file
    inFile2.close();
}

void passToBookArray(BookList &bookArray, ifstream &inFile1) {
    int count = 0;
    string author, title, year;                 // to store author, title, year
    string line;

    while (getline(inFile1, line)) {
        stringstream ss(line);

        while (getline(ss, line, ',')) {
            if (count % 3 == 0) {
                author = line;
            } else if (count % 3 == 1) {
                title = line;
            } else if (count % 3 == 2) {
                year = line;
                bookArray.add(author, title, year);
            }
            count++;
        }
    }
}

void memberAndRatingArray(MemberList &memberList, RatingList &ratingList,
                          ifstream &inFile2)
{
    string line1, line2;
    int colCount;                               // count of column
    int rowCount = 0;                           // count of row
    while (getline(inFile2, line1)) {
        memberList.add(line1);
        getline(inFile2, line2);

        // Used to split string around spaces.
        istringstream stream(line2);
        colCount = 0;
        int number;
        while (stream >> number) {
            ratingList.add(rowCount, colCount, number);
            colCount++;
        }
        rowCount++;
    }
}

void printSize(BookList &bookArray, MemberList &memberList)
{
    cout << endl << "# of books: " << bookArray.size() << endl;
    cout << "# of members: " << memberList.size() << endl;
}

void mainMenu(BookList &bookArray,RatingList &ratingList, MemberList
&memberList)
{
    const int FIRST = 1;
    const int SECOND = 2;
    const int THIRD = 3;
    const int FOURTH = 4;
    int menuOption;
    do {
        printMainMenu();
        cin >> menuOption;

        if (menuOption == FIRST) {
            addMember(memberList);
        } else if (menuOption == SECOND) {
            addBook(bookArray);
        } else if (menuOption == THIRD) {
            login(memberList, bookArray, ratingList);
        } else if (menuOption == FOURTH) {
            goodBye();
        } else {
            cout << "Invalid Option, choose from menu(1 - 4)." << endl;
        }
    } while (menuOption != FOURTH);
}

void login(MemberList &memberList, BookList &bookArray,
           RatingList &ratingList)
{
    const int FIRST = 1;
    const int SECOND = 2;
    const int THIRD = 3;
    const int FOURTH = 4;
    const int FIFTH = 5;
    const int SIXTH = 6;
    int memberKey;
    int choice;
    cout << endl << "Enter member account: ";
    cin >> memberKey;
    if (memberList.getMember(memberKey - 1) != "")
    {
        cin.ignore();
        cout << memberList.getMember(memberKey - 1) << ", you are logged in!"
             << endl;
        do {
            printMenu();
            cin >> choice;

            if (choice == FIRST) {
                addMember(memberList);
            } else if (choice == SECOND) {
                addBook(bookArray);
            } else if (choice == THIRD) {
                rateBook(memberKey, bookArray, ratingList);
            } else if (choice == FOURTH) {
                viewRatings(memberKey, memberList,
                            bookArray, ratingList);
            } else if (choice == FIFTH) {
                bookRecommendation(ratingList, memberList, bookArray,
                                   memberKey);
            } else if (choice < FIRST || choice > SIXTH) {
                cout << "Invalid Option, choose from menu(1 - 6)" << endl;
            }
        } while (choice != SIXTH);
    }
    else
    {
        cout << endl << "Account is invalid, please input correct one" << endl;
    }
}

void addMember(MemberList &memberList)
{
    string memberName;                          // member name
    cout << "Enter the name of the new member: ";
    cin.ignore();
    getline(cin, memberName);
    memberList.add(memberName);
    cout << memberList.getMember(memberList.size() - 1)
         << " (account #: " << memberList.size() << ") was added." << endl;
}

void addBook(BookList &bookArray)
{
    string bookName, bookTitle, bookYear;       // Book name, title, year
    cout << "Enter the author of the new book: ";
    cin.ignore();
    getline(cin, bookName);
    cout << "Enter the title of the new book: ";
    getline(cin,bookTitle);
    cout << "Enter the year (or range of years) of the new book: ";
    getline(cin, bookYear);

    bookArray.add(bookName, bookTitle, bookYear);
    cout << bookArray.getBook(bookArray.size() - 1) << " was added." << endl;
}

void bookRecommendation(RatingList &ratingList, MemberList &memberList,
                        BookList &bookArray, int memberKey)
{
    const int REALLY_LIKED_RATING = 5;
    const int LIKED_RATING = 3;

    int similarMemberIndex = ratingList.vectorProduct(memberKey - 1);

    cout << endl << "You have similar taste in books as "
         << memberList.getMember(similarMemberIndex) << endl;

    cout << endl << "Here are the books they really liked:" << endl;
    printRecommendation(ratingList,bookArray, similarMemberIndex,
                        memberKey, REALLY_LIKED_RATING);

    cout << endl << "Here are the books they liked:" << endl;
    printRecommendation(ratingList,bookArray, similarMemberIndex,
                        memberKey, LIKED_RATING);
}

void printRecommendation(RatingList &ratingList, BookList &bookArray,
                    int similarMemberIndex, int memberKey, int rating)
{
    for (int i = 0; i < ratingList.size(); i++)
    {
        if (ratingList.getRating(similarMemberIndex, i) == rating && ratingList
                .getRating(memberKey - 1,i) == 0)
        {
            cout << bookArray.getBook(i) << endl;
        }
    }
}

void rateBook(int memberKey, BookList &bookArray, RatingList
                 &ratingList)
{
    int isbn;
    int rating;
    char input1;

    // validating isbn
    do {
        cout << endl << "Enter the ISBN for the book you'd like to rate: ";
        cin >> isbn;
    } while (bookArray.getIsbn(isbn) != true);

    // checking if book has been already rated or not
    if (ratingList.getRating(memberKey - 1, isbn - 1) == 0)
        {
            // validating rating
            do{
                cout << "Enter your rating: ";
                cin >> rating;
            } while (ratingList.validate(rating) != true);

            ratingList.add(memberKey - 1, isbn - 1, rating);

            cout << "Your new rating for" << ", " << bookArray
                    .getBook(isbn - 1) << " => rating: "
                 << ratingList.getRating(memberKey - 1, isbn - 1) << endl;

        }
        else
        {
        cout << "Your current rating for " << bookArray
                .getBook(isbn - 1) << " => rating: "<< ratingList.getRating
                                                    (memberKey - 1, isbn - 1);
        cout << endl << "Would you like to re-rate this book (y/n)? ";
        cin >> input1;

        if (input1 == 'Y' || input1 == 'y')
        {
            // validating rating
            do {
                cout << "Enter your rating: ";
                cin >> rating;
            } while (ratingList.validate(rating) != true);

            ratingList.add(memberKey - 1, isbn - 1,
                                    rating);

            cout << "Your new rating for" << ", " << bookArray
                    .getBook(isbn - 1) << " => rating: "
                 << ratingList.getRating(memberKey - 1, isbn - 1) << endl;
        }
        else
        {
            cout << "The rating has not been changed" << endl;
        }
    }
}

void viewRatings(int memberKey, MemberList &memberList, BookList &bookArray,
                 RatingList &ratingList)
{
    cout << endl << memberList.getMember(memberKey - 1)
         << "'s ratings..." << endl;
    for (int i = 0; i < bookArray.size(); i++) {
        cout << bookArray.getBook(i) << " => rating: "
             << ratingList.getRating(memberKey - 1, i) << endl;
    }
}

void printMainMenu() {
    cout << endl << "************** MENU **************\n"
            "* 1. Add a new member            *\n"
            "* 2. Add a new book              *\n"
            "* 3. Login                       *\n"
            "* 4. Quit                        *\n"
            "**********************************" << endl << endl;
    cout << "Enter a menu option: ";
}
void printMenu()
{
    cout << endl << "************** MENU **************\n"
            "* 1. Add a new member            *\n"
            "* 2. Add a new book              *\n"
            "* 3. Rate book                   *\n"
            "* 4. View ratings                *\n"
            "* 5. See recommendations         *\n"
            "* 6. Logout                      *\n"
            "**********************************" << endl << endl;
    cout << "Enter a menu option: ";
}

void goodBye()
{
    cout << endl << "Thank you for using the Book "
                    "Recommendation Program!" << endl;
}
