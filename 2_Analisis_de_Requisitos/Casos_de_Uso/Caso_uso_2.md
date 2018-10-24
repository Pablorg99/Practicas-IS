# Caso_uso_2.md
### Modificar Alumno
**ID:** 002.  
**Breve descripción:** Permite editar un alumno ya existente.

**Actores principales:** Profesor.  
**Actores secundarios:** Alumnos.

**Precondiciones:**
1. El alumno debe existir.

**Flujo Principal:**
1. El caso empieza cuando el usuario desea modificar un alumno.
2. El sistema pregunta al usuario que parámetro desea editar.
3. El sistema recoge el nuevo valor introducido por el ususario.
4. El sistema pregunta si se desea editar algún otro parámetro.
5. En caso afirmattivo, se vuelve al paso 2.

**Postcondiciones:**
* El sistema sustituye los datos antiguos por los nuevos datos introducidos.

**Flujo alternativo:**
* Si el alumno a modificar no existe, el sistema muestra un error.
