workspace_dir="/home/wingboy/workspace/os_study"
src_path=${workspace_dir}/src/course1.hpp
gcc -c -S ${src_path} 
# gcc -o main ${src_path} 
# objdump -s -d main > main.txt