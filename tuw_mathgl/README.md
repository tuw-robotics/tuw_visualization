# tuw_mathgl
ROS wrapper arount mathgl to create visualizations. MathGL it is platform independent and free (under GPL v.2.0 license). I can be found at: http://mathgl.sourceforge.net
## Installation
The CMakeList.txt holds a statement to download a spezific mathgl version for compilation.

### Ubuntu dependencies

```bash
sudo apt-get install \
  libqt5opengl5-dev \
  libfltk1.3-dev
```

### Compile Options
Deactivate the command ```unset(MGL_HAVE_TYPEOF CACHE)``` at line 264 in mathgl/CMakeLists.txt o that it looks like a ```#unset(MGL_HAVE_TYPEOF CACHE``` 

```bash
catkin_make \
  -Denable-gif=ON \
  -Denable-pthr-widget=ON \
  -Denable-qt5=ON \
  -Denable-fltk=ON \
  -DMGL_HAVE_C99_COMPLEX=0 \
  -DMGL_HAVE_TYPEOF=0
```
