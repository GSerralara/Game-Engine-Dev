# If the line starts with a # symbol, it is a comment
# and should be ignored

*SCENE_NAME Nivell4

# The RESOURCES line tells us how many resources we need to load
*RESOURCES 9

# each resource to load starts with RESOURCE followed by the type
*RESOURCE mesh
*NAME submarine
*PATH data/assets/submarino.ase


*RESOURCE mesh
*NAME sphere
*PATH data/assets/sphere.ase

*RESOURCE shader
*NAME simple
*PATH data/shaders/simple.vert data/shaders/simple.frag

*RESOURCE shader
*NAME simpleBlue
*PATH data/shaders/simple.vert data/shaders/simpleBlue.frag

*RESOURCE shader
*NAME phong_tex
*PATH data/shaders/phong.vert data/shaders/phong.frag

*RESOURCE shader
*NAME skybox_shader
*PATH data/shaders/skybox.vert data/shaders/skybox.frag

*RESOURCE texture
*NAME submarine_diffuse
*PATH data/assets/submarino.tga


*RESOURCE texture
*NAME milkyway_tex
*PATH data/assets/milkyway.tga


*RESOURCE texture
*NAME rock_diffuse
*PATH data/assets/asteroide.tga
# the OBJECTS line tells us how many objects we need to load
*OBJECTS 5

*OBJECT GameObjectSkybox
*NAME skybox
*MESH sphere
*SHADER simpleBlue
*TEXTURE milkyway_tex
*POSITION 0.0 0.0 0.0
*ROTATION 0.0 0.0 0.0
*SCALE 3.0 3.0 3.0

# each object starts with the OBJECT followed by the type

*OBJECT GameObjectMesh
*NAME waypoint1
*MESH sphere
*SHADER phong_tex
*TEXTURE rock_diffuse
*POSITION 0.0 0.0 50.0
*ROTATION 0.0 0.0 0.0
*SCALE 0.01 0.01 0.01
*PARENT root
*COLLISION yes

*OBJECT GameObjectMesh
*NAME waypoint2
*MESH sphere
*SHADER phong_tex
*TEXTURE rock_diffuse
*POSITION 25.0 25.0 25.0
*ROTATION 0.0 0.0 0.0
*SCALE 0.01 0.01 0.01
*PARENT root
*COLLISION no

*OBJECT GameObjectEnemy
*NAME enemy1
*MESH sphere
*SHADER phong_tex
*TEXTURE rock_diffuse
*POSITION -50.0 0.0 0.0
*ROTATION 0.0 0.0 90.0
*SCALE 0.3 0.3 0.3
*PARENT root
*COLLISION yes
*NUMWAYPOINTS 4
*WAYPOINT 0.0 0.0 50.0
*WAYPOINT 25.0 25.0 25.0
*WAYPOINT 0.0 25.0 0.0
*WAYPOINT -125.0 100.0 125.0

*OBJECT GameObjectEnemy
*NAME enemy2
*MESH sphere
*SHADER simpleBlue
*TEXTURE x3_runner_diffuse
*POSITION 50.0 0.0 0.0
*ROTATION 0.0 0.0 90.0
*SCALE 0.1 0.1 0.1
*PARENT root
*COLLISION no
*NUMWAYPOINTS 4
*WAYPOINT 0.0 50.0 50.0
*WAYPOINT 15.0 -25.0 25.0
*WAYPOINT 0.0 35.0 0.0
*WAYPOINT -105.0 300.0 205.0

*OBJECT GameObjectPlayer
*NAME player1
*MESH submarine
*SHADER phong_tex
*TEXTURE submarine_diffuse
*POSITION 0.0 40.0 0.0
*ROTATION 0.0 0.0 0.0
*SCALE 1.0 1.0 1.0
*PARENT root
*COLLISION yes