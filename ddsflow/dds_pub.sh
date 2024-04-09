#!/bin/bash
export LD_LIBRARY_PATH=./lib:./runtime
./bin/dds_pub ./config/pub.json "camera_id"