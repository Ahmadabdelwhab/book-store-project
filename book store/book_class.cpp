#include "book_class.h"
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;
book::book()
{
}

book::~book()
{
}

    //*************************************************Setters**************************************************************//

void book::setAuthorName(string authorName)
{
    strcpy(this->authorName,authorName.c_str());
}
void book::setBookTitle(string bookTitle)
{
    strcpy(this->bookTitle, bookTitle.c_str());
}
void book::setGenre(string genre)
{
    strcpy(this->genre,  genre.c_str());
}
void book::setPrice(int price)
{
    this->price = price;
}
void book::setQuantity(int quantity)
{
    this->quantity = quantity;
}
void book::setID(int ID)
{
    this->ID = ID;
}

    //*************************************************Getters**************************************************************//


char* book::getBookTitle()
{
    return bookTitle;
}
char* book::getAuthorName()
{
    return authorName;
}
char* book::getGenre()
{
    return genre;
}
int book::getPrice()
{
    return price;
}
int book::getQuantity()
{
    return quantity;
}
int book::getID()
{
    return ID;
}
//Print

void book::printBook(book temp)
{
    //CALCULATING SPACES
    int l_bookTitle = strlen(temp.getBookTitle());
    int l_authorName = strlen(temp.getAuthorName());
    int l_genre = strlen(temp.getGenre());
    int l_ID = to_string(temp.getID()).length();
    int l_price = to_string(temp.getPrice()).length();
    int l_qunatity= to_string(temp.getQuantity()).length();

    // alignment and printing
    cout << temp.getID() << string(8 - l_ID,' ') << "||";

    l_bookTitle = (40 - l_bookTitle) / 2;
    cout << string(l_bookTitle, ' ') << temp.getBookTitle() << string(l_bookTitle - !(l_bookTitle & 1), ' ') << "||";


    l_authorName = (40 - l_authorName) / 2;
    cout << string(l_authorName, ' ') << temp.getAuthorName() << string(l_authorName - !(l_authorName & 1), ' ') << "||";


    l_genre = (40 - l_genre) / 2;
    cout << string(l_genre, ' ') << temp.getGenre() << string(l_genre, ' ') << "|| ";


    cout << temp.getPrice() << " L.E" << string(10 - l_price, ' ') << "|| ";

    cout << temp.getQuantity() << string(10 - l_qunatity,' ') << "|";

    cout <<"\n"<<string(120 + 10 + 13 + 19,'_') <<"\n";
    
}