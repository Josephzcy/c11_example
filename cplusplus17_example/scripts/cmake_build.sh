#!/bin/bash
RED_COLOR='\E[1;31m'
GREEN_COLOR='\E[1;32m'
NC='\e[0m'

echo -e "${GREEN_COLOR} ====================== [ build start ] ....======================== ${NC}"
echo -e "${GREEN_COLOR}Usage: $0 eg: $0 ${NC}"
# echo -e "${GREEN_COLOR}Usage: $0 <ball name> <j3|tda4>   eg: $0 mviz_apa_vm_v2.0.4 tda4  ${NC}"

workspace_dir="/home/wingboy/workspace/cplusplus17_example"
target_dir=${workspace_dir}/build

if [ ! -d ${target_dir}  ];then
  mkdir -p ${target_dir} 
fi
cd build
cmake -j ${nproc} ..
make

echo -e "${GREEN_COLOR} ======================  [ build end ]  ....======================== ${NC}"
