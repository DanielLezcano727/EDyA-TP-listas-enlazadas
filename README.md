# TP 1 EdyAl

## Tareas:
 - [X] Implementacion de selection sort **Fran** 
     - [X] Respetar signatura dada por el PDF
 
 - [X] Implementacion de merge sort
     - [X] Mergear alguna implemetación
     - [X] Respetar signatura dada por el PDF
    
 - [X] Implementacion de insertion sort **Dani** 
     - [X] Respetar signatura dada por el PDF
 
 - [X] Generador de personas
 
 - [X] Cambiar función Compara para que respete PDF
 
 - [ ] Considerar sugerencia final del TP (Funcion que toma archivoSalida, lista, metodo ord, func comp y retorna la lista ordenada escrita en un archivo)
    
 - [X] Implementar input para Ordenar lista
 
 - [X] Implementar output para Ordenar lista
    - [X] Función que parsea struct_persona a string
    
 - [ ] Decidir e implementar un funcionamiento para makefile
  
 - [ ] Escribir informe
 
 - [X] Limpiar código siguiendo convenciones de C, proyectos y TP1
 
 - [X] Considerar multiplicar dos rand (respetando que sigan dentro del rango) para evitar limite de windows
    
 - [ ] Una ejecucion, 6 resultados
 
 

## Consultas

 * ¿Como almacenar los datos en la lista? (Copiar los datos o asignar puntero)
    * Copiar los datos:
      * ¿Como copiarlo cuando el dato es de tipo struct?
    * Reasignar el puntero:
      * ¿Que hacer respecto a los datos primitivos?
      * ¿Que hacer hacer si el usuario modifica los datos?
 * Fijarse lo del triple puntero en generar datos de prueba -> leer paises
 * Sobre el punto 2d (Como funciona el tema de las dos funciones. Los dos metodos de comparacion, como interpretar)
   -rta: una lista por ejecucion
 * Stable sort. Nosotros leemos al reves el archivo (con agregar inicio), el stable sort deberia devolver al reves tambien
   -rta: agregar al final
 * De que se mide el tiempo (algoritmo o programa completo). Y si se hace solo del algoritmo, como se mide el algoritmo dentro del programa?)
   -rta: de los algoritmos puntualmente
 
## Notas para informe
* Convenciones:
   * La función que compara es T si x > y
