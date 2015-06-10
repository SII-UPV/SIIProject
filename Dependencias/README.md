"OpenSceneGraph-3.2.0.zip" son los fuentes de OpenSceneGraph que descargué de la página web.
Versión 3.2.0


"OpenSceneGraph" son las librerías de OpenSceneGraph (binarios generados con CMake) que podemos utilizar en nuestros proyectos de Qt Creator
He copiado este directorio en "C:\Archivos de programa (x86)"
MinGW y CMake lo descargamos de la web ogicial, y ajustamos estas varibles de entorno a la última versión
He añadido las siguientes variables de entorno...

   En mi usuario...

      OSG_LIBRARY_PATH
      C:\Program Files (x86)\OpenSceneGraph\bin (o la subcarpeta "bin" de la carpeta donde tengáis la librería)

      OSG_FILE_PATH
      C:\Development\OpenSceneGraph\OpenSceneGraphData (o donde tengáis los archivos de datos que OSG carga)

      OSG_NOTIFY_LEVEL
      DEBUG (para que ahora que estamos desarrollando nos dé más información de depuración)

      PATH contiene...
      C:\MinGW\bin;C:\Development\CMake\CMake 3.0.0\CMake\bin; (para que funcionasen MinGW y CMake) /*MinGW y CMake lo descargamos de la web ogicial, y ajustamos estas varibles de entorno a la última versión*/

   En el sistema...

      PATH contiene...
      C:\Program Files (x86)\OpenSceneGraph\bin;C:\Qt\5.3\mingw482_32\bin;


*****
Para compilar OpenSceneGraph utilicé...

"MinGW" compilador de C++ (GNU)
Versión 2.4.8

"CMake"
Versión 3.0.0


*****
Puede que todavía necesitemos descargar plugins para poder leer archivos de imágenes con compresión: jpg, png,... por ejemplo para cargar texturas y aplicarlas en los modelos.


*****
"OpenSceneGraphHelloWorld.pro" es una plantilla de un proyecto Qt que he utilizado para compilar el "Hola Mundo" con OSG.
La ruta de INCLUDEPATH y LIBS son como las tengo en mi ordenador, cambiadlas según vuestro caso.