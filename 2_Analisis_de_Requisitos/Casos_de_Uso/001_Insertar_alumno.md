## Insertar Alumno

**ID:** 001.  
**Breve descripción:** Permite insertar un nuevo alumno.

**Actores principales:** Profesor.  
**Actores secundarios:** Alumnos.

**Precondiciones:**

1. El máximo permitido será de 150 alumos.
2. El alumno no debe existir.

**Flujo Principal:**

1. El caso empieza cuando el usuario desea añadir un alumno.
2. El sistema recoge los datos introducidos por el usuario.

**Postcondiciones:**

* El sistema guarda los datos introducidos.

**Flujo alternativo:**

* Si no se introducen los campos obligatorios (DNI, nombre y apellidos), el sistema muestra un error y pide que se introduzcan.
* Si el alumno existe se mostrará un error y se vuelve al menú.
