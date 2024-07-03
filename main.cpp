#include <iostream>
#include <raylib.h>
#include <valarray>

struct Particle {
    Vector2 pos{};
    float radius = 50.0f;
};


int main() {

    InitWindow(800 , 900 , "Sim");
    Particle c1{400 , 200};
    Particle c2{400, 400};
    SetTargetFPS(60);
    auto clr = WHITE;
    while (!WindowShouldClose()) {
        c1 = {GetMousePosition()};
        float dx = c2.pos.x - c1.pos.x;
        float dy = c1.pos.y - c2.pos.x;
        float distance = std::sqrt(dx*dx + dy*dy);
        float sumofRadii = c1.radius  + c2.radius;
        std::string distanceStr = "Distance:"+std::to_string(distance);
        if (distance <= sumofRadii) {
            clr = SKYBLUE;
        }else {
            clr = WHITE;
        }
        ClearBackground(BLACK);
        BeginDrawing();
        DrawText(distanceStr.c_str() , 50 , 0, 20 , WHITE);
        DrawCircleV(c1.pos , c1.radius , clr);
        DrawLineV(c1.pos , c2.pos, WHITE);
        DrawCircleV(c2.pos , c2.radius , WHITE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

