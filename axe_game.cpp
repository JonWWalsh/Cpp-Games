#include "raylib.h"
int main()
{
    // window dimensions
    int width{800};
    int height{450};
    InitWindow(width, height, "Jon's Window");

    // circle coordinates
    int circle_x{200};
    int circle_y{200};
    int circle_radius{25};
    //circle edges
    int l_circle_x{circle_x - circle_radius}; //circle's left edge
    int r_circle_x{circle_x + circle_radius}; //circle's right edge
    int u_circle_y{circle_y - circle_radius}; //circle's top edge
    int b_circle_y{circle_y + circle_radius}; //circle's bottom edge

    // axe coordinates
    int axe_x{400};
    int axe_y{0};
    int axe_length{50};
    // axe edges
    int l_axe_x{axe_x}; // upper left corner of rectangle
    int r_axe_x{axe_x + axe_length}; // x coordinate of right edge of axe
    int u_axe_y{axe_y}; // y coordinate of upper edge of axe
    int b_axe_y{axe_y + axe_length}; // y coordinate of bottom edge of axe

    int direction{10};

    bool collision_with_axe = 
                        (b_axe_y >= u_circle_y) && 
                        (u_axe_y <= b_circle_y) && 
                        (l_axe_x <= r_circle_x) && 
                        (r_axe_x >= l_circle_x);

    SetTargetFPS(60); // sets target value for the # of times the window will update each second
    while(WindowShouldClose() == false) { //As long as WindowShouldClose is == false the window will stay open, once the x or escape is triggered, the value changes to true.

        BeginDrawing();
        ClearBackground(WHITE); //ClearBackground must be used to avoid flickering as the image updates.
        if (collision_with_axe)
        {
            DrawText("Game Over!", 250, 200, 20, RED);
        } else {

        // game logic begins

        // update the edges
            l_circle_x = circle_x - circle_radius;
            r_circle_x = circle_x + circle_radius;
            u_circle_y = circle_y - circle_radius;
            b_circle_y = circle_y + circle_radius;
            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_length;
            u_axe_y = axe_y;
            b_axe_y = axe_y + axe_length;
        // update collision with axe each frame
            collision_with_axe = 
                        (b_axe_y >= u_circle_y) && 
                        (u_axe_y <= b_circle_y) && 
                        (l_axe_x <= r_circle_x) && 
                        (r_axe_x >= l_circle_x);

        DrawCircle (circle_x, circle_y,circle_radius, BLUE);
        DrawRectangle(axe_x, axe_y, axe_length, axe_length, RED);

        // move the axe
        axe_y += direction;
        if(axe_y > height || axe_y < 0) //whenever axe_y goes down to the edge of the window direction will reverse and the amount added will have the opposite sign.
        {
            direction = -direction;
        }

        if (IsKeyDown(KEY_D) && circle_x < width)
        {
            circle_x += 10;
        }
                if (IsKeyDown(KEY_A) && circle_x > 0)
        {
            circle_x -= 10;
        }
        // game logic ends
        }
        EndDrawing();
    }
    //Function Return Values
    //getTheAnswer (returns an int)
    //int answerToLife = getTheAnswer(); or
    //int theUniverse {getTheAnswer()}; (braced method)
    //useAnswer(getTheAnswer()); //We pass getTheAnswer into useAnswer - this only works if useAnswer accepts an int value.

    //raylib uses a function called "WindowShouldClose" (returns a bool)
    //returns true when the x icon is clicked or escape key pressed, otherwise remains false.

    //IsKeyDown (raylib) is used to check if a key is pressed and takes an int as input.  if (IsKeyDown(KEY_D) {}
}