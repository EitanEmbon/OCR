# OCR
INTRODUCCIÓN

  El objetivo de este trabajo práctico es el desarrollo y evaluación de una herramienta
de OCR (Optical Character Recognition) para el reconocimiento de d´ıgitos manuscritos en
imágenes.
  Se quiere desarrollar un algoritmo de clasificación supervisado el cual se debería entrenar
con una base de caracteres conocidos que luego nos serviría para reconocer otras instancias
de esos caracteres no presentes en la base de datos de entrenamiento.
  El foco de este trabajo está puesto en la experimentación científica de un método de OCR
simplificado, clasificación por vecinos más cercanos con reducción de la dimensionalidad.

METODOLOGÍA

  En este trabajo práctico nos limitaremos a reconocer dígitos manuscritos entre el 0 y el 9.
 Sin embargo, es deseable que este método pueda ser extendido para reconocer cualquier tipo
de caracteres o símbolos.
  Como instancias de entrenamiento, se tiene una base de datos de n imágenes en escala de
grises, las cuales se encuentran etiquetadas con su clase correspondiente, es decir, el dígito,
0-9, al que representan.

RECONOCIMIENTO DE DÍGITOS

  El objetivo del reconocimiento de dígitos consiste en utilizar la información de la base de
datos para, dada una nueva imagen de un dígito sin etiquetar, determinar a cuál corresponde.
  Una primera aproximaci´on es utilizar el conocido algoritmo de k vecinos más cercanos o
kNN (k nearest neghborhood). 
  En esta dirección, consideraremos el método de reducción de dimensionalidad Análisis de
componentes principales o PCA (por su sigla en inglés) dejando de la lado los procesamientos
de imágenes que se puedan realizar previamente o alternativamente a aplicar PCA.
  
VALIDACIÓN CRUZADA

  Finalmente, nos concentramos en la evaluación de los métodos y en la correcta elección
de sus parámetros.

  Por lo tanto, se hará uso de la técnica de cross validation, en particular el K-fold cross
validation, para realizar una estimación de los parámetros de los métodos que resulte estadísticamente más robusta.
