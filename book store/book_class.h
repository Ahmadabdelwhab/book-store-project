#ifndef BOOK_CLASS_H
#define BOOK_CLASS_H
#include<string>
class book
{
private:

    char bookTitle [40] ;
    char authorName [40];
    char genre [40];
    int price;
    int quantity;
    int ID;

public:

    book();
    ~book();

    //*************************************************Getters**************************************************************//
    
    int getID();
    char* getBookTitle();
    char* getAuthorName();
    char *getGenre();
    int getPrice();
    int getQuantity();

    //*************************************************Setters**************************************************************//
    
    void setID(int);
    void setBookTitle(std::string);
    void setAuthorName(std::string);
    void setGenre(std::string);
    void setPrice(int);
    void setQuantity(int);

    //print
    static void printBook(book);
};
#endif