## Formatear la Base de Datos

**ID:** 007.  
**Breve descripción:** Borra todos los datos almacenados en la base de datos.

**Actores principales:** Profesor.  
**Actores secundarios:** Alumnos.

**Precondiciones:**

1. La base de datos debe tener almacenada información de al menos un alumno.

**Flujo Principal:**

1. El caso empieza cuando el usuario elige la opción de reset de la base de datos.
2. Se realiza una pregunta al usuario para asegurarse de que el usuario desea borrar todos los datos.

**Postcondiciones:**

* El sistema borra todos los datos de la base de datos.

**Flujo alternativo:**

* Si no se encuentra ningún alumno en la base de datos, se le informará al usuario y no se realizará ninguna acción.
