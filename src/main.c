#include <raylib.h>
#include <stdio.h>

typedef struct
{
    float width;
    float height;
} SIZE;

float width, height;

SIZE initialize()
{
    InitWindow(0, 0, "Library Management System");
    SetTargetFPS(60);
    return (SIZE){
        .width = GetScreenWidth(),
        .height = GetScreenHeight(),
    };
}

int main()
{
    SIZE size = initialize();
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        EndDrawing();
    }

    CloseWindow();
}