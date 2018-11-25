## Crear Coordinador

**ID:** 011.  
**Breve descripción:** Permite insertar al profesor coordinador.

**Actores principales:** Profesor.  
**Actores secundarios:** Alumnos.

**Precondiciones:**

1. Se ejecuta al iniciar el sistema por primera vez, por tanto el coordinador no debe existir.

**Flujo Principal:**

1. El caso empieza cuando el usuario inicia el sistema por primera vez.
2. El sistema comprueba que no existe ningún coordinador y pide que el usuario se registre como tal.

**Postcondiciones:**

*  El sistema recoge los datos introducidos por el usuario y lo registra como coordinador.

**Flujo alternativo:**

* Si no se introducen los campos obligatorios (DNI, nombre, apellidos y contraseña), el sistema muestra un error y pide que se introduzcan.
