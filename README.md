# SIIProject Grupo 5

Interfaz gráfica 3D para el videojuego empleando las bibliotecas libres openscenegraph.

- Conseguimos poder añadir elementos a la vista 3D, incluso partiendo de una vista vacia sin ocasionar cuelgues del sistema.
- Implementamos el borrado de los diversos elementos de forma correcta y adecuada (sin que se quedaran en pantalla los elementos antiguos que ya no debían aparecer), solucionando el problema de que el programa se quedase colgado cada vez que realizábamos tal acción con el programa en marcha.
- Hemos logrado implementar, mediante la aplicación de transformaciones, variar la posición, orientación y escalado de los nodos (persona, robot, cofre y esfera).
- Hemos separado todo el bloque dedicado a la visualización (función run) en dos partes: actualizar y mostrar, con el fin de modularlo.
- Hemos substituido los nodos gráficos anteriores  representados por formas simples (cilindros) por modelos en 3D (persona, robot, cofre). 
- Se ha cambiado el tamaño de las pelotas para visualizarlas mejor. Sugerimos realizar idéntico cambio en el modelo 2D.
- Implementamos la posibilidad de añadir diferentes puntos de luz, con posiciones y tonalidades de color configurables, según se considere oportuno. Sugerimos añadir sliders para configurar el color según los gustos del usuario, ya que nosotros hemos puesto valores fijos.
- Añadimos en MainWindow.cpp los eventos necesarios para que funcionara la visualización en 3D, ya que sólo estaban implementados para el 2D.

Ideas para mejorar por los alumnos del próximo año:
- Añadir sombras
- Cargar modelos 3D que permitan movilidad de alguna de sus partes, agrupando varias figuras y empleando las matrices de transformación (nosotros sólo hemos podido jugar con la posición, orientación y escalado del bloque completo)
- Trabajar con modelos que no sean STL para poder dar diferentes capas de color a diferentes partes del modelo. (Ej. Cartoon-cow en el libro OSG beginner’s book)
- Valorar distintos puntos de vista de la cámara (1ª persona, 3ª persona, etc)
- Valorar implementación en 3D con gafas (anaglifo; en el libro mencionado anteriormente aparece un ejemplo)
- Implementar las funciones guardar y recuperar la vista 3D, que ahora están vacías.
