# Caso_uso_008.md

## Ordenar alumnos

**ID:** 008.  
**Breve descripción:** Ordena los alumnos almacenados en el sistema por un determinado parámetro.

**Actores principales:** Profesor.  
**Actores secundarios:** Alumnos.

**Precondiciones:**

1. Debe haber dos o más alumnos almacenados en el sistema.

**Flujo Principal:**

1. El caso empieza cuando el usuario elige la opción de mostrar varios alumnos (todos, o de un equipo) y se ha producido la selección de los mismos.
2. Se pregunta al usuario por el parámetro encargado de ordenar el conjunto de alumnos entre los siguientes:
    * DNI
    * Apellido
    * Curso más alto matriculado
3. Una vez seleccionado, se permite que el usuario elija que se ordenen los alumnos de manera ascendente o descendente (en función del parámetro escogido).

**Postcondiciones:**

* El sistema borra todos los datos de la base de datos.

**Flujo alternativo:**

* Si se ha seleccionado la opción de mostrar todos los alumnos, también se debe seleccionar un cuarto parámetro por el que ordenar los alumnos: Nº de equipo.