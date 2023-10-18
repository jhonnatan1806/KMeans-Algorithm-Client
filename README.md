# Manual de uso

Instalar dependencias necesarias para compilar

```bash
sudo apt update
sudo apt install build-essential
```

Compilar archivos

```bash
g++ src/*.cpp lib/*.hpp include/*.hpp -o bin/client -lpthread
```

Ejecutar cliente

```bash
./client <ip> <puerto>
```
