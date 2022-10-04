pushd .

mkdir -p ~/tools && cd ~/tools
git clone https://github.com/emscripten-core/emsdk.git
cd emsdk
git pull
./emsdk install latest
./emsdk activate latest

case "$1" in
  exp) export;;
esac

popd

export() {
      echo 'export PATH=:$PATH:~/tools/emsdk' >> ~/.profile
      echo 'export PATH=$PATH:~/tools/emsdk' >> ~/.profile
      echo 'export EMSDK=~/tools/emsdk/upstream/emscripten' >> ~/.profile
      echo 'export EMSCRIPTEN_ROOT=~/tools/emsdk/upstream/emscripten' >> ~/.profile
      echo 'export EMSDK_NODE=~/tools/emsdk/node/14.18.2_64bit/bin/node' >> ~/.profile
      echo 'export EM_CONFIG=~/tools/emsdk/.emscripten' >> ~/.profile
      echo 'export EMSDK_QUIET=1' >> ~/.profile
      source ~/.profile
}