#!/bin/bash
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
BASE_DIR=$SCRIPT_DIR/../
rm -rf $SCRIPT_DIR/out/* 
php $SCRIPT_DIR/gen_packets.php 
cp -rf $SCRIPT_DIR/out/* $BASE_DIR
