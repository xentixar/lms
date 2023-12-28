#include "./books.h"
#include <string.h>

bool borrowBook(struct Book *_book, User *user)
{
    Book *book = (Book *)_book;

    if (book != NULL && book->owner == NULL && user != NULL)
    {
        book->owner = user;
        return true;
    }
    else
    {
        return false;
    }
}

bool returnBook(struct Book *_book, User *user)
{
    Book *book = (Book *)_book;
    if (book != NULL && user != NULL && book->owner->id == user->id)
    {
        book->owner = NULL;
        return true;
    }
    else
    {
        return false;
    }
}

void updateBook(struct Book *_book, Edition edition)
{
    Book *book = (Book *)_book;
    if (book != NULL)
    {
        book->isbn = edition;
    }
}

Book initialize(int id, User author, User *owner, Edition edition, Category category[], int cat_count, float price, char *title)
{
    Book book;
    book.id = id;
    book.author = author;
    book.owner = owner;
    book.is_available = true;
    book.isbn = edition;
    book.price = price;
    for (int i = 0; i < cat_count; i++)
    {
        book.category[i] = category[i];
    }
    strcpy(book.title, title);

    book.m_borrow = &borrowBook;
    book.m_return = &returnBook;
    book.m_update = &updateBook;
    return book;
}
