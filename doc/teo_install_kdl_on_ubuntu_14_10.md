## Install KDL (Ubuntu 14.10)

We use KDL for kinematics. Installing KDL on Ubuntu is quite straightforward. Note that you will be prompted for your password upon using '''sudo''' a couple of times:

```bash
sudo apt-get install libeigen3-dev
cd  # go home
mkdir -p repos; cd repos  # make $HOME/repos if it doesn't exist; then, enter it
git clone https://github.com/orocos/orocos_kinematics_dynamics.git
cd orocos_kinematics_dynamics/orocos_kdl; mkdir build; cd build
cmake ..
make -j3;  sudo make install; sudo ldconfig; cd  # go home
```
