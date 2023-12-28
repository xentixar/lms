#ifndef __BOOKS__
#define __BOOKS__
#include <stdbool.h>
#include <time.h>
#define MAX_STRING_LENGTH 1024
#define MAX_VERSION_LENGTH 100
#define MAX_CATEGORY_LENGTH 200
#define MAX_CATEGORY_COUNT 20

typedef enum
{
    ROLE_ADMIN = 0,
    ROLE_USER,
    ROLE_AUTHOR
} ROLE;

struct Book;
struct Subscription;
struct User;
struct Category;
struct Edition;

typedef struct
{
    int id;
    struct timespec issue_date;
    struct timespec expire_date;
} Subscription;

typedef struct
{
    int id;
    ROLE role;
    Subscription subscription;
    char name[MAX_STRING_LENGTH];
} User;

typedef struct
{
    int id;
    char name[MAX_CATEGORY_LENGTH];
} Category;

typedef struct
{
    int id;
    char version[MAX_VERSION_LENGTH];
    struct timespec date;
} Edition;

typedef struct
{
    int id;
    User author;
    User *owner;
    bool is_available;
    Edition isbn;
    float price;
    char title[MAX_STRING_LENGTH];
    Category category[MAX_CATEGORY_COUNT];
    bool (*m_borrow)(struct Book *, User *);
    bool (*m_return)(struct Book *, User *);
    void (*m_update)(struct Book *, Edition);
} Book;

Book initialize(int, User, User *, Edition, Category *, int, float, char *);

#endif