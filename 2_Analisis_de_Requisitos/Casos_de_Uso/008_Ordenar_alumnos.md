# Caso_uso_008.md

## Ordenar alumnos

**ID:** 008.  
**Breve descripción:** Ordena los alumnos almacenados en el sistema por un determinado parámetro.

**Actores principales:** Profesor.  
**Actores secundarios:** Alumnos.

**Precondiciones:**

1. Debe haber dos o más alumnos almacenados en el sistema.

**Flujo Principal:**

1. El caso empieza cuando el usuario elige la opción de mostrar alumnos (deben ser varios) y se ha seleccionado la opción de ordenar.
2. Se pregunta al usuario por el parámetro encargado de ordenar el conjunto de alumnos entre los siguientes:
    * DNI
    * Apellido
    * Curso más alto matriculado
3. Una vez seleccionado, se permite que el usuario elija que se ordenen los alumnos de manera ascendente o descendente (en función del parámetro escogido).

**Postcondiciones:**

* Se produce la impresión de los alumnos en el orden establecido.

**Flujo alternativo:**

* Si se ha seleccionado la opción de mostrar todos los alumnos, también se debe seleccionar un cuarto parámetro por el que ordenar los alumnos: Nº de equipo.