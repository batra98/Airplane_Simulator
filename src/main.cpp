#include "main.h"
#include "timer.h"
#include "plane.h"
#include "floor.h"
#include "bullet.h"
#include "sea.h"
#include "ring.h"
#include "indicator.h"
#include "enemy_bullet.h"

using namespace std;

GLMatrices Matrices;
GLuint     programID;
GLFWwindow *window;

/**************************
* Customizable functions *
**************************/

Plane player;
Sea sea;
Ring ring;
// Indicator indicator;
vector <Floor> islands;
vector <Bullet> bullets;
vector <Enemy_bullet> enemy_bullets;


float screen_zoom = 1, screen_center_x = 0, screen_center_y = 0;
float camera_rotation_angle = 0;
glm::vec3 eye,target,up;
camera_view_t camera_view = CAMERA_NORMAL;

int number_of_islands = 20;
int counter=0;
float shortest_enemy=0.0f;



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
        target = glm::vec3(player.position.x-50*player.local_rotation[2][0],player.position.y-50*player.local_rotation[2][1],player.position.z-50*player.local_rotation[2][2]);
        up = glm::vec3(player.local_rotation[1][0],player.local_rotation[1][1],player.local_rotation[1][2]);
        // up = glm::vec3(0,1,0);
    }
    else if(camera_view == CAMERA_DRIVER)
    {
        eye = glm::vec3(player.position.x-4*player.local_rotation[2][0],player.position.y-4*player.local_rotation[2][1],player.position.z-4*player.local_rotation[2][2]);
        target = glm::vec3(player.position.x-50*player.local_rotation[2][0],player.position.y-50*player.local_rotation[2][1],player.position.z-50*player.local_rotation[2][2]);
        up = glm::vec3(player.local_rotation[1][0],player.local_rotation[1][1],player.local_rotation[1][2]);
    }

    

    Matrices.view = glm::lookAt(eye,target,up);
    glm::mat4 VP = Matrices.projection * Matrices.view;

    // Send our transformation to the currently bound shader, in the "MVP" uniform
    // For each model you render, since the MVP will be different (at least the M part)
    // Don't change unless you are sure!!
    glm::mat4 MVP;  // MVP = Projection * View * Model

    player.draw(VP);
    sea.draw(VP);
    ring.draw(VP);
    // indicator.draw(VP);


    for(int i=0;i<number_of_islands;i++)
    {
        islands[i].draw(VP);
    }

    for(int i = 0;i<bullets.size();i++)
    {
        bullets[i].draw(VP);
    }

    for(int i = 0;i<enemy_bullets.size();i++)
    {
        enemy_bullets[i].draw(VP);
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
    int f = glfwGetKey(window,GLFW_KEY_F);
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
    if(f)
    {
        if(counter%10==0)
        {
            glm::vec3 direction = player.translate_z;
            bullets.push_back(Bullet(player.position.x,player.position.y,player.position.z,direction));            
        }
    }
}

void tick_elements() {
    player.tick();
    player.indicator.tick(player.position,ring.position-player.indicator.position,player.translate_z);

    
    float length,min = 10000;
    for(int i=0;i<number_of_islands;i++)
    {
        islands[i].tick(player.position);
        // cout << islands[i].land_enemies.enemy_cannon.position.x << '\n';
        length = glm::length(player.position-islands[i].land_enemies.enemy_cannon.position);
        if(length<min)
        {
            min = length;
            shortest_enemy = i;
        }
        if(detect_collision(player.bounding_sphere(),islands[i].bounding_sphere()))
        {
            cout << i << " " << "detected 1" << '\n';
        }
        if(detect_collision(player.bounding_sphere(),islands[i].bounding_sphere2()))
        {
            cout << i << " " << "detected 2" << '\n';
        }
    }

    if(counter%20==0)
    enemy_selected(shortest_enemy);

    for(int i=0;i<bullets.size();i++)
    {
        bullets[i].tick();
        
    }

    if(check_pass_through()==true)
    {
        ring.set_position(-rand()%60,rand()%60,-rand()%60);
    }

    for(int i = 0;i<enemy_bullets.size();i++)
    {
        enemy_bullets[i].tick();
        if(detect_collision(player.bounding_sphere(),enemy_bullets[i].bounding_sphere()))
        {
            cout << i << " hit" << '\n';
        }
    }
    
    cout << enemy_bullets.size() << '\n';
    // cout << player.position.x << " " << player.position.y << " " << player.position.z << '\n';
    // cout << islands[0].position.x << " " << islands[0].position.y << " " << islands[0].position.z << '\n';
    // cout << bullets.size() << '\n';
    // cout << player.local_rotation[2][0] << " " << player.local_rotation[2][1] << " " << player.local_rotation[2][2] << '\n';
    // cout << "eye " << eye.x << " " << eye.y << " " << eye.z << '\n';
    //clouds.tick();
    //camera_rotation_angle += 1;
    //cout << player.indicator.position.x << " " << player.indicator.position.y << " " << player.indicator.position.z << '\n';
}

/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL(GLFWwindow *window, int width, int height) {
    /* Objects should be created before any other gl function and shaders */
    // Create the models

    
    player = Plane(0,0,0);
    sea = Sea(0,-30,0);
    ring = Ring(0,20,0);
    // indicator = Indicator(player.position.x,player.position.y+5,player.position.z);

    for(int i = 0;i<number_of_islands;i++)
    {
        // int positions = rand()%4;
        // if(positions==0)
        //    islands.push_back(Floor(rand()%1000,-100,rand()%1000));
        // else if(positions==1)
        // {
        //     islands.push_back(Floor(-rand()%1000,-100,rand()%1000));
        // }
        // else if(positions == 2)
        // {
           islands.push_back(Floor(-rand()%500,-25,-rand()%500));
        // }
        // else if(positions == 3)
        // {
        //     islands.push_back(Floor(-rand()%1000,-100,rand()%1000));
        // }
        
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
            counter ++ ;
            // 60 fps
            // OpenGL Draw commands
            draw();
            // Swap Frame Buffer in double buffering
            glfwSwapBuffers(window);

            tick_elements();
            tick_input(window);
            delete_objects();
        }

        // Poll for Keyboard and mouse events
        glfwPollEvents();
    }

    quit(window);
}

bool detect_collision(bounding_sphere_t a, bounding_sphere_t b) {
    return (abs(a.x - b.x) * 1 < (a.radius + b.radius)) &&
           (abs(a.y - b.y) * 1 < (a.radius + b.radius)) &&
           (abs(a.z - b.z) * 1 < (a.radius + b.radius)) ;
}

void reset_screen() {
    float top    = screen_center_y + 4 / screen_zoom;
    float bottom = screen_center_y - 4 / screen_zoom;
    float left   = screen_center_x - 4 / screen_zoom;
    float right  = screen_center_x + 4 / screen_zoom;
    Matrices.projection = glm::perspective(1.0f, 1.0f, 1.0f, 500.0f);
}

bool check_pass_through()
{
    if(ring.position.z < player.position.z + 4)
    {
        float length = glm::length(player.position-ring.position);

        if(length<5)
        {
            return true;
        }
    }

    return false;
}

void delete_objects()
{
    for(int i = 0;i<bullets.size();i++)
    {
        if(bullets[i].position.x -bullets[i].initial_position.x > 100 || bullets[i].position.z - bullets[i].initial_position.z > 100 || bullets[i].position.x - bullets[i].initial_position.x < -100 || bullets[i].position.z - bullets[i].initial_position.z < -100 )
        {
            bullets.erase(bullets.begin()+i);
        }
    }

    for(int i = 0;i<enemy_bullets.size();i++)
    {
        if(enemy_bullets[i].position.x - enemy_bullets[i].initial_direction.x > 100 || enemy_bullets[i].position.y - enemy_bullets[i].initial_direction.y > 100 || enemy_bullets[i].position.z - enemy_bullets[i].initial_direction.z > 100)
        {
            enemy_bullets.erase(enemy_bullets.begin()+i);
        }
    }
}

void enemy_selected(int i)
{
    enemy_bullets.push_back(Enemy_bullet(islands[i].land_enemies.enemy_cannon.position.x,islands[i].land_enemies.enemy_cannon.position.y,islands[i].land_enemies.enemy_cannon.position.z,(player.position)-islands[i].land_enemies.enemy_cannon.position));
}
