Sistema de Gestión de Inventario: El Científico de Juegos

Este proyecto es una aplicación de consola desarrollada en C++ diseñada para administrar de manera eficiente el stock de una tienda de videojuegos. El sistema permite realizar todas las operaciones de mantenimiento de datos (CRUD) utilizando estructuras de datos dinámicas y validaciones en tiempo real para garantizar la integridad de la información.
Descripción General

El programa utiliza una matriz dinámica para organizar los juegos. A diferencia de una lista simple, este sistema trata el inventario como un espacio físico donde cada registro tiene una ubicación específica y un estado de ocupación. Está diseñado para ser robusto frente a errores de usuario y para automatizar procesos de negocio comunes en la industria.
Funcionalidades Principales

    Registro Inteligente: Al agregar un juego, el sistema solicita datos como título, desarrollador, precio, calificación y categoría.

    Prevención de Duplicados: Antes de guardar, el programa verifica que el ID ingresado no pertenezca a otro juego ya registrado.

    Reglas de Negocio Automáticas: Si se define que un juego es de formato digital, el sistema aplica automáticamente un descuento del 10% sobre el precio base.

    Gestión de Espacios: El sistema reconoce qué lugares de la matriz están vacíos, permitiendo reutilizar espacios de juegos eliminados.

    Ordenamiento por Precio: Incluye un algoritmo que organiza los juegos del más económico al más costoso, manteniendo los espacios vacíos al final de la visualización.

    Módulo de Análisis: Calcula estadísticas clave como el precio promedio del inventario y identifica el título con la calificación más alta.

Aspectos Técnicos

    Estructuras de Datos: Uso de struct para el modelado de objetos y std::vector para la gestión de memoria dinámica.

    Validación de Entrada: Implementación de filtros para evitar que el ingreso de caracteres no numéricos bloquee el programa.

    Algoritmos de Búsqueda: Búsqueda secuencial optimizada para encontrar registros por ID o por nombre exacto.

    Formateo de Salida: Uso de la librería iomanip para generar tablas alineadas y legibles en la terminal.

Instrucciones de Uso

    Compilación: Utilizar un compilador de C++ (como GCC o Clang) compatible con el estándar C++11 o superior.

    Navegación: Al iniciar, se presenta un menú numerado. Ingrese el número correspondiente a la acción que desea realizar.

    Ingreso de Datos: Siga las instrucciones en pantalla. Para opciones de sí/no (como el formato digital), utilice 1 para afirmar y 0 para negar.

    Finalización: Utilice la opción 0 para cerrar el programa de forma correcta.

Requisitos del Sistema

    Sistema operativo compatible con ejecución de consola (Windows, Linux o macOS).

    Compilador de C++ instalado.

Este software fue desarrollado como parte de la actividad de Investigación Formativa para demostrar la aplicación de estructuras de datos en soluciones del mundo real.
