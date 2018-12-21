## Añadir Ayudante

**ID:** 013.  
**Breve descripción:** Permite insertar un nuevo profesor ayudante.

**Actores principales:** Profesor.  
**Actores secundarios:** Alumnos.

**Precondiciones:**

1. El usuario debe ser profesor coordinador.

**Flujo Principal:**

1. El caso empieza cuando el usuario selecciona dicha opción en el menú.
2. El sistema pide la información del nuevo profesor.
3. El usuario introduce los datos solicitados.

**Postcondiciones:**

* El sistema recoge los datos introducidos por el usuario y lo registra como coordinador.

**Flujo alternativo:**

* Si no se introducen los campos obligatorios (DNI, nombre, apellidos y contraseña), el sistema muestra un error y pide que se introduzcan.
