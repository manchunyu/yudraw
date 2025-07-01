#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 800

typedef struct Point {
    Vector2 position;
    Color color;
    float radius;
    struct Point* prev;
    struct Point* next;
} Point;

void UpdateBoard(void);
void DrawBoard(void);
void AppendPoint(void);
void DrawPoints(Point *first);

Point* FirstPoint = NULL;
Point* CurrentPoint = NULL;

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Paint");
    HideCursor();

    while (!WindowShouldClose())
    {
        UpdateBoard();
        DrawBoard();
    }
    CloseWindow();
    return 0;
}

void DrawBoard(void)
{
    BeginDrawing();

    DrawText("PAINT by MCY", 100, 100, 100, WHITE);
    DrawCircleV(GetMousePosition(), 3, RAYWHITE);
    EndDrawing();
}

void UpdateBoard(void)
{
    if (IsMouseButtonPressed(0))
    {
        AppendPoint();
    }
}

void AppendPoint(void)
{
    Point* p = malloc(sizeof(Point));
    p->position = GetMousePosition();
    p->color = RAYWHITE;
    p->radius = 3;

    if (CurrentPoint == NULL)
    {
        FirstPoint = p;
        CurrentPoint = p;
        p->prev = NULL;
        p->next = NULL;
    } else
    {
        CurrentPoint = p;
        p->prev = CurrentPoint;
        p->next = NULL;
    }
}


void DrawPoints(Point *first)
{
    for (Point *p = first; p != NULL; p = p->next)
    {
        DrawCircleV(p->position, p->radius, p->color);
    }
}


