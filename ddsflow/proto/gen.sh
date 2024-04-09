#!/bin/bash
total_proto=(
"parkingspace.proto"
)

#PROTO_PATH="/home/devin/data2/workspace/conan_lane/pack_from_prebuild/protobuf/binaries/linux/"
PROTO_PATH="/home/lpzone/.conan/data/protobuf/3.13.0/minieye/release/package/3514868bc476d2de54aeec66950036c00b484169"

export PATH=${PROTO_PATH}:${PATH}

for var in ${total_proto[@]};
do
	echo $var
	#${PROTO_PATH}/bin/protoc --help
	#echo ${PROTO_PATH}/include/google/protobuf/
	${PROTO_PATH}/bin/protoc --proto_path=${PROTO_PATH}/include/google/protobuf/ --proto_path=.  --cpp_out . $var
done
