workspace_dir="/home/wingboy/workspace/os_study"
cd ${workspace_dir}
if [ ! -d "build" ]; then
    mkdir build && cd build
fi

cd build
cmake .. &&make -j8
