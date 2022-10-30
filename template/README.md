# Reconocimiento de dígitos: TP2 de Métodos Numéricos
## 2022, 1er cuatrimestre


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

4. Compilación

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

- Luego se podrá hacer directamente import desde Jupyter notebooks usando el nombre del módulo exportado (import metnum en este caso)


Listo. Ya pueden disfrutar del trabajo.

### Otros directorios

En `src/` está el código de C++, en particular en `src/metnum.cpp` está el entry-point de pybind.


## Creación de un entorno virtual de python

### Con pyenv

```
curl https://pyenv.run | bash
```

Luego, se sugiere agregar unas líneas al bashrc (fijarse en la seccion "set up your shell envirnment for pyenv" en el [link https://github.com/pyenv/pyenv#set-up-your-shell-environment-for-pyenv] Se necesita openssl descargado). Hacer eso, **REINICIAR LA CONSOLA** y luego...

```
pyenv install 3.6.5
pyenv global 3.6.5
pyenv virtualenv 3.6.5 tp2
```

En el directorio del proyecto

```
pyenv activate tp2
```

### Directamente con python3
```
python3 -m venv tp2
source tp2/bin/activate
```

### Con Conda
```
conda create --name tp2 python=3.6.5
conda activate tp2
```

## Instalación de las depencias
```
pip install -r requirements.txt
```

## Correr notebooks de jupyter  (Acuerdense de hacer esto)

```
cd notebooks
jupyter lab
```
o  notebook
```
jupyter notebook
```


