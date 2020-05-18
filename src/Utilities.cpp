#include "../include/Utilities.h"


// Function Display
// Inputs:
//        gameState - An integer that specifies the gamestate
// Output: None
// Purpose:  The display function sets up the window for the game.
void display(void)
{
    int gameState = 0;
    // Clear the screen to black
    glClearColor(0.0, 0.0, 0.0, 0.0);

    // Clear the color buffer
    glClear(GL_COLOR_BUFFER_BIT);

    // Display environment based on gameState

    glutSwapBuffers();
 
    return;
}

// Function reshape
// Inputs:
//       width - An integer indicating the new width
//       height - An integer indicating the new height
//       screen - A GameScreen object containing the play area
// Output: None
// Purpose:  The reshape function resizes the game window.
void reshape(int w, int h)
{
//    screen.setWidth(static_cast<GLdouble>(w));
//    screen.setHeight(static_cast<GLdouble>(h));

   // glViewport(0,0, (GLsizei) screen.getWidth(), (GLsizei) screen.getHeight());

    glViewport(0,0,(GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, w, 0.0, h);
//    gluOrtho2D(0.0, static_cast<int>(screen.getWidth()), 0.0, static_cast<int>(screen.getHeight()));

    return;
}

// Function mouseButtons
// Inputs:
//       button - An integer indicating the button being pressed
//       state - An integer indicating the state of the button
//       x - The x coordinate of the mouse
//       y - The y coordinate of the mouse
// Ouputs: None
// Purpose:  This is an opengl mouse listener for handling mouse input
void mouseButtons(int button, int state, int x, int y)
{
    switch(button)
    {
        case GLUT_LEFT_BUTTON:
        {
            if (state == GLUT_DOWN)
            {
                cout << "Left mouse button pressed." << endl;
            }

            break;
        }
        case GLUT_RIGHT_BUTTON:
        {
            if (state == GLUT_DOWN)
            {
                cout << "Right mouse button pressed." << endl;
            }

            break;
        }
        case GLUT_MIDDLE_BUTTON:
        {
            if (state == GLUT_DOWN)
            {
                cout << "Middle mouse button pressed." << endl;
            }

            break;
        }
    }

    return;
}

// Function mouseActiveMotion
// Inputs:
//       x - An integer indicating the x coordinate of the mouse
//       y - An integer indicating the y coordinate of the mouse
// Outputs: None
// Purpose:  Track mouse motion when the buttons are being pressed
void mouseActiveMotion(int x, int y)
{
    cout << "active x = " << x << endl;
    cout << "active y = " << y << endl;

    return;
}

// Function mousePassiveMotion
// Inputs:
//       x - An integer indicating the x coordinate of the mouse
//       y - An integer indicating the y coordinate of the mouse
// Outputs:  None
// Purpose:  Track the movement of the mouse whenever it is in screen
void mousePassiveMotion(int x, int y)
{
    cout << "passive x = " << x << endl;
    cout << "passive y = " << y << endl;

    return;
}
