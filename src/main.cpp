#include "main.h"
#include "timer.h"
#include "plane.h"
#include "floor.h"

using namespace std;

GLMatrices Matrices;
GLuint     programID;
GLFWwindow *window;

/**************************
* Customizable functions *
**************************/

Plane player;
vector <Floor> islands;

float screen_zoom = 1, screen_center_x = 0, screen_center_y = 0;
float camera_rotation_angle = 0;
glm::vec3 eye,target,up;
camera_view_t camera_view = CAMERA_NORMAL;

int number_of_islands = 50;

Timer t60(1.0 / 60);

/* Render the scene with openGL */
/* Edit this function according to your assignment */
void draw() {
    // clear the color and depth in the frame buffer
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // use the loaded shader program
    // Don't change unless you know what you are doing
    glUseProgram (programID);

    if(camera_view == CAMERA_NORMAL)
    {
        eye = glm::vec3( 0, player.position.y+10,20);
        target = glm::vec3(player.position.x, player.position.y,player.position.z);
        up = glm::vec3(0, 1, 0);
    }
    else if(camera_view == CAMERA_TOWER)
    {
        eye = glm::vec3( 20, 20 ,0);
        target = glm::vec3 (0, 3, -2);
        up = glm::vec3(0, 1, 0);
    }
    else if (camera_view == CAMERA_TOP){
        eye  = glm::vec3(player.position.x, player.position.y+45, player.position.z-2);
        target = glm::vec3 (player.position.x,player.position.y,player.position.z);
        up = glm::vec3 (0, -1, 0);
    }
    else if(camera_view == CAMERA_FOLLOW)
    {       
        eye = glm::vec3(player.position.x+10*player.local_rotation[2][0],player.position.y+10*player.local_rotation[2][1],player.position.z+10*player.local_rotation[2][2]);
        target = glm::vec3(player.position.x-25*player.local_rotation[2][0],player.position.y-25*player.local_rotation[2][1],player.position.z-25*player.local_rotation[2][2]);
        up = glm::vec3(player.local_rotation[1][0],player.local_rotation[1][1],player.local_rotation[1][2]);
        // up = glm::vec3(0,1,0);
    }

    

    Matrices.view = glm::lookAt(eye,target,up);
    glm::mat4 VP = Matrices.projection * Matrices.view;

    // Send our transformation to the currently bound shader, in the "MVP" uniform
    // For each model you render, since the MVP will be different (at least the M part)
    // Don't change unless you are sure!!
    glm::mat4 MVP;  // MVP = Projection * View * Model

    player.draw(VP);
    player.draw2(VP);

    for(int i=0;i<number_of_islands;i++)
    {
        islands[i].draw(VP);
    }
    // clouds.draw(VP);
    // Scene render
    
}

void tick_input(GLFWwindow *window) {
    int a  = glfwGetKey(window, GLFW_KEY_A);
    int d = glfwGetKey(window, GLFW_KEY_D);
    int w = glfwGetKey(window,GLFW_KEY_W);
    int r = glfwGetKey(window,GLFW_KEY_R);
    int e = glfwGetKey(window,GLFW_KEY_E);
    int s = glfwGetKey(window,GLFW_KEY_S);
    int x = glfwGetKey(window,GLFW_KEY_X);
    int c = glfwGetKey(window,GLFW_KEY_C);
    if (a) {
        player.left();
        //player.left_tilt();
    }
    if(d){
        player.right();
        //player.right_tilt();
    }
    if(w)
    {
        player.forward();
    }
    if(e)
    {
        player.nose_down();
    }
    if(r)
    {
        player.nose_up();
    }
    if(s)
    {
        player.backward();
    }
    if(x)
    {
        player.right_tilt();
    }
    if(c)
    {
        player.left_tilt();
    }
}

void tick_elements() {
    player.tick();

    for(int i=0;i<number_of_islands;i++)
    {
        islands[i].tick();
    }

    cout << player.position.x << " " << player.position.y << " " << player.position.z << '\n';
    cout << player.local_rotation[2][0] << " " << player.local_rotation[2][1] << " " << player.local_rotation[2][2] << '\n';
    cout << "eye " << eye.x << " " << eye.y << " " << eye.z << '\n';
    //clouds.tick();
    //camera_rotation_angle += 1;
}

/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL(GLFWwindow *window, int width, int height) {
    /* Objects should be created before any other gl function and shaders */
    // Create the models

    
    player = Plane(0,0,0);

    for(int i = 0;i<number_of_islands;i++)
    {
        islands.push_back(Floor(rand()%1000,-100,rand()%1000));
    }
    
    // clouds = Floor(0,-100,0);
    // Create and compile our GLSL program from the shaders
    programID = LoadShaders("Sample_GL.vert", "Sample_GL.frag");
    // Get a handle for our "MVP" uniform
    Matrices.MatrixID = glGetUniformLocation(programID, "MVP");


    reshapeWindow (window, width, height);

    // Background color of the scene
    glClearColor (COLOR_SKY.r / 256.0, COLOR_SKY.g / 256.0, COLOR_SKY.b / 256.0, 0.0f); // R, G, B, A
    glClearDepth (1.0f);

    glEnable (GL_DEPTH_TEST);
    glDepthFunc (GL_LEQUAL);

    cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
    cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
    cout << "VERSION: " << glGetString(GL_VERSION) << endl;
    cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}


int main(int argc, char **argv) {
    srand(time(0));
    int width  = 800;
    int height = 800;

    window = initGLFW(width, height);

    initGL (window, width, height);

    /* Draw in loop */
    while (!glfwWindowShouldClose(window)) {
        // Process timers

        if (t60.processTick()) {
            // 60 fps
            // OpenGL Draw commands
            draw();
            // Swap Frame Buffer in double buffering
            glfwSwapBuffers(window);

            tick_elements();
            tick_input(window);
        }

        // Poll for Keyboard and mouse events
        glfwPollEvents();
    }

    quit(window);
}

bool detect_collision(bounding_box_t a, bounding_box_t b) {
    return (abs(a.x - b.x) * 2 < (a.width + b.width)) &&
           (abs(a.y - b.y) * 2 < (a.height + b.height));
}

void reset_screen() {
    float top    = screen_center_y + 4 / screen_zoom;
    float bottom = screen_center_y - 4 / screen_zoom;
    float left   = screen_center_x - 4 / screen_zoom;
    float right  = screen_center_x + 4 / screen_zoom;
    Matrices.projection = glm::perspective(1.0f, 1.0f, 1.0f, 500.0f);
}
