/* 

Ce projet me permet de mieux me familiariser avec C++ mais également avec la bibliothèque OpenGl.

Le code s'inspire de beaucoup de forum ou video sur internet pour que je puisse bien m'entrainner.

*/

#include <iostream>
#include <GLFW/glfw3.h>
#include <cmath>

int main(void)
{

    int window_width = 640;
    int window_height = 480;
    float centre_x = window_width / 2.0f;
    float centre_y = window_height / 2.0f;
    float radius = 50.0f;
    int res = 100;


    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(window_width, window_height, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);


    /* For projecting in the window in pixels */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, window_width, 0, window_height, -1, 1);
    glMatrixMode(GL_MODELVIEW);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLE_FAN);
        glVertex2d(centre_x, centre_y);
        
        for (int i = 0; i <= res; i++) {
            float angle = 2.0f * 3.1415926535 * (static_cast<float>(i) / res);
            float x = centre_x + cos(angle) * radius;
            float y = centre_y + sin(angle) * radius;
            glVertex2d(x, y);
        }

        glEnd();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}