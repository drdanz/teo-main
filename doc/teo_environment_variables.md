## Advanced: TEO Environment Variables (Ubuntu 14.10)

For the general installation and use case, TEO Environment Variables are not required.

There are two cases where you will want to:

### Using TEO Libraries externally

You will need TEO_DIR for CMake to find the TEO configuration file.

There are two ways of doing this. Please __select only one of these two options__:

 1) Through the ~/.profile file (parsed on init, so would require reboot).
 
 2) Through the ~/.bashrc file (parsed inside each _new_ terminal, so not available if launched directly from GUI).

__Add the following line__ at the end of __the selected file, substituting '/your/full/path/to/teo-main/' for your full path__:

```bash
export TEO_DIR=/your/full/path/to/teo-main/build
```


### Using TEO without installing

You will need YARP_DATA_DIRS for finding the share folder. You also probably want build/bin in your PATH.

There are two ways of doing this. Please __select only one of these two options__:

 1) Through the ~/.profile file (parsed on init, so would require reboot).
 
 2) Through the ~/.bashrc file (parsed inside each _new_ terminal, so not available if launched directly from GUI).
 
__Add the following lines__ at the end of __the selected file, substituting '/your/full/path/to/teo-main/' for your full path__:

```bash
export YARP_DATA_DIRS=/your/full/path/to/teo-main/build/share/teo:$YARP_DATA_DIRS:/usr/local/share/yarp
export PATH=$PATH:/your/full/path/to/teo-main/build/bin
```
