#!/bin/bash

if [ $# -eq 0 ];
then
    ACE_DIR=../AdvancedCrystalEngine/
else
    ACE_DIR=$1
fi

rm -Rf ./Include/*
rm -Rf ./Library/*

cp -R $ACE_DIR/Include/* ./Include
cp -R $ACE_DIR/Binary/* ./Library