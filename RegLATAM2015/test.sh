#!/bin/bash

for i in $(seq 99)
do
  echo "Run $i"
  time ./g<Ginp/G_$i.in >Ginp/GG_$i.sol
  diff Ginp/G_$i.sol Ginp/GG_$i.sol
done
