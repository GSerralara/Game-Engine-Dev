# If the line starts with a # symbol, it is a comment
# and should be ignored

*SCENE_NAME Nivell3

# The RESOURCES line tells us how many resources we need to load
*RESOURCES 9

*RESOURCE mesh
*NAME barco
*PATH data/assets/barco.ase

*RESOURCE mesh
*NAME terrain
*PATH data/assets/agua.ase

*RESOURCE mesh
*NAME avio
*PATH data/assets/bomber_axis.ase

*RESOURCE texture
*NAME avio_diffuse
*PATH data/assets/bomber_axis.tga

*RESOURCE mesh
*NAME enemic
*PATH data/assets/wildcat.ase

*RESOURCE texture
*NAME enemic_diffuse
*PATH data/assets/wildcat.tga

*RESOURCE texture
*NAME barco_diffuse
*PATH data/assets/barco.tga

*RESOURCE texture
*NAME terrain_tex
*PATH data/assets/agua.tga

*RESOURCE texture
*NAME sky_tex
*PATH data/assets/cielo.tga

# each resource to load starts with RESOURCE followed by the type

# the OBJECTS line tells us how many objects we need to load
*OBJECTS 6

*OBJECT GameObjectSkybox
*NAME skybox
*MESH sphere
*SHADER skybox_shader
*TEXTURE sky_tex
*POSITION 0.0 0.0 0.0
*ROTATION 0.0 0.0 0.0
*SCALE 3.0 3.0 3.0

# each object starts with the OBJECT followed by the type
*OBJECT GameObjectMesh
*NAME terrain
*MESH terrain
*SHADER phong_tex
*TEXTURE terrain_tex
*POSITION -50.0 -40.0 20.0
*ROTATION 0.0 0.0 0.0
*SCALE 1.0 1.0 1.0
*PARENT root
*COLLISION yes

*OBJECT GameObjectPlayer
*NAME player1
*MESH avio
*SHADER phong_tex
*TEXTURE avio_diffuse
*POSITION 0.0 40.0 0.0
*ROTATION 0.0 0.0 0.0
*SCALE 1.0 1.0 1.0
*PARENT root
*COLLISION yes

*OBJECT GameObjectEnemy
*NAME enemy4
*MESH barco
*SHADER phong_tex
*TEXTURE barco_diffuse
*POSITION 200.0 -40.0 0.0
*ROTATION 90.0 0.0 0.0
*SCALE 1.0 1.0 1.0
*PARENT root
*COLLISION yes
*NUMWAYPOINTS 4
*WAYPOINT 50.0 -40.0 50.0
*WAYPOINT 0.0 -40.0 150.0
*WAYPOINT 200.0 -40.0 0.0
*WAYPOINT 0.0 -40.0 125.0

*OBJECT GameObjectEnemy
*NAME enemy5
*MESH enemic
*SHADER phong_tex
*TEXTURE enemic_diffuse
*POSITION 20.0 50.0 50.0
*ROTATION 0.0 0.0 0.0
*SCALE 1.0 1.0 1.0
*PARENT root
*COLLISION yes
*NUMWAYPOINTS 4
*WAYPOINT 50.0 25.0 50.0
*WAYPOINT 55.0 75.0 10.0
*WAYPOINT 78.0 75.0 26.0
*WAYPOINT 10.0 0.0 123.0

*OBJECT GameObjectEnemy
*NAME enemy6
*MESH enemic
*SHADER phong_tex
*TEXTURE enemic_diffuse
*POSITION -20.0 50.0 -50.0
*ROTATION 0.0 0.0 0.0
*SCALE 1.0 1.0 1.0
*PARENT root
*COLLISION yes
*NUMWAYPOINTS 5
*WAYPOINT 30.0 25.0 200.0
*WAYPOINT 36.0 25.0 100.0
*WAYPOINT 75.0 25.0 540.0
*WAYPOINT 78.0 25.0 26.0
*WAYPOINT 10.0 25.0 123.0