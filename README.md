# TP3 de Métodos Numéricos
## 2021, 2do cuatrimestre

## Instrucciones

1. Crear un repo git en donde se bajen esto

```
git init
git remote add origin <nuestra-nueva-url-de-git>
```

2. Bajarse los repositorios de `pybind` y `eigen` como submódulos

```
git submodule init
git submodule add https://github.com/eigenteam/eigen-git-mirror
git submodule add https://github.com/pybind/pybind11
git mv eigen-git-mirror eigen
# Elegimos versiones de eigen y pybind
cd pybind11/ && git checkout v2.2.4 && cd ..
cd eigen && git checkout 3.3.7 && cd ..
```

3. Instalar requerimientos (*Previamente activar el entorno virtual. Ver  más abajo*)

```
pip install -r requirements.txt
```

4. Descomprimir datos

```
cd data && gunzip *.gz && cd ..
```

5. Correr Jupyter

```
jupyter lab
```

Listo!

### Datos

En `data/` tenemos los datos brindados (`data/expectativa_de_vida.csv`) y su descripción (`data/expectativa_de_vida_descripcion.txt`). Además de otros indicadores y métricas añadidos para completar los mismos.  

### Otros directorios

En `src/` está el código de C++, en particular en `src/metnum.cpp` está el entry-point de pybind.

En `notebooks/` está el análisis exploratorio de datos (`notebooks/analisis.ipynb`), los modelos de regresión que fueron probados 
(`notebooks/modelado.ipynb`) y el test de las funciones de regresión lineal (`notebooks/test.ipynb`)


## Compilación
Ejecutar la primera celda del notebook `notebooks/test.ipynb` o seguir los siguientes pasos:

- Compilar el código C++ en un módulo de python
```
mkdir build
cd build
rm -rf *
cmake -DPYTHON_EXECUTABLE="$(which python)" -DCMAKE_BUILD_TYPE=Release ..
```
- Al ejecutar el siguiente comando se compila e instala la librería en el directorio `notebooks`
```
make install
```
