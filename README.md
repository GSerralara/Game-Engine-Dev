# Game Engine Dev
En este proyecto hemos trabajado el desarrollo de un Game Engine, a su vez que desarrollar un juego con este

# Estudiantes:
- Aleix Olle Requena - aleix.olle@students.salle.url.edu
- Guillermo Serraclara Vall - guillermo.serraclara@students.salle.url.edu

# Demo Video

* (Youtube video)[https://youtu.be/DNBDPFsAIao]

> **WARNING**: No sabemos porque el video se ve a tirones pero en la aplicacion esto no pasa

# CONTROLES

## movimiento
	Shift-izquierdo --> acelerar
	Crtl-izquierdo --> frenar
	W / S --> Subir / Bajar
	A / D --> Rotar Izquierda / Derecha

## movimiento de camara
	La camara seguira al jugador, cuando se pulsa la tecla C se activa el modo de camara libre.
	Para mover la camara en modo libre utilizar el raton pulsando el boton izquierdo mientras se mueve.

## Mapas
	Hay 4 mapas de diferentes tem�ticas.
	Para pasar de un mapa a otro se debe pulsar B / N.

## Salir
	Para salir del juego se debe pulsar la tecla Esc.

El juego simmplemente deja que el jugador se mueva por el mapa donde hay distintos objetos en el espacio y tambien algunos enemigos que se van moviendo.

## Camara 
	La clase camera tiene un atributo que muestra que objeto esta siguiendo, como es la camara de jugador seguira a GameObjectPlayer.

## Movimiento de los enemigos
	Los enemigos se moveran por el mapa siguiendo unos waypoints.

## Colisiones
	Aunque no hay ninguna animacion que muestre las colisiones, estas se pueden ver en la linea de comandos cuando suceden.
	Las colisiones se pueden habilitar o deshabilitar para cada objeto en los ficheros sceneX.rg. 

## SceneParser
	Los recursos y los objetos del juego se cargan con la clase Scenegraph. Los archivos de escena solo necesitan el encabezado con 
	el numero de objetos necesarios del mapa que se esta mostrando y los recursos necesarios (meshes, texturas ...). Los objetos se analizan de forma recursiva.

## SceneGraph
	Las escenas se cargan con un GameObject "rooteado" que puede tener hijos cada uno de los cuales podr� tener m�s hijos. 
	Cada objeto en la escena tiene que especificar quien es su padre.


## Diferentes niveles
	Diferentes niveles pueden ser cargados a la vez, usando las teclas B y N para cambiar entre ellos. Si se quiere crear
	un nuevo nivel, se tiene que crear un nuevo sceneX.rg y añadir una nueva linea Game::init() para cargarlo. A partir 
	de ese momento se podra jugar con el nuevo nivel.

## Diferentes shaders
	Hay distintos shaders, los enemigos, el jugador y algun objeto mas estan renderizados con phong shaders. En cambio, hay un objeto renderizado
	con un shader simple sin textura con un solo color.



# Problemas encontrados
Cuando cambiamos el nivel en el que se juega, el aspect ratio del mundo 3d cambia un poco y los modelos aparecen un poco distorsionados.
El cambio de camara cuesta un poco de realizar ya que hay veces que al apretar la C no hace el cambio. El movimiento de la camara con el 
raton es un poco tosco y solo funciona cuando el boton izquierdo esta presionado.
Las colisiones en el nivel 2 no funcionan.
El nivel 4, se quedo en fase de desarrollo.Pero se pueden observar los assets del nivel se hayan entre los archivos.