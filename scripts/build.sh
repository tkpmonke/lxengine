#!/bin/bash
set -e

echo -e "\n\nChecking if premake is installed"
if ! command -v premake5 &> /dev/null; then
    echo -e "\033[1;4;91mPremake not found.\nLXEngine requires premake for building makefiles."
    echo "Please Install premake To Continue Build"
    

    echo -e "\033[0m\n\nExiting..."
    exit 1

else
   echo -e "\nPremake is installed!"
fi

echo "Starting Premake build"
cd ../ 
premake5 gmake2

echo -e "\nPremake files generated"

echo -e "\n\nBuilding"
make -j20 config=release
if [ $? -ne 0 ]; then
   echo -e "\n\033[1;4;91mBuild Failed\033[0m"
else
   echo -e "\033[1;96mBuild Successful\033[0m"
fi

