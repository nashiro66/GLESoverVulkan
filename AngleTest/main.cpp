#include <iostream>

#define GLFW_INCLUDE_ES2
#define GL_GLEXT_PROTOTYPES

#include "GLFW/glfw3.h"

int main(){

    int Width = 800;
    int Height = 600;

    //バックエンドにVulkanを選択
    glfwInitHint(GLFW_ANGLE_PLATFORM_TYPE, GLFW_ANGLE_PLATFORM_TYPE_VULKAN);

    if (glfwInit() == GL_FALSE)
    {
        throw std::runtime_error("failed to init GLFW");
    }

    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
    glfwWindowHint(GLFW_CONTEXT_CREATION_API, GLFW_EGL_CONTEXT_API);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    auto window = glfwCreateWindow(Width, Height, "App", nullptr, nullptr);
    if (!window)
    {
        throw std::runtime_error("failed to create Window");
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    while (glfwWindowShouldClose(window) == GL_FALSE)
    {
        glfwPostEmptyEvent();
        glViewport(0, 0, Width, Height);
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.f, 0.f, 0.5f, 1.f);
        glfwSwapBuffers(window);
        glfwWaitEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return -1;
}
