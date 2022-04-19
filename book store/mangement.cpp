#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "book_class.h"
#include "managment.h"
#include <cstdlib>
#include <algorithm>
using namespace std;


void addBook(std::string fileName)
{
    string bookTitle ;
    string authorName;
    string genre  ;
    int price;
    int quantity;
    int ID;

    book temp;
    // prompt
    cout << "Enter Book ID : ";
    cin >> ID;

    cout << "Enter Book Title : ";
    getline(cin >> ws, bookTitle);

    cout << "Enter Author Name : ";
    getline(cin >> ws, authorName);

    cout << "Enter Book's Genre : ";
    getline(cin >> ws, genre);

    cout << "Enter Book's Price : ";
    cin >> price;

    cout << "Enter Book's quantity : ";
    cin >> quantity;
    // assigning values
    temp.setAuthorName(authorName);
    temp.setBookTitle(bookTitle);
    temp.setGenre(genre);
    temp.setID(ID);
    temp.setPrice(price);
    temp.setQuantity(quantity);
    

    // writing into file
    ofstream out(fileName.c_str(),ios::app);
    out.write((char *)&temp, sizeof(temp));
    out.close();

    cout << "Record was added successfully\n";
    system("pause");
}
void header()
{
    cout << "ID" << string(6,' ') <<"||"
        <<string(17,' ') << "Title" << string(17,' ')<<"||"
        <<string(17,' ') << "Author"<< string(16,' ')<<"||"
        <<string(17,' ') << "genre" << string(17,' ')<<"|| "
        <<"Price"<<string(8,' ') <<"|| "
        <<"Quantity" << string(2,' ') <<"|"
        <<"\n"<<string(120 + 10 + 13 + 19,'_') <<"\n";
}
void displayRecords(std::string fileName)
{
    ifstream in(fileName.c_str(), ios::in);
    book temp;
    in.read((char *)&temp, sizeof(temp));
    header();
    while(!in.eof())
    {
        book::printBook(temp);
        in.read((char *)&temp, sizeof(temp));
    }
    in.close();

    system("pause");
}
//********************************************** search fucntions *****************************************************//
void searchByID(std::string fileName)
{
    int ID;
    ifstream in(fileName.c_str());
    book temp;
    


    cout << "Enter ID : ";
    cin >> ID;
    in.read((char *)&temp, sizeof(temp));

    while(!in.eof())
    {
        if(temp.getID() == ID)
        {
            header();
            book::printBook(temp);
            return;
        }
        in.read((char *)&temp, sizeof(temp));
        
    }
    in.close();
    cout << "No book is found with ID : " << ID << "\n";
    system("pause");
}
void searchByAuthor(std::string fileName)
{
    string author;
    ifstream in(fileName.c_str());
    book temp;
    bool isFound = false;

    cout << "Enter author's name : ";
    getline(cin >> ws, author);
    transform(author.begin(), author.end(), author.begin(), ::tolower);

    in.read((char *)&temp, sizeof(temp));

    header();
    while(!in.eof())
    {
        string searchAuthor(temp.getAuthorName());
        transform(searchAuthor.begin(), searchAuthor.end(), searchAuthor.begin(), ::tolower);
    
        if(searchAuthor.find(author) != string::npos)
        {
            book::printBook(temp);
            isFound = true;
        }

        in.read((char *)&temp, sizeof(temp));
        
    }
    in.close();
    if(!isFound)
        cout << "No author is found with name : " << author << "\n";
    system("pause");
}
void searchByTitle(std::string fileName)
{
    string title;
    ifstream in(fileName.c_str());
    book temp;
    bool isFound = false;

    cout << "Enter book's title: ";
    getline(cin >> ws, title);
    transform(title.begin(), title.end(), title.begin(), ::tolower);

    in.read((char *)&temp, sizeof(temp));

    header();
    while(!in.eof())
    {
        string searchTitle(temp.getBookTitle());
        transform(searchTitle.begin(), searchTitle.end(), searchTitle.begin(), ::tolower);
    
        if(searchTitle.find(title) != string::npos)
            book::printBook(temp) , isFound = true;

        in.read((char *)&temp, sizeof(temp));
        
    }
    in.close();
    if(!isFound)
        cout << "No book is found with title : " << title << "\n";
    system("pause");
}
void searchByGenre(std::string fileName)
{
    string genre;
    ifstream in(fileName.c_str());
    book temp;
    bool isFound = false;

    cout << "Enter book's genre: ";
    getline(cin >> ws, genre);
    transform(genre.begin(), genre.end(), genre.begin(), ::tolower);

    in.read((char *)&temp, sizeof(temp));

    header();
    while(!in.eof())
    {
        string searchGenre(temp.getGenre());
        transform(searchGenre.begin(), searchGenre.end(), searchGenre.begin(), ::tolower);
    
        if(searchGenre.find(genre) != string::npos)
            book::printBook(temp) , isFound = true;

        in.read((char *)&temp, sizeof(temp));
        
    }
    in.close();
    if(!isFound)
        cout << "No book is found with genre : " << genre << "\n";
    system("pause");
}
void searchMenu(std::string fileName)
{
    char choice;
    cout<< "1 - Serach by ID\n\n"
        << "2 - Search by title\n\n"
        << "3 - Search by author\n\n"
        << "4 - Search by genre\n\n";
    cout<< "Enter your choice : ";
    cin >> choice;

    if(choice == '1')
        searchByID(fileName);
    else if (choice == '2')
        searchByTitle(fileName);
    else if(choice == '3')
        searchByAuthor(fileName);
    else if(choice == '4')
        searchByGenre(fileName);
    else
    {
        cout << "Invalid option\n\n";
        system("pause");
    }
}
void updateRecordByID(std::string fileName)
{
    int ID;
    fstream update(fileName.c_str(), ios::in | ios::out);
    book temp;
    cout << "Enter ID : ";
    cin >> ID;
    streampos curposition;
    while(!update.eof())
    {
        update.read((char *)&temp, sizeof(temp));
        if(ID == temp.getID())
        {
            header();
            book::printBook(temp);

        }

    }
    

    
}