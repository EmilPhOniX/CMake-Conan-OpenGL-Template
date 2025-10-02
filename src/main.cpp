#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main(int argc, char* argv[])
{
    glfwInit();

#ifdef __APPLE__
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    GLFWwindow* window = glfwCreateWindow(800, 600, "Fenêtre OpenGL", NULL, NULL);
    glfwMakeContextCurrent(window); // Le contexte est maintenant actif !
    glewExperimental = GL_TRUE; // Nécessaire pour le profil core
#endif
    
    glGetString(GL_VERSION);
    glewInit();

    return 0;
}