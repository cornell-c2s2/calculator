### Platformio Setup

### Setup the Venv

```
python3 -m venv venv
pip install -r requirements.txt
```

### Everytime Setup

Before you start development with `platformio` always start by setting up your virtual environment:
```. venv/bin/activate```

You'll know the virtual environment is active when your shell always starts with `(venv)`.
### Compiling Native

```pio run -e native```

### Running native

```.pio/build/native/program```

### Build and run native tests

```pio test -e native_test```


### Compiling Arduino

```
pio run -e arduino
```