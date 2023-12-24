#include <GL/glew.h>
#define MAX_VERTEX_BUFFER 512 * 1024
#define MAX_ELEMENT_BUFFER 128 * 1024
#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT
#define NK_IMPLEMENTATION
#define NK_GLFW_GL3_IMPLEMENTATION
#define NK_KEYSTATE_BASED_INPUT
#include "nuklear.h"
#include "nuklear_glfw_gl3.h"

GLFWwindow *win;
struct nk_context *ctx;
struct nk_glfw glfw = {0};

void init(void) {
  int p_width = 200, p_height = 60;
  if (!glfwInit()) {
    fprintf(stderr, "Failed to init GLFW!\n");
    exit(EXIT_FAILURE);
  }
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
  win = glfwCreateWindow(p_width, p_height, "Counter", NULL, NULL);
  glfwMakeContextCurrent(win);
  if (!win) {
    glfwTerminate();
    fprintf(stderr, "Failed to create GLFW window\n");
    exit(EXIT_FAILURE);
  }
  glewExperimental = 1;
  if (glewInit() != GLEW_OK) {
    fprintf(stderr, "Failed to setup GLEW\n");
    exit(EXIT_FAILURE);
  }
  ctx = nk_glfw3_init(&glfw, win, NK_GLFW3_INSTALL_CALLBACKS);
  struct nk_font_atlas *atlas;
  nk_glfw3_font_stash_begin(&glfw, &atlas);
  nk_glfw3_font_stash_end(&glfw);
}

void cleanup(void) {
  nk_glfw3_shutdown(&glfw);
  glfwTerminate();
}

void main_loop(void) {
  int w_width = 200, w_height = 60, counter = 0;
  char counter_txt[10] = "0";
  while (!glfwWindowShouldClose(win)) {
    glfwPollEvents();
    nk_glfw3_new_frame(&glfw);
    /* Σχεδίαση του GUI */
    if (nk_begin(ctx, "Counter window", nk_rect(0, 0, w_width, w_height), 0)) {
      nk_layout_row_dynamic(ctx, 30, 2);
      snprintf(counter_txt, 9, "%d", counter);
      nk_label(ctx, counter_txt, NK_TEXT_CENTERED);
      if (nk_button_label(ctx, "Count")) {
        counter++;
        fprintf(stdout, "Counter=%d\n", counter);
      }
    }
    nk_end(ctx);
    /* Απεικόνιση στην οθόνη */
    glViewport(0, 0, w_width, w_height);
    glClear(GL_COLOR_BUFFER_BIT);
    nk_glfw3_render(&glfw, NK_ANTI_ALIASING_ON, MAX_VERTEX_BUFFER,
                    MAX_ELEMENT_BUFFER);
    glfwSwapBuffers(win);
  }
}

int main(void) {
  init();
  main_loop();
  cleanup();
  return 0;
}
