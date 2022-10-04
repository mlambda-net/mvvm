#!/bin/bash
pushd .

  mkdir -p ~/tools/sonarqube
  cd ~/tools/sonarqube
  wget https://binaries.sonarsource.com/Distribution/sonar-scanner-cli/sonar-scanner-cli-4.7.0.2747-linux.zip
  unzip sonar-scanner-cli-4.7.0.2747-linux.zip
  mv sonar-scanner-cli-4.7.0.2747-linux ~/tools/sonar-scanner
  export

  case "$1" in
    exp) export;;
  esac

popd


export() {
    echo 'export PATH=:$PATH:PATH=$PATH:~/tools/sonar-scanner/bin' >> ~/.profile
    source ~/.profile
}