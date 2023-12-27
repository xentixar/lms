#include <raylib.h>
#include <stdio.h>

int main()
{
    InitWindow(400, 500, "LMS");
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        EndDrawing();
        if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
        {
            break;
        }
    }

    CloseWindow();
}