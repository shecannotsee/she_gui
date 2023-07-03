//
// Created by shecannotsee on 23-7-3.
//

#ifndef SHE_GUI_TEST_M1_HELLO_WINDOW_H_
#define SHE_GUI_TEST_M1_HELLO_WINDOW_H_

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace m1_hello_window {

int main() {
  // glfw: 初始化和配置
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // GLFW 窗口创建
  GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
  if (window == NULL) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);
  // glfw：每当窗口大小发生变化（通过操作系统或用户调整大小）时，都会执行此回调函数
  glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int width, int height){
    // 确保视口与新的窗口尺寸匹配;请注意，宽度和高度将明显大于 Retina 显示屏上指定的宽度和高度。
    glViewport(0, 0, width, height);
  });

  // glad: 加载所有 OpenGL 函数指针
  // ---------------------------------------
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }

  // render loop
  while (!glfwWindowShouldClose(window)) {
    // input
    // 处理所有输入：查询GLFW是否按下了相关键释放此帧并做出相应反应
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      glfwSetWindowShouldClose(window, true);
    }

    // glfw：交换缓冲区和轮询 IO 事件（按键释放、鼠标移动等）
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  // GLFW：终止，清除所有以前分配的 GLFW 资源。
  glfwTerminate();
  return 0;
};

} // namespace m1_hello_window

#endif //SHE_GUI_TEST_M1_HELLO_WINDOW_H_
