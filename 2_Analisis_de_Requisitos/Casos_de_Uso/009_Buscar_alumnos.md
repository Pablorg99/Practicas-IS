# Caso_uso_009.md

## Buscar alumnos

**ID:** 009.  
**Breve descripción:** Busca uno, o un conjunto de alumnos y los selecciona.

**Actores principales:** Profesor.  
**Actores secundarios:** Alumnos.

**Precondiciones:**

1. El alumno o conjunto de alumnos a seleccionar debe existir.

**Flujo Principal:**

1. El caso empieza cuando el usuario selecciona la opción de buscar.
2. Se pregunta al usuario si desea seleccionar:
    * Un alumno.
    * Un equipo.
    * Todos los alumnos.
    * Un número determinado de alumnos.
3. Según lo que se haya seleccionado:
    * *Un alumno:* 
        * Se le pregunta al usuario por el parámetro por el que se quiere buscar:
            * DNI.
            * Apellidos.
        * Se pide dicho parámetro.
    * *Un equipo:*
        * Se pide el número del equipo. 
    * *Un numero determinado:*
        * El usuario introduce dicho número.
        * Se pregunta el parámetro por el que se quiere buscar.
        * Se itera preguntando dicho parámetro el número de veces introducido previamente.
4. Se sale de la búsqueda
**Postcondiciones:**

* El alumno o conjunto de alumnos de la búsqueda son seleccionados y se abre el menú para seleccionar la acción a realizar.

**Flujo alternativo:**

* Si en alguna búsqueda no se encuentra el alumno indicado, mostrar mensaje de error y dar la opción de seguir buscando, o de salir.