### Platformio Setup

### Setup the Venv

```
python3 -m venv venv
pip install -r requirements.txt
```

### Everytime Setup

```. venv/bin/activate```

### Compiling Native

```pio run -e native```

### Running native

```./.pio/build/native/program```

### Compiling Arduino

```
pio run -e arduino
```