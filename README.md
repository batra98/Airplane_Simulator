# Airplane Simulator

# DEVELOPER
  GAURAV BATRA

## About the game
It is a 3D emulation of a jet fighter plane game built in OpenGL.

![Movement](./gifs/Movement.gif)

## :file_folder: File Structure
```bash
.
├── CMakeLists.txt
├── README.md
├── assets
├── build
└── src

3 directories, 2 files
```
- **assets** - Contains the files for the bullet sound and theme song.
- **src** - Contains all the code for the game in cpp.

## :running: Running the game
* To build the game enter these command:
```bash
mkdir output
cd output
cmake ..
make all
```
* To run the game enter these command in the output directory:
```bash
./graphics_asgn1
```

## :video_game: Controls
- **Movement**
	- Move Forward: **W**
	- Move Backward: **S**
	- Yaw Right: **D**
	- Yaw Left: **A**
	- Pitch Up: **E**
	- Pitch Down: **R**
	- Roll Left: **X**
	- Roll Right: **C**
	- Fire bullet: **F**
	- Drop bomb: **B**
- Changing Camera Views: **V**


### Types of Views
- Plane View: In this view, the player sees what the plane sees.
- Top View: This is a top down view, as if the player is looking vertically downwards from a position.
- Tower View: The camera is on a tower, observing the plane from an angle.
- Helicopter-cam View: Movement of the camera is controlled by mouse.
- Follow-cam View: In this view, the camera is following the plane. 

![Movement](./gifs/Camera_angles.gif)

### Features
- The plane view has a dashboard with a compass and altitude and speed-meter.
- There are enemies that follow the plane and shoot missiles.
- There are parachutes that can fired and ground enemies can be destroyed by bombs. Each action given certain score.
- There is a arrow over the plane, which points towards a ring suspended in the air. Passing through the ring gives addtional points.
- Also have included theme sound and firing sound.

___________________________________________

Feel free to Contribute :heart:




